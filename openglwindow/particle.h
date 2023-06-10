
#ifndef PARTICLE_H
#define PARTICLE_H
#include <QVector3D>
#include <vector>
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
    std::vector<Particle> history;
};

#endif // PARTICLE_H
