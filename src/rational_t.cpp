/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file rational_t.cpp
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 06 March 2021
  * @brief programa proporcionado por el profesorado para realizar la práctica 2 de Algoritmos y estructura de datos
  * @bug ningún bug conocido
  * 
  */
#include "rational_t.hpp"

/**
 * @brief constructor de la clase rational_t
 * @param n numerador del objeto racional
 * @param d denominador del objeto racional
 */
rational_t::rational_t(const int n, const int d) {
  assert(d != 0);
  num_ = n, den_ = d;
}

/**
 * @brief método que retorna el numerador de un objeto racional_t (getter).
 */
inline
int rational_t::get_num() const {
  return num_;
}


/**
 * @brief método que retorna el denominador de un objeto racional_t (getter).
 */
inline int rational_t::get_den() const {
  return den_;
}


/**
 * @brief método que permite inicializar directamente el numerador de un objeto racional_t (setter).
 */
void rational_t::set_num(const int n) {
  num_ = n;
}


/**
 * @brief método que permite inicializar directamente el denominador de un objeto racional_t (setter).
 */
void rational_t::set_den(const int d) {
  assert(d != 0);
  den_ = d;
}


/**
 * @brief método que retorna el valor de la división del numerador entre el denominador.
 */
inline double rational_t::value() const { 
  return double(get_num()) / get_den();
}


/**
 * @brief retorna el racional cambiado de signo.
 */
rational_t  rational_t::opposite() const { 
  return rational_t((-1)*get_num(), get_den());
}


/**
 * @brief inicializa un racional inverso, partiendo de un racional previo que llamó a este método.
 */
rational_t rational_t::reciprocal() const { 
  return rational_t(get_den(), get_num());
}



/**
 * @brief método que permite comparar 2 racionales y determinar si son iguales.
 * @param r 2do racional con el que se va a comparar.
 * @param precision determinará la precisión a partir de la cual se consideraran 2 racionales iguales.
 */
bool rational_t::is_equal(const rational_t& r, const double precision) const { 
  return fabs(value() - r.value()) < precision;
}


/**
 * @brief método que permite comparar 2 racionales y determinar si es mayor que r.
 * @param r 2do racional con el que se va a comparar.
 * @param precision determinará la precisión a partir de la cual se considerará el racional mayor que "r".
 */
bool rational_t::is_greater(const rational_t& r, const double precision) const {
  return (value() - r.value()) > precision;
}


/**
 * @brief método que permite comparar 2 racionales y determinar si son si es mayor que r.
 * @param r 2do racional con el que se va a comparar.
 * @param precision determinará la precisión a partir de la cual se considerará el racional mayor que "r".
 */
bool rational_t::is_less(const rational_t& r, const double precision) const {
  return r.is_greater(*this, precision);
}


// operaciones
/**
 * @brief metodo que retorna la suma algebraica de 2 objetos rational_t.
 * @param r sumando de la operación.
 */
rational_t rational_t::add(const rational_t& r) const {
  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), 
                    get_den() * r.get_den());
}


/**
 * @brief metodo que retorna la resta algebraica de 2 objetos rational_t.
 * @param r sustraendo de la operación.
 */
rational_t rational_t::substract(const rational_t& r) const {
  return add(r.opposite());
}


/**
 * @brief metodo que retorna la multiplicación de 2 objetos rational_t.
 * @param r 2do factor de la operación.
 */
rational_t rational_t::multiply(const rational_t& r) const {
  return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}


/**
 * @brief metodo que retorna la división de 2 objetos rational_t.
 * @param r 2do factor de la operación.
 */
rational_t rational_t::divide(const rational_t& r) const {
  return multiply(r.reciprocal());
}











// FASE I: operadores
/**
 * @brief sobrecarga del operador + que permite la suma de 2 objetos rational_t.
 * @param a 1er sumando de la operación.
 * @param b 2do sumando de la operación.
 */
rational_t operator+(const rational_t& a, const rational_t& b) {
  int numerator, denominator;
  numerator = (b.get_den() * a.get_num()) + (a.get_den() * b.get_num());
  denominator = a.get_den() * b.get_den();
  return rational_t(numerator, denominator);
}


/**
 * @brief sobrecarga del operador - que permite la resta de 2 objetos rational_t.
 * @param a minuendo de la operación.
 * @param b sustraendo de la operación.
 */
rational_t operator-(const rational_t& a, const rational_t& b) {
  int numerator, denominator;
  numerator = (b.get_den() * a.get_num()) - (a.get_den() * b.get_num());
  denominator = a.get_den() * b.get_den();
  return rational_t(numerator, denominator);
}


/**
 * @brief sobrecarga del operador * que permite la multiplicación de 2 objetos rational_t.
 * @param a multiplicando de la operación.
 * @param b multiplicador de la operación.
 */
rational_t operator*(const rational_t& a, const rational_t& b) {
  int numerator, denominator;
  numerator = a.get_num() * b.get_num();
  denominator = a.get_den() * b.get_den();
  return rational_t(numerator, denominator);
}


/**
 * @brief sobrecarga del operador / que permite la división de 2 objetos rational_t.
 * @param a dividendo de la operación.
 * @param b divisor de la operación.
 */
rational_t operator/(const rational_t& a, const rational_t& b) {
  int numerator, denominator;
  numerator = a.get_num() * b.get_den();
  denominator = a.get_den() * b.get_num();
  return rational_t(numerator, denominator);
}



// E/S
/**
 * @brief permite imprimir en pantalla un objeto de la clase rational_t.
 */
void rational_t::write(ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}


/**
 * @brief permite leer e inicializar un objeto rational_t a partir de una secuencia de caracteres.
 */
void rational_t::read(istream& is) {
  is >> num_ >> den_;
  assert(den_ != 0);
}


/**
 * @brief sobrecarga del operador de insersión << que permite insertar en el flujo un objeto rational_t.
 * @param os variable donde se almacena la información para insertarla en el flujo.
 * @param r objeto rational_t a insertar en el flujo.
 */
ostream& operator<<(ostream& os, const rational_t& r) {
  r.write(os);
  return os;
}

/**
 * @brief sobrecarga del operador de extracción >> que permite inicializar un objeto rational_t a partir de una secuencia de caracteres.
 * @param is variable donde se almacena al información de la extracción.
 * @param r racional que va a ser inicializado.
 */
istream& operator>>(istream& is, rational_t& r) {
  r.read(is);
  return is;
}