/**
    \file Main.cpp
*/

#include <iostream>

#include "Utilities.h"
#include "Camera.h"
#include "Controls.h"
#include "Lights.h"
#include "State.h"
#include "Geometry.h"
#include "RedCube.h"

Camera      camera;
Lights      lights;
State       state;
Controls    controls;

void display()
{

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    if(state.getPrintInfoOnScreen())
    {
        Utils::printInfoOnScreen();
    }
    camera.moveCamera();
    
    if(state.getDrawAxis())
    {
        Utils::drawAxis();
    }

    if(state.getLighting())
    {
        lights.renderLights();
    }

    if(state.getWireFrame())
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    display_redcube();

    glutSwapBuffers();
    Utils::printError();
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glClearColor(0.0,0.0,0.0,1.0);
    glClearDepth(1.0f);
    glShadeModel(GL_SMOOTH);    //Or GL_FLAT
}
void reshape(GLsizei width, GLsizei height)
{
    glViewport(0, 0, width, height);
    camera.changeWindowSize(width, height);
}

void idle()
{

}

void main(int argc, char **argv)
{
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitContextVersion(3,3);
#ifdef COMPATIBILITY_PROFILE
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
#else
    glutInitContextProfile(GLUT_CORE_PROFILE);
#endif
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(camera.getWindowWidth(), camera.getWindowHeight());
    int x = 0, y = 0;
    Utils::centerWindow(x,y);
    glutInitWindowPosition(x, y);
    glutCreateWindow(WINDOW_TITLE);

    // Initialize GLEW
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        cerr << "Error: " << glewGetErrorString(err) << endl;
        std::exit(EXIT_FAILURE);
    }
    if (!glewIsSupported("GL_VERSION_3_2"))
    {
        cerr << "Warning: OpenGL version 3.2 not supported with GLEW" << endl;
    }

    Utils::printStatus();

    init();
 
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    glutMouseFunc(Controls::mousePressHandler);
    glutMotionFunc(Controls::mouseMotionHandler);
    glutKeyboardFunc(Controls::keyboardHandler);
	glutSpecialFunc(Controls::specialKeyHandler);

    glutMainLoop();
}
