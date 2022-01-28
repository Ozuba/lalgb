#include <stdio.h>
#include <iostream>
#include "../include/matrix.h"

using namespace std;


matrix<int> a(3,3);
matrix<int> b(3,3);


int main(){
    int c = 10;

    for(int i= 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            a(i,j) = c;
            c--;
        }
    }

    for(int i= 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == j)
            b(i,j) = 2;
           
        }
    }
    

a.print();
(5 * a).print();
std::cout << "Hola mundo";
    
}