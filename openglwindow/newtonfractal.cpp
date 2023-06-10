#include "newtonfractal.h"
#include <iostream>
#include <vector>
#include <complex>
#include "openglwindow/particle_render.h"
#include <QOpenGLFunctions>
using namespace std;

const double EPS = 1e-10;
vector<vector<int>> image(600, vector<int>(400));

complex<double> Sin(complex<double> z) {
  complex<double> m;
  //z.imag()
  m = complex<double>(sin(z.real()) * cosh(z.imag()) , cos(z.real()) * sinh(z.imag()));
  return m;
}

void draw_newton_fractal(const complex<double>& c, int max_iterations, vector<vector<int>>& image)
{
  for (int i = 0; i < image.size(); i++) {
    for (int j = 0; j < image[i].size(); j++) {
      complex<double> z = complex<double>((float)i/60, (float)j/40);
      int iterations = 0;
      while (abs(z - c) > EPS && iterations < max_iterations) {
        //z = z - (z * z * z * Sin(z) - complex<double>(1, 0)) / (complex<double>(3, 0) * z * z);
         z = z - (z * z - c) / (complex<double>(2, 0) * z);
        iterations++;
      }
      image[i][j] = iterations;
    }
  }
}



void update_fractal() {
  // Draw the fractal
  auto prender = ParticleRender::getInstance();
  draw_newton_fractal(complex<double>(-0.5, 0.5), 100, image);

  for (int i = 0; i < image.size(); i++) {
    for (int j = 0; j < image[i].size(); j++) {

      QVector3D col(image[i][j] / 255.0, image[i][j] / 255.0, image[i][j] / 255.0);
      Particle p;
      p.position = QVector3D((float)i/60, (float)j/40,0);
      p.velocity = QVector3D(1,1,1);
      prender->spawnParticle(p, col);
    }
  }

}
