#include <stdio.h>
#include <iostream>
#include <exception>

using namespace std;


class inv_size : public exception
{
    private:
    char error[100];//No es ideal reimplementar errores en un futuro
    public:
    inv_size(int r1 ,int c1,int r2,int c2) throw() {
    sprintf(error,"Different matrix sizes: m1:%dx%d  m2:%d,%d",r1,c1,r2,c2);
    }

    const char * what () const throw ()
    {
    	return error;
    }
};

class inc_size : public exception
{
    private:
    char error[100];//No es ideal reimplementar errores en un futuro
    public:
    inc_size(int r1 ,int c1,int r2,int c2) throw() {
    sprintf(error,"Incompatible Matrix Sizes for Product: m1:%dx%d  m2:%d,%d",r1,c1,r2,c2);
    }

    const char * what () const throw ()
    {
    	return error;
    }
};
