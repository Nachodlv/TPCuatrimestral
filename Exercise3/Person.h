//
// Created by Ignacio on 19/5/2017.
//

#include "Material.h"
#include "Borrow.h"

#ifndef TPCUATRIMESTRAL_PERSON_H
#define TPCUATRIMESTRAL_PERSON_H
typedef struct person Person;
struct person{
    int personType;
    char* name;
    char* mail;
    int phone;
    int booksQuantity;
    int code;
    int enrollment;
    int employeeNumber;
    double debt;
};

//crea un estudiante, el personType es 1
Person* newStudent(char* name,char* mail, int phone,int code, int enrollment);
//persontype es 2
Person* newTeacher(char* name, char* mail, int phone,int code, int employeeNumber);
void freePerson(Person* person);

#endif //TPCUATRIMESTRAL_PERSON_H
