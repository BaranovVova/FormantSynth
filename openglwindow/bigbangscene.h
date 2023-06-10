
#ifndef BIGBANGSCENE_H
#define BIGBANGSCENE_H

#include "scene.h"
#include "happybirsday.h"
#include "particle_render.h"
#include <QOpenGLFunctions>
#include <vector>

class BigBangScene : public Scene
{

public:
    BigBangScene(QOpenGLFunctions* f, int width, int height)
        : Scene(f, width, height)
    {

    }
    void init();
    void render();
    void Render(bool doTimeStep);
    void TrowRandomPointsInside(QVector3D minBoundary, QVector3D maxBoundary);
    void TrowRandomPointsInsideRect(QRectF rect);

    ParticleRender* prender;

    void NotePlaySlot(std::vector<Notestruct>* song, Notestruct note);

};

#endif // BIGBANGSCENE_H
