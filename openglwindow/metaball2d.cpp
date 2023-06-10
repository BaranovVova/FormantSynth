#if 0

#include "blastsphere.h"
#include <math.h>
#include "GL/freeglut.h"

#include <limits>
#include <QVector3D>
#include <QMatrix4x4>
#include <QDebug>
#include <QThread>
#include <random>
#include <vector>
#include <QElapsedTimer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include "metaball2d.h"

using namespace std;

#define REBORN_TIME 2
#define PARTICLES_HISTORY_SIZE 60*4 // for 60 fps and 5 seconds
#define MAX_PARTICLES 5000
int Nframe = 0;
double t = 0, delta_t = 0.01;
int direction = 1;
const float threshold = 0.2;
float phaze_corr = 0;
static vector<QVector3D> points, points0;
static vector<float> radii;
static vector<QVector3D> velocities;
static vector<QVector3D> output;
    // The start time.
QElapsedTimer timer;
void findBoundaries(QVector3D& minBoundary, QVector3D& maxBoundary);
extern void shapesPrintf (int row, int col, const char *fmt, ...);

struct Particle {
    Particle()
    {

    }
    QVector3D position;
    QVector3D velocity;
    QVector3D acceleration;
    float mass;
    float radius;
    float color;
    float life;
    vector<Particle> history;
};

struct Sphere {
    QVector3D center;
    float radius;
};

void createSpiralFlow(std::vector<Particle>& particles, float centerX, float centerY, float centerZ, float radius, float velocity, float angularVelocity, int numParticles);

std::vector<Particle> particles;
std::vector<std::vector<Particle>> particles_copy;
vector<QVector3D> spherePoints;
const int sphereResolution = 30;
BlastSphere sphere_blast;


Metaball2d::Metaball2d()
{
    points.push_back(QVector3D(-1,0,0));
    points.push_back(QVector3D(4.17f,5,0));
    points.push_back(QVector3D(0,0,0));
    velocities.resize(points.size());
    points0 = points;
    output.resize(points.size());
    radii.push_back(1);
    radii.push_back(1);
    radii.push_back(0.7);
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
    particles_copy.resize(PARTICLES_HISTORY_SIZE);
    for(int i=0; i < PARTICLES_HISTORY_SIZE; i++)
        particles_copy[i].resize(MAX_PARTICLES);
//    for(int i=0; i < 10000; i++)
//        particles[i].history.resize(60*5);


    createSpiralFlow(particles, 0.0f, 0.0f, 0.0f, 1.0f, 10.0f, 1.0f, 1000);

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

QVector3D interpolateLine(QVector3D p1, QVector3D p2, float t) {
    // Calculate the vector between the points.
    QVector3D v = p2 - p1;

    // Calculate the interpolated point.
    return p1 + v * t;
}

float metaball(QVector3D point, std::vector<QVector3D> centers, std::vector<float> radii) {
    // Initialize the output value.
    float value = 0.0f;

    // Iterate over the metaballs.
    for (int i = 0; i < centers.size(); i++) {
        // Calculate the distance between the point and the current metaball center.
        float distance = (point - centers[i]).length();

        // Calculate the contribution of the current metaball to the output value.
        value += (1.0f / (distance * distance + radii[i] * radii[i]));
    }

    // Return the output value.
    return value;
}

void TrowRandomPointsInside(QVector3D minBoundary, QVector3D maxBoundary)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::mt19937 gen2(rd());
    // 50% of the time, generate a random number between 0 and 1
    // 50% of the time, generate a random number between 10 and 15

    // Algorithm of dividing the space :
    // 1. Throw 4 random points inside boundaries of 1 child
    // 2. if all 4 points do not metaball surface points
    // 3.    set node as rejected
    std::exponential_distribution<> d(0.5);
    int N = MAX_PARTICLES;
    glColor3f(0,1,0);
    glPointSize(2);
    glBegin(GL_POINTS);


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

            glVertex3f(X, Y, Z);

        }
    }
    glEnd();
}

void Metaball2d::DrawBoundary(QVector3D min, QVector3D max)
{

    glBegin(GL_LINE_LOOP);
    glVertex3f(min.x(), min.y(), 0);
    glVertex3f(min.x(), max.y(), 0);
    glVertex3f(min.x(), max.y(), 0);
    glVertex3f(max.x(), max.y(), 0);
    glVertex3f(max.x(), max.y(), 0);
    glVertex3f(max.x(), min.y(), 0);
    glEnd();

}



QVector3D circularTrajectory(float radius, float frequency, float time, float phi0=0) {
    // Calculate the angle of the point.
    float angle = frequency * time;

    // Calculate the x and y coordinates of the point.
    float x = radius * cos(angle + phi0);
    float y = radius * sin(angle + phi0);

    // Return the point.
    return QVector3D(x, y, 0.0f);
}

void createSpiralFlow(std::vector<Particle>& particles, float centerX, float centerY, float centerZ, float radius, float velocity, float angularVelocity, int numParticles) {
    // Create a random number generator.
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create a vector to store the particles.
    std::uniform_real_distribution<> dis(0.0, 1.0);


    QVector3D r1(0,0,0), r2(radius,0,0);
    // Generate the particles.
    for (int i = 0; i < numParticles; i++) {
        float radiusT = interpolateLine(r1,r2,(float)i/numParticles).x();
        // Generate a random x coordinate.
        float x = centerX + radiusT * std::cos(2 * M_PI * i / numParticles) + (float)dis(gen);

        // Generate a random y coordinate.
        float y = centerY + radiusT * std::sin(2 * M_PI * i / numParticles) + (float)dis(gen);

        // Generate a random z coordinate.
        float z = centerZ;

        // Generate a random velocity.
        float vx = velocity * std::cos(2 * M_PI * i / numParticles) + (float)4*dis(gen);
        float vy = velocity * std::sin(2 * M_PI * i / numParticles) + (float)4*dis(gen);
        float vz = (float)4*dis(gen);

        // Generate a random angular velocity.
        float wx = angularVelocity * std::cos(2 * M_PI * i / numParticles)  + (float)6*dis(gen);;
        float wy = angularVelocity * std::sin(2 * M_PI * i / numParticles)  + (float)6*dis(gen);;
        float wz = (float)6*dis(gen);

        // Add the particle to the vector.
        Particle p;
        p.position = QVector3D(x,y,z);
        p.velocity = QVector3D(vx,vy,vz);
        p.acceleration = QVector3D(wx,wy,wz);
        p.mass = 2.4;
        particles[i] = p;
    }

    const float dt = 0.0125f;
    // Set the velocity of the particles to spiral outwards.
    for (int i = 0; i < particles.size(); i++) {
        particles[i].velocity.setX( particles[i].velocity.x() + particles[i].acceleration.x() * dt );
        particles[i].velocity.setY( particles[i].velocity.y() + particles[i].acceleration.y() * dt );
        particles[i].velocity.setZ( particles[i].velocity.z() + particles[i].acceleration.z() * dt );
    }
}

QVector3D integrateCoordinates(Particle& particle, float dt) {
    // Update the position of the particle.
    particle.position += particle.velocity * dt;

    // Update the velocity of the particle.
    particle.velocity += particle.acceleration * dt;

    // Return the new position of the particle.
    return particle.position;
}

bool collide(Particle& particle, Sphere sphere) {

    // Check if the particle is colliding with the surface of the sphere.
    float distance = (particle.position - sphere.center).length();
    if (distance <= sphere.radius) {
        // Calculate the normal vector to the surface of the sphere.
        QVector3D normal = (particle.position - sphere.center) / distance;

        // Calculate the impulse that needs to be applied to the particle.
        float impulse = 2.0f * (sphere.radius - distance) / particle.mass;
        //qDebug() << "impulse " << impulse;

        // Apply the impulse to the particle.
        particle.velocity += impulse * normal;

        return true;
    }

    return false;
}

// Create a pulsating function.
float pulsatingFunction(float time) {
    return  sin(time * 200.0f * M_PI);
}

bool collide_spheres(Sphere& sphere1, Sphere& sphere2) {
    // Calculate the distance between the centers of the spheres.
    float distance = (sphere1.center - sphere2.center).length();

    // If the distance is less than the sum of the radii, then the spheres are colliding.
    if (distance <= sphere1.radius + sphere2.radius) {
        return true;
    }

    return false;
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


void Metaball2d::Render()
{
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);

    QVector3D c0 = points[0];
    QVector3D c1 = points[1];

    points[0] = circularTrajectory(4, 1, t, phaze_corr);
    velocities[0] = (c0 - points[0]) / 0.0125;
    velocities[1] = (c1 - points[1]) / 0.0125;
    if(velocities[0].length() != 5 ) velocities[0] = QVector3D(4.59204, -1.97805, 0);

    // update radius
    radii[0] = 1 + 0.05*pulsatingFunction(t);

    points[1] = circularTrajectory(4, 8, 1 - t, M_PI);

    QVector3D min, max;
    findBoundaries(min, max);
    glColor3f(1,1,1);

    // check colisions
    Sphere s1, s2;
    s1.center = points[0];
    s1.radius = radii[0];
    s2.center = points[1];
    s2.radius = radii[1];


    shapesPrintf(7,1,"      time_reborn=%f t=%f frame_since_blast = %d!",sphere_blast.time_reborn,t, sphere_blast.frame_since_blast);
    shapesPrintf(8,1,"     frames_2endreverse=%d  frames_since_blast=%d ", sphere_blast.frames_2endreverse, sphere_blast.frames_since_blast);


    if( collide_spheres(s1, s2) )
    {
        sphere_blast.generateSphere(points[0], 30, radii[0]);
        glColor3f(1,1,1);
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
             //                                                         sphere_blast.frame_reborn);
            for(int i=0; i < sphere_blast.spherePoints.size(); i++)
            {
                particles[i].position = sphere_blast.spherePoints[i];
                particles[i].velocity = QVector3D(50-(float)100*dis(gen), 50-(float)100*dis(gen), 50-(float)100*dis(gen));
                particles[i].acceleration = QVector3D((float)5*dis(gen), (float)5*dis(gen), (float)5*dis(gen));
            }
        }
    }

    // correct phase ant the reverse end
    if( Nframe == sphere_blast.frames_2endreverse)
    {
        phaze_corr = M_PI/2;
        sphere_blast.blasted = false;
        glColor3f(1,1,0);
        glPushMatrix();
        glTranslatef(points[0].x(), points[0].y(), points[0].z());
        glutWireSphere(radii[0], 20, 20);
        glPopMatrix();

        for(int i=0; i < particles.size(); i++)
            particles[i].position = QVector3D(1000,1000,1000);

    }



     if( !sphere_blast.blasted )
     {
        glPushMatrix();
        glTranslatef(points[0].x(), points[0].y(), points[0].z());
        glutWireSphere(radii[0], 20, 20);
        glPopMatrix();
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
                particles[i] = p;
            }
        }

     }


        // draw spheres
        glColor3f(0,1,0);
        for(int i=1; i < 2; i++)
        {

            glPushMatrix();
            glTranslatef(points[i].x(), points[i].y(), points[i].z());
            glutWireSphere(radii[i], 20, 20);
            glPopMatrix();
        }


    // integrate particle coords
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    glPointSize(1);
    for (int i = 0; i < particles.size(); i++) {

        {
            Particle p = particles[i];
            Sphere sphere;
            sphere.center = points[1];
            sphere.radius = 5;
            collide(particles[i], sphere);
        }
        particles[i].position = integrateCoordinates(particles[i], delta_t);


        if(dis(gen)>0.7)
            glVertex3f( particles[i].position.x(), particles[i].position.y(), particles[i].position.z());

    }
    glEnd();

    //QThread::currentThread()->msleep(100);


    // save particles in history buffer
    if(sphere_blast.frames_since_blast < PARTICLES_HISTORY_SIZE)
    for(int i=0; i < sphere_blast.spherePoints.size(); i++)
        particles_copy[sphere_blast.frames_since_blast][i] = particles[i];

    findBoundaries(min, max);
    TrowRandomPointsInside(min, max);

    Nframe++;
    sphere_blast.frames_since_blast++;
    delta_t = 0.0166666666;
    t+=delta_t;
    delta_t = updateFPSLabel();
    if((Nframe % 100) == 0)
        // Create a spiral flow with speed 10 m/s.
        createSpiralFlow(particles, points[0].x(), points[0].y(), 0,
                         (float)dis(gen), 10*(float)dis(gen), 1.0f, 1000 * (float)dis(gen));


    if (( t > sphere_blast.time_reborn ) )
    {
        sphere_blast.blasted = false;
    }

}

#endif
