
#ifndef CONE_H
#define CONE_H
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265
#define DEG2RAD (PI/180.0)

typedef struct {
    float x, y, z;
}Vector3f;

void DesenhaCone(const Vector3f *d, const Vector3f *a, const float h, const float rd, const int n);

#endif //CONE_H
