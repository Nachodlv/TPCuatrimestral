//
// Created by Ignacio on 19/5/2017.
//


#include "ExecuteExercise3.h"
#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Library.h"


void printActions();


Material* material1;

int executeExercise3(){
    Library* library = newLibrary();

    Person* student1 = newStudent("Nacho", "@gmail.com", 1, 1, 1);
    Person* student2 = newStudent("Gonza", "@yahoo.com", 2, 2, 2);
    int amountOfStudents = 2;
    addPerson(library, student1);
    addPerson(library, student2);

    Person* teacher1 = newTeacher("Alicia", "@bing.com", 1, 1, 1);
    Person* teacher2 = newTeacher("Laura", "@hotmail.com", 2, 2, 2);
    int amountOfTeachers = 2;
    addPerson(library, teacher1);
    addPerson(library, teacher2);

    Material* book1 = newBook(1, "Roald Dahl", "Title1", 2002, "Editorial1");
    Material* book2 = newBook(2, "Roald Dahl", "Title2", 2002, "Editorial1");
    Material* book3 = newBook(3, "Steig Larsson", "Title3", 2006, "Editorial3");
    int amountOfBooks = 3;
    addMaterial(library, book1);
    addMaterial(library, book2);
    addMaterial(library, book3);

    Material* magazine1 = newMagazine(1, "TitleMag1", 2010, "Editorial1Mag");
    int amountOfMagazines = 1;
    addMaterial(library, magazine1);


    printFirstMenu();
    Person* person = studentsOrTeachers(library, amountOfStudents, amountOfTeachers);
    actionsPerson(library, person, amountOfBooks, amountOfMagazines);

    return 1;
}


void printFirstMenu(){
    printf(" %d\t", 1);
    printf("%s\n", "Print Students");
    printf(" %d\t", 2);
    printf("%s\n", "Print Teachers");
}

Person* studentsOrTeachers(Library* library1, int amountOfStudents, int amountOfTeachers){
    int i = getIndex();
    switch(i){
        case 1: printStudents(library1, amountOfStudents+amountOfTeachers);
            break;
        case 2: printTeachers(library1, amountOfTeachers+amountOfStudents);
            break;
        default: break;
    }
    return library1->personArray[getIndex()-1];
}

int getIndex() {
    int index;
    printf("%s", "Choose valid option: \t");
    scanf(" %i*c",&index);
    printf("\n");
    return index;
}

void printStudents(Library *pLibrary, int amount) {
    printf("%s", "Students:");
    printf("\n");
    for(int i=0; i<amount; i++){
        if(pLibrary->personBooleanArray[i]==1 && pLibrary->personArray[i]->personType==1) {
            printf(" %d\t", i+1);
            printf("%s\n", pLibrary->personArray[i]->name);
        }
    }
}

void printTeachers(Library *pLibrary, int amount) {
    printf("\n%s", "Teachers:");
    printf("\n");
    for(int i=0; i<amount; i++){
        if(pLibrary->personBooleanArray[i]==1 && pLibrary->personArray[i]->personType==2) {
            printf(" %d\t", i+1);
            printf("%s\n", pLibrary->personArray[i]->name);
        }
    }
}

void actionsPerson(Library* library, Person* person, int amountOfBooks, int amountOfMagazines) {
    int trueFalse = 1;
    while (trueFalse) {
        printActions();
        switch (getIndex()) {
            case 1:
                borrowMenu(library, person);
                break;
            case 2:
                material1 = chooseMaterial(library, amountOfBooks, amountOfMagazines);
                takeMaterial(person, material1, library, generateBorrow(library, material1));
                break;
            case 3:
                trueFalse = 0;
                break;
            default:
                break;
        }
    }
}

Borrow* generateBorrow(Library* library, Material* material) {
    Borrow* borrow = newBorrow(100, 2, material->title);
    addBorrow(library, borrow, material);
    return borrow;
}

void printActions() {
    printf("\n");
    printf(" %d\t", 1);
    printf("%s\n", "Leave material");
    printf(" %d\t", 2);
    printf("%s\n", "Take material");
    printf(" %d\t", 3);
    printf("%s\n", "Exit");
}

void borrowMenu(Library* library, Person* person) {
    Borrow* borrow = chooseBorrow(library,person->code);
    printBorrow(borrow);
    leaveMaterial(person, getMaterial(library,borrow->materialName), library, borrow);
}

Borrow* chooseBorrow(Library* library, int personCode) {
    Borrow** bArray = library->borrowArray;
    for(int i=0; i<library->borrowMaxCapacity; i++){
        if(library->borrowBooleanArray[i]==1){
            if(library->borrowArray[i]->personCode == personCode){
                printf(" %d\t", i+1);
                printf("Material name: %s\n", bArray[i]->materialName);
            }
        }
    }
    return bArray[getIndex()-1];
}

void printBorrow(Borrow* pBorrow) {
    printf("\n%s", "Borrows:\n");
    printf("Price: %.1f%s\n", pBorrow->price, "$");
    double diff_t;
    diff_t = difftime(time(0), pBorrow->departureDate);
    printf("You returned your material %.0f%s\n", (diff_t), " seconds after you borrowed it");
    printf("%s%.d%s", "You had: ", pBorrow->returnDays*60, " hours");
    printf("\n");
}

Material* chooseMaterial(Library* library, int amountOfBooks, int amountOfMagazines) {
    printMagOrBook();
    int i = getIndex();
    switch(i){
        case 1: printBooks(library, amountOfBooks+amountOfMagazines);
            break;
        case 2: printMagazines(library, amountOfMagazines+amountOfBooks);
            break;
        case 3: break;
        default: break;
    }
    return library->materialArray[getIndex()-1];
}

void printMagOrBook(){
    printf(" %d\t", 1);
    printf("%s\n", "Print Books");
    printf(" %d\t", 2);
    printf("%s\n", "Print Magazines");
    printf(" %d\t", 3);
    printf("%s\n", "Exit");

}

void printBooks(Library *pLibrary, int amount) {
    printf("\n%s", "Books:");
    printf("\n");
    for(int i=0; i<amount; i++){
        if(pLibrary->materialBooleanArray[i]==1 && pLibrary->materialArray[i]->materialType==1) {
            printf(" %d\t", i+1);
            printf("Title: %s\n", pLibrary->materialArray[i]->title);
            printf("Author: %s\n", pLibrary->materialArray[i]->author);
            printf("\n");
        }
    }
}

void printMagazines(Library *pLibrary, int amount) {
    printf("\n%s", "Magazines:");
    printf("\n");
    for(int i=0; i<amount; i++){
        if(pLibrary->materialBooleanArray[i]==1 && pLibrary->materialArray[i]->materialType==2) {
            printf(" %d\t", i+1);
            printf("Title: %s\n", pLibrary->materialArray[i]->title);
            printf("\n");
        }
    }
}

