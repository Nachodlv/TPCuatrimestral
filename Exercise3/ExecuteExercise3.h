//
// Created by Ignacio on 19/5/2017.
//

#ifndef TPCUATRIMESTRAL_EXECUTEEXERCISE3_H
#define TPCUATRIMESTRAL_EXECUTEEXERCISE3_H
#include "Library.h"

void printFirstMenu();

Person* studentsOrTeachers(Library* library1, int amountOfStudents, int amountOfTeachers);
Borrow *chooseBorrow(Library* library, int personCode);
void printBorrow(Borrow** pBorrow, int amount);
int getIndex();
void actionsPerson(Library* library, Person* person, int amountOfBooks, int amountOfMagazines);
void printStudents(Library *pLibrary, int amount);
void printTeachers(Library *pLibrary, int amount);
void borrowMenu(Library* library, Person* person);
int executeExercise3();
Material* chooseMaterial(Library* library, int amountOfBooks, int amountOfMagazines);
void printMagOrBook();
void printBooks(Library *pLibrary, int amount);
void printMagazines(Library *pLibrary, int amount);



#endif //TPCUATRIMESTRAL_EXECUTEEXERCISE3_H
