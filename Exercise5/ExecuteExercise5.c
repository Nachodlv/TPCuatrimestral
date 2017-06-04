//
// Created by Ignacio on 30/5/2017.
//

#include <stdlib.h>
//#include <printf.h>
#include <memory.h>
#include <stdio.h>
#include <ctype.h>
#include "ExecuteExercise5.h"
#include "Client.h"
#include "Admin.h"
#include "DataBase.h"
#include "Excess.h"


int executeExercise5(){
    DataBase* database = newDataBase();
    Client* client1 = newClientExercise5("Nacho", getIdCode(database));
    Client* client2 = newClientExercise5("Gonza", getIdCode(database));
    Client* client3 = newClientExercise5("Nanza", getIdCode(database));

    Admin* admin1 = newAdmin("NachoADMIN", 40693682);
    Admin* admin2 = newAdmin("GonzaADMIN", 41222862);
    Admin* admin3 = newAdmin("NanzaADMIN", 12345679);
    int amountOfAdmins = 3;
    Admin** admins = malloc(sizeof(Admin*)*amountOfAdmins);
    admins[0] = admin1;
    admins[1] = admin2;
    admins[2] = admin3;

    Movie* movie1 = newMovie("Zombieland");
    Movie* movie2 = newMovie("Marley and Me");
    Movie* movie3 = newMovie("Inception");
    Movie* movie4 = newMovie("In Time");

    addMovie(movie1, database);
    addMovie(movie2, database);
    addMovie(movie3, database);
    addMovie(movie4, database);

    addClient(client1, database);
    addClient(client2, database);
    addClient(client3, database);

    Excess* excess = newExcess(10);

    firstMenu(admins, amountOfAdmins, database, excess);

    return 0;
}

void firstMenu(Admin** admins, int amountOfAdmins, DataBase* database, Excess* excess) {
    int trueFalse = 1;
    while(trueFalse){
        printf("\n");
        printf("%s\n", "1. Print admins");
        printf("%s\n", "2. Print clients");

        switch(getIndexExercise5()) {
            case 1:
                printAdmins(admins, amountOfAdmins);
                Admin* admin = admins[getIndexExercise5() - 1];
                adminDecision(database, excess);
                break;
            case 2:
                printClientsExercise5(database);
                Client *client = database->clientArray[getIndexExercise5() - 1];
                clientDecision(database, client, excess);
                break;
            case 3:
                trueFalse=0;
                break;
            default:
                break;
        }
    }
}

void clientDecision(DataBase* database, Client* client, Excess* excess) {
    int truefalse = 1;
    while(truefalse){
        printFirstOptionClient();
        switch(getIndexExercise5()){
            case 1:
                chooseMovie(database, client);
                break;
            case 2:
                chooseMovieToLeave(database, client, excess);
                break;
            case 3:
                truefalse = 0;
                break;
            default:
                break;

        }
    }
}

void chooseMovieToLeave(DataBase* database, Client* client, Excess* excess) {
    printMoviesToLeave(database, client->id);
    Movie* chosenMovie = database->movieArray[getIndexExercise5()-1];
    leaveMovie(chosenMovie, excess);
}

void printMoviesToLeave(DataBase* database, Id* id) {
    int counter=1;
    for(int i=0;i<database->movieQuantity;i++){
        if(database->movieArray[i]->numberId==id->numberId){
            printf("%d. ", counter);
            printf("%s\n", database->movieArray[i]->name);
            counter++;
        }
    }
}

void chooseMovie(DataBase* dataBase, Client* client) {
    printAvailableMovies(dataBase);
    Movie* chosenMovie = dataBase->movieArray[getIndexExercise5()-1];
    int amount = getDaysToRent();
    rentMovie(chosenMovie, client->id, amount);
}

void printAvailableMovies(DataBase* database) {
    int counter=1;
    for(int i=0;i<database->movieQuantity;i++){
        if(database->movieArray[i]->available==1){
            printf("%d. ", counter);
            printf("%s\n", database->movieArray[i]->name);
            counter++;
        }
    }
}

void printFirstOptionClient() {
    printf("\n");
    printf("%s\n", "1. Rent movie");
    printf("%s\n", "2. Leave movie");
    printf("%s\n", "3. Exit");
}

void adminDecision(DataBase* database, Excess* excess) {
    while(1) {
        printAdminOptions();
        switch (getIndexExercise5()) {
            case 1:
                printf("%d\n", moviesWithoutReturn(database));
                break;
            case 2:
                printf("%.2f\n", excess->money);
                break;
            case 3:
                caseNewClient(database);
                break;
            case 4:
                return;
            default:
                printf("Please choose a valid option\n");
                break;
        }
    }
}

void caseNewClient(DataBase* database){
    Client* client = newClientExercise5(scanChar(),getIdCode(database));
    addClient(client, database);
}

void printAdminOptions() {
    printf("\n");
    printf("%s\n", "1. See amount of movies without return");
    printf("%s\n", "2. See money accumulated");
    printf("%s\n", "3. Create client");
    printf("4. Exit\n");
}


void printClientsExercise5(DataBase* database) {
    printf("\nCLIENTS\n");
    Client** clients = database->clientArray;
    for(int i=0;i<database->clientQuantity;i++){
        printf("%d%s", i+1, ". ");
        printf("%s\n", clients[i]->name);
    }
}

void printAdmins(Admin** admins, int amountOfAdmins) {
    printf("\nADMINS\n");
    for(int i=0; i<amountOfAdmins; i++){
        printf("%d%s", i+1, ". ");
        printf("%s\n", admins[i]->name);
    }
}

int getIndexExercise5() {
    int index;
    printf("%s", "Choose valid option: \t");
    scanf(" %i*c",&index);
    printf("\n");
    return index;
}

static void trim(char *str) {
    int len = strlen(str);
    char *frontp = str;
    char *endp = str + len;

    while(isspace((unsigned char) *frontp)) ++frontp;
    if(endp != frontp){
        while(isspace((unsigned char) *(--endp)) && endp != frontp);
    }

    if(str + len - 1 != endp) *(endp + 1) = '\0';
    else if(frontp != str &&  endp == frontp)*str = '\0';

    endp = str;
    if(frontp != str) {
        while(*frontp) {*endp++ = *frontp++;}
        *endp = '\0';
    }
}

/*
 * Function: scanChar
 * Description: takes a string input from the user, ignoring trailing and leading whitespace.
 * Returns: inputted string.
 */

char* scanChar(){
    size_t bufferSize = sizeof(char) * 256;
    char* line = malloc(bufferSize);
    while(1) {
        if (fgets(line, bufferSize, stdin)) {
            trim(line);
            if(strlen(line) != 0) return line;
        }
        printf("Please enter the name of client: \n");
    }
}

int getDaysToRent() {
    int id;
    printf("%s", "Please enter the amount of days to rent:\t");
    scanf(" %i*c",&id);
    printf("\n");
    return id;
}