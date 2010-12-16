/**
    \file   Defines.h
    \brief  
*/

#ifndef _DEFINES_H
#define _DEFINES_H

#include <windows.h>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <iostream>
using namespace std;

#define DEBUG_MESSAGES
#define  EPSILON .00001           ///< For use when comparing floats.

//#define CORE_PROFILE
#define COMPATIBILITY_PROFILE

#if defined (CORE_PROFILE) && defined (COMPATIBILITY_PROFILE)
#error Cannot define both CORE and COMPATIBILITY profiles.
#endif

//#define USING_GLUT
#define USING_FREEGLUT

#if defined (USING_GLUT) && defined (USING_FREEGLUT)
#error Cannot define both USING_GLUT and USING_FREEGLUT.
#endif

#define RESOURCE_DIR "..\\Resources\\"
#define WINDOW_TITLE "Continuous Model Synthesis"
#define WINDOW_WIDTH  700
#define WINDOW_HEIGHT 700

#define X 0
#define Y 1
#define Z 2
#define W 3

#define CONSTANT_ATTENUATION  0
#define LINEAR_ATTENUATION    1
#define QUADRATIC_ATTENUATION 2

#define ESC_KEY 27

#endif // _DEFINES_H