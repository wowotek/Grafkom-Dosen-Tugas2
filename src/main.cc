#include <iostream>
#include "wo2glib.hh"

#define       PINK 1
#define  BIRU_MUDA 2
#define HIJAU_MUDA 3

GLfloat r = 0, g = 0, b = 0;
void myInit(void);
void renderDisplay(void);
void changeColor(void);

int main(int argc, char ** argv){
    initGLWindow(768, 768,
        "BelajarOpenGL-672017282",
        GLUT_DOUBLE | GLUT_RGB);

    glutDisplayFunc(renderDisplay);
    glutIdleFunc(changeColor);

    myInit();
    glutMainLoop();

	return 0;
}

void myInit(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(10.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);   
}

void renderDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);

    fill(r, g, b);
    rect(0, 0, 1, 1);
    
    glutSwapBuffers();
}

void changeColor(void){
    if(glutGet(GLUT_ELAPSED_TIME) % 1000 == 0){
        std::cout << "SECOND" << std::endl;
    }
}

void _changeColor(GLint theColor){
    switch(theColor){
        case 1: // PINK
            r = 1.00; g = 0.41; b = 0.71;
            break;
        case 2: // BIRU_MUDA
            r = 0.00; g = 1.00; b = 1.00;
            break;
        case 3: // HIJAU_MUDA
            r = 0.60; g = 0.98; b = 0.60;
            break;
        default: break;
    }
}

