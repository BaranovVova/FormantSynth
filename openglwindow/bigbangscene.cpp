
#include "bigbangscene.h"
#include <vector>
#include <random>
#include "blastsphere.h"
#include "particle.h"
#include "openglwindow/common2.h"
#include "freqtable.h"
#include "openglwindow/newtonfractal.h"
#include <QElapsedTimer>

#define REBORN_TIME 2
#define PARTICLES_HISTORY_SIZE 60*4 // for 60 fps and 5 seconds
#define MAX_PARTICLES 5000

using namespace std;

const float threshold = 0.2;
static vector<QVector3D> points, points0;
static vector<float> radii;
static vector<QVector3D> velocities;
static vector<QVector3D> output;
    // The start time.
QElapsedTimer timer;
FreqTable freq_table;
int Ncloud = 0;
float lastNoteTime;

struct StatisticsOnFrame
{
    QVector2D maxVelocity;
    QVector2D minVelocity;
    QVector2D averageVelocity;
    //QVector2D averagePosition;

};

StatisticsOnFrame stat;

void createSpiralFlow(std::vector<Particle>& particles, float centerX, float centerY, float centerZ, float radius, float velocity, float angularVelocity, int numParticles);



std::vector<Particle> particles;
std::vector<Particle> particles_blast;
std::vector<std::vector<Particle>> particles_clouds;
std::vector<std::vector<Particle>> particles_copy;
vector<QVector3D> spherePoints;
BlastSphere sphere_blast;
std::vector<QRectF> rects;
float y_window_offset=0;

void BigBangScene::init()
{
    points.push_back(QVector3D(-1,0,0));
    points.push_back(QVector3D(4.17f,5,0));
    points.push_back(QVector3D(0,0,0));

    for(int i = 0; i < 20; i++)
        points.push_back(QVector3D(0,0,0));

    velocities.resize(points.size());
    points0 = points;
    output.resize(points.size());
    rects.clear();

    radii.push_back(1);
    radii.push_back(1);
    radii.push_back(0.7);
    for(int i = 0; i < 20; i++)
        radii.push_back(1);

    QVector3D min, max;
    findBoundaries(min, max);
    sphere_blast.generateSphere(points[0], 30, 1);
    // Initialize the start time.
    timer.start();

    //qDebug() << "boundaries " << min << " to " << max;

    // Create a spiral flow with speed 10 m/s.
    //how many frames 60 * 5
    // reserve memory for history on 5 seconds
    particles.resize(MAX_PARTICLES);
    particles_blast.resize(MAX_PARTICLES);
    particles_copy.resize(PARTICLES_HISTORY_SIZE);
    particles_clouds.resize(PARTICLES_HISTORY_SIZE);
    for(int i=0; i < PARTICLES_HISTORY_SIZE; i++)
    {
        particles_copy[i].resize(MAX_PARTICLES);
        particles_clouds[i].resize(MAX_PARTICLES);
    }
    //    for(int i=0; i < 10000; i++)
    //        particles[i].history.resize(60*5);




    createSpiralFlow(particles, points[0].x(), points[0].y(), 0.0f, 1.0f, 10.0f, 1.0f, 1000);


    // Create RINGS
}


//! [5]
void BigBangScene::render()
{
    clrscr();
    const qreal retinaScale = 1;//devicePixelRatio();
    f->glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    f->glClear(GL_COLOR_BUFFER_BIT);

    auto prender = ParticleRender::getInstance();
    prender->m_program->bind();

    QMatrix4x4 matrix;
    matrix.perspective(60.0f, 1, 0.1f, 500.0f);
    matrix.translate(0, 0, -20);
    //matrix.rotate(100.0f * m_frame / screen()->refreshRate(), 0, 1, 0);

    prender->m_program->setUniformValue(prender->m_matrixUniform, matrix);

    static const GLfloat vertices[] = {
        0.0f,  0.707f,
        -0.5f, -0.5f,
        0.5f, -0.5f
    };

    static const GLfloat vertices2[] = {
        -24, -11,
        24, -11,
        24, 11,
        -24, 11
    };
    static const GLfloat textcoords[] = {
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f
    };

    static const GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };

    // Render to the framebuffer
    f->glBindFramebuffer(GL_DRAW_FRAMEBUFFER, prender->framebuffer);
    f->glClear(GL_COLOR_BUFFER_BIT);
    prender->m_program->setUniformValue(prender->m_pipe, 0);
    //Render(true);
    f->glReadPixels( 0,0,  prender->TEXTURE_WIDTH, prender->TEXTURE_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, prender->pixels);

    //Render velocities image
    f->glClear(GL_COLOR_BUFFER_BIT);
    prender->m_program->setUniformValue(prender->m_pipe, 1);
    for(int i = 0; i < particles.size(); i++)
        prender->spawnParticle(particles[i], QVector3D(1,1,1));
    f->glReadPixels( 0,0,   prender->TEXTURE_WIDTH,  prender->TEXTURE_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, prender->vel_pixels);

    //QImage qi = QImage(vel_pixels, TEXTURE_WIDTH, TEXTURE_HEIGHT, QImage::Format_ARGB32);
    //qi = qi.rgbSwapped();
    //qi.save("frame.png");


    // Unbind the framebuffer
    f->glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);

    // get texture units
    int u1 = prender->m_program->uniformLocation("texture");
    int u2 = prender->m_program->uniformLocation("vel_texture");

    // Read the texture from the framebuffer

    f->glUniform1i(u1, 0);
    f->glActiveTexture(GL_TEXTURE0);
    f->glEnable(GL_TEXTURE_2D);
    f->glBindTexture(GL_TEXTURE_2D, prender->texture);
    f->glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,  prender->TEXTURE_WIDTH,  prender->TEXTURE_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE,  prender->pixels);


    f->glUniform1i(u2, 1);
    f->glActiveTexture(GL_TEXTURE1);
    f->glEnable(GL_TEXTURE_2D);
    f->glBindTexture(GL_TEXTURE_2D, prender->vel_texture);
    f->glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,  prender->TEXTURE_WIDTH,  prender->TEXTURE_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE,  prender->vel_pixels);

    prender->m_program->setUniformValue(prender->m_pipe, 2);

    // DRAW a TEXTURED QUAD with framebuffer blurred image


    f->glVertexAttribPointer(prender->m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices2);
    f->glVertexAttribPointer(prender->m_textcoordAttr, 2, GL_FLOAT, GL_FALSE, 0, textcoords);

    f->glEnableVertexAttribArray(prender->m_posAttr);
    f->glEnableVertexAttribArray(prender->m_textcoordAttr);
    f->glEnableVertexAttribArray(prender->m_colAttr);

    f->glDrawArrays(GL_QUADS, 0, 4);

    f->glDisableVertexAttribArray(prender->m_colAttr);
    f->glDisableVertexAttribArray(prender->m_posAttr);
    f->glDisableVertexAttribArray(prender->m_textcoordAttr);



    // DRAW several particles as rectangles on current window
    prender->m_program->setUniformValue(prender->m_pipe, 0);
  /*
    //float y = -11;
    float note_width = 0.55;
    int n_note = 0;
    for(float y=-11; y < 11; y+=note_width)
    for(float x=-11; x < 11; x+=note_width)
    {
        //if(n_note < 28)
        {
            Particle p;
            p.position = QVector3D(x,y,0);
            prender->spawnParticle(p, QVector3D(1,1,1),note_width);
        }
        //n_note++;
    }

*/

    // detecting center of a cloud (once a frame)
    // try to do linear interpolation between two point clouds
    int cnt=0;
    for(int i=0; i < rects.size(); i++)
    {
        if( ( rects[i].topLeft().x() > -10) &&
             ( rects[i].topLeft().x() < 10) &&
             ( rects[i].topLeft().y() > -10) &&
             ( rects[i].topLeft().y() < 10))
            if( ( rects[i].bottomRight().x() > -10) &&
                 ( rects[i].bottomRight().x() < 10) &&
                 ( rects[i].bottomRight().y() > -10) &&
                 ( rects[i].bottomRight().y() < 10))
            {
                if(cnt < 5)
                {
                    points[cnt] = QVector3D(rects[i].center().x(), rects[i].center().y(),0);
                    radii[cnt] = rects[i].height();
    //                prender->spawnRect(rects[i], QVector3D(0,1,0));
                }
                cnt++;
            }
    }

    Render(true);
    for(int i=0; i < rects.size(); i++)
        prender->spawnRect(rects[i], QVector3D(0,1,0));



    //propagateWaves(particles, 5,5, MAX_PARTICLES, 20, 5, 0.1, t);

    //Render();
    prender->m_program->release();

    //QPainter painter(this);
    //painter.drawText(QPointF(10,10),"Test string!");
    Nframe++;
    sphere_blast.frames_since_blast++;
    delta_t = 0.0166666666;
    t+=delta_t;
    delta_t = updateFPSLabel();

}



void BigBangScene::NotePlaySlot(std::vector<Notestruct>* song, Notestruct note)
{

    // Map Notes to the space of rectangles in xy plane

    if(rects.size() < song->size())
        rects.resize( song->size() );
    float pixels_in_second = 10;
    y_window_offset = note.t_start  * pixels_in_second;
    float half_screen_offset = 12.0f;
    float note_width = 0.33;
    int i=0;
    for(auto ns=song->begin(); ns!=song->end(); ns++)
    {
        QRectF r;
        float x_margin = 0;
        QString name = freq_table.getNoteName((*ns).note);
        char c = (char)name[0].toLatin1();
        if( c == 'C' || c == 'D' || c == 'E' || c == 'F')
        {
            x_margin = -note_width/2;
        }

        if( c == 'F' || c == 'G' || c == 'A' || c == 'B')
        {
            x_margin =  0;
        }

        float x_offset = 72 * note_width + x_margin;
        float h = (*ns).t_end - (*ns).t_start;

        r.setLeft(note_width * ((*ns).note) - x_offset);
        r.setRight(note_width * ((*ns).note) + 2*note_width - x_offset);

        r.setTop(((*ns).t_start - note.t_start ) * pixels_in_second - half_screen_offset);
        r.setBottom(((*ns).t_end - note.t_start ) * pixels_in_second - half_screen_offset);
        r.setHeight(h * pixels_in_second);
        r.setWidth(note_width);
        rects[i] = r;
        i++;
    }

    {
        QVector3D min, max;
        findBoundaries(min, max);
        TrowRandomPointsInside(min, max);

        if( Ncloud % 20 == 0)
          createSpiralFlow(particles, points[0].x(), points[0].y(), 0.0f, 1.0f, 10.0f, 1.0f, MAX_PARTICLES);
    }

    if( Ncloud > PARTICLES_HISTORY_SIZE-2 )
        Ncloud = 0;
    Ncloud++;
    lastNoteTime = t;


}


void BigBangScene::Render(bool doTimeStep)
{
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);

    QVector3D c0 = points[0];
    QVector3D c1 = points[1];

    //points[0] = circularTrajectory(4, 1, t, phaze_corr);
    velocities[0] = (c0 - points[0]) / 0.0125;
    velocities[1] = (c1 - points[1]) / 0.0125;
    if(velocities[0].length() != 5 ) velocities[0] = QVector3D(4.59204, -1.97805, 0);

    // update radius
    radii[0] = 1 + 0.05*pulsatingFunction(t);

    //points[1] = circularTrajectory(4, 8, 1 - t, M_PI);

    QVector3D min, max;
    findBoundaries(min, max);
    //glColor3f(1,1,1);

    // check colisions
    Sphere s1, s2;
    s1.center = points[0];
    s1.radius = radii[0];
    s2.center = points[1];
    s2.radius = radii[1];
    auto prender = ParticleRender::getInstance();

    shapesPrintf(7,1,"      time_reborn=%f t=%f frame_since_blast = %d!",sphere_blast.time_reborn,t, sphere_blast.frame_since_blast);
    shapesPrintf(8,1,"     frames_2endreverse=%d  frames_since_blast=%d ", sphere_blast.frames_2endreverse, sphere_blast.frames_since_blast);


    if( collide_spheres(s1, s2) )
    {
        sphere_blast.generateSphere(points[0], 30, radii[0]);
        //glColor3f(1,1,1);
        if(sphere_blast.blasted == false)
        {

            sphere_blast.blasted = true;
            sphere_blast.frame_since_blast = Nframe;
            sphere_blast.frames_since_blast = 0;
            sphere_blast.reversingStarted = false;
            sphere_blast.time_reborn = t + REBORN_TIME;
            sphere_blast.frame_2startreverse = Nframe + 15;
            sphere_blast.frames_2endreverse = Nframe + 30;
            sphere_blast.frames_in_history = 15;
            sphere_blast.frame_reborn = Nframe + 15 * REBORN_TIME + 10;

            // RESET ALL PARTICLES
            for(int i=0; i < particles_blast.size(); i++)
            {

                particles_blast[i].position = QVector3D(0,0,0);
                particles_blast[i].velocity = QVector3D(0,0,0);
                particles_blast[i].acceleration = QVector3D(0,0,0);
                particles_blast[i].mass = 2.4;
            }


            for(int i=0; i < sphere_blast.spherePoints.size(); i++)
            {
                particles_blast[i].position = sphere_blast.spherePoints[i];
                particles_blast[i].velocity = QVector3D(50-(float)100*dis(gen), 50-(float)100*dis(gen), 50-(float)100*dis(gen));
                particles_blast[i].acceleration = QVector3D((float)5*dis(gen), (float)5*dis(gen), (float)5*dis(gen));
                particles_blast[i].mass = 2.4;
            }
        }
    }

    // correct phase ant the reverse end
    if( Nframe == sphere_blast.frames_2endreverse)
    {
        sphere_blast.blasted = false;
        //glColor3f(1,1,0);
        //glPushMatrix();
        //glTranslatef(points[0].x(), points[0].y(), points[0].z());
        //glutWireSphere(radii[0], 20, 20);
        //glPopMatrix();
        //prender->m_program->setUniformValue(prender->m_pipe, 0);
        //sphere_blast.Render(f,  prender->m_posAttr,  prender->m_colAttr, QVector3D(1,1,1),points[0]);

        //for(int i=0; i < particles.size(); i++)
        //    particles[i].position = QVector3D(1000,1000,1000);

    }



    if( !sphere_blast.blasted )
    {
        //glPushMatrix();
        //glTranslatef(points[0].x(), points[0].y(), points[0].z());
        //glutWireSphere(radii[0], 20, 20);
        //glPopMatrix();
        //  sphere_blast.Render(this,  prender->m_posAttr,  prender->m_colAttr, QVector3D(0.7,0.0,0.0),points[0]);

    }


    // reverse the blast!

    if( Nframe > sphere_blast.frame_2startreverse && Nframe < sphere_blast.frame_reborn)
    {
        int delta = sphere_blast.frame_2startreverse - sphere_blast.frame_since_blast;
        int offset_reverse = sphere_blast.frames_in_history + delta - sphere_blast.frames_since_blast;
        shapesPrintf(15,1,"START REVERSING PROCESS!");
        shapesPrintf(17,1," offset_reverse = %d", offset_reverse);
        int frames_before_reborn = sphere_blast.frame_reborn - Nframe;
        for(int i=0; i < sphere_blast.spherePoints.size(); i++)
        {
            if( offset_reverse > 0 )
            {
                Particle p = particles_copy[offset_reverse][i];
                p.velocity =  -p.velocity;
                particles_blast[i] = p;
            }
        }

    }



    // draw spheres
    //glColor3f(0,1,0);
    for(int i=1; i < 2; i++)
    {

        //glPushMatrix();
        //glTranslatef(points[i].x(), points[i].y(), points[i].z());
        //glutWireSphere(radii[i], 20, 20);
        //glPopMatrix();
    }


    // integrate particle coords
    //glColor3f(1,1,1);
    //glBegin(GL_POINTS);
    //glPointSize(1);


    //collide rectangles with particles


        for(int j=0; j < rects.size(); j++)
        {
            if( ( rects[j].topLeft().x() > -10) &&
                 ( rects[j].topLeft().x() < 10) &&
                 ( rects[j].topLeft().y() > -10) &&
                 ( rects[j].topLeft().y() < -6))
                if( ( rects[j].bottomRight().x() > -10) &&
                     ( rects[j].bottomRight().x() < 10) &&
                     ( rects[j].bottomRight().y() > -10) &&
                     ( rects[j].bottomRight().y() < -6))
                {
                    for (int i = 0; i < 1000; i++)
                    {
                        Particle p = particles[i];
                        Sphere sphere;
                        sphere.center = QVector3D(rects[j].center().x(),rects[j].center().y(),0);
                        sphere.radius = rects[j].height();
                        collide(particles[i], sphere);
                    }
                }
        }


    for (int i = 0; i < particles_blast.size(); i++)
    {


        particles_blast[i].position = integrateCoordinates(particles_blast[i], delta_t);
        prender->spawnParticle(particles_blast[i], QVector3D(1,1,1));
    }

    for (int i = 0; i < particles.size(); i++)
    {
          particles[i].position = integrateCoordinates(particles[i], delta_t);

          prender->spawnParticle(particles[i], QVector3D(1,1,1));


    }
    //glEnd();

    //QThread::currentThread()->msleep(10);


    // save particles in history buffer
    if(sphere_blast.frames_since_blast < PARTICLES_HISTORY_SIZE)
        for(int i=0; i < sphere_blast.spherePoints.size(); i++)
            particles_copy[sphere_blast.frames_since_blast][i] = particles[i];



    //    if((Nframe % 100) == 0)
    // Create a spiral flow with speed 10 m/s.
    //        createSpiralFlow(particles, points[0].x(), points[0].y(), 0,
    //                         (float)dis(gen), 10*(float)dis(gen), 1.0f, 1000 * (float)dis(gen));

    //qDebug() << "Nframe " << Nframe;
    if (( t > sphere_blast.time_reborn ) )
    {
        sphere_blast.blasted = false;
    }

}


void findBoundaries(QVector3D& minBoundary, QVector3D& maxBoundary)
{
    double minX=numeric_limits<double>::max(), minY=minX, minZ=minX;
    double maxX=numeric_limits<double>::min(), maxY=maxX, maxZ=maxX;
    for(int i=0; i < points.size(); i++)
    {
        double d;
        d = points[i].x() - radii[i];
        minX = qMin(d, minX) - 1;
        d = points[i].y() - radii[i];
        minY = qMin(d, minY) - 1;
        d = points[i].z() - radii[i];
        minZ = qMin(d, minZ);
        d = points[i].x() + radii[i];
        maxX = qMax(d, maxX);
        d = points[i].y() + radii[i];
        maxY = qMax(d, maxY);
        d = points[i].z() + radii[i];
        maxZ = qMax(d, maxZ);
    }
    minBoundary = QVector3D(minX, minY, minZ);
    maxBoundary = QVector3D(maxX, maxY, maxZ);
}


void BigBangScene::TrowRandomPointsInside(QVector3D minBoundary, QVector3D maxBoundary)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::mt19937 gen2(rd());
    auto prender = ParticleRender::getInstance();
    // 50% of the time, generate a random number between 0 and 1
    // 50% of the time, generate a random number between 10 and 15

    // Algorithm of dividing the space :
    // 1. Throw 4 random points inside boundaries of 1 child
    // 2. if all 4 points do not metaball surface points
    // 3.    set node as rejected
    std::exponential_distribution<> d(0.5);
    int N = MAX_PARTICLES;
    //glColor3f(0,1,0);
    //glPointSize(2);
    //glBegin(GL_POINTS);


    float mean = 2;
    float standardDeviation = 5;
    std::normal_distribution<float> d2(mean, standardDeviation);

    for(int i=0; i < N; i++)
    {
        int s1 = 1;
        int s2 = 1;
        int s3 = 1;
        int j = 1;

        if( d2(gen2) > 1) s1 = -1;
        if( d2(gen2) > 1) s2 = -1;
        if( d2(gen2) > 1) s3 = -1;

        double X = points[j].x() - s1*d(gen) ;
        double Y = points[j].y() - s2*d(gen);
        double Z = points[j].z() - s3*d(gen);

        //        float X = points[j].x() + std::normal_distribution<float>(mean, standardDeviation)(gen);
        //        float Y = points[j].y() + std::normal_distribution<float>(mean, standardDeviation)(gen);
        //        float Z = points[j].z() + std::normal_distribution<float>(mean, standardDeviation)(gen);

        float f = metaball(QVector3D(X, Y, Z),points,radii);
        //qDebug() << "X=" << X << "Y=" << Y << " f = " << f;


        if(f > threshold)
        {

            //glVertex3f(X, Y, Z);
            Particle p;
            p.position = QVector3D(X, Y, Z);
            p.velocity = QVector3D(d(gen), d(gen), d(gen));

            //particles[i]=p;
            particles_clouds[Ncloud][i] = p;
            if(Ncloud>1)
            {
                particles[i].velocity = (p.position - particles_clouds[Ncloud-1][i].position);
                particles[i].velocity.normalize();
                particles[i].velocity*=particles[i].mass;
                particles[i].acceleration = QVector3D(10*d(gen)*particles[i].mass,10*d(gen)*particles[i].mass,10*d(gen));
            }
            if(Ncloud%13 == 0)
                particles[i].position = p.position;

            //prender->spawnParticle(p, QVector3D(0,0.5,0));


        }
    }
    //glEnd();
}

void BigBangScene::TrowRandomPointsInsideRect(QRectF rect)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::mt19937 gen2(rd());
    auto prender = ParticleRender::getInstance();
    // 50% of the time, generate a random number between 0 and 1
    // 50% of the time, generate a random number between 10 and 15

    // Algorithm of dividing the space :
    // 1. Throw 4 random points inside boundaries of 1 child
    // 2. if all 4 points do not metaball surface points
    // 3.    set node as rejected
    std::exponential_distribution<> d(0.5);
    int N = 10;
    //glColor3f(0,1,0);
    //glPointSize(2);
    //glBegin(GL_POINTS);


    float mean = 2;
    float standardDeviation = 5;
    std::normal_distribution<float> d2(mean, standardDeviation);

    for(int i=0; i < N; i++)
    {
        int s1 = 1;
        int s2 = 1;
        int s3 = 1;
        int j = 1;

        if( d2(gen2) > 1) s1 = -1;
        if( d2(gen2) > 1) s2 = -1;
        if( d2(gen2) > 1) s3 = -1;

        double X = rect.center().x() - s1*d(gen);
        double Y = rect.center().y() - s2*d(gen);
        double Z = s3*d(gen);

        //        float X = points[j].x() + std::normal_distribution<float>(mean, standardDeviation)(gen);
        //        float Y = points[j].y() + std::normal_distribution<float>(mean, standardDeviation)(gen);
        //        float Z = points[j].z() + std::normal_distribution<float>(mean, standardDeviation)(gen);

        //float f = metaball(QVector3D(X, Y, Z),pointsrect.height());
        //qDebug() << "X=" << X << "Y=" << Y << " f = " << f;


       //if(f > threshold)
        {

            //glVertex3f(X, Y, Z);
            Particle p;
            p.position = QVector3D(X, Y, Z);
            p.velocity = QVector3D(d(gen), d(gen), d(gen));
            prender->spawnParticle(p, QVector3D(0,0.5,0));


        }
    }
    //glEnd();
}



// Update the FPS label.
double updateFPSLabel() {

    // Calculate the FPS.
    float fps = 1000000000. / ((float)timer.nsecsElapsed());
    double dt = ((float)timer.nsecsElapsed()) / 1000000000.;
    timer.restart();

    // Set the text of the FPS label.
    shapesPrintf(20,1,"FPS: %f", fps);
    return dt;
}
