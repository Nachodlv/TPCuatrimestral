//
// Created by Ignacio on 30/5/2017.
//

#ifndef TPCUATRIMESTRAL_DATABASE_H
#define TPCUATRIMESTRAL_DATABASE_H

#include "Movie.h"
#include "Client.h"

typedef struct dataBase DataBase;
struct dataBase{
    Movie** movieArray;
    int movieQuantity;
    int maxMovies;
    Client** clientArray;
    int clientQuantity;
    int maxClients;
    int idCode;
};
DataBase* newDataBase();
void freeDataBase(DataBase* dataBase);
void addMovie(Movie* movie, DataBase* dataBase);
void growMovieArray(DataBase* dataBase);
void addClient(Client* client, DataBase* dataBase);
void growClientArray(DataBase* dataBase);
Movie** getRentMovieClient(Id id, DataBase* dataBase);
Movie** getMoviesAvailable(DataBase* dataBase);
Movie* getMovie(char* movieName, DataBase* dataBase);
int getIdCode(DataBase* dataBase);
#endif //TPCUATRIMESTRAL_DATABASE_H
