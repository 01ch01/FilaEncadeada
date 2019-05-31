// by ch
#include <iostream>
#include <string>
using namespace std;

#ifndef PESSOA_H
#define PESSOA_H

class Pessoa {
 public:
  Pessoa();                       // construtor
  Pessoa(const Pessoa& claudio);  // construtor de cópias (método copiar)
  virtual ~Pessoa();

  void fill();
  void fillRandom(int i);  // aqui eu irei definir como o meu arquivo será salvo
  void print();
  void copy(Pessoa claudio);  // mesma coisa -_-

  void setSexo(string sexo);
  string getSexo() const;
  void setEmail(string email);
  string getEmail() const;
  void setData_nasc(string data_nasc);
  string getData_nasc() const;
  void setTel(string tel);
  string getTel() const;
  void setNome(string nome);
  string getNome() const;
  void setCpf(int cpf);
  int getCpf() const;

 private:
  string nome, tel, data_nasc, email, sexo;
  int cpf;
};

#endif /* PESSOA_H */
