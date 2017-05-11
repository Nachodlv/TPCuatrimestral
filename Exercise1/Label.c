//
// Created by Ignacio on 10/5/2017.
//

#include <malloc.h>
#include <mem.h>
#include "Label.h"
Label* newLabel(char* id, char* name){
    Label* label = malloc(sizeof(label));
    label->id=malloc(sizeof(strlen(id)));
    label->name=malloc(sizeof(strlen(name)));

    strcpy(label->id,id);
    strcpy(label->name,name);
    return label;
}

void freeLabel(Label* label){
    free(label->id);
    free(label->name);
    free(label);
}
