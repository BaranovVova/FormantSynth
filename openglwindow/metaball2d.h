
#ifndef METABALL2D_H
#define METABALL2D_H

#include <QVector3D>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <vector>



class Metaball2d : public QOpenGLFunctions
{
public:
    Metaball2d();
    void DrawBoundary(QVector3D min, QVector3D max);
    void setShaderProgram(QOpenGLShaderProgram* program)
    {
        myprogram = program;
    }
//    void init();
    void Render();
    QOpenGLShaderProgram* myprogram;
    GLint positionLocation;
};

#endif // METABALL2D_H
