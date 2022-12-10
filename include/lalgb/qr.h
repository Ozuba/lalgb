#ifndef QR_H
#define QR_H
#include "matrix.h"
#include "transpose.h"

//#define USE_GRAM_SCHMIDT // Not working

//#define USE_GRAM_SCHMIDT

#define USE_SCHWARZ_RUTISHAUSER

template <class T>
struct QR
{ // Struct to hold QR decomposition
    Matrix<T> Q;
    Matrix<T> R;

    
    QR(int _rows,int _cols){
     Matrix<T> Q(_rows,_cols);
     Matrix<T> R(_rows,_cols);
    }
  

    void print(){
        Q,print();
        R.print();

    }
};

template <class T>
QR<T> qrdecomp(Matrix<T> A)
{
    QR<T> qr(A.rown,A.coln);

    

    #ifdef USE_GRAM_SCHMIDT
    T dot;
    Col<T> proj(A.rown); // Columna proyeccion auxiliar
    Col<T> ort(A.rown); // Columna ortogonal auxiliar
    for (int j = 0; j < A.coln; j++)
    { // Por cada vector de A
        if (j > 1)
        { // Si no es el primero proyectamos sobre coln-j vectores anteriores
            for (int k = 0; k < A.coln - j; k++)
            {
                dot = transpose<T>(A.col(j)) * A.col(j - k);
                qr.R(k,j);//Ponemos los coeficientes donde tocan en R
                proj = proj +  A.col(j - k)*dot;
            }
        }
        ort = A.col(j)-proj;//Sacamos la columna ortogonal(En la primera iteracion proj es columna nula)
        dot = sqrt(transpose(ort)*ort);//Sacamos la norma del vector ortogonal
        qr.R(j,j) = dot;//Añadimos la norma a R
        A.setcol(j,ort*(1/dot));//Añadimos la columna normalizada
        


    }
    #endif


    #ifdef USE_SCHWARZ_RUTISHAUSER

    qr.Q = A;
    qr.R = zeros(A.coln);


   for (int k = 0; k < A.coln; k++){
    for(int i; i < k;i++){
        qr.R(i,k) = transpose(qr.Q.col(i)) * qr.Q.col(k);
        qr.Q.setcol = qr.Q().col(k) - qr.R(i,k) * qr.Q.col(i);
    }
    qr.R(k,k) = qr.Q.row(k);
    qr.Q.col(k) = qr.Q.col(k) / qr.R(k,k);
    }



    #endif

    


    return qr;
}

#endif