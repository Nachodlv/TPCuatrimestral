//
// Created by Ignacio on 19/5/2017.
//

#include <printf.h>
#include "ExecuteExercise3.h"
#include "Person.h"
#include "Library.h"

int getStudentOrTeacher();

void printActions();

Borrow *chooseBorrow(Borrow **pBorrow);

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
    actionsPerson(library, studentsOrTeachers(library, amountOfStudents, amountOfTeachers));



    



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
        case 1: printStudents(library1, amountOfStudents);
            break;
        case 2: printTeachers(library1, amountOfTeachers);
            break;
        default: break;
    }
    return library1->personArray[i];
}

int getIndex() {
    int index;
    printf("%s", "Choose valid option: \t");
    scanf(" %i*c",&index);
    printf("\n");
    return index;
}

void printStudents(Library *pLibrary, int amount) {
    printf("\n%s\n", "Students:");
    for(int i=0; i<amount; i++){
        if(pLibrary->personBooleanArray[i]==1 && pLibrary->personArray[i]->personType==1) {
            printf(" %d\t", i);
            printf("%s", pLibrary->personArray[i]->name);
        }
    }
}

void printTeachers(Library *pLibrary, int amount) {
    printf("\n%s", "Teachers:");
    for(int i=0; i<amount; i++){
        if(pLibrary->personBooleanArray[i]==1 && pLibrary->personArray[i]->personType==2) {
            printf(" %d\t", i);
            printf("%s", pLibrary->personArray[i]->name);
        }
    }
}

void actionsPerson(Library* library, Person* person) {
    int trueFalse = 1;
    while (trueFalse) {
        printActions();
        switch (getIndex()) {
            case 1:
                Borrow* borrow = chooseBorrow(getBorrows(library,person->code));
                leaveMaterial(person, getMaterial(library,borrow->materialName), library, borrow; //personas no tienen material...
                break;
            case 2:
                takeMaterial(person, chooseMaterial(library), library, newBorrow(100, 2));
                break;
            case 3:
                trueFalse = 0;
                break;
            default:
                break;
        }
    }

}


void printActions() {
    printf(" %d\t", 1);
    printf("%s\n", "Leave material");
    printf(" %d\t", 2);
    printf("%s\n", "Take material");
    printf(" %d\t", 3);
    printf("%s\n", "Exit");
}


Borrow *chooseBorrow(Borrow** borrow) {
    return NULL;
}
