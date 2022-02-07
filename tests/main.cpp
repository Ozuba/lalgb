#include <stdio.h>
#include <iostream>
#include "../include/lalgb.h"

using namespace std;


Matrix<int> a(3,3);
Col<int> b(3);

int ad[10] = {1,2,3,
              4,5,6,
              7,8,9};

int coldata[] = {1,6,2};

int main(){
  
a << ad;// volcar contenidos de la matriz
b << coldata;

a.print();
b.print();
Col<int> c = a.col(2);
a.setcol(1,c);
try{
   
(a).print();
cout << "HOla";
}catch(MatrixError error){
cout << error.watch();
    
}

    
}