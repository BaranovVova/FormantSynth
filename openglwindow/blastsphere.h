
#ifndef BLASTSPHERE_H
#define BLASTSPHERE_H

#include <QVector3D>
#include <vector>
#include <QOpenGLFunctions>

struct Sphere {
    QVector3D center;
    float radius;
};

class BlastSphere
{
public:
    BlastSphere();
    void generateSphere(QVector3D center, int resolution, float radius);
    void Render(QOpenGLFunctions* f, GLuint m_posAttr, GLuint m_colAttr, QVector3D col, QVector3D center);
    std::vector<QVector3D> spherePoints;
    int Resolution;
    float radius;
    bool blasted;
    bool reversingStarted;
    double time_reborn;
    int frame_2startreverse;
    int frames_2endreverse;
    int frame_reborn;
    int frame_since_blast;
    int frames_in_history;
    int frames_since_blast;

};

#endif // BLASTSPHERE_H
