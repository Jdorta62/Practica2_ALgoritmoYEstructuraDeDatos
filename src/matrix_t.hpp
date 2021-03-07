/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file matrix_t.hpp
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 06 March 2021
  * @brief programa proporcionado por el profesorado para realizar la práctica 2 de Algoritmos y estructura de datos
  * @bug ningún bug conocido
  * 
  */
#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

template<class T>
class matrix_t {
 public:
  matrix_t(const int = 0, const int = 0);
  ~matrix_t();
  
  void resize(const int, const int);
  
  // getters
  int get_m(void) const;
  int get_n(void) const;
  
  // getters-setters
  T& at(const int, const int);
  T& operator()(const int, const int);
  
  // getters constantes
  const T& at(const int, const int) const;
  const T& operator()(const int, const int) const;
  
  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&);

  void write(ostream& = cout) const;
  void read(istream& = cin);

 private:
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_;
  
  int pos(const int, const int) const;
};


/**
 * @brief constructor de la clase matrix:t
 * @param m filas de la matriz
 * @param n columnas de la matriz
 */
template<class T>
matrix_t<T>::matrix_t(const int m, const int n) { 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}


/**
 * @brief destructor de la clase matrix_t
 */
template<class T> 
matrix_t<T>::~matrix_t(){
}


/**
 * @brief funcion que permite darle una nueva dimensión a la matriz
 * @param m cantidad de filas que se le quiere dar a la matriz
 * @param n cantidad de columnas que se le quiere dar a la matriz
 */
template<class T>
void matrix_t<T>::resize(const int m, const int n) {
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}


/**
 * @brief método que retorna el número de filas de un objeto matrix_t (getter)
 */
template<class T>
inline int matrix_t<T>::get_m() const {
  return m_;
}


/**
 * @brief método que retorna el número de columnas de un objeto matrix_t (getter)
 */
template<class T>
inline int matrix_t<T>::get_n() const {
  return n_;
}


/**
 * @brief método que retorna el valor de una posición determinada dentro de la matriz y puede sobreescribir este valor
 * @param i indica la fila donde se quiere saber el valor
 * @param j indica la columna donde se quiere saber el valor
 */
template<class T>
T& matrix_t<T>::at(const int i, const int j) {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}


/**
 * @brief tiene la misma funcion del método "at" pero se logra a traves de la sobrecarga del operador ()
 * @param i fila donde se quiere saber el valor
 * @param j columna donde se quiere saber el valor
 */
template<class T>
T& matrix_t<T>::operator()(const int i, const int j) {
  return at(i, j);
}


/**
 * @brief método que retorna el valor de una posición determinada dentro de la matriz (no permite sobreescribir)
 * @param i indica la fila donde se quiere saber el valor
 * @param j indica la columna donde se quiere saber el valor
 */
template<class T>
const T& matrix_t<T>::at(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}


/**
 * @brief tiene la misma funcion del método "at" pero se logra a traves de la sobrecarga del operador () (no permite sobreescribir)
 * @param i fila donde se quiere saber el valor
 * @param j columna donde se quiere saber el valor
 */
template<class T>
const T& matrix_t<T>::operator()(const int i, const int j) const {
  return at(i, j);
}



template<class T>
void matrix_t<T>::write(ostream& os) const { 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}



template<class T>
void matrix_t<T>::read(istream& is) {
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}

/**
 * @brief retorna la posición que ocuparía una coordenada i j de una matriz en el vector donde están almacenados estos valores.
 * @param i coordenada i que indica la fila exacta.
 * @param j coordenada j que indica la columna exacta.
 */
template<class T>
inline int matrix_t<T>::pos(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}



// FASE III: producto matricial
/**
 * @brief método de la clase matrix_t que retorna el resultado de la multiplicación de 2 matrices
 * @param A primera matriz a multiplicar
 * @param B segunda matriz a multiplicar
 */
template<class T>
void matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B) {
  assert(A.get_n() == B.get_m());
  resize(A.get_m(), B.get_n());
  for (int i{1}; i <= A.get_m(); ++i) {
    for (int j{1}; j <= B.get_n(); ++j) {
      T result_of_operations{0};
      for (int k{1}; k <= B.get_m(); ++k) {
        result_of_operations = result_of_operations + (A.at(i,k)*B.at(k,j));
      }
      at(i,j) = result_of_operations;
    }
  }
}
