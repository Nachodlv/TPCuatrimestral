//
// Created by Ignacio on 30/5/2017.
//

#include "DataBase.h"
#include <stdlib.h>
#include <memory.h>
DataBase* newDataBase(){
    DataBase* dataBase =malloc(sizeof(DataBase));
    dataBase->movieArray=malloc(sizeof(Movie*)*10);
    dataBase->movieQuantity=0;
    dataBase->maxMovies=10;
    dataBase->clientArray=malloc(sizeof(Client*)*10);
    dataBase->clientQuantity=0;
    dataBase->maxClients=10;
    dataBase->idCode=0;
    return dataBase;
}

void freeDataBase(DataBase* dataBase){
    for(int i=0;i<dataBase->maxMovies;i++){
        freeMovie(dataBase->movieArray[i]);
    }
    for(int i=0;i<dataBase->maxClients;i++){
        freeClientExercise5(dataBase->clientArray[i]);
    }
    free(dataBase->clientArray);
    free(dataBase->movieArray);
    free(dataBase);
}

void addMovie(Movie* movie, DataBase* dataBase){
    if(dataBase->movieQuantity==dataBase->maxMovies){
        growMovieArray(dataBase);
    }
    dataBase->movieArray[dataBase->movieQuantity]=movie;
    dataBase->movieQuantity++;
}

void growMovieArray(DataBase* dataBase){
    dataBase->maxMovies=dataBase->maxMovies*2;
    dataBase->movieArray=realloc(dataBase->movieArray, sizeof(Movie*)*dataBase->maxMovies);
}

void addClient(Client* client, DataBase* dataBase){
    if(dataBase->clientQuantity==dataBase->maxClients){
        growClientArray(dataBase);
    }
    dataBase->clientArray[dataBase->clientQuantity]=client;
    dataBase->clientQuantity++;
}

void growClientArray(DataBase* dataBase){
    dataBase->maxClients=dataBase->maxClients*2;
    dataBase->clientArray=realloc(dataBase->clientArray, sizeof(Client*)*dataBase->maxClients);
}

int getIdCode(DataBase* dataBase){
    int aux = dataBase->idCode;
    dataBase->idCode++;
    return aux;
}