// by ch

#include <iostream>
#include <string>
#include "Fila.h"
#include "Nodo.h"
#include "Pessoa.h"

using namespace std;

void menu() {
  cout << "\n\t-------------------------------------";
  cout << "\n\t\t   MENU PRINCIPAL";
  cout << "\n\t-------------------------------------";
  cout << "\n\t1 - Cadastrar pessoa;"
          "\n\t2 - Buscar pessoa;"
          "\n\t3 - Mostrar todas as pessoas;"
          "\n\t4 - Preencher lista aleatória;"
          "\n\t5 - Salvar lista;"
          "\n\t6 - Excluir pessoa;"
          "\n\t7 - Carregar lista salva;"
          "\n\tQ - Sair.";
  cout << "\n\t-------------------------------------";
  cout << "\n\tINSIRA SUA OPÇÃO: ";
}

int main(int argc, char** argv) {
  Fila lista;
  char op;
  lista.loadLista();
  lista.print();

  do {
    menu();
    cin >> op;
    switch (op) {
      case '1':
        lista.insert();
        break;

      case '2':
        lista.search();
        break;

      case '3':
        lista.print();
        break;

      case '4':
        lista.fillRandom();
        break;

      case '5':
        lista.saveLista();
        break;

      case '6':
        lista.remove();
        break;

      case '7':
        lista.loadLista();
        break;

      case 'q':
      case 'Q':
        break;

      default:
        cout << "\n\tERRO! Favor inserir uma opção válida.\n";
    }
  } while (op != 'q' && op != 'Q');

  return 0;
}
