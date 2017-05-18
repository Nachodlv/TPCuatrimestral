//
// Created by Gonzalo de Achaval on 18/5/17.
#include <stdlib.h>

#include "Camera.h"

Camera* newCamera(int megaPixels, int lcdScreen, int opticZoom, int type, Accesory* accesory, int code){
    Camera* camera = malloc(sizeof(Camera));
    camera->accesory=malloc(sizeof(Accesory));
    camera->accesory = newAccesory(accesory->accesoryType,accesory->comment,accesory->code);
    camera->megaPixels=megaPixels;
    camera->lcdScreen=lcdScreen;
    camera->opticZoom=opticZoom;
    camera->type=type;
    camera->code=code;
    return camera;
}

void freeCamera(Camera* camera){
    freeAccesory(camera->accesory);
    free(camera);
}