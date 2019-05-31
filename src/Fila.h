// by ch

#include <iostream>
#include <string>
#include "Nodo.h"
#include "Pessoa.h"
using namespace std;

#ifndef FILA_H
#define FILA_H

class Fila {
 public:
  Fila();
  Fila(const Fila& orig);
  virtual ~Fila();

  void insert();  // feito
  void remove();  // feito

  bool isEmpty();  // feito
  void print();    // feito

  Nodo* getElemento(int index);  // feito
  void search();                 // feito

  // trabalhando com arquivos salvos '-'
  void loadLista();
  void saveLista();

  // sobrecarga necessária para preencher a fila aleatoriamente
  void insert(Pessoa p);
  void fillRandom();

  // getters & setters
  void setHead(Nodo* head);
  Nodo* getHead() const;
  void setQuant(int quant);
  int getQuant() const;

 private:
  int quant;
  Nodo* head;
};

#endif /* FILA_H */
