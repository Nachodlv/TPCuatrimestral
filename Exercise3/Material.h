//
// Created by Ignacio on 19/5/2017.
//

#ifndef TPCUATRIMESTRAL_MATERIAL_H
#define TPCUATRIMESTRAL_MATERIAL_H
typedef struct material Material;
struct material{
    int materialType;
    int code;
    char* author;
    char* title;
    int year;
    int status;
    char* editorial;
};

//Crea un book que es un material, modifica el materialType a 1
Material* newBook(int code, char* author, char* title, int year, char* editorial);

//crea una revista q es un material, a diferencia del book no recibe un author, el materialType es 2
Material* newMagazine(int code, char* title, int year, char* editorial);

//modifica el status a disponible
void enlistMaterial(Material* material);

//modifica el status a noDisponible
void takeOutMaterial(Material* material);

void freeMaterial(Material* material);
#endif //TPCUATRIMESTRAL_MATERIAL_H
