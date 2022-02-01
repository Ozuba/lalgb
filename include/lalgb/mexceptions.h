#ifndef MEXCEPTIONS_H
#define MEXCEPTIONS_H


#include <stdio.h>
#include <iostream>
using namespace std;

#define ERRORMSGSIZE 100


class MatrixError {//Clase base de Errores

    protected:
        char error[ERRORMSGSIZE];//Mensaje Error

    public://El constructor de clase base se ejecuta siempre que se crea una clase derivada
        MatrixError() throw(){};//throw()Promete al compilador que no lanzará excepciones        }
        char* watch(){
            return error;
        }
};


class inv_size : public MatrixError //Tamaño Invalido
{
    public:
    inv_size(int r1 ,int c1,int r2,int c2) throw() {
    sprintf(error,"Different matrix sizes: m1:%dx%d  m2:%dx%d",r1,c1,r2,c2);
    }
 
};

class inc_size : public MatrixError //Tamaño Incorrecto
{
    public:
    inc_size(int r1 ,int c1,int r2,int c2) throw() {
    sprintf(error,"Incompatible Matrix Sizes for Product: m1:%dx%d  m2:%dx%d",r1,c1,r2,c2);
    }
 
};

//Implementar Indice Invalido

#endif