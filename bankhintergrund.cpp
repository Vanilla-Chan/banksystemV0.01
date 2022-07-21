#include "bankhintergrund.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
Benutzer::Benutzer(int ID, std::string iName, std::string iNachname,
		std::string iTelefonnummer, std::string iAdresse,
		std::string iGeburtsdatum) {
	this->benutzerID = ID;
	this->vorname = iName;
	this->nachname = iNachname;
	this->telefonnummer = iTelefonnummer;
	this->adresse = iAdresse;
	this->geburtsdatum = iGeburtsdatum;
	this->aktiv = true;
	this->geloescht = true;
}
int Benutzer::getID() {
	return this->benutzerID;
}
std::string Benutzer::getVorname() {
	return this->vorname;
}

std::string Benutzer::getNachname() {
	return this->nachname;
}

std::string Benutzer::getTelefonnummer() {
	return this->telefonnummer;
}

std::string Benutzer::getAdresse() {
	return this->adresse;
}

std::string Benutzer::getGeburtsdatum() {
    return this->geburtsdatum;
}
bool Benutzer::getGeloescht() {
	return this->geloescht;
}

bool Benutzer::getAktiv() {
	return this->aktiv;
}


//Konto

Konto::Konto(int kontonummer,int benutzerID,float kontostand){
this->kontonummer = kontonummer;
this->benutzerID = benutzerID;
this->kontostand = kontostand;
};
//Konto::Konto(std::string kontonummer,std::string benutzerID,std::string kontostand){
//	this->kontonummer = int(kontonummer);
//	this->benutzerID = int(benutzerID);
//	this->kontostand = float(kontostand);
//}
int Konto::getBenutzerID(){
	return this->benutzerID;
}
int Konto::getKontonummer(){
	return this->kontonummer;
};
float Konto::getkontostand(){
	return this->kontostand;
};
void Konto::setKontostand(float kontostand){
	this->kontostand = kontostand;
};


//Transaktion
Transaktion::Transaktion(Konto& sender,Konto& empfaenger, float betrag,std::string verwendungszweck){
	this->sendkontoID = sender.getBenutzerID();
	this->empfkontoID = empfaenger.getBenutzerID();
	this->betrag = betrag;
	this->verwendungszweck = verwendungszweck;
}
void Transaktion::ueberweisung(Konto& sender, Konto& empfaenger, float betrag, std::string verwendungszweck){
	this->sendkontoID = sender.getBenutzerID();
	this->empfkontoID = empfaenger.getBenutzerID();
	this->betrag = betrag;
	this->verwendungszweck = verwendungszweck;
}
void Transaktion::auszahlen(Konto& auskonto, float betrag){
  std::cout << "Ihr aktueller Kontostand ist " << auskonto.getkontostand() << "€" << std::endl;
  std::cout << "Sie haben " << betrag << "€ ausgezahlt" << std::endl;
  auskonto.setKontostand(auskonto.getkontostand()-betrag);
  std::cout << "Ihr neuer Kontostand beträgt" << auskonto.getkontostand() << "€" << std::endl;
}
void Transaktion::einzahlen(Konto& einkonto, float betrag){
  std::cout << "Ihr aktueller Kontostand ist " << einkonto.getkontostand() << "€" << std::endl;
	  std::cout << "Sie haben " << betrag << "€ eingezahlt" << std::endl;
	  einkonto.setKontostand(einkonto.getkontostand()+betrag);
	  std::cout << "Ihr neuer Kontostand beträgt" << einkonto.getkontostand() << "€" << std::endl;
}

//banksystem
void Banksystem::ladeBenutzerAusDatei(){
	std::ifstream inFile;
	int id;
	std::string line, name, nachname, telefonnummer, adresse, geburtsdatum;
	inFile.open("banksystemV0.01/benutzer.txt");
		if(inFile.fail()){
			std::cout << "konnte Datei nicht oeffnen" << std::endl;
		}
		else{
			while(getline(inFile, line)){
				std::istringstream stream(line);
				if(!(stream >> id >> name >> nachname >> telefonnummer >> adresse >> geburtsdatum)){
					throw std::runtime_error("invalid data");
				}
				ladeBenutzerInMap(Benutzer(id,name,nachname,telefonnummer,adresse,geburtsdatum));
			}
		}

}

void Banksystem::ladeKontosAusDatei(){
	std::ifstream inFile;
	int kontonummer, benutzerID;
	float kontostand;
	std::string line;
	inFile.open("banksystemV0.01/benutzer.txt");
		if(inFile.fail()){
			std::cout << "konnte Datei nicht oeffnen" << std::endl;
		}
		else{
			while(getline(inFile,line)){
				std::istringstream stream(line);
				if(!(stream >> kontonummer >> benutzerID >> kontostand)){
					throw std::runtime_error("invalid data");
				}
				ladeKontoInMap(Konto(kontonummer,benutzerID,kontostand));
				}
			}
		}

void Banksystem::ladeTransaktionenAusDatei(){}

void Banksystem::speichereBenutzerInDatei(){

std::ofstream outFile;
outFile.open("benutzer.txt");
if(outFile.fail()){
	std::cout << "Datei konnte nicht geoeffnet werden!" << std::endl;
}
else{
	for(long long unsigned int a = 1; a < this->mBenutzer.size()+1; a++){

		//ueberpruefen ob Nutzer geloescht ist

		if(mBenutzer.at(a).getAdresse() != ""){
			outFile << mBenutzer.at(a).getID() << " ";
			outFile << mBenutzer.at(a).getVorname() << " ";
			outFile << mBenutzer.at(a).getNachname() << " ";
			outFile << mBenutzer.at(a).getTelefonnummer() << " ";
			outFile << mBenutzer.at(a).getAdresse() << " ";
			outFile << mBenutzer.at(a).getGeburtsdatum() << std::endl;

		}else{}

	}

}
outFile.close();

}
void Banksystem::speichereKontosInDatei(){};


void Banksystem::speichereTransaktionenInDatei(){};


void Banksystem::ladeBenutzerInMap(Benutzer benutzer) {
	this->mBenutzer.insert(std::pair<int,Benutzer>(benutzer.getID(), benutzer));
}

void Banksystem::ladeKontoInMap(Konto konto){
	this->mKonten.insert(std::pair<int,Konto>(konto.getKontonummer(), konto));
};


void Banksystem::ladeTransaktionInMap(Transaktion){};


Benutzer Banksystem::getBenutzer(int id){
  	int x = -1;
  	try {
  	  if (id > mBenutzer.size())
  	  {
  		  std::cout << "Benutzer nicht gefunden" << std::endl;
  		  throw x;

  	  }
  	}
  	catch (int x ) {
  		return Benutzer(0,"","","","","");
  		std::cout << "Exception Caught \n";
  	}
  	return mBenutzer.at(id);
}

bool Banksystem::benutzerExistiert(int id) {

	  if (id > mBenutzer.size())
	  {
		  return false;
	  }else{
		  return true;
	  }
}
bool Banksystem::benutzerAktiv(int id) {
	if(benutzerExistiert(id)){
		if(mBenutzer.at(id).getAktiv()){
			return true;
		}

	}
	return false;
}





