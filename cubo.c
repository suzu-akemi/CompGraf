#include "cubo.h"

void DesenhaCubo() {

    glColor3f(1, 0, 1);
    glLineWidth(1);
    glutSolidCube(1);
    glLineWidth(1);
    glColor3f(1, 1, 1);
    glutWireCube(1);
}