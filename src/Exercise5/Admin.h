//
// Created by Ignacio on 30/5/2017.
//

#ifndef TPCUATRIMESTRAL_ADMIN_H
#define TPCUATRIMESTRAL_ADMIN_H
typedef struct admin Admin;
struct admin{
    char* name;
    int dni;
};
Admin* newAdmin(char* name, int dni);
void freeAdmin(Admin* admin);

#endif //TPCUATRIMESTRAL_ADMIN_H
