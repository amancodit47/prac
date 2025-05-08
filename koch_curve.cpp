#include <GL/glut.h>
#include <cmath>

void drawKoch(float x1, float y1, float x2, float y2, int iter) {
    if (iter == 0) {
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
        return;
    }

    float dx = (x2 - x1) / 3;
    float dy = (y2 - y1) / 3;

    float xA = x1 + dx;
    float yA = y1 + dy;

    float xB = x1 + 2 * dx;
    float yB = y1 + 2 * dy;

    float xC = (x1 + x2) / 2 - sqrt(3.0) * (y1 - y2) / 6;
    float yC = (y1 + y2) / 2 - sqrt(3.0) * (x2 - x1) / 6;

    drawKoch(x1, y1, xA, yA, iter - 1);
    drawKoch(xA, yA, xC, yC, iter - 1);
    drawKoch(xC, yC, xB, yB, iter - 1);
    drawKoch(xB, yB, x2, y2, iter - 1);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    drawKoch(100, 300, 500, 300, 4);

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0);
    gluOrtho2D(0.0, 600.0, 0.0, 480.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 480);
    glutCreateWindow("Koch Curve Fractal");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
