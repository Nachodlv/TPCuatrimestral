//
// Created by Ignacio on 30/5/2017.
//

#include "Id.h"
#include <stdlib.h>
Id* newId(int numberId){
    Id* id = malloc(sizeof(Id));
    id->numberId=numberId;
    return id;
}

void freeId(Id* id){
    free(id);
}