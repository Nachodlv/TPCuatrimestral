//
// Created by Ignacio on 30/5/2017.
//

#include "Id.h"

#ifndef TPCUATRIMESTRAL_MOVIE_H
#define TPCUATRIMESTRAL_MOVIE_H
typedef struct movie Movie;
struct movie{
    char* name;
    int numberId;
    int available;
    int rentalDays;
};
Movie* newMovie(char* name);
void freeMovie(Movie* movie);
void rentMovie(Movie* movie, Id* id, int rentalDays);
void leaveMovie(Movie* movie);
#endif //TPCUATRIMESTRAL_MOVIE_H
