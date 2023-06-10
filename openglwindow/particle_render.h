
#ifndef PARTICLE_RENDER_H
#define PARTICLE_RENDER_H

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include "particle.h"

class ParticleRender
{
public:
    ParticleRender();
    static ParticleRender* getInstance()
    {
        return instance;
    }
    void init(QOpenGLFunctions* f, bool bCreate_framebuffer=true);
    void spawnParticle(Particle p, QVector3D col, float quad_size=0.1);
    void spawnRect(QRectF rect, QVector3D col);
    static ParticleRender* instance;
    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_textcoordAttr = 0;
    GLint m_matrixUniform = 0;
    GLint m_pipe = 0;
    GLint m_velocitiesAttr = 0;
    GLuint framebuffer;
    GLuint texture, vel_texture;
    uchar *pixels;
    uchar *vel_pixels;
    const int TEXTURE_WIDTH = 1076;
    const int TEXTURE_HEIGHT = 486;

    QOpenGLShaderProgram* m_program;
};

#endif // PARTICLE_RENDER_H
