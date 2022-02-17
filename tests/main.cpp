#include <stdio.h>
#include <iostream>
#include "../include/lalgb.h"

using namespace std;

Matrix<int> a(3, 3);
Col<int> b(3);
int ad[10] = {1, 2, 3,
                4, 5, 6,
                7, 8, 4};

int coldata[] = {1, 1, 2};

int main()
{

    a << ad; // volcar contenidos de la matriz
    b << coldata;
    Matrix<float> g = rand(1500);
    (g*g).print();
    b.print();
 
    (solve(a,b)).print();
}s