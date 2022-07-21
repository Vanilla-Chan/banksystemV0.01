#include <iostream>
#include "bankhintergrund.h"
#include "frontend.h"
#include <stdlib.h>
#include <cstdlib>

using namespace std;
int main(){

	cout << mainmenu();

	Banksystem BS;
	//BS.ladeBenutzerInMap(Benutzer(1,"jakob","hermanowski","110","berg.1","20.04.1997"));
	//BS.speichereBenutzerInDatei();
	BS.ladeBenutzerAusDatei();
	if(BS.benutzerAktiv(1)){
		cout << BS.getBenutzer(1).getNachname();
	}else{
		cout << "Nutzer existiert nicht oder ist deaktiviert!" << endl;
	}
}
/*
 * Original Implementation of Frontend
 *
 * int  mainmenu(){
	int eingabe;
	bool check = true;
	do{
	cout << "=======Banksystem V0.01======" << endl
		 << "==========Hauptmenü=========="<< endl
		 << "1)Erster Menuepunkt" << endl
		 << "2)Zweiter Menuepunkt" << endl
		 << "3)Dritter Menuepunkt" << endl
		 << "4)Vierter Menuepunkt" << endl
		 << "5)Fuenfter Menuepunkt" << endl
		 << "6)Sechster Menuepunkt" << endl
		 << "0)Adminmenue" << endl
		 << "=============================" << endl
		 << "Bitte Treffen Sie eine Auswahl ";

	cin >> eingabe;
	if(eingabe >= 1 && eingabe <=6){
		check = false;
	}
	if(eingabe == 0){
		adminmenu();
	}
	}
	while(check);

	return eingabe;
}
void adminmenu(){
	if(!login()){
		cout << "Willkommen im Adminmenü" << endl;

	}
}
int login(){
	string dbnutzer = "Admin";
	string dbpw = "passwort";
	string nutzer;
	string pw;
	int status = 1;
	int i = 0;
	 cout << "Bitte melden Sie sich mit Ihren Nutzerdaten an:" << endl;
	 while(i <3){
	 cout << "Benutzername:";
	 cin >> nutzer;
	 cout << "Passwort:";
	 cin >> pw;

	 if(dbnutzer == nutzer && dbpw == pw){
		 cout << "Sie haben sich erfolgreich angemeldet!" << endl;
				 status = 0;
				 return status;
	 }
	 i++;
	 cout << "Sie haben das Passwort bereits " << i << "mal falsch eingegeben"<< endl;
	 cout << "Sie haben " << 3-i << " Versuche uebrig" << endl;
	 }
	 cout << "Sie haben zu oft falsche Daten eingegeben!" << endl;
	 exit(1);
	 return status;

}*/
