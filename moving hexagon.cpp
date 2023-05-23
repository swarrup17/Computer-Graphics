#include <GL/glut.h>
#include <cmath>

float centerX = 0.0; // Initial x-coordinate
float centerY = 0.0; // Initial y-coordinate
float velocityX = 5.5; // Velocity in the x-direction
float velocityY = 5.5; // Velocity in the y-direction

void draw()
{
    glClearColor(2, 2, 2, 2);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3d(3, 0, 0);
    
    const float PI = 3.14159;
    const int sides = 6;
    const float radius = 0.5;
    
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < sides; i++) {
        float angle = 2 * PI * i / sides;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    
    glFlush();
    
    // Update position based on velocity
    centerX += velocityX;
    centerY += velocityY;
    
    // Reverse direction if hexagon reaches the window boundaries
    if (centerX + radius >= 1.0 || centerX - radius <= 0.0) {
        velocityX = -velocityX;
    }
    if (centerY + radius >= 1.0 || centerY - radius <= 0.0) {
        velocityY = -velocityY;
    }
    
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(200, 200);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Moving Hexagon");
    glutDisplayFunc(draw);
    glutMainLoop();
    
    return 0;
}

