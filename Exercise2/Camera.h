//
// Created by Gonzalo de Achaval on 18/5/17.
//

#ifndef TPCUATRIMESTRAL_CAMERA_H
#define TPCUATRIMESTRAL_CAMERA_H

#include "Accesory.h"
typedef struct camera Camera;
struct camera{
    int megaPixels;
    int lcdScreen;
    int opticZoom;
    int type;
    Accesory** accesoryArray;
    int maxCapacity;
    int code;
};
Camera* newCamera(int megaPixels, int lcdScreen, int opticZoom, int type, int code);
void addAccesory(Camera* camera,Accesory* accesory);
void freeCamera(Camera* camera);
#endif //TPCUATRIMESTRAL_CAMERA_H
