//
// Created by Ignacio on 30/5/2017.
//

#include "Admin.h"
#include <stdlib.h>
#include <memory.h>

Admin* newAdmin(char* name, int idCode){
    Admin* admin = malloc(sizeof(Admin));
    admin->name=malloc(sizeof(char)*strlen(name));
    admin->dni=idCode;
    strcpy(admin->name,name);
    return admin;
}

void freeAdmin(Admin* admin){
    free(admin->name);
    free(admin);
}