//
// Created by Gonzalo de Achaval on 18/5/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "ExecuteExercise2.h"
#include "Product.h"
#include "Camera.h"

void printUsers(RegisteredUser **pUser);

int executeExercise2(){

    int usersQuantity = 3;
    RegisteredUser* user1 = newResgisteredUser("Gonza", "1", "A", "2", "B", "C", "D", "3");
    RegisteredUser* user2 = newResgisteredUser("Nacho", "11", "AA", "22", "BB", "CC", "DD", "33");
    RegisteredUser* user3 = newResgisteredUser("Gocho", "111", "AAA", "222", "BBB", "CCC", "DDD", "333");
    RegisteredUser** registeredUsers = malloc(sizeof(RegisteredUser)*usersQuantity);
    registeredUsers[0] = user1;
    registeredUsers[1] = user2;
    registeredUsers[2] = user3;

    Manufacturer* manufacturer1 = newManufacturer("Hector", 1);
    Manufacturer* manufacturer2 = newManufacturer("Victor", 2);

    Provider* provider1 = newProvider("CIF", "Gianni", "Edu", "1", "A", "B", "C", "D", "2", "3");
    Provider* provider2 = newProvider("CIF2", "Edu", "Gianni", "1", "A", "B", "C", "D", "2", "3");

    Product* product1 = newProduct("NIKON", 1, 100, "A", provider1, manufacturer1);
    Product* product2 = newProduct("CANON", 2, 200, "B", provider2, manufacturer2);

    Camera* camera1 = newCamera()


    printUsersArray(registeredUsers, usersQuantity);
    chooseUser(registeredUsers);






    return 0;
}

void printUsersArray(RegisteredUser** pUser, int usersQuantity) {
    for(int i=0;i<usersQuantity;i++){
        printf(" %d\t",i+1);
        printf("%s\n",pUser[i]->name);
    }
}

RegisteredUser* chooseUser(RegisteredUser** pUser){
    int userNumber;
    printf("%s\n", "Choose valid option: \n");
    scanf(" %i*c",&userNumber);
    return pUser[userNumber-1];
}

void printProductsArray()




