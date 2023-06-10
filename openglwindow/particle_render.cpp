
#include <QDebug>
#include "particle_render.h"

QOpenGLFunctions* fun;
ParticleRender* ParticleRender::instance;

ParticleRender::ParticleRender()
{
    instance = this;
}


void ParticleRender::init(QOpenGLFunctions* f, bool bCreate_framebuffer)
{
    fun = f;
    m_program = new QOpenGLShaderProgram();
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/openglwindow/vshader.glsl");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/openglwindow/fshader.glsl");
    m_program->link();
    qDebug() << m_program->log();
    m_posAttr = m_program->attributeLocation("posAttr");
    //Q_ASSERT(m_posAttr != -1);
    m_colAttr = m_program->attributeLocation("colAttr");
    //Q_ASSERT(m_colAttr != -1);
    m_textcoordAttr = m_program->attributeLocation("a_texcoord");
    m_matrixUniform = m_program->uniformLocation("matrix");
    //Q_ASSERT(m_matrixUniform != -1);
    m_pipe = m_program->uniformLocation("pipe");
    m_velocitiesAttr = m_program->attributeLocation("velocitiesAttr");

    //Q_ASSERT(m_pipe != -1);


    if(bCreate_framebuffer)
    {
        // Create a framebuffer object
        f->glGenFramebuffers(1, &framebuffer);
        f->glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);


        pixels = new uchar[TEXTURE_WIDTH * TEXTURE_HEIGHT * 4];
        for(int i=0; i < (TEXTURE_WIDTH * TEXTURE_HEIGHT * 4) ; i++ ) {
            pixels[i] = 0;
        }

        vel_pixels = new uchar[TEXTURE_WIDTH * TEXTURE_HEIGHT * 4];
        for(int i=0; i < (TEXTURE_WIDTH * TEXTURE_HEIGHT * 4) ; i++ ) {
            vel_pixels[i] = 0;
        }

        // Create a texture object
        f->glGenTextures(1, &texture);
        f->glBindTexture(GL_TEXTURE_2D, texture);
        f->glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
        f->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        f->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        f->glBindTexture(GL_TEXTURE_2D, 0);

        // Create a texture object
        f->glGenTextures(1, &vel_texture);
        f->glBindTexture(GL_TEXTURE_2D, vel_texture);
        f->glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
        f->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        f->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


        // Attach the texture to the framebuffer
        f->glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);
    }
}

void ParticleRender::spawnRect(QRectF rect, QVector3D col)
{
    QPointF p = rect.center();
    GLfloat vertices[] = {
        float(p.x()-rect.width()/2),  float(p.y()-rect.height()/2),
        float(p.x()-rect.width()/2), float(p.y()+rect.height()/2),
        float(p.x()+rect.width()/2), float(p.y()+rect.height()/2),
        float(p.x()+rect.width()/2), float(p.y()-rect.height()/2)
    };
    GLfloat colors[] = {
        col.x(), col.y(), col.z(),
        col.x(), col.y(), col.z(),
        col.x(), col.y(), col.z(),
        col.x(), col.y(), col.z()
    };


    fun->glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    fun->glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

    fun->glEnableVertexAttribArray(m_posAttr);
    fun->glEnableVertexAttribArray(m_colAttr);

    fun->glDrawArrays(GL_QUADS, 0, 4);

    fun->glDisableVertexAttribArray(m_colAttr);
    fun->glDisableVertexAttribArray(m_posAttr);
}

void ParticleRender::spawnParticle(Particle p, QVector3D col, float quad_size)
{
    float half_size = quad_size/2;
    GLfloat vertices[] = {
        p.position.x()-half_size,  p.position.y()-half_size,
        p.position.x()-half_size, p.position.y()+half_size,
        p.position.x()+half_size, p.position.y()+half_size,
        p.position.x()+half_size, p.position.y()-half_size
    };

    //QVector4D v_color = vel2color(p.velocity);
    float vx = p.velocity.x()/70;
    float vy = p.velocity.y()/70;
    GLfloat velocities[] = {
        vx,vy,
        vx,vy,
        vx,vy,
        vx,vy
    };

    GLfloat colors[] = {
        col.x(), col.y(), col.z(),
        col.x(), col.y(), col.z(),
        col.x(), col.y(), col.z()
    };


    fun->glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    fun->glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);
    fun->glVertexAttribPointer(m_velocitiesAttr, 2, GL_FLOAT, GL_FALSE, 0, velocities);

    fun->glEnableVertexAttribArray(m_posAttr);
    fun->glEnableVertexAttribArray(m_colAttr);
    fun->glEnableVertexAttribArray(m_velocitiesAttr);

    fun->glDrawArrays(GL_QUADS, 0, 4);

    fun->glDisableVertexAttribArray(m_colAttr);
    fun->glDisableVertexAttribArray(m_posAttr);
    fun->glDisableVertexAttribArray(m_velocitiesAttr);

    //compute statistics
    //stat.st

}

