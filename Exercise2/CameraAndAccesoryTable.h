//
// Created by Oscar on 18/05/2017.
//

#ifndef TPCUATRIMESTRAL_CAMERAANDACCESORYTABLE_H
#define TPCUATRIMESTRAL_CAMERAANDACCESORYTABLE_H

#include "Camera.h"
#include "Accesory.h"
typedef struct cameraAndAccesoryTable CameraAndAccesoryTable;
struct cameraAndAccesoryTable{
    Camera** cameraArray;
    Accesory** accesoryArray;
    int cameraQuantity;
    int accesoryquantity;
    int cameraArrayMaxCapacity;
    int accesoryArrayMaxCapacity;
};
CameraAndAccesoryTable* newCameraAndAccesoryTable();
void freeCameraAndAccesoryTable(CameraAndAccesoryTable* cameraAndAccesoryTable);
void addCameraToTable(CameraAndAccesoryTable* cameraAndAccesoryTable,Camera* camera);
void addAccesoryToTable(CameraAndAccesoryTable* cameraAndAccesoryTable,Accesory* accesory);
int isCamera(CameraAndAccesoryTable* cameraAndAccesoryTable,int code);
int isAccesory(CameraAndAccesoryTable* cameraAndAccesoryTable,int code);
Camera* getCamera(CameraAndAccesoryTable* cameraAndAccesoryTable, int code);
Accesory* getAccesory(CameraAndAccesoryTable* cameraAndAccesoryTable,int code);

#endif //TPCUATRIMESTRAL_CAMERAANDACCESORYTABLE_H
