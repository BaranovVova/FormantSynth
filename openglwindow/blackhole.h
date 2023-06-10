
#ifndef BLACKHOLE_H
#define BLACKHOLE_H

#include "particle.h"
#include "particle_render.h"
#include "Scene.h"
#include <vector>
#include <QOpenGLFunctions>

struct DParticle
{
    double x,y,z;
    double vx,vy,vz;
    double ax,ay,az;

};

class BlackHoleScene : public Scene
{    
public:
    std::vector<DParticle> particles;
    BlackHoleScene(QOpenGLFunctions* f, int width, int height);
    void init();
    DParticle integrate(DParticle p, float dt);
    void render();
    double r_s;
};

#endif // BLACKHOLE_H
