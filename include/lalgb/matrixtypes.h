#ifndef MATRIXTYPES_H
#define MATRIXTYPES_H

#include <random>
#include "matrix.h"

// Unitaria de dimension n
template <class T>
Matrix<T> ones(int n,int m = -1)
{
    if (m == -1)
    {
        m = n;
    }
    Matrix<T> ones(n, n);
    int i = -1;
    while (i++ < n)
    {
        ones(i, i) = static_cast<T> (1);
    }
    return ones;
}


// Random Matrix
Matrix<float> rand(int n, int m = -1)
{   
    if (m == -1)
    {
        m = n;
    }
    Matrix<float> rnd(n,m);
    for (int i = 0; i < rnd.rown; i++)
    {
        for (int j = 0; j < rnd.coln; j++)
        {
            rnd(i,j) = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

        }
    }
    return rnd;
}

#endif