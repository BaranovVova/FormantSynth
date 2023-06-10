#include <QVector3D>
#include <math.h>
#include "blastsphere.h"
//#include "GL/freeglut.h"

BlastSphere::BlastSphere()
{
    blasted = false;
}

// This function generates a sphere with radius 1.
void BlastSphere::generateSphere(QVector3D center, int resolution, float radius) {
    // Create a vector to store the vertices of the sphere.
    Resolution = resolution;
    spherePoints.resize(resolution*resolution);
    // Loop over all vertices.
    for (int i = 0; i < resolution; i++) {
        for (int j = 0; j < resolution; j++) {
            // Calculate the latitude and longitude of the current vertex.
            double latitude = M_PI * (i + 0.5) / resolution;
            double longitude = 2 * M_PI * j / resolution;

            // Calculate the position of the current vertex on the sphere.
            spherePoints[i * resolution + j].setX(  center.x() + radius * cos(latitude) * cos(longitude ) );
            spherePoints[i * resolution + j].setY(  center.y() + radius * sin(latitude) * cos(longitude ) );
            spherePoints[i * resolution + j].setZ(  center.z() + radius * sin(longitude));
        }
    }



    // Return the vertices of the sphere.
}



void BlastSphere::Render(QOpenGLFunctions* f, GLuint m_posAttr, GLuint m_colAttr, QVector3D col, QVector3D center)
{
    // Draw the sphere.


    GLfloat colors[] = {
        col.x(), col.y(), col.z(),
        col.x(), col.y(), col.z(),
        col.x(), col.y(), col.z()
    };
    GLfloat vertices[] = {
        0,0,0,
        0,0,0,
        0,0,0
    };


    f->glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    f->glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);
    f->glEnableVertexAttribArray(m_posAttr);
    f->glEnableVertexAttribArray(m_colAttr);

    for (int i = 0; i < spherePoints.size() - 1; i++) {

        vertices[0] =  spherePoints[i].x();
        vertices[1] =  spherePoints[i].y();
        vertices[2] =  spherePoints[i].z();
        vertices[3] =  spherePoints[i + 1].x();
        vertices[4] =  spherePoints[i + 1].y();
        vertices[5] =  spherePoints[i + 1].z();
        vertices[6] =  spherePoints[i + Resolution].x();
        vertices[7] =  spherePoints[i + Resolution].y();
        vertices[8] =  spherePoints[i + Resolution].z();

        f->glDrawArrays(GL_POINTS, 0, 3);

    }

    f->glDisableVertexAttribArray(m_colAttr);
    f->glDisableVertexAttribArray(m_posAttr);

}


