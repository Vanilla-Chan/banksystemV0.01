
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
public:
  Benutzer();
};
class Konto{
private:
  int kontonummer;
  int benutzerID;
  float kontostand;
};
class Ueberweisung{
private:
  int sendkontoID;
  int empfkontoID;
  float betrag;
  std::string verwendungszweck;
};
class Banksystem{
private:
  vector<Benutzer> Kunden;
  vector<Konto> Konten;
  vector<Ueberweisung> Ueberweisungen;
};
#endif
