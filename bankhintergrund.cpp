#include "bankhintergrund.h"
#include <iostream>


Benutzer::Benutzer(std::string iName, std::string iNachname,
		std::string iTelefonnummer, std::string iAdresse,
		std::string iGeburtsdatum) {
	this->nachname = iName;
	this->nachname = iNachname;
	this->telefonnummer = iTelefonnummer;
	this->adresse = iAdresse;
	this->geburtsdatum = iGeburtsdatum;

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

void Banksystem::ladeBenutzerVonDatei() {
}

void Banksystem::speichereBenutzerInDatei() {
}
