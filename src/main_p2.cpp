/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file main_p2.cpp
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 06 March 2021
  * @brief programa proporcionado por el profesorado para realizar la práctica 2 de Algoritmos y estructura de datos
  * @bug ningún bug conocido
  * 
  */

#include <iostream>
#include <cmath>

// pauta de estilo [41]: ficheros de cabecera agrupados y separados
#include "rational_t.hpp"

#include "vector_t.hpp"

#include "matrix_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3);

  // FASE I
  cout << "a + b: ";
  (a+b).write();

  cout << "b - a: ";
  (b-a).write();

  cout << "a * b: ";
  (a*b).write();
  
  cout << "a / b: ";
  (a/b).write();
  
  cout << endl;
  
  // FASE II
  vector_t<double> v, w;
  v.read(), v.write();
  w.read(), w.write();
  
  cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w) << endl << endl;
  
  vector_t<rational_t> x, y;
  x.read(), x.write();
  y.read(), y.write();
  
  cout << "Producto escalar de vector_t<rational_t>: " << scal_prod(x, y) << endl << endl;
  
  
  // FASE III
  matrix_t<double> A, B, C;
  A.read(), A.write();
  B.read(), B.write();
  
  C.multiply(A, B);
  cout << "Multiplicación de matrices A y B: " << endl;
  C.write();
  
  return 0;
}