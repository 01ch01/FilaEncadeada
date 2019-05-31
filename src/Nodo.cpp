// by ch
#include "../include/Nodo.h"

Nodo::Nodo() {
  this->next = NULL;
}

Nodo::Nodo(Pessoa& p) {
  this->item.copy(p);
  this->next = NULL;
}

Nodo::Nodo(const Nodo& orig) {
  this->item.copy(orig.GetItem());
}

Nodo::~Nodo() {}

void Nodo::SetItem(Pessoa item) {
  this->item = item;
}

Pessoa Nodo::GetItem() const {
  return item;
}

void Nodo::SetNext(Nodo* next) {
  this->next = next;
}

Nodo* Nodo::GetNext() const {
  return next;
}
