//
// Created by Ignacio on 30/5/2017.
//

#include "Movie.h"
#include <stdlib.h>
#include <memory.h>
Movie* newMovie(char* name){
    Movie* movie = malloc(sizeof(Movie));
    movie->name=malloc(sizeof(char)*strlen(name));
    strcpy(movie->name,name);
    movie->numberId=-1;
    movie->available=1;
    movie->rentalDays=0;
    return movie;
}

void freeMovie(Movie* movie){
    free(movie->name);
    free(movie);
}

void rentMovie(Movie* movie, Id* id, int rentalDays){
    movie->rentalDays=rentalDays;
    movie->available=0;
    movie->numberId=id->numberId;
}