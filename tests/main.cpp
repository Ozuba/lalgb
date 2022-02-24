#include <stdio.h>
#include <iostream>
#include "../include/lalgb.h"

using namespace std;

Matrix<long> a(3, 3);
Col<long> b(3);
long ad[10] = {1, 2, 3,
                4, 5, 6,
                7, 8, 4};

long coldata[] = {1, 1, 2};

int main()
{

    a << ad; // volcar contenidos de la matriz
    b << coldata;
    Matrix<float> g = rand(150);
    (a*a* a).print();
    (a^100).print();
    b.print();
 
    (solve(a,b)).print();
}