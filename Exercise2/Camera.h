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
    Accesory* accesory;
    int code;
};
Camera* newCamera(int megaPixels, int lcdScreen, int opticZoom, int type, Accesory* accesory, int code);
void freeCamera(Camera* camera);
#endif //TPCUATRIMESTRAL_CAMERA_H
