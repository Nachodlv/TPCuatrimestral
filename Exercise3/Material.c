//
// Created by Ignacio on 19/5/2017.
//

#include "Material.h"
#include <stdlib.h>
#include <memory.h>
Material* newBook(int code, char* author, char* title, int year, char* editorial){
    Material* material = malloc(sizeof(Material));
    material->materialType=1;
    material->code=code;
    material->author=malloc(sizeof(char)*(strlen(author)+1));
    material->title=malloc(sizeof(char)*(strlen(title)+1));
    material->year=year;
    material->editorial=malloc(sizeof(char)*(strlen(editorial)+1));
    strcpy(material->author,author);
    strcpy(material->title,title);
    strcpy(material->editorial,editorial);
    return material;
}

Material* newMagazine(int code, char* title, int year, char* editorial){
    Material* material = malloc(sizeof(Material));
    material->materialType=2;
    material->code=code;
    material->title=malloc(sizeof(char)*(strlen(title)+1));
    material->year=year;
    material->editorial=malloc(sizeof(char)*(strlen(editorial)+1));
    strcpy(material->title,title);
    strcpy(material->editorial,editorial);
    return material;
}

void enlistMaterial(Material* material){
    material->status=malloc(sizeof(char)*(strlen("Disponible")+1));
    strcpy(material->status,"Disponible");
}

void takeOutMaterial(Material* material){
    material->status=realloc(material->status,sizeof(char)*(strlen("No disponible")+1));
    strcpy(material->status,"No disponible");
}

void freeMaterial(Material* material){
    free(material->title);
    free(material->editorial);
    if(material->materialType==1) free(material->author);
    free(material);
}


