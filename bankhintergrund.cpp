#include "bankhintergrund.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
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



//banksystem
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

Benutzer Banksystem::getBenutzer(int id){
	int x = -1;
	try {
	  if (id > mBenutzer.size())
	  {
		  cout << "Benutzer nicht gefunden" << endl;
		  throw x;

	  }
	}
	catch (int x ) {

		cout << "Exception Caught \n";
	}
	return mBenutzer.at(id);
}
Benutzer Banksystem::getBenutzer(std::string username){
	cout << mBenutzer.at(1).getUsername();
	for(int a = 1; a <= mBenutzer.size();a++){
		if(username == mBenutzer.at(a).getUsername()){
			return	mBenutzer.at(a);
		}
	}
	return	mBenutzer.at(-1);
}
void Banksystem::speichereBenutzerInDatei() {

	ofstream outFile;
	outFile.open("benutzer.txt");
	if(outFile.fail()){
		cout << "Datei konnte nicht geoeffnet werden!" << endl;
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
				outFile << mBenutzer.at(a).getGeburtsdatum() << endl;

			}else{}

		}

	}
	outFile.close();

}

void Banksystem::ladeBenutzerAusDatei(){
	ifstream inFile;
	int id;
	string line, name, nachname, telefonnummer, adresse, geburtsdatum;
	inFile.open("banksystemV0.01/benutzer.txt");
	if(inFile.fail()){
		cout << "konnte datei nicht oeffnen" << endl;
	}else{
		while(getline(inFile, line)){
			istringstream stream(line);
			if(!(stream >> id >> name >> nachname >> telefonnummer >> adresse >> geburtsdatum)){
				throw runtime_error("invalid data");
			}
			ladeBenutzerInMap(Benutzer(id,name,nachname,telefonnummer,adresse,geburtsdatum,"test","",1));


		}
	}

}

void Banksystem::ladeBenutzerInMap(Benutzer benutzer) {
	this->mBenutzer.insert(std::pair<int,Benutzer>(benutzer.getID(), benutzer));
}

std::string Benutzer::getUsername() {
	return this->username;
}

std::string Benutzer::getPasswort() {
}

int Benutzer::getAdmin() {
}
