#include <stdio.h>
#include <iostream>
#include "mexceptions.h"
using namespace std;




template<class T>
class matrix{

    private:
    int rows, cols;//Implementar acceso publico
    T* data; //Puntero a datos matriz
    T* allocate(int _rows, int _cols);
    
    inline T& get(int row,int col){return data[row*cols+col];};//Internal access function

    public:
    //Constructores
    matrix(int _rows, int _cols);//constructor por defecto

    //Acceso y representacion
    T& operator()(int row,int col);
    void print();

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
matrix<U> operator+(U a, matrix<U> b){
    for(int i= 0; i < a.rows; i++){
            for(int j = 0; j < a.cols; j++){
                b(i,j) = a* b(i,j);//Operation
            }
        }
    return b;
  
}