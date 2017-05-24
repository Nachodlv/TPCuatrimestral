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
    person->name=malloc(sizeof(char)*(strlen(name)+1));
    person->mail=malloc(sizeof(char)*(strlen(mail)+1));
    person->phone=phone;
    person->code=code;
    person->enrollment=enrollment;
    person->booksQuantity=0;
    person->debt=0;
    strcpy(person->name,name);
    strcpy(person->mail,mail);
    return person;
}

Person* newTeacher(char* name, char* mail, int phone, int code, int employeeNumber){
    Person* person =malloc(sizeof(Person));
    person->personType=2;
    person->name=malloc(sizeof(char)*(strlen(name)+1));
    person->mail=malloc(sizeof(char)*(strlen(mail)+1));
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


