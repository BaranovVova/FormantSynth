#include "common2.h"
#include <random>

// dummy stub
void clrscr()
{

}

// dummy stub
void shapesPrintf (int row, int col, const char *fmt, ...)
{

}

QVector3D interpolateLine(QVector3D p1, QVector3D p2, float t) {
    // Calculate the vector between the points.
    QVector3D v = p2 - p1;

    // Calculate the interpolated point.
    return p1 + v * t;
}

float metaball(QVector3D point, std::vector<QVector3D> centers, std::vector<float> radii) {
    // Initialize the output value.
    float value = 0.0f;

    // Iterate over the metaballs.
    for (int i = 0; i < centers.size(); i++) {
        // Calculate the distance between the point and the current metaball center.
        float distance = (point - centers[i]).length();

        // Calculate the contribution of the current metaball to the output value.
        value += (1.0f / (distance * distance + radii[i] * radii[i]));
    }

    // Return the output value.
    return value;
}

const double PI = acos(-1.0);

void propagateWaves(std::vector<Particle>& particles, float width, float height, int numParticles, double frequency, double amplitude, double speed, double timeStep)
{
  // Initialize the output vector.
  // Loop over each point in the output vector.
  for (int i = 0; i < numParticles; i++) {
      // Calculate the distance from the point to the source.
      float x = particles[i].position.x();
      float y = particles[i].position.y();
      double distance = sqrt((x - width / 2) * (x - width / 2) + (y - height / 2) * (y - height / 2));
      // Calculate the wave amplitude at the point.
      double amplitudeAtPoint = amplitude * sin(2 * PI * frequency * timeStep * distance / speed);
      if(amplitudeAtPoint > -5 && amplitudeAtPoint < 5)
        particles[i].velocity*=amplitudeAtPoint;
      //particles[i].velocity.setZ(amplitudeAtPoint);
  }
}

QVector3D circularTrajectory(float radius, float frequency, float time, float phi0) {
    // Calculate the angle of the point.
    float angle = frequency * time;

    // Calculate the x and y coordinates of the point.
    float x = radius * cos(angle + phi0);
    float y = radius * sin(angle + phi0);

    // Return the point.
    return QVector3D(x, y, 0.0f);
}



void createSpiralFlow(std::vector<Particle>& particles, float centerX, float centerY, float centerZ, float radius, float velocity, float angularVelocity, int numParticles) {
    // Create a random number generator.
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create a vector to store the particles.
    std::uniform_real_distribution<> dis(0.0, 1.0);


    QVector3D r1(0,0,0), r2(radius,0,0);

    float Nturns = 20*dis(gen);

    // Generate the particles.
    for (int i = 0; i < numParticles; i++) {
        float radiusT = interpolateLine(r1,r2,(float)i/numParticles).x();
        //float radiusT = radius;
        // Generate a random x coordinate.
        float x = centerX + radiusT * std::cos(Nturns * M_PI * i / numParticles);

        // Generate a random y coordinate.
        float y = centerY + radiusT * std::sin(Nturns * M_PI * i / numParticles);

        // Generate a random z coordinate.
        float z = centerZ;

        // Generate a random velocity.
        float vx = radiusT*velocity * std::cos(Nturns * M_PI * i / numParticles);
        float vy = radiusT*velocity * std::sin(Nturns * M_PI * i / numParticles);
        float vz = (float)4*dis(gen);

        // Generate a random angular velocity.
        float wx = angularVelocity * std::cos(Nturns * M_PI * i / numParticles);
        float wy = angularVelocity * std::sin(Nturns * M_PI * i / numParticles);
        float wz = (float)6*dis(gen);

        // Add the particle to the vector.
        Particle p;
        p.position = QVector3D(x,y,z);
        p.velocity = QVector3D(vx,vy,vz);
        p.acceleration = QVector3D(wx,wy,wz);
        p.mass = 1.4 * 1./radiusT;
        particles[i] = p;
    }

    const float dt = 0.0125f;
    // Set the velocity of the particles to spiral outwards.
    for (int i = 0; i < particles.size(); i++) {
        particles[i].velocity.setX( particles[i].velocity.x() + particles[i].acceleration.x() * dt );
        particles[i].velocity.setY( particles[i].velocity.y() + particles[i].acceleration.y() * dt );
        particles[i].velocity.setZ( particles[i].velocity.z() + particles[i].acceleration.z() * dt );
    }
}

QVector3D integrateCoordinates(Particle particle, float dt) {
    // Update the position of the particle.
    particle.position += particle.velocity * dt;

    // Update the velocity of the particle.
    particle.velocity += particle.acceleration * dt;

    // Return the new position of the particle.
    return particle.position;
}

bool collide(Particle& particle, Sphere sphere) {

    // Check if the particle is colliding with the surface of the sphere.
    float distance = (particle.position - sphere.center).length();
    if (distance <= sphere.radius) {
        // Calculate the normal vector to the surface of the sphere.
        QVector3D normal = (particle.position - sphere.center) / distance;

        // Calculate the impulse that needs to be applied to the particle.
        float impulse = 2.0f * (sphere.radius - distance) / particle.mass;
        //qDebug() << "impulse " << impulse;

        // Apply the impulse to the particle.
        particle.velocity += impulse * normal;

        return true;
    }

    return false;
}

// Create a pulsating function.
float pulsatingFunction(float time) {
    return  sin(time * 200.0f * M_PI);
}

bool collide_spheres(Sphere& sphere1, Sphere& sphere2) {
    // Calculate the distance between the centers of the spheres.
    float distance = (sphere1.center - sphere2.center).length();

    // If the distance is less than the sum of the radii, then the spheres are colliding.
    if (distance <= sphere1.radius + sphere2.radius) {
        return true;
    }

    return false;
}
