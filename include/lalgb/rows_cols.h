#ifndef ROWS_COLS_H
#define ROWS_COLS_H

using namespace std;

// la memoria reservada permite usar directamente el operador << para introducir datos ya que en ambos casos los huecos de memoria son contiguos al ser unidimensional
template <class T>
class Matrix;



template <class T>
class Col : public Matrix<T>
{
public:
    Col(int _row) : Matrix<T>(_row, 1){}; // llama al constructor base para matriz vacia
    Col(int _row, T *colptr) : Matrix<T>(_row, 1, colptr){};
};

template <class T>
class Row : public Matrix<T>
{
public:
    Row(int _col) : Matrix<T>(1, _col){};                    // llama al constructor base con los argumentos
    Row(int _col, T *rowptr) : Matrix<T>(1, _col, rowptr){}; // Construye la columna y apunta a la direccion dada
    template <class U>
    friend U operator*(Row<U> a, Col<U> b);
    void print(); // redefinimos el operador impresión
};
///////////////////////////////////////////////////[ROWS]/////////////////////////////////////////////////////////////////////
template <class T>
void Row<T>::print()
{
    cout << '\n'; // Nueva linea
    for (int j = 0; j < this->cols; j++)
    {
        cout << this->get(0, j) << " ";
    }
    cout << '\n'; // Nueva linea
}

template <class U> // PRODUCTO MATRICIAL FILA POR COLUMNA (Devuelve tipo T)
U operator*(Row<U> a, Col<U> b)
{
    if (a.coln == b.rown)
    {
        float c = 0;
        for (int k = 0; k < a.coln; k++)
        {
            c += a(0, k) * b(k, 0);
        }
        return c;
    }
    else
    {
        throw inc_size(a.rown, a.coln, b.rown, b.coln);
    }
}
///////////////////////////////////////////////////[COLS]/////////////////////////////////////////////////////////////////////

#endif
