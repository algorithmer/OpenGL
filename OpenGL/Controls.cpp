/**
    \file   Controls.cpp
    \brief  
*/

#include "Controls.h"
#include "Camera.h"
#include "State.h"
#include "Defines.h"
#include <GL/freeglut.h>
#include <math.h>       //for fmod()

extern Camera camera;
extern State state;
extern Controls controls;

void Controls::mousePressHandler(int button, int state, int x, int y) 
{
    if ((state == GLUT_DOWN) && (button == GLUT_LEFT_BUTTON))
    {
        controls.setLeftButton(true);
        controls.setOldx(x);
        controls.setOldy(y);
    }
    else if((state == GLUT_UP) && (button == GLUT_LEFT_BUTTON))
    {
        controls.setLeftButton(false);
    }

    else if((state == GLUT_DOWN) && (button == GLUT_RIGHT_BUTTON))
    {
        controls.setOldx(x);
        controls.setOldy(y);
        controls.setRightButton(true);
    }
    else if((state == GLUT_UP) && (button == GLUT_RIGHT_BUTTON))
    {
        controls.setRightButton(false);
    }

    glutPostRedisplay();
}

void Controls::mouseMotionHandler(int x, int y)
{
    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport );

    // Rotate Camera
    if(controls.getLeftButton() == true && controls.getRightButton() == false)
    {
        //We fmod it by 360 because it is easier to see that it rotated 360 degrees instead of 720 degrees.
        //camera.setRotatex( fmod(camera.getRotatex() + (y - controls.getOldy()), 360) );
        //camera.setRotatey( fmod(camera.getRotatey() + (x - controls.getOldx()), 360) ); 
		camera.pitch((y - controls.getOldy())/2.0f);
		camera.yaw((x - controls.getOldx())/2.0f);
    }
    // Translate Camera
    else if(controls.getLeftButton() == false && controls.getRightButton() == true)
    {
        //camera.setTranslatex( camera.getTranslatex() +  .1f * (x - controls.getOldx()) ); 
        //camera.setTranslatey( camera.getTranslatey() + -.1f * (y - controls.getOldy()) ); 
		camera.upd(-(y - controls.getOldy())/5.0f);
		camera.leftr(-(x - controls.getOldx())/5.0f);
    }
    // Scale Camera
    else if(controls.getLeftButton() == true && controls.getRightButton() == true)
    {
        camera.setScale( camera.getScale() + float(y-controls.getOldy())/viewport[3] ); 
    }

    controls.setOldy(y);
    controls.setOldx(x);

    glutPostRedisplay();
}

void Controls::specialKeyHandler(int key, int x, int y){
	switch(key){
		case GLUT_KEY_UP:
			//camera.setRotatex( camera.getRotatex() + 10);
			camera.forwardb(2.0f);
			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN:
			//camera.setRotatex( camera.getRotatex() - 10);
			camera.forwardb(-2.0f);
			glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT:
			//camera.setRotatey( camera.getRotatey() + 10);
			
			break;
		case GLUT_KEY_RIGHT:
			//camera.setRotatey( camera.getRotatey() - 10);
			camera.leftr(-2.0f);
			glutPostRedisplay();
			break;
	}
}

void Controls::keyboardHandler(unsigned char key, int x, int y)
{
    switch(key)
    {	
	case 'z':
			camera.setTranslatez( camera.getTranslatez() + -.8f );
			glutPostRedisplay();
			break;
	case 'x':
			camera.setTranslatez( camera.getTranslatez() + .8f);
			glutPostRedisplay();
			break;
    case 'i':   //Prints the top left information on the screen
        state.setPrintInfoOnScreen(!state.getPrintInfoOnScreen());
        glutPostRedisplay();
        break;
    case ESC_KEY:   //Exits the program
        exit(EXIT_SUCCESS);
        break;
    case 'l':   //Turns on/off lights
        state.setLighting(!state.getLighting());
        glutPostRedisplay();
        break;
    case 'n':   //Turns on/off axis
        state.setDrawAxis(!state.getDrawAxis());
        glutPostRedisplay();
        break;
    case 'w':
        camera.forwardb(2.0f);
		glutPostRedisplay();
        break;
    case 'a':
        camera.leftr(2.0f);
		glutPostRedisplay();
        break;
    case 's':
        camera.forwardb(-2.0f);
        glutPostRedisplay();
	    break;
    case 'd':
        camera.leftr(-2.0f);
        glutPostRedisplay();
        break;

   /* case 'd':
        state.setDrawLights(!state.getDrawLights());
        glutPostRedisplay();
        break;*/
    case 'r':   //Resets all transformations
        camera.position.x = 15.0f;
	    camera.position.y =45.0f;
	    camera.position.z = 90.0f;
	    camera.look.x = 0.0f;
	    camera.look.y = -0.2f;
	    camera.look.z = -1.0f;
        camera.look.normalize();
	    camera.up.x=0.0f;
	    camera.up.y=1.0f;
	    camera.up.z=0.0f;
        glutPostRedisplay();
        break;
    case 't':
        if(state.getTest() == 3) 
        { 
            state.setTest(0); 
        }
        else
        {
            state.setTest(state.getTest() + 1);
        }
        glutPostRedisplay();
        break;
    }
}