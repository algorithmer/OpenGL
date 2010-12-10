#include "RedCube.h"
#include "Lights.h"
#include "State.h"

extern Lights lights;
extern State state;

void display_redcube()
{

    
    glColor3f(1.0f, 0.0f, 0.0f);

    GLfloat size = 10.0f;
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-size, size, -size);     //top
        glVertex3f( size, size, -size);
        glVertex3f( size,  size, size);
        glVertex3f(-size,  size, size);

        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(size, size, size);       //right
        glVertex3f(size, size, -size);
        glVertex3f(size, -size,-size);
        glVertex3f(size, -size, size);

        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(-size, size, -size);     //far
        glVertex3f( size, size, -size);
        glVertex3f( size, -size,-size);
        glVertex3f(-size,  -size, -size);

        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-size, size, size);      //front
        glVertex3f( size, size, size);
        glVertex3f( size, -size, size);
        glVertex3f(-size, -size, size);

        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(-size, size, -size);     //left
        glVertex3f(-size,  size, size);
        glVertex3f(-size, -size, size);
        glVertex3f(-size, -size, -size);

        glNormal3f(0.0f,-1.0f, 0.0f);
        glVertex3f(-size, -size, size);     //bottom
        glVertex3f( size,  -size, size);
        glVertex3f(size,  -size, -size);
        glVertex3f(-size,  -size, -size);
    glEnd();
}

void init_redcube()
{
   
   
   state.setWireFrame(false);
   state.setLighting(true);
   state.setDrawLights(true);
   state.setDrawAxis(false);
   state.setPrintInfoOnScreen(true);

   lights.addLight( 15.0,15.0,0.0, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
   lights.addLight(-20.0,5.0, 0.0, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
}