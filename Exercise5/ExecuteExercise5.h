//
// Created by Ignacio on 30/5/2017.
//

#ifndef TPCUATRIMESTRAL_EXECUTEEXERCISE5_H
#define TPCUATRIMESTRAL_EXECUTEEXERCISE5_H

#include "Admin.h"
#include "DataBase.h"
#include "Excess.h"

int executeExercise5();
void firstMenu(Admin** admins, int amountOfAdmins, DataBase* database, Excess* excess);
void clientDecision(DataBase* dataBase, Client* client, Excess* excess);
void chooseMovieToLeave(DataBase* database, Client* client, Excess* excess);
void printMoviesToLeave(DataBase* database, Id* id);
void chooseMovie(DataBase* dataBase, Client* client);
void printAvailableMovies(DataBase* database);
void printFirstOptionClient();
void adminDecision(DataBase* database, Excess* excess);
void printAdminOptions();
void printClientsExercise5(DataBase* database);
void printAdmins(Admin** admins, int amountOfAdmins);
int getIndexExercise5();
char* scanChar();
int getID();
int getDaysToRent();


#endif //TPCUATRIMESTRAL_EXECUTEEXERCISE5_H
