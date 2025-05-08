#include <GL/glut.h>
#include <cmath>

float xpos = 50.0;
int direction = 1;

void drawCircle(float cx, float cy, float r, int num_segments = 100) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0 * 3.1415926 * float(i) / float(num_segments);
        float dx = r * cosf(theta);
        float dy = r * sinf(theta);
        glVertex2f(cx + dx, cy + dy);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2f, 0.7f, 1.0f);
    drawCircle(xpos, 240, 30);

    glFlush();
}

void update(int value) {
    xpos += direction * 5;

    // reverse direction at borders
    if (xpos > 570 || xpos < 30)
        direction *= -1;

    glutPostRedisplay();
    glutTimerFunc(30, update, 0); // call update again after 30ms
}

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 480);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(600, 480);
    glutCreateWindow("Object Animation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0); // start animation
    glutMainLoop();
    return 0;
}
