
#pragma once
#ifndef BANKHINTERGRUND_H_
#define BANKHINTERGRUND_H_
#include <string>
#include <vector>
class Benutzer{
private:
  int benutzerID;
  std::string name;
  std::string nachname;
  std::string telefonnummer;
  std::string adresse;
  std::string geburtsdatum;

};

class Konto{
  int kontonummer;
  int benutzerID;
  float kontostand;

};
class Ueberweisugn{};
class Banksystem{
private:
  vector<Benutzer> USER;
  vector<Konto> KONTEN;

};
#endif
