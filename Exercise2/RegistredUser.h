//
// Created by Gonzalo de Achaval on 18/5/17.
//

#ifndef TPCUATRIMESTRAL_REGISTREDUSER_H
#define TPCUATRIMESTRAL_REGISTREDUSER_H

typedef struct registeredUser RegisteredUser;
struct registeredUser{
    char* name;
    char* dni;
    char* address;
    char* phone;
    char* location;
    char* province;
    char* country;
    char* postalCode;
    //int role;
};
RegisteredUser* newResgisteredUser(char* name, char* dni, char* address, char* phone, char* location, char* province, char* country, char* postalCode);
void freeResgisteredUser(RegisteredUser*);


#endif //TPCUATRIMESTRAL_REGISTREDUSER_H
