#include "bankhintergrund.h"
#include <iostream>
#include <fstream>

using namespace std;
Benutzer::Benutzer(std::string iName, std::string iNachname,
		std::string iTelefonnummer, std::string iAdresse,
		std::string iGeburtsdatum) {
	this->nachname = iName;
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
void Banksystem::ladeBenutzerAusDatei() {

}


void Banksystem::speichereBenutzerInDatei() {

	ofstream outFile;
	outFile.open("benutzer.txt");
	if(outFile.fail()){
		cout << "date konnte nicht geoeffnet werden!" << endl;
	}
	else{
		for(long long unsigned int a = 0; a < this->mBenutzer.size(); a++){
			//ueberpruefen ob Nutzer geloescht ist
			if(mBenutzer.at(a).getVorname() != ""){

				outFile << mBenutzer.at(a).getID() << "";
				outFile << mBenutzer.at(a).getVorname() << "";
				outFile << mBenutzer.at(a).getNachname() << "";
				outFile << mBenutzer.at(a).getTelefonnummer() << "";
				outFile << mBenutzer.at(a).getAdresse() << "";
				outFile << mBenutzer.at(a).getGeburtsdatum();

			}else{}

		}

	}
	outFile.close();

}

void Banksystem::ladeBenutzerInMap(Benutzer benutzer) {
	this->mBenutzer.insert(std::pair<int,Benutzer>(benutzer.getID(), benutzer));
}
