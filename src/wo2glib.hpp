#ifndef WO2GLIB_HH
#define WO2GLIB_HH

#include <GL/gl.h>
#include <GL/glut.h>

/*
 * initGLWindow(GLfloat width, GLfloat height, std::string name, uint switches)
 * 
 * a simpler syntax for initializing your window
 */
#define initGLWindow(width, height, name, switches) \
    glutInit(&argc, argv); \
    glutInitDisplayMode(switches); \
    glutInitWindowSize(width, height); \
    glutCreateWindow(name)

/*
 * POINTS -> glBegin(GL_POINTS)
 */
#define POINTS glBegin(GL_POINTS)
/*
 * POLYGON -> glBegin(GL_POLYGON)
 */
#define POLYGON glBegin(GL_POLYGON)
/*
 * LINES -> glBegin(GL_LINES)
 */
#define LINES glBegin(GL_LINES)

/*
 * fill(GLfloat r, GLfloat g, GLfloat b)
 * 
 * Fill the next Polygon with RGB values with A as an Alpha (RGB)
 */
#define fill(r, g, b) glColor3f(r, g, b)
/*
 * filla(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
 * 
 * Fill the next Polygon with RGB values with A as an Alpha (RGBA)
 */
#define filla(r, g, b, a) glColor4f(r, g, b, a)

/*
 * rect(GLfloat x, GLfloat y, GLfloat width, GLfloat height)
 * 
 * draw a rectangle which x, y is on top-left
 * with certain width and height
 */ 
#define rect(x, y, width, height) \
    POLYGON; \
        glVertex2f(x, y); glVertex2f(x + width, y); \
        glVertex2f(x + width, y + height); glVertex2f(x, y + height); \
    glEnd()

/*
 * line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat x2)
 * 
 * draw a single line, from (x1, y1) to (x2, y2)
 */ 
#define line(x1, y1, x2, y2) \
    LINES; \
        glVertex2f(x1, y1); glVertex2f(x2, y2); \
    glEnd()

/*
 * randint(int min, int max)
 * 
 * get a random single integer ranging from min, to max
 */
#define randint(min, max) std::rand() % max + min

#endif
