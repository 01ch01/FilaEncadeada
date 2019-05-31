// by ch
#include "Pessoa.h"

#include <iostream>
#include <string>
using namespace std;
#ifndef NODO_H
#define NODO_H

class Nodo {
 public:
  Nodo();
  Nodo(Pessoa& p);
  Nodo(const Nodo& orig);
  virtual ~Nodo();

  void SetItem(Pessoa item);
  Pessoa GetItem() const;
  void SetNext(Nodo* next);
  Nodo* GetNext() const;

 private:
  Pessoa item;
  Nodo* next;
};

#endif /* NODO_H */
