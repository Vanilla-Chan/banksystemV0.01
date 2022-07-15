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



//banksystem

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
		return Benutzer(0,"","","","","");
		cout << "Exception Caught \n";
	}
	return mBenutzer.at(id);
}

void Banksystem::speichereBenutzerInDatei() {

	ofstream outFile;
	outFile.open("benutzer.txt");
	if(outFile.fail()){
		cout << "date konnte nicht geoeffnet werden!" << endl;
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
				outFile << mBenutzer.at(a).getGeburtsdatum();

			}else{}

		}

	}
	outFile.close();

}

void Banksystem::ladeBenutzerAusDatei(){
	ifstream inFile;
	int id;
	string line, name, nachname, telefonnummer, adresse, geburtsdatum;
	inFile.open("benutzer.txt");
	if(inFile.fail()){
		cout << "konnte datei nicht oeffnen" << endl;
	}else{
		while(getline(inFile, line)){
			istringstream stream(line);
			if(!(stream >> id >> name >> nachname >> telefonnummer >> adresse >> geburtsdatum)){
				throw runtime_error("invalid data");
			}
			ladeBenutzerInMap(Benutzer(id,name,nachname,telefonnummer,adresse,geburtsdatum));
		}
	}

}

void Banksystem::ladeBenutzerInMap(Benutzer benutzer) {
	this->mBenutzer.insert(std::pair<int,Benutzer>(benutzer.getID(), benutzer));
}
