
#ifndef COMMON2_H
#define COMMON2_H

#include <vector>
#include <QVector3D>
#include "blastsphere.h"
#include "particle.h"

void findBoundaries(QVector3D& minBoundary, QVector3D& maxBoundary);
QVector3D circularTrajectory(float radius, float frequency, float time, float phi0=0);
double updateFPSLabel();
void shapesPrintf (int row, int col, const char *fmt, ...);
float pulsatingFunction(float time);
bool collide_spheres(Sphere& sphere1, Sphere& sphere2);
QVector3D integrateCoordinates(Particle particle, float dt);
bool collide(Particle& particle, Sphere sphere);
float metaball(QVector3D point, std::vector<QVector3D> centers, std::vector<float> radii);
void clrscr();
void propagateWaves(std::vector<Particle>& particles, float width, float height, int numParticles, double frequency, double amplitude, double speed, double timeStep);

class common
{
public:
    common();
};

#endif // COMMON2_H
