#pragma once
#ifndef BANKHINTERGRUND_H_
#define BANKHINTERGRUND_H_
#include <string>
#include <vector>
#include <map>
#include <utility>

class Benutzer{
private:
  int benutzerID;
  std::string vorname;
  std::string nachname;
  std::string telefonnummer;
  std::string adresse;
  std::string geburtsdatum;
  bool geloescht;
  bool aktiv;
public:
  Benutzer(int ID, std::string iName, std::string iNachname,std::string iTelefonnummer,std::string iAdresse, std::string iGeburtsdatum);
  int getID();
  std::string getVorname();
  std::string getNachname();
  std::string getTelefonnummer();
  std::string getAdresse();
  std::string getGeburtsdatum();
  bool getGeloescht();
  bool getAktiv();

};


class Konto{
private:
  int kontonummer;
  int benutzerID;
  float kontostand;
public:
  Konto(int kontonummer,int benutzerID,float kontostand);
  Konto(std::string kontonummer,std::string benutzerID,std::string kontostand);
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
  std::string text;
public:
  Transaktion(Konto& sender,Konto& empfaenger, float betrag,std::string verwendungszweck);
  void ueberweisung(Konto& sender, Konto& empfaenger, float betrag, std::string verwendungszweck);
  void auszahlen(Konto& auskonto, float betrag);
  void einzahlen(Konto& einkonto, float betrag);
};


class Banksystem{
private:
	std::map<int,Benutzer> mBenutzer;
	std::map<int,Konto> mKonten;
	std::map<int,Transaktion> mransaktionen;
public:

	void ladeBenutzerAusDatei();
	void ladeKontosAusDatei();
	void ladeTransaktionenAusDatei();

	void speichereBenutzerInDatei();
	void speichereKontosInDatei();
	void speichereTransaktionenInDatei();

	void ladeBenutzerInMap(Benutzer);
	void ladeKontoInMap(Konto);
	void ladeTransaktionInMap(Transaktion);

	Benutzer getBenutzer(int id);
	bool benutzerExistiert(int id);
	bool benutzerAktiv(int id);
};
#endif
