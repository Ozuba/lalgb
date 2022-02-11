#ifndef GAUSSJORDAN_H
#define GAUSSJORDAN_H

#include <stdio.h>
#include <iostream>
#include "matrix.h"
#include "mexceptions.h"

// Implementar opcion a pivotamiento parcial partialsolve() y comprobacion de sistemas mal condicionados(hay que implementar todo el set de valores singulares primero)
// Implementacion con columnas, puede ser mas eficiente trabajar directamente sobre elementos
// Ojo plantear que sea escalable, si podemos meter multiples columnas b(En forma de matriz) lo util que seria para un cambio de base


template <class T>
Col<T> solve(Matrix<T> A, Col<T> b)
{
    float gaussmul; // Preinicializacion
    for (int i = 0; i < A.rown; i++)
    {
        
        if (A(i, i) == 0.0) // El elemento diagonal de esta fila es nulo, no puede hacer 0 arriba o abajo
        {
            cout << "Mathematical Error!";
            //throw non_regular(A);// Lanzar excepción sistema no compatible determinado, si nos damos cuenta necesitamos un vector que llegue a cada dimension del espacio por eso la diagonal debe estar poblada siempre
        }
        for (int j = 0; j < A.coln; j++)
        {
            if (i != j) // El elemento no pertenece a la diagonal
            {
                gaussmul = A(j, i) / A(i, i);
               
                for (int k = 0; k < A.rown; k++) // Se aplica a todos los elementos de A
                {
                    A(j, k) = A(j, k) - gaussmul * A(i, k);
                }
                b(j, 0) = b(j, 0) - gaussmul * b(i, 0);//Se aplica La operacion a la columna
            }
        }
    }

     for(int i=0 ;i < b.rown ;i++)
     {
        b(i,0) = b(i,0)/A(i,i);//Dividimos por la diagonal
     }
    return b;
}


#endif