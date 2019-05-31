// by ch

#include "../include/Pessoa.h"

Pessoa::Pessoa() {  // CONSTRUTOR
  this->cpf = 0;
  this->nome = "empty";
  this->data_nasc = "empty";
  this->email = "empty";
  this->sexo = "empty";
  this->tel = "empty";
}

void Pessoa::setSexo(string sexo) {
  this->sexo = sexo;
}

string Pessoa::getSexo() const {
  return sexo;
}

void Pessoa::setEmail(string email) {
  this->email = email;
}

string Pessoa::getEmail() const {
  return email;
}

void Pessoa::setData_nasc(string data_nasc) {
  this->data_nasc = data_nasc;
}

string Pessoa::getData_nasc() const {
  return data_nasc;
}

void Pessoa::setTel(string tel) {
  this->tel = tel;
}

string Pessoa::getTel() const {
  return tel;
}

void Pessoa::setNome(string nome) {
  this->nome = nome;
}

string Pessoa::getNome() const {
  return nome;
}

void Pessoa::setCpf(int cpf) {
  this->cpf = cpf;
}

int Pessoa::getCpf() const {
  return cpf;
}

Pessoa::Pessoa(const Pessoa& claudio) {  // CONSTRUTOR DE CÓPIAS (MÉTODO COPIAR)
  this->cpf = claudio.getCpf();
  this->nome = claudio.getNome();
  this->tel = claudio.getTel();
  this->data_nasc = claudio.getData_nasc();
  this->email = claudio.getEmail();
  this->sexo = claudio.getSexo();
}

Pessoa::~Pessoa() {  // DESTRUTOR
}

void Pessoa::copy(Pessoa claudio) {
  this->cpf = claudio.getCpf();
  this->nome = claudio.getNome();
  this->tel = claudio.getTel();
  this->data_nasc = claudio.getData_nasc();
  this->email = claudio.getEmail();
  this->sexo = claudio.getSexo();
}

void Pessoa::fill() {
  cout << "\n\tINSERINDO DADOS\n";
  cout << "\tCPF: ";
  cin >> this->cpf;
  cout << "\tNome: ";
  cin >> this->nome;
  cout << "\tTelefone: ";
  cin >> this->tel;
  cout << "\tAno de nascimento: ";
  cin >> this->data_nasc;
  cout << "\tE-mail: ";
  cin >> this->email;
  do {
    cout << "\tSexo (M ou F): ";
    cin >> this->sexo;
  } while (this->sexo != "m" && this->sexo != "M" && this->sexo != "f" &&
           this->sexo != "F");
}

void Pessoa::print() {
  cout << "\n\tCPF: " << this->cpf << "\n\tNome: " << this->nome
       << "\n\tTelefone: " << this->tel
       << "\n\tAno de nascimento: " << this->data_nasc
       << "\n\tE-mail: " << this->email << "\n\tSexo: " << this->sexo << "\n";
}

void ::Pessoa::fillRandom(int i) {
  srand(i);

  this->nome = "Pessoa_" + to_string(i + 1);  // criação de nomes aleatórios
  this->cpf = rand() % 99999999999;
  int sex = rand() % 2;  // 50% M & 50% F
  if (sex == 0)
    this->sexo = 'M';
  else
    this->sexo = 'F';

  this->tel = to_string(rand() % 999999999);
  this->email = "Pessoa_" + to_string(i + 1) + "@gmail.com";
  this->data_nasc = to_string(rand() % 30 + 1985);  // vai de 1985 até 2014
}
