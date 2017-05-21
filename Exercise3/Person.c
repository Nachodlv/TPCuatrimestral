//
// Created by Ignacio on 19/5/2017.
//

#include "Person.h"
#include "Library.h"
#include <stdlib.h>
#include <memory.h>

Person* newStudent(char* name,char* mail, int phone, int code, int enrollment){
    Person* person = malloc(sizeof(Person));
    person->personType=1;
    person->name=malloc(sizeof(name));
    person->mail=malloc(sizeof(mail));
    person->phone=phone;
    person->code=code;
    person->enrollment=enrollment;
    strcpy(person->name,name);
    strcpy(person->mail,mail);
    return person;
}

Person* newTeacher(char* name, char* mail, int phone, int code, int employeeNumber){
    Person* person =malloc(sizeof(Person));
    person->personType=2;
    person->name=malloc(sizeof(name));
    person->mail=malloc(sizeof(mail));
    person->phone=phone;
    person->code=code;
    person->employeeNumber=employeeNumber;
    strcpy(person->name,name);
    strcpy(person->mail,mail);
    return person;
}

void freePerson(Person* person){
    free(person->name);
    free(person->mail);
    free(person);
}

void takeMaterial(Person* person, Material* material,Library* library, Borrow* borrow){
    takeOutMaterial(material);
    removeMaterial(library,material->code);
    addBorrow(library,borrow);
    person->booksQuantity++;
    person->debt+=borrow->price;
}

void leaveMaterial(Person* person, Material* material, Library* library, Borrow borrow){
    enlistMaterial(material);
    addMaterial(library,material);
    person->booksQuantity--;
    freeBorrow(removeBorrow(library,borrow.code));
}
