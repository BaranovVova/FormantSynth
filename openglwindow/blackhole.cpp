
#include "blackhole.h"
#include "particle_render.h"
#include "common.h"
#include <random>
#include <iostream>
#include <vector>
#include <ttmath/ttmath.h>
#include <QtMath>

using namespace std;

const double G = 6.6743015e-11; // Gravitational constant
const double c = 299792458; // Speed of light
const int NUM_PARTICLES = 1000;
void createSpiralFlow(std::vector<Particle>& particles, float centerX, float centerY, float centerZ, float radius, float velocity, float angularVelocity, int numParticles);

// Big<exponent, mantissa>
typedef ttmath::Big<TTMATH_BITS(64), TTMATH_BITS(128)> MyBig;


BlackHoleScene::BlackHoleScene(QOpenGLFunctions* f, int width, int height)
   : Scene(f, width, height)
{
    particles.resize(NUM_PARTICLES);
}

// This function calculates a point on a circle in polar coordinates.
// The function takes the radius of the circle and the angle of the point as input.
// The function returns the x- and y-coordinates of the point as a pair.
pair<double, double> pointOnCircle(double radius, double angle) {

    // Calculate the x-coordinate of the point.
    double x = radius * cos(angle);

    // Calculate the y-coordinate of the point.
    double y = radius * sin(angle);

    // Return the point as a pair.
    return make_pair(x, y);
}

void BlackHoleScene::init()
{
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    // Define the parameters of the black hole.
    double Msun = 1.989e30;
    double mass = Msun; // Mass of the black hole in solar masses
    r_s = (2 * G * mass) / (c*c); // Schwarzschild radius
    delta_t = 0.01;
    Nframe = 0;

    for(int i=0; i < NUM_PARTICLES; i++)
    {
        pair<double, double> xy;
        xy = pointOnCircle(r_s+(r_s*0.01)*dis(gen), qDegreesToRadians(i+0.02));
        QVector2D v(xy.first, xy.second);
        v.normalize();
        v = v * 1000;

        particles[i].x =  500*r_s + xy.first; //*(float)dis(gen);
        particles[i].y =  500*r_s + xy.second; //*(float)dis(gen);
        particles[i].vx = v.x()*(float)dis(gen);
        particles[i].vy = v.y()*(float)dis(gen);
        particles[i].ax = 0;
        particles[i].ay = 0;

    }

}



DParticle BlackHoleScene::integrate(DParticle p, float dt)
{


    // Define the parameters of the black hole.
    double Msun = 1.989e30;
    double mass = 1 * Msun; // Mass of the black hole in solar masses
    //double r_s = (2 * G * mass) / (c*c); // Schwarzschild radius

    // Define the time step and number of steps to simulate.
    //double dt = 0.01; // Time step



    // Calculate the acceleration of the particle.
    double a_x = (-G * mass) / ((pow(p.x*p.x + p.y*p.y,1.5)) * p.x);
    double a_y = (-G * mass) / ((pow(p.x*p.x + p.y*p.y,1.5)) * p.y);

    // Update the position and velocity of the particle.
    p.x+= p.vx * dt;
    p.y+= p.vy * dt;
    p.vx+= a_x * dt;
    p.vy+= a_y * dt;
    p.ax = a_x;
    p.ay = a_y;

    return p;
}

void BlackHoleScene::render()
{
    clrscr();
    const qreal retinaScale = 1;//devicePixelRatio();
    //f->glBindFramebuffer(GL_FRAMEBUFFER, 0);
    f->glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    f->glClear(GL_COLOR_BUFFER_BIT);

    auto prender = ParticleRender::getInstance();
    prender->m_program->bind();

    QMatrix4x4 matrix;
    matrix.perspective(60.0f, 1, 0.1f, 500.0f);
    matrix.translate(0, 0, -20);
    //matrix.rotate(100.0f * m_frame / screen()->refreshRate(), 0, 1, 0);

    prender->m_program->setUniformValue(prender->m_matrixUniform, matrix);
    prender->m_program->setUniformValue(prender->m_pipe, 0);
    for(int i=0; i < NUM_PARTICLES; i++)
    {
        DParticle p = particles[i];
        p = integrate(p, delta_t);
        //particles[i].velocity = p.velocity;
        particles[i] = p;
        Particle ps;
        //ps.position = QVector3D(p.x/(r_s*1000000000), p.y/(r_s*1000000000),0);
        ps.position = QVector3D((p.x-500*r_s)/(r_s), (p.y-500*r_s)/(r_s),0);
        prender->spawnParticle(ps, QVector3D(1,1,1));



    }

    for(int i=0; i < 10; i++)
    {
        DParticle p = particles[i];
        shapesPrintf(i,0,"pos = %f, %f delta_t = %f",(p.x-500*r_s)/(r_s), (p.y-500*r_s)/(r_s),delta_t);
    }


    //Render();
    prender->m_program->release();

    Nframe++;
    //delta_t = 0.0166666666;
    t+=delta_t;
    //delta_t = updateFPSLabel();
}

