/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file vector_t.hpp
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 06 March 2021
  * @brief programa proporcionado por el profesorado para realizar la práctica 2 de Algoritmos y estructura de datos
  * @bug ningún bug conocido
  * 
  */
#pragma once

#include <iostream>
#include <cassert>

using namespace std;

template<class T>
class vector_t {
 public:
  vector_t(const int = 0);
  ~vector_t();
  
  void resize(const int);
  
  // getters
  T get_val(const int) const;
  int get_size(void) const;
  
  // setters
  void set_val(const int, const T);
  
  // getters-setters
  T& at(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  void write(ostream& = cout) const;
  void read(istream& = cin);

 private:
  T *v_;
  int sz_;
  
  void build(void);
  void destroy(void);
};


/**
 * @brief constructor de la clase vector_t.
 * @param n tamaño del vector.
 */
template<class T>
vector_t<T>::vector_t(const int n) { 
  sz_ = n;
  build();
}


/**
 * @brief destructor de la clase vector_t.
 */
template<class T>
vector_t<T>::~vector_t() {
  destroy();
}


/**
 * @brief un método al que llama el contructor para inicializar un objeto vector_t.
 */
template<class T>
void vector_t<T>::build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}


/**
 * @brief un método al que llama el destructor para destruir los residuos que pueda dejar este objeto.
 */
template<class T>
void vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}


/**
 * @brief método que permite cambiar el tamaño del vector y a su vez reservar la memoria necesaria.
 */
template<class T>
void vector_t<T>::resize(const int n) {
  destroy();
  sz_ = n;
  build();
}


/**
 * @brief método que permite conocer el valor de una posición prederteminada del vector. (getter)
 * @param i posición del vector cuyo valor se quiere conocer.
 */
template<class T>
inline T vector_t<T>::get_val(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}


/**
 * @brief método que retorna el tamaño del vector.
 */
template<class T>
inline int vector_t<T>::get_size() const {
  return sz_;
}


/**
 * @brief permite dale un valor predeterminado a una posición determinada del vector.
 * @param i posición del vector a la que se le quiere dar valor.
 * @param d nuevo valor que a tener la posición i del vector.
 */
template<class T>
void vector_t<T>::set_val(const int i, const T d) {
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}


/**
 * @brief getter-setter de la clase vector_t.
 * @param i posición del vector que se quiere conocer o sobreescribir.
 */
template<class T>
T& vector_t<T>::at(const int i) {
  assert(i >= 0 && i < get_size());
  return v_[i];
}


/**
 * @brief sobrecarga del operador []
 * @param i posición del vector
 */
template<class T>
T& vector_t<T>::operator[](const int i) {
  return at(i);
}


/**
 * @brief getter constante  de la clase vector_t.
 * @param i posición del vector que se quiere conocer.
 */
template<class T>
const T& vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}


/**
 * @brief sobrecarga constante del operador []
 * @param i posición del vector
 */
template<class T>
const T& vector_t<T>::operator[](const int i) const {
  return at(i);
}


/**
 * @brief permite imprimir en pantalla un objeto de la clase vector_t.
 */
template<class T>
void vector_t<T>::write(ostream& os) const { 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}


/**
 * @brief permite leer e inicializar un objeto vector_t a partir de una secuencia de caracteres.
 */
template<class T>
void vector_t<T>::read(istream& is) {
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}

// FASE II: producto escalar
/**
 * @brief método que permite el producto escalar de 2 vectores independientemente del tipo de dato que contenga.
 * @param v primer vector.
 * @param w segundo vector.
 */
template<class T>
T scal_prod(const vector_t<T>& v, const vector_t<T>& w) {
  T scalar_product{0};
  int smallest_vector_size;
  if (v.get_size() < w.get_size()) {
    smallest_vector_size = v.get_size();
  } else {
    smallest_vector_size = w.get_size();
  }
  for (int i{0}; i < smallest_vector_size; ++i) {
    T multiplication_result = v[i] * w[i];
    scalar_product = scalar_product + multiplication_result;
  }
  return scalar_product;
}

/**
 * @brief método que permite el producto escalar de 2 vectores que almacenen objetos de la clase rational_t.  
 * @param v primer vector.
 * @param w segundo vector.
 */
double scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w) {
  double scalar_product{0};
  int smallest_vector_size;

  if (v.get_size() < w.get_size()) {
    smallest_vector_size = v.get_size();
  } else {
    smallest_vector_size = w.get_size();
  }
  for (int i{0}; i < smallest_vector_size; ++i) {
    rational_t multiplication = v[i] * w[i];
    double multiplication_result = multiplication.value();
    scalar_product = scalar_product + multiplication_result;
  }
  return scalar_product; 
}
