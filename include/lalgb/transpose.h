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

#endif