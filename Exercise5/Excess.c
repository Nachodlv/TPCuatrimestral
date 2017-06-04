//
// Created by Ignacio on 30/5/2017.
//

#include "Excess.h"
#include <stdlib.h>
Excess* newExcess(int costOfMovieRentPerDay){
    Excess* excess = malloc(sizeof(Excess));
    excess->costPerDay=costOfMovieRentPerDay;
    excess->money=0;
    return excess;
}

void freeExcess(Excess* excess){
    free(excess);
}

int moviesWithoutReturn(DataBase* dataBase){
    int counter=0;
    for(int i=0;i<dataBase->maxMovies;i++){
        if(dataBase->movieArray[i]->available==0){
            counter++;
        }
    }
    return counter;
}

void leaveMovie(Movie* movie, Excess* excess1){
    movie->available=1;
    movie->numberId=-1;
    excess1->money+=movie->rentalDays*excess1->costPerDay;
    movie->rentalDays=0;
}