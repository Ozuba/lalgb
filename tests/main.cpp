#include <stdio.h>
#include <iostream>
#include "../include/lalgb.h"

using namespace std;


matrix<int> a(3,3);
col<int> b(3);

int ad[10] = {1,2,3,
              4,5,6,
              7,8,9};

int coldata[] = {1,6,2};

int main(){
  
a << ad;// volcar contenidos de la matrizç
b << coldata;
a.print();
b.print();
try{
(b*a).print();
}catch(MatrixError error){
cout << error.watch();
    
}

    
}