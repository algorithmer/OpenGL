#include "SimpleSquareTexture.h"
#include "Texture.h"
#include "State.h"
/*
extern GLuint  simpleID;
extern Texture texWater;
extern State    state;

void display_simplesquaretexture()
{
    
    glBindTexture(GL_TEXTURE_2D, texWater.getId());

    glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0); glVertex2f(-10.0, -10.0);
        glTexCoord2f(1.0, 0.0); glVertex2f(10.0, -10.0);
        glTexCoord2f(1.0, 1.0); glVertex2f(10.0, 10.0);
        glTexCoord2f(0.0, 1.0); glVertex2f(-10.0, 10.0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0); //Make sure you bind it to 0, or else drawAxis might not color correctly if you decide to turn it on
}

void init_simplesquaretexture()
{
    state.setWireFrame(false);
    state.setLighting(true);
    state.setDrawLights(true);
    state.setDrawAxis(false);
    state.setPrintInfoOnScreen(true);

    texWater.loadTexture(RESOURCE_DIR "water.jpg");

    glEnable(GL_TEXTURE_2D);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); //instead of GL_MODULATE, we do GL_REPLACE so that it won't multiply
    glGenTextures(1, texWater.setId());                             //the texture color with the primitive color.
    glBindTexture(GL_TEXTURE_2D, texWater.getId());
    glTexImage2D(GL_TEXTURE_2D, 0, texWater.getFormat(), texWater.getWidth(), texWater.getHeight(), 0, texWater.getFormat(), GL_UNSIGNED_BYTE, texWater.getData());
    texWater.destroyTexture();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
    glBindTexture(GL_TEXTURE_2D, 0);
}*/