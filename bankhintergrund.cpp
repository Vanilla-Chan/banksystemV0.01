#include "bankhintergrund.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
std::string readstring(std::string);
Benutzer::Benutzer(int ID, std::string iName, std::string iNachname, std::string iTelefonnummer, std::string iAdresse,std::string iGeburtsdatum, std::string iUsername,std::string iPasswort,int admin ) {
	this->benutzerID = ID;
	this->vorname = iName;
	this->nachname = iNachname;
	this->telefonnummer = iTelefonnummer;
	this->adresse = iAdresse;
	this->geburtsdatum = iGeburtsdatum;
	this->aktiv = true;
	this->geloescht = true;
	this->username = iUsername;
	this->passwort = iPasswort;
	this->admin = admin;
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
Transaktion::Transaktion(int transaktionsID, int sendkontoID,int empfkontoID, float betrag,std::string verwendungszweck,int typ){
	this->typ = typ;
	this->transaktionsID = transaktionsID;
	this->sendkontoID = sendkontoID;
	this->empfkontoID = empfkontoID;
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
int Transaktion::getTransaktionsid(){
	return transaktionsID;
}
int Transaktion::getSendkontoid(){
	return this->sendkontoID;
};
int Transaktion::getEmpfkontoid(){
	return this->empfkontoID;
};
float Transaktion::getBetrag(){
	return this->betrag;
};
std::string Transaktion::getVerwendungszweck(){
	return this->verwendungszweck;
};
int Transaktion::getTyp(){
	return this->typ;
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
				ladeBenutzerInMap(Benutzer(id,name,nachname,telefonnummer,adresse,geburtsdatum,"","",1));
			}
		}

}


bool Banksystem::benutzerAktiv(int id) {
	if(benutzerExistiert(id)){
		if(mBenutzer.at(id).getAktiv()){
			return true;
		}
		return false;
	}
}

void Banksystem::ladeKontosAusDatei(){
	std::ifstream inFile;
	int kontonummer, benutzerID;
	float kontostand;
	std::string line;
	inFile.open("banksystemV0.01/konten.txt");
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

void Banksystem::ladeTransaktionenAusDatei(){
	std::ifstream inFile;
	int transaktionsid, senderid,empfaengerid,typ;
	float betrag;
	std::string line, verwendungszweck;
	inFile.open("banksystemV0.01/transaktionen.txt");
		if(inFile.fail()){
			std::cout << "konnte Datei nicht oeffnen" << std::endl;
		}
		else{
			while(getline(inFile, line)){
				std::istringstream stream(line);
				if(!(stream >> transaktionsid >> senderid >> empfaengerid >> betrag >> verwendungszweck >> typ)){
					throw std::runtime_error("invalid data");
				}
				ladeTransaktionInMap(Transaktion(transaktionsid, senderid,empfaengerid,betrag,verwendungszweck,typ));
			}
		}

}


void Banksystem::speichereBenutzerInDatei(){

std::ofstream outFile;
outFile.open("banksystemV0.01/benutzer.txt");
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

}

Benutzer Banksystem::getBenutzer(std::string username){
	std::cout << mBenutzer.at(1).getUsername();
	for(int a = 1; a <= mBenutzer.size();a++){
		if(username == mBenutzer.at(a).getUsername()){
			return	mBenutzer.at(a);
		}
	}
	return	mBenutzer.at(1);
}

void Banksystem::speichereKontosInDatei(){
	std::ofstream outFile;
	outFile.open("banksystemV0.01/konten.txt");
	if(outFile.fail()){
		std::cout << "Datei konnte nicht geoeffnet werden!" << std::endl;
	}
	else{
		for(long long unsigned int a = 1; a < this->mKonten.size()+1; a++){

			//ueberpruefen ob Nutzer geloescht ist

			if(mKonten.at(a).getKontonummer() != 0){
				outFile << mKonten.at(a).getKontonummer() << " ";
				outFile << mKonten.at(a).getBenutzerID() << " ";
				outFile << mKonten.at(a).getkontostand() << std::endl;

			}else{}

		}

	}
	outFile.close();

}


void Banksystem::speichereTransaktionenInDatei(){
	std::ofstream outFile;
	outFile.open("banksystemV0.01/konten.txt");
	if(outFile.fail()){
		std::cout << "Datei konnte nicht geoeffnet werden!" << std::endl;
	}
	else{
		for(long long unsigned int a = 1; a < this->mTransaktionen.size()+1; a++){

			//ueberpruefen ob Nutzer geloescht ist

			if(mTransaktionen.at(a).getTransaktionsid() != 0){
				outFile << mTransaktionen.at(a).getTransaktionsid() << " "
						<< mTransaktionen.at(a).getSendkontoid() << " "
						<< mTransaktionen.at(a).getEmpfkontoid() << " "
						<< mTransaktionen.at(a).getBetrag() << " "
						<< mTransaktionen.at(a).getVerwendungszweck() << std::endl;

			}else{}

		}

	}
	outFile.close();

}


void Banksystem::ladeBenutzerInMap(Benutzer benutzer) {
	this->mBenutzer.insert(std::pair<int,Benutzer>(benutzer.getID(), benutzer));
}

void Banksystem::ladeKontoInMap(Konto konto){
	this->mKonten.insert(std::pair<int,Konto>(konto.getKontonummer(), konto));
};


void Banksystem::ladeTransaktionInMap(Transaktion transaktion){
	this->mTransaktionen.insert(std::pair<int,Transaktion>(transaktion.getTransaktionsid(),transaktion));
};


Benutzer Banksystem::getBenutzer(int id){

  	  if (id > mBenutzer.size())
  	  {
  		  std::cout << "Benutzer nicht gefunden" << std::endl;


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

Transaktion Banksystem::getTransaktion(int transaktionsid){
	if (transaktionsid > mTransaktionen.size())
	  	  {
	  		  std::cout << "Transaktion nicht gefunden" << std::endl;


	  	  }


	  	return mTransaktionen.at(transaktionsid);

};

std::string Benutzer::getUsername() {
	return username;
}

std::string Benutzer::getPasswort() {
	return passwort;
}
// New Stuff to make Strings readable after Saving and Reading from file not working yet
std::string printstring(std::string input){
	std::string printable = input;
	printable.replace(printable.find(" "), 2, "_");
	return printable;
}
std::string readstring(std::string input){
	std::string readable = input;
	int index = readable.find(" ");
	std::cout << index;
	// readable.replace(index,1," ");
	return readable;
}

