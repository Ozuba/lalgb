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
class Matrix{

    protected:
        int rows, cols;//Implementar acceso publico
        T* data; //Puntero a datos matriz
        T* allocate(int _rows, int _cols);
        inline T& get(int row,int col){return data[row*cols+col];};//Internal access function, implementar out of range aqui

    public:
    //Constructores
        Matrix(int _rows, int _cols);//constructor por defecto
        Matrix(int _rows, int _cols,T* matrixptr);//constructor con puntero a datos, cuidado con estos constructores no chequean el tamaño en destino

        //Acceso Llenado y representacion
        void operator<<(T* list);//llenado por array
        void print();//imprimir

        //Operadores de acceso 
        T& operator()(int row,int col);//operador de acceso implementar que con Cordenadas -1 acceda a toda la fila?

        //crea un objeto row y col con copia de memoria de dicho indice, no mira si el indice es valido
        Col<T> col(int j);
        Row<T> row(int i);
        //Cambia columnas o filas implementar con chequeo de tamaños en un futuro unir los dos operadores, problemas de liberacion de memoria compartida por clase derivada 
        void setcol(int j, Col<T> _col);
        void setrow(int i, Row<T> _row);

        //Funciones operadoras

        template<class U> friend Matrix<U> operator+(Matrix<U> a, Matrix<U> b);
        template<class U> friend Matrix<U> operator*(Matrix<U> a, Matrix<U> b);
        template<class U> friend Matrix<U> operator*(U a, Matrix<U> b);//Definimos producto por escalar dando por escalar un unico elemento del tipo de matriz

};
///////////////////////////////////////[Funciones de reserva de memoria]///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T* Matrix<T>::allocate(int _rows,int _cols){
return new T[_rows * _cols];//reserva espacio para todos los elementos
}




/////////////////////////////////[Constructores]////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Matrix<T>::Matrix(int _rows,int _cols){
rows = _rows;
cols = _cols;
data = allocate(rows,cols);

}
template<class T>
Matrix<T>::Matrix(int _rows,int _cols, T* matrixptr){
rows = _rows;
cols = _cols;
data = allocate(rows,cols);
memcpy(data,matrixptr,rows*cols*sizeof(T));//copia de datos en bruto
}

/////////////////////////////////[Operadores de acceso]/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T& Matrix<T>::operator()(int row,int col){
    return this->get(row,col);
}
template<class T>
void Matrix<T>::operator<<(T* list){
//no imlementa chequeo de boundaries
    memcpy(data,list,rows*cols*sizeof(T));//copia los arrays de datos
}
//////////ACCESO A COLUMNAS Y FILAS////////////////
template<class T>
Row<T> Matrix<T>::row(int i){
Row<T> r(cols,&get(i,0));//introduce los datos del puntero a dicha direccion directamente puesto que son contiguos
return r;
}


template<class T>
Col<T> Matrix<T>::col(int j){
T coldata[rows];
for(int i = 0;i < rows; coldata[i++]= get(i,j));
Col<T> c(rows,coldata);//Crea Matriz c de tamaño de las columnas de la matriz
return c;
}



template<class T>
void Matrix<T>::setcol(int j,Col<T> _col){
if(_col.rows == this->rows){
    for(int i = 0;i < rows; get(i++,j) = _col.data[i]);//Ojo al orden de ejecucion de la asignacion, primero se ejecuta el segundo
    }else{
        throw inv_size(_col.rows,_col.cols,rows,cols);
    }

}


template<class T>
void  Matrix<T>::setrow(int i, Row<T> _row){
    if(_row.cols == this->cols){
        memcpy(&get(i,0),_row.data,sizeof(T)*_row.cols);
    }else{
        throw inv_size(_row.rows,_row.cols,rows,cols);
    }
}



//////////////////////////////////[Miscelaneo]///////////////////////////////////////////////////////
template<class T>
void Matrix<T>::print(){
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
Matrix<U> operator+(Matrix<U> a, Matrix<U> b)
{
    if(a.rows == b.rows && a.cols == b.cols ){//Si esta permitida
            Matrix<U> c(a.rows,b.cols);
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
Matrix<U> operator*(Matrix<U> a, Matrix<U> b){
    if(a.cols == b.rows){
        Matrix<U> c(a.rows,b.cols);//crea matriz resultado
         for(int i= 0; i < c.rows; i++){
                    for(int j = 0; j < c.cols; j++){
                        for(int k = 0; k < a.cols;k++){
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
Matrix<U> operator*(U a, Matrix<U> b){
    for(int i= 0; i < b.rows; i++){
            for(int j = 0; j < b.cols; j++){
                b(i,j) = a* b(i,j);//Operation
            }
        }
    return b;
  
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*Cosas importantes a implementar
Submatrices

Implementar asignador de columnas y de aqui se puede construir una matriz por columnas facilmente
3-Metodo de Gauss en archivo distinto, ha de trabajar con la interfaz proporcionada por la clase matriz, aprovechar la interfaz de manera que sirva para el calculo de inversas
3bis-Por tanto implementar acceso a fila y reorganizacion para pivotamiento parcial
*/
#endif
