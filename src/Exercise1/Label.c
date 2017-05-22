//
// Created by Ignacio on 10/5/2017.
//


#include <stdlib.h>
#include <memory.h>
#include "Label.h"
Label* newLabel(char* id, char* name){
    Label* label = malloc(sizeof(Label));
    label->id=malloc(sizeof(char)*(strlen(id)+1));
    label->name=malloc(sizeof(char)*(strlen(name)+1));

    strcpy(label->id,id);
    strcpy(label->name,name);
    return label;
}

void freeLabel(Label* label){
    free(label->id);
    free(label->name);
    free(label);
}
