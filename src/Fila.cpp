// by ch

#include <fstream>

#include "../include/Fila.h"

Fila::Fila() {
  this->head = NULL;
  this->quant = 0;
}

Fila::Fila(const Fila& orig) {}

Fila::~Fila() {}

void Fila::setHead(Nodo* head) {
  this->head = head;
}

Nodo* Fila::getHead() const {
  return head;
}

void Fila::setQuant(int quant) {
  this->quant = quant;
}

int Fila::getQuant() const {
  return quant;
}

bool Fila::isEmpty() {
  if (this->quant == 0)
    return true;
  else
    return false;
}

void Fila::insert() {  // na fila, o elemento é inserido na primeira posição
  Pessoa p;
  p.fill();

  Nodo* novo = new Nodo();
  novo->SetItem(p);

  if (this->isEmpty() == true) {
    this->head = novo;
    novo->SetNext(NULL);
    this->quant++;
  } else {
    this->getElemento(this->quant)->SetNext(novo);
    novo->SetNext(NULL);
    this->quant++;
  }
}

void Fila::remove() {  // na fila, o elemento é removido na primeira posição
  this->head = this->head->GetNext();
  this->quant--;
}

Nodo* Fila::getElemento(int index) {
  Nodo* nodoDesejado = this->head;  // o nó criado está no primeiro elemento

  int i = 1;
  while (i != index && nodoDesejado->GetNext() != NULL) {
    nodoDesejado = nodoDesejado->GetNext();
    i++;
  }
  if (i == index)
    return nodoDesejado;
  else
    return NULL;
}

void Fila::print() {
  cout << "\n\t__________________________________";
  cout << "\n\t\t|FILA DE PESSOAS|\n";

  if (this->isEmpty() == true)
    cout << "\n\t\tA LISTA ESTÁ VAZIA =(\n";
  else {
    Nodo* p = this->head;
    while (p != NULL) {
      p->GetItem().print();
      p = p->GetNext();
    }
  }
}

void Fila::search() {
  char op;
  Nodo* busca = this->head;
  bool flag = false;

  do {
    cout << "\n\tComo deseja realizar a busca?\n\t1 - Busca por nome;\n\t2 - "
            "Busca por CPF;\n\tInsira aqui a sua opção: ";
    cin >> op;

    if (op == '1') {
      string term;

      cout << "\n\tInsira aqui o nome que deseja buscar: ";
      cin >> term;

      for (int i = 0; busca->GetNext() != NULL; i++) {
        if (busca->GetItem().getNome() == term) {
          flag = true;
          busca->GetItem().print();
        }

        busca = busca->GetNext();
      }
      if (flag == false)
        cout << "\n\tA busca não encontrou resultados para [" << term << "].\n";

    } else if (op == '2') {
      int term;

      cout << "\n\tInsira aqui o CPF da pessoa que deseja buscar: ";
      cin >> term;

      for (int i = 0; busca->GetNext() != NULL; i++) {
        if (busca->GetItem().getCpf() == term) {
          flag = true;
          busca->GetItem().print();
        }

        busca = busca->GetNext();
      }
      if (flag == false)
        cout << "\n\tA busca não encontrou resultados para [" << term << "].\n";

    } else
      cout << "\n\tERRO! Opção inválida.Tente novamente.\n";
  } while (op != '1' && op != '2');
}

/*PARA CRIAR A FILA ALEATORIAMENTE, EU PRECISO INSTANCIAR AS PESSOAS
 *  E INSERI-LAS NA FILA ENTÃO (TÔ COM PREGUIÇA DE EXPLICAR PRA MIM)
 * EU PRECISO FAZER UMA SOBRECARGA NO MÉTODO INSERE DA FILA
 * ACHO QUE É ISSO
 */

void Fila::insert(Pessoa p) {
  Nodo* novo = new Nodo();
  novo->SetItem(p);

  if (this->isEmpty() == true) {
    this->head = novo;
    novo->SetNext(NULL);
    this->quant++;
  } else {
    this->getElemento(this->quant)->SetNext(novo);
    novo->SetNext(NULL);
    this->quant++;
  }
}

void Fila::fillRandom() {
  Pessoa p;
  int max = 0;

  cout << "\n\tQuantas pessoas deseja inserir na lista aleatoriamente? ";
  cin >> max;

  for (int i = 0; i < max; i++) {
    p.fillRandom(i);
    this->insert(p);
  }
}

void Fila::saveLista() {
  string nomeDoArquivo = "people.txt";
  ofstream arquivoSalvo;
  arquivoSalvo.open(nomeDoArquivo.c_str());

  // agora vou definir como os arquivos de texto serão salvos
  arquivoSalvo << "Quant: " << this->quant << "\n\n";
  arquivoSalvo << "\tCPF\t\tNome\t\tTel\t\tAno\tEmail\t\t\tSexo\n";

  for (int i = 1; i <= this->quant; i++) {
    arquivoSalvo << "\t" << this->getElemento(i)->GetItem().getCpf() << "\t"
                 << this->getElemento(i)->GetItem().getNome() << "\t"
                 << this->getElemento(i)->GetItem().getTel() << "\t"
                 << this->getElemento(i)->GetItem().getData_nasc() << "\t"
                 << this->getElemento(i)->GetItem().getEmail() << "\t"
                 << this->getElemento(i)->GetItem().getSexo() << "\n";
  }
}

void Fila::loadLista() {
  string nomeDoArquivo = "people.txt";
  ifstream arquivoLido;
  arquivoLido.open(nomeDoArquivo.c_str());

  int q = 0;

  arquivoLido >> q;

  string nome = "";
  string tel = "";
  string data_nasc = "";
  string email = "";
  string sexo = "";
  int cpf = 0;
  Pessoa p;

  // agora vou ler os arquivos salvos de acordo com o meu BD.txt
  for (int i = 0; i < this->quant; i++) {
    // isso são os "getters" do txt
    arquivoLido >> cpf;
    arquivoLido >> nome;
    arquivoLido >> tel;
    arquivoLido >> data_nasc;
    arquivoLido >> email;
    arquivoLido >> sexo;

    // e agora vou vou colocá-los na Pessoa p criada na linha [208]
    p.setCpf(cpf);
    p.setNome(nome);
    p.setTel(tel);
    p.setData_nasc(data_nasc);
    p.setEmail(email);
    p.setSexo(sexo);

    // e agora vou colocar esses atributos da Pessoa claudio dentro da lista que
    // foi criada na linha [208]
    this->insert(p);
  }

  arquivoLido.close();
}
