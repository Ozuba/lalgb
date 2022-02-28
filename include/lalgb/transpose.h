#ifndef TRANSPOSE_H
#define TRANSPOSE_H

#include <stdio.h>
#include <iostream>
#include "matrix.h"

template <class T>
Matrix<T> transpose(Matrix<T> m)
{
  Matrix<T> t(m.rown, m.coln);
  for (int i = 0; i < m.rown; i++)
  {
    for (int j = 0; j < m.coln; j++)
    {
      t(i, j) = m(j, i);
    }
  }
  return t;
}
/////////////////////////////////////////////[Trasposiciones Fila-Columna]///////////////////////////////
template <class T>
Row<T> transpose(Col<T> m)
{
  Row<T> t = m;//Funciona pq los datos son contiguas en ambas
  return t;
}

template <class T>
Col<T> transpose(Row<T> m)
{
  Row<T> t = m; 
  return t;
}
#endif