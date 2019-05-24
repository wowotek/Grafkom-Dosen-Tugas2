#include <iostream>
#include "wo2glib.hpp"

GLfloat r = 0, g = 0, b = 0;

void myInit(void);
void renderDisplay(void);
void changeColorSubRoutine(int);

int main(int argc, char ** argv){
    initGLWindow(400, 400, "BelajarOpenGL-672017282", GLUT_DOUBLE | GLUT_RGB);

    glutDisplayFunc(renderDisplay);
    changeColorSubRoutine(1000/120);

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(10.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
    
    glutMainLoop();

	return 0;
}

void renderDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);

    fill(r/100, g/100, b/100);
    rect(0, 0, 1, 1);
    
    glutSwapBuffers();
}

#define       PINK {100,  41,  71}
#define  BIRU_MUDA {  0, 100, 100}
#define HIJAU_MUDA { 60,  98,  60}

#define ALL_COLOR_STATUS (gradientStatus[0] && \
                          gradientStatus[1] && \
                          gradientStatus[2])
#define GRADIENT_SPEED 1

GLint targetColor[3][3] = {PINK, BIRU_MUDA, HIJAU_MUDA};
GLint colorTracker = 0;
GLint delayTime = 0;
GLboolean gradientStatus[] = {false, false, false};
void changeColorSubRoutine(int ms){
    if(r < targetColor[colorTracker][0]){
        r += GRADIENT_SPEED;
        gradientStatus[0] = false;
    } else if(r > targetColor[colorTracker][0]) {
        r -= GRADIENT_SPEED;
        gradientStatus[0] = false;
    } else {
        gradientStatus[0] = true;
    }

    if(g < targetColor[colorTracker][1]){
        g += GRADIENT_SPEED;
        gradientStatus[1] = false;
    } else if(g > targetColor[colorTracker][1]) {
        g -= GRADIENT_SPEED;
        gradientStatus[1] = false;
    } else {
        gradientStatus[1] = true;
    }

    if(b < targetColor[colorTracker][2]){
        b += GRADIENT_SPEED;
        gradientStatus[2] = false;
    } else if(b > targetColor[colorTracker][2]) {
        b -= GRADIENT_SPEED;
        gradientStatus[2] = false;
    } else {
        gradientStatus[2] = true;
    }

    if (ALL_COLOR_STATUS && delayTime < 120){
        delayTime++;
    } else if (ALL_COLOR_STATUS && delayTime >= 120) {
        colorTracker++; 
        if(colorTracker >= 3){
            colorTracker = 0;
        }
        delayTime = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(ms, changeColorSubRoutine, ms);
}

