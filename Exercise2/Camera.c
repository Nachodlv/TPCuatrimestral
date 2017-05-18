//
// Created by Gonzalo de Achaval on 18/5/17.
#include <stdlib.h>

#include "Camera.h"

Camera* newCamera(int megaPixels, int lcdScreen, int opticZoom, int type, int code){
    Camera* camera = malloc(sizeof(Camera));
    camera->megaPixels=megaPixels;
    camera->lcdScreen=lcdScreen;
    camera->opticZoom=opticZoom;
    camera->type=type;
    camera->code=code;
    return camera;
}

void freeCamera(Camera* camera){
    free(camera);
}