//
// Created by Ignacio on 19/5/2017.
//

#ifndef TPCUATRIMESTRAL_EXECUTEEXERCISE3_H
#define TPCUATRIMESTRAL_EXECUTEEXERCISE3_H
#include "Library.h"

void printFirstMenu();
void actionsPerson(Library* library, Person* person);
Person* studentsOrTeachers(Library* library1, int amountOfStudents, int amountOfTeachers);
Borrow *chooseBorrow(Library* library, int personCode);
void printBorrow(Borrow** pBorrow, int amount);
int getIndex();
void printStudents(Library *pLibrary, int amount);
void printTeachers(Library *pLibrary, int amount);
void actionsPerson(Library* library, Person* person);
void borrowMenu(Library* library, Person* person);
int executeExercise3();



#endif //TPCUATRIMESTRAL_EXECUTEEXERCISE3_H
