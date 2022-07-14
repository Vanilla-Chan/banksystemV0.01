#pragma once
#ifndef BANKHINTERGRUND_H_
#define BANKHINTERGRUND_H_
#include <string>
#include <vector>
#include <map>


class Benutzer{
private:
  int benutzerID;
  std::string vorname;
  std::string nachname;
  std::string telefonnummer;
  std::string adresse;
  std::string geburtsdatum;
public:
  Benutzer(std::string iName, std::string iNachname,std::string iTelefonnummer,std::string iAdresse, std::string iGeburtsdatum);
  std::string getVorname();
  std::string getNachname();
  std::string getTelefonnummer();
  std::string getAdresse();
  std::string getGeburtsdatum();
};


class Konto{
private:
  int kontonummer;
  int benutzerID;
  float kontostand;
public:
  Konto(int iKontonummer,int iBenutzerID,float iKontostand);
  int getKontonummer();
  int getBenutzerID();
  float getkontostand();
  void setKontostand(float iKontostand);
};


class Transaktion{
private:
  int sendkontoID;
  int empfkontoID;
  float betrag;
  std::string verwendungszweck;
public:
  void ueberweisung(Konto& sender, Konto& empfaenger, float betrag);
  void auszahlen(Konto&, float betrag);
  void einzahlen(Konto&, float betrag);
};


class Banksystem{
private:
std::map<int,Benutzer> Kunden;
std::map<int,Konto> Konten;
std::map<int,Transaktion> Transaktionen;
};
#endif
