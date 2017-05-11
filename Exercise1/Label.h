//
// Created by Ignacio on 10/5/2017.
//

#ifndef TPCUATRIMESTRAL_LABEL_H
#define TPCUATRIMESTRAL_LABEL_H
typedef struct label Label;
struct label{
    char* id;
    char* name;
};
Label* newLabel(char* id, char* name);
void freeLabel(Label* label);
#endif //TPCUATRIMESTRAL_LABEL_H
