#ifndef ROWS_COLS_H
#define ROWS_COLS_H


using namespace std;

//la memoria reservada permite usar directamente el operador << para introducir datos ya que en ambos casos los huecos de memoria son contiguos al ser unidimensional
template<class T> class matrix;





template<class T>
class row : public matrix<T> {
    public:
        row(int _col) : matrix<T>(1,_col){};//llama al constructor base con los argumentos
        void print();//redefinimos el operador impresión
};

template<class T>
class col : public matrix<T> {
    public:
        col(int _row) : matrix<T>(_row,1){};//llama al constructor base con los argumentos
};



///////////////////////////////////////////////////[ROWS]/////////////////////////////////////////////////////////////////////
template<class T>
void row<T>::print(){
cout << '\n';//Nueva linea
    for(int j = 0; j < this->cols; j++)
    {
            cout << this->get(0,j) << " " ;
    }
    cout << '\n';//Nueva linea

}

///////////////////////////////////////////////////[COLS]/////////////////////////////////////////////////////////////////////


#endif
