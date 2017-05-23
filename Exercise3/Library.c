//
// Created by Ignacio on 19/5/2017.
//

#include "Library.h"
#include <stdlib.h>
#include <memory.h>

Library* newLibrary (){
    Library* library = malloc(sizeof(Library));
    library->materialArray=malloc(sizeof(Material)*10);
    library->personArray=malloc(sizeof(Person)*10);
    library->borrowArray=malloc(sizeof(Borrow)*10);
    library->materialBooleanArray=malloc(sizeof(int)*10);
    library->personBooleanArray=malloc(sizeof(int)*10);
    library->borrowBooleanArray=malloc(sizeof(int)*10);
    library->materialMaxCapacity=10;
    library->personMaxCapacity=10;
    library->borrowMaxCapacity=10;
    library->personQuantity=0;
    library->materialQuantity=0;
    library->borrowQuantity=0;
    for(int i=0;i<10;i++){
        library->materialBooleanArray[i]=0;
        library->personBooleanArray[i]=0;
        library->borrowBooleanArray[i]=0;
    }
    return library;
}

void freeLibrary(Library* library){
    for(int i=0;i<library->borrowMaxCapacity;i++){
        if(library->borrowBooleanArray[i]==1) freeBorrow(library->borrowArray[i]);
    }
    for(int i=0;i<library->personMaxCapacity;i++){
        if(library->personBooleanArray[i]==1) freePerson(library->personArray[i]);
    }
    for(int i=0;i<library->materialMaxCapacity;i++){
        if(library->materialBooleanArray[i]==1) freeMaterial(library->materialArray[i]);
    }
    free(library->borrowArray);
    free(library->borrowBooleanArray);
    free(library->personArray);
    free(library->personBooleanArray);
    free(library->materialArray);
    free(library->materialBooleanArray);
    free(library);
}

void addMaterial(Library* library, Material* material){
    for(int i=0;i<library->materialMaxCapacity;i++){
        if(library->materialBooleanArray[i]==0){
            library->materialBooleanArray[i]=1;
            if(material->materialType==1) {
                library->materialArray[i] = newBook(material->code, material->author, material->title, material->year, material->editorial);
                return;
            } else{
                library->materialArray[i]=newMagazine(material->code,material->title,material->year,material->editorial);
                return;
            }
        }
    }
    increaseMaterialArray(library);
    addMaterial(library,material);
}

void increaseMaterialArray(Library* library){
    library->materialArray=realloc(library->materialArray, sizeof(Material)*library->materialMaxCapacity*2);
    library->materialBooleanArray=realloc(library->materialBooleanArray, sizeof(int)*library->materialMaxCapacity*2);
    for(int i=library->materialMaxCapacity;i<library->materialMaxCapacity*2;i++){
        library->materialBooleanArray[i]=0;
    }
    library->materialMaxCapacity=library->materialMaxCapacity*2;
}

Material* removeMaterial(Library* library,int materialCode){
    for(int i=0;i<library->materialMaxCapacity;i++){
        if(library->materialBooleanArray[i]==0){
            if(library->materialArray[i]->code==materialCode)
                library->materialBooleanArray[i]=0;
                return library->materialArray[i];
        }
    }
    exit(2);
}

void addPerson(Library* library, Person* person){
    for(int i=0;i<library->personMaxCapacity;i++){
        if(library->personBooleanArray[i]==0){
            library->personBooleanArray[i]=1;
            if(person->personType==1) {
                library->personArray[i] = newStudent(person->name,person->mail,person->phone,person->code,person->enrollment);
                return;
            } else{
                library->personArray[i]=newTeacher(person->name,person->mail,person->phone,person->code,person->employeeNumber);
                return;
            }
        }
    }
    increasePersonArray(library);
    addPerson(library,person);
}

Person* removePerson(Library* library,int personCode){
    for(int i=0;i<library->personMaxCapacity;i++){
        if(library->personBooleanArray[i]==0){
            if(library->personArray[i]->code==personCode)
                library->personBooleanArray[i]=0;
                return library->personArray[i];
        }
    }
    exit(2);
}

void increasePersonArray(Library* library){
    library->personArray=realloc(library->personArray, sizeof(Person)*library->personMaxCapacity*2);
    library->personBooleanArray=realloc(library->personBooleanArray, sizeof(int)*library->personMaxCapacity*2);
    for(int i=library->personMaxCapacity;i<library->personMaxCapacity*2;i++){
        library->personBooleanArray[i]=0;
    }
    library->personMaxCapacity=library->personMaxCapacity*2;
}

void addBorrow(Library* library, Borrow* borrow){
    for(int i=0;i<library->borrowMaxCapacity;i++){
        if(library->borrowBooleanArray[i]==0){
            library->borrowArray[i]=newBorrow(borrow->price,borrow->returnDays);
            library->borrowBooleanArray[i]=1;
            return;
        }
    }
    increaseBorrowArray(library);
    addBorrow(library,borrow);
}

Borrow* removeBorrow(Library* library, int idBorrow){
    for(int i=0;i<library->borrowMaxCapacity;i++){
        if(library->borrowBooleanArray[i]==0){
            if(library->borrowArray[i]->code==idBorrow)
                library->borrowBooleanArray[i]=0;
                return library->borrowArray[i];
        }
    }
    exit(2);
}

void increaseBorrowArray(Library* library){
    library->borrowArray=realloc(library->borrowArray, sizeof(Borrow)*library->borrowMaxCapacity*2);
    library->borrowBooleanArray=realloc(library->borrowBooleanArray, sizeof(int)*library->borrowMaxCapacity*2);
    for(int i=library->borrowMaxCapacity;i<library->borrowMaxCapacity*2;i++){
        library->borrowBooleanArray[i]=0;
    }
    library->borrowMaxCapacity=library->borrowMaxCapacity*2;
}

int generateBorrowCode(Library* library){
    int code = library->borrowCode;
    library->borrowCode++;
    return code;
}

Material* getMaterial(Library* library, char* materialName){
    for(int i=0;i<library->materialMaxCapacity;i++){
        if(library->materialBooleanArray[i]==1){
            if(strcmp(library->materialArray[i]->title,materialName)) return library->materialArray[i];
        }
    }
    exit(2);
}
