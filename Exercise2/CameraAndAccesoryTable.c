//
// Created by Oscar on 18/05/2017.
//
#include <stdlib.h>
#include <memory.h>
#include "CameraAndAccesoryTable.h"

CameraAndAccesoryTable* newCameraAndAccesoryTable(){
    CameraAndAccesoryTable* cameraAndAccesoryTable = malloc(sizeof(CameraAndAccesoryTable));
    cameraAndAccesoryTable->accesoryArrayMaxCapacity=10;
    cameraAndAccesoryTable->cameraArrayMaxCapacity=10;
    cameraAndAccesoryTable->accesoryArray=malloc(sizeof(Accesory)*10);
    cameraAndAccesoryTable->cameraArray=malloc(sizeof(Camera)*10);
    cameraAndAccesoryTable->cameraQuantity=0;
    cameraAndAccesoryTable->accesoryquantity=0;
    return cameraAndAccesoryTable;
}

void freeCameraAndAccesoryTable(CameraAndAccesoryTable* cameraAndAccesoryTable){
    for(int i=0;i<cameraAndAccesoryTable->accesoryArrayMaxCapacity;i++){
        freeAccesory(cameraAndAccesoryTable->accesoryArray[i]);
    }
    for(int i=0;i<cameraAndAccesoryTable->cameraArrayMaxCapacity;i++){
        freeCamera(cameraAndAccesoryTable->cameraArray[i]);
    }
    free(cameraAndAccesoryTable);
}

void growAccesoryArray(CameraAndAccesoryTable* cameraAndAccesoryTable){
    cameraAndAccesoryTable->accesoryArray=realloc(cameraAndAccesoryTable->accesoryArray, sizeof(Accesory)*cameraAndAccesoryTable->accesoryArrayMaxCapacity*2);
    cameraAndAccesoryTable->accesoryArrayMaxCapacity = cameraAndAccesoryTable->accesoryArrayMaxCapacity*2;
}

void growCameraArray(CameraAndAccesoryTable* cameraAndAccesoryTable){
    cameraAndAccesoryTable->cameraArray=realloc(cameraAndAccesoryTable->cameraArray, sizeof(Camera)*cameraAndAccesoryTable->cameraArrayMaxCapacity*2);
    cameraAndAccesoryTable->cameraArrayMaxCapacity = cameraAndAccesoryTable->cameraArrayMaxCapacity*2;
}

void addAccesoryToTable(CameraAndAccesoryTable* cameraAndAccesoryTable,Accesory* accesory){
    if(cameraAndAccesoryTable->accesoryArrayMaxCapacity==cameraAndAccesoryTable->accesoryquantity){
        growAccesoryArray(cameraAndAccesoryTable);
    }
    cameraAndAccesoryTable->accesoryArray[cameraAndAccesoryTable->accesoryquantity] = newAccesory(accesory->accesoryType,accesory->comment,accesory->code);
    cameraAndAccesoryTable->accesoryquantity++;
}

void addCameraToTable(CameraAndAccesoryTable* cameraAndAccesoryTable,Camera* camera){
    if(cameraAndAccesoryTable->cameraArrayMaxCapacity==cameraAndAccesoryTable->cameraQuantity){
        growCameraArray(cameraAndAccesoryTable);
    }
    cameraAndAccesoryTable->cameraArray[cameraAndAccesoryTable->cameraQuantity] = newCamera(camera->megaPixels,camera->lcdScreen,camera->opticZoom,camera->type,camera->code);
    cameraAndAccesoryTable->cameraQuantity++;
}

int isCamera(CameraAndAccesoryTable* cameraAndAccesoryTable,int code){
    for(int i=0;i<cameraAndAccesoryTable->cameraQuantity;i++){
        if(cameraAndAccesoryTable->cameraArray[i]->code==code) return 1;
    }
    return 0;
}

int isAccesory(CameraAndAccesoryTable* cameraAndAccesoryTable,int code){
    for(int i=0;i<cameraAndAccesoryTable->accesoryquantity;i++){
        if(cameraAndAccesoryTable->accesoryArray[i]->code==code) return 1;
    }
    return 0;
}

Camera* getCamera(CameraAndAccesoryTable* cameraAndAccesoryTable, int code){
    for(int i=0;i<cameraAndAccesoryTable->cameraQuantity;i++){
        if(cameraAndAccesoryTable->cameraArray[i]->code==code) return cameraAndAccesoryTable->cameraArray[i];
    }
    exit(2);
}

Accesory* getAccesory(CameraAndAccesoryTable* cameraAndAccesoryTable,int code){
    for(int i=0;i<cameraAndAccesoryTable->accesoryquantity;i++){
            if(cameraAndAccesoryTable->accesoryArray[i]->code==code) return cameraAndAccesoryTable->accesoryArray[i];
    }
    exit(2);
}