#include <stdio.h>
#include <iostream>
#include "../include/lalgb.h"

using namespace std;

Matrix<float> a(3, 3);
Col<long> b(3);
float ad[10] = {1, 2, 3,
                4, 5, 6,
                7, 8, 4};

long coldata[] = {1, 1, 2};

int main()
{

    a << ad; // volcar contenidos de la matriz
    b << coldata;
    Matrix<float> g = rand(150);
   
    QR<float> qr(3,3);
    qrdecomp<float>(a).print();
}