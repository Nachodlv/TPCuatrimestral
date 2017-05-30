//
// Created by Ignacio on 30/5/2017.
//

#ifndef TPCUATRIMESTRAL_ID_H
#define TPCUATRIMESTRAL_ID_H
typedef struct id Id;
struct id{
    int numberId;
};
Id* newId(int numberId);
void freeId(Id*);
#endif //TPCUATRIMESTRAL_ID_H
