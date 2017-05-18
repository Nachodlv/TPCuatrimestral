//
// Created by Gonzalo de Achaval on 18/5/17.
#include <stdlib.h>

#include "Camera.h"

Camera* newCamera(int megaPixels, int lcdScreen, int opticZoom, int type, int code){
    Camera* camera = malloc(sizeof(Camera));
    camera->quantityOfAccesories=0;
    camera->maxCapacity=5;
    camera->accesoryArray = malloc(sizeof(Accesory)*5);
    camera->megaPixels=megaPixels;
    camera->lcdScreen=lcdScreen;
    camera->opticZoom=opticZoom;
    camera->type=type;
    camera->code=code;
    return camera;
}

void freeCamera(Camera* camera){
    for(int i=0;i<camera->maxCapacity;i++){
        freeAccesory(camera->accesoryArray[i]);
    }
    free(camera->accesoryArray);
    free(camera);
}

void addAccesoryToCamera(Camera* camera,Accesory* accesory){
    if(camera->quantityOfAccesories==camera->maxCapacity){
        exit(2);
    }else{
        camera->accesoryArray[camera->quantityOfAccesories]=newAccesory(accesory->accesoryType,accesory->comment,accesory->code);
        camera->quantityOfAccesories++;
    }
}
