//
// Created by Ignacio on 30/5/2017.
//

#include <stdlib.h>
#include "ExecuteExercise5.h"
#include "Client.h"
#include "Admin.h"

int executeExercise5(){
    Client* client1 = newClientExercise5("Nacho", 40693681);
    Client* client2 = newClientExercise5("Gonza", 41222861);
    Client* client3 = newClientExercise5("Nanza", 12345678);
    int amountOfClients = 3;
    Client** clients = malloc(sizeof(Client*)*amountOfClients);
    clients[0] = client1;
    clients[1] = client2;
    clients[2] = client3;

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
    int amountOfMovies = 4;
    Movie** movies = malloc(sizeof(Movie*)*amountOfMovies);
    movies[0] = movie1;
    movies[1] = movie2;
    movies[2] = movie3;
    movies[3] = movie4;


    return 0;
}
