#ifndef MATRIX_H//Inclusion guard proteje el archivo de ser incluido varias veces
#define MATRIX_H



#include <stdio.h>
#include <iostream>
#include <string.h>
#include "mexceptions.h"
#include "rows_cols.h"

using namespace std;

//Row storage order implementar en un futuro almacenamiento por columnas, eficiencia de acceso a vectores


template<class T>
class matrix{

    protected:
    int rows, cols;//Implementar acceso publico
    T* data; //Puntero a datos matriz
    T* allocate(int _rows, int _cols);
    
    inline T& get(int row,int col){return data[row*cols+col];};//Internal access function

    public:
    //Constructores
    matrix(int _rows, int _cols);//constructor por defecto

    //Acceso Llenado y representacion
    T& operator()(int row,int col);//operador de acceso implementar que con Cordenadas -1 acceda a toda la fila?
    void operator<<(T* list);//llenado por array
    void print();//imprimir

    //Modificadores
    void setCol(col<T> _col);
    void setRow(row<T> _row);

    //Funciones operadoras

    template<class U> friend matrix<U> operator+(matrix<U> a, matrix<U> b);
    template<class U> friend matrix<U> operator*(matrix<U> a, matrix<U> b);
    template<class U> friend matrix<U> operator*(U a, matrix<U> b);//Definimos producto por escalar dando por escalar un unico elemento del tipo de matriz

};
///////////////////////////////////////[Funciones de reserva de memoria]///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T* matrix<T>::allocate(int _rows,int _cols){
return new T[_rows * _cols];//reserva espacio para todos los elementos
}




/////////////////////////////////[Constructores]////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
matrix<T>::matrix(int _rows,int _cols){
rows = _rows;
cols = _cols;
data = allocate(rows,cols);

}

/////////////////////////////////[Operadores de acceso]/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T& matrix<T>::operator()(int row,int col){
    return this->get(row,col);
}
template<class T>
void matrix<T>::operator<<(T* list){
//no imlementa chequeo de boundaries
    memcpy(data,list,rows*cols*sizeof(T));//copia los arrays de datos

}
//////////////////////////////////[Miscelaneo]///////////////////////////////////////////////////////
template<class T>
void matrix<T>::print(){
    cout << '\n';//Nueva linea
    for(int i = 0; i < this->rows; i++)
    {
        for(int j = 0; j < this->cols; j++){

            cout << this->get(i,j) << " " ;
        }
    cout << '\n';
    }
}


/////////////////////////////////////////////////////////[Operadores Aritmeticos]////////////////////////////////////////////
template<class U>//SUMA
matrix<U> operator+(matrix<U> a, matrix<U> b)
{
    if(a.rows == b.rows && a.cols == b.cols ){//Si esta permitida
            matrix<U> c(a.rows,b.cols);
            for(int i= 0; i < a.rows; i++){
                    for(int j = 0; j < a.cols; j++){
                        c(i,j) = a(i,j)+ b(i,j);//Suma elementos
                    }
                }
    return c;
    }else{
        throw inv_size(a.rows,a.cols,b.rows,b.cols);
    }
}



template<class U>//PRODUCTO MATRICIAL
matrix<U> operator*(matrix<U> a, matrix<U> b){
    if(a.cols == b.rows){
        matrix<U> c(a.rows,b.cols);//crea matriz resultado
         for(int i= 0; i < c.rows; i++){
                    for(int j = 0; j < c.cols; j++){
                        for(int k = 0; k < a.rows;k++){
                            c(i,j) += a(i,k) * b(k,j);//Recorre los elementos
                        }
                    }
         }
    return c;
    }else{
    throw inc_size(a.rows,a.cols,b.rows,b.cols);
    }
}

template<class U>//PRODUCTO POR ESCALAR definida en un sentido hay que cambiarlo
matrix<U> operator*(U a, matrix<U> b){
    for(int i= 0; i < b.rows; i++){
            for(int j = 0; j < b.cols; j++){
                b(i,j) = a* b(i,j);//Operation
            }
        }
    return b;
  
}


/*Cosas importantes a implementar
2-Construcíon de matriz por columnas para ello implementar la subclase columna
3-Metodo de Gauss en archivo distinto, ha de trabajar con la interfaz proporcionada por la clase matriz, aprovechar la interfaz de manera que sirva para el calculo de inversas
3bis-Por tanto implementar acceso a fila y reorganizacion para pivotamiento parcial
*/
#endif
