//
// Created by Ignacio on 19/5/2017.
//

#ifndef TPCUATRIMESTRAL_LIBRARY_H
#define TPCUATRIMESTRAL_LIBRARY_H

#include "Material.h"
#include "Person.h"

typedef struct library Library;
struct library{
    Material** materialArray;
    Person** personArray;
    Borrow** borrowArray;
    int* materialBooleanArray;
    int* personBooleanArray;
    int* borrowBooleanArray;
    int materialMaxCapacity;
    int personMaxCapacity;
    int borrowMaxCapacity;
    int materialQuantity;
    int personQuantity;
    int borrowQuantity;
    int borrowCode;
};

Library* newLibrary ();
void freeLibrary(Library* library);
void addMaterial(Library* library, Material* material);
void addPerson(Library* library, Person* person);
void addBorrow(Library* library, Borrow* borrow);
Borrow** getBorrows(Library* library, int personCode);
Material* removeMaterial(Library* library,int materialCode);
Person* removePerson(Library* library,int personCode);
Borrow* removeBorrow(Library* library, int idBorrow);
int generateBorrowCode(Library* library);
Material* getMaterial(Library* library, char* materialName);
void increaseMaterialArray(Library* library);
void increaseBorrowArray(Library* library);
void increasePersonArray(Library* library);
#endif //TPCUATRIMESTRAL_LIBRARY_H
