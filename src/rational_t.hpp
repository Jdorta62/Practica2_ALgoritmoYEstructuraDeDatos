/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file rational_t.hpp
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 06 March 2021
  * @brief programa proporcionado por el profesorado para realizar la práctica 2 de Algoritmos y estructura de datos
  * @bug ningún bug conocido
  * 
  */
#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilos [44] y [73]: primero "public" y después "private"
public:
  rational_t(const int = 0, const int = 1);
  ~rational_t() {}
  
  // pauta de estilo [71]: indentación a 2 espacios
  
  // getters
  int get_num() const;
  int get_den() const;
  
  // setters
  void set_num(const int);
  void set_den(const int);

  double value(void) const;
  rational_t opposite(void) const;
  rational_t reciprocal(void) const;

  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;

  rational_t add(const rational_t&) const;
  rational_t substract(const rational_t&) const;
  rational_t multiply(const rational_t&) const;
  rational_t divide(const rational_t&) const;

  void write(ostream& os = cout) const;
  void read(istream& is = cin);
  
private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  int num_, den_;
};


// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const rational_t&);
istream& operator>>(istream& is, rational_t&);

// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&);
rational_t operator-(const rational_t&, const rational_t&);
rational_t operator*(const rational_t&, const rational_t&);
rational_t operator/(const rational_t&, const rational_t&);

