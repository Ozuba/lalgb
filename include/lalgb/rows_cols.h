#ifndef ROWS_COLS_H
#define ROWS_COLS_H


using namespace std;

//la memoria reservada permite usar directamente el operador << para introducir datos ya que en ambos casos los huecos de memoria son contiguos al ser unidimensional
template<class T> class Matrix;





template<class T>
class Row : public Matrix<T> {
    public:
        Row(int _col) : Matrix<T>(1,_col){};//llama al constructor base con los argumentos
        Row(int _col,T* rowptr) : Matrix<T>(1,_col,rowptr){};//Construye la columna y apunta a la direccion dada
        
        void print();//redefinimos el operador impresión
};

template<class T>
class Col : public Matrix<T> {
    public:
        Col(int _row) : Matrix<T>(_row,1){};//llama al constructor base para matriz vacia
        Col(int _row,T* colptr) : Matrix<T>(_row,1,colptr){};
};



///////////////////////////////////////////////////[ROWS]/////////////////////////////////////////////////////////////////////
template<class T>
void Row<T>::print(){
cout << '\n';//Nueva linea
    for(int j = 0; j < this->cols; j++)
    {
            cout << this->get(0,j) << " " ;
    }
    cout << '\n';//Nueva linea

}

///////////////////////////////////////////////////[COLS]/////////////////////////////////////////////////////////////////////


#endif
