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
  std::string username;
  std::string passwort;
  int admin;
public:
  Benutzer(int ID, std::string iName, std::string iNachname,std::string iTelefonnummer,std::string iAdresse, std::string iGeburtsdatum, std::string iUsername,std::string iPasswort,int admin);
  int getID();
  std::string getVorname();
  std::string getNachname();
  std::string getTelefonnummer();
  std::string getAdresse();
  std::string getGeburtsdatum();
  std::string getUsername();
  std::string getPasswort();
  bool getGeloescht();
  bool getAktiv();
  int getAdmin();
  bool ueberpruefePasswort(std::string passwort);
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
  int transaktionsID;
  int typ; // 1 einzalung //2 Auszahlung // 3 ueberweisung
  int sendkontoID;
  int empfkontoID;
  float betrag;
  std::string verwendungszweck;
public:
  Transaktion(int transaktionsid,int senderid,int empfaengerid, float betrag,std::string verwendungszweck,int typ);
  void ueberweisung(Konto& sender, Konto& empfaenger, float betrag, std::string verwendungszweck);
  int getTransaktionsid();
  int getSendkontoid();
  int getEmpfkontoid();
  float getBetrag();
  int getTyp();
  std::string getVerwendungszweck();
  void auszahlen(Konto& auskonto, float betrag);
  void einzahlen(Konto& einkonto, float betrag);
};


class Banksystem{
private:
	std::map<int,Benutzer> mBenutzer;
	std::map<int,Konto> mKonten;
	std::map<int,Transaktion> mTransaktionen;
public:
	void addbenutzer(Benutzer);
	void clearbenutzer(int benutzerID);
	void addKonto(Konto);
	void clearKonto(int kontoID);

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
	Benutzer getBenutzer(std::string userName);
	bool benutzerExistiert(int id);
	bool benutzerExistiert(std::string userName);
	bool benutzerAktiv(int id);

	Konto getKonto(int Kontonummer);
	Transaktion getTransaktion(int transaktionsid);
};
std::string printstring(std::string input);
std::string readstring(std::string input);
#endif
