#ifndef _FRONTEND_H_
#define _FRONTEND_H_
#include <iostream>
int mainmenu();
void adminmenu(int iStatus);
int login();
inline int  mainmenu(){
	int eingabe;
	bool check = true;
	do{
	std::cout << "=======Banksystem V0.01======" << std::endl
		 << "==========Hauptmenü=========="<< std::endl
		 << "1)Erster Menuepunkt" << std::endl
		 << "2)Zweiter Menuepunkt" << std::endl
		 << "3)Dritter Menuepunkt" << std::endl
		 << "4)Vierter Menuepunkt" << std::endl
		 << "5)Fuenfter Menuepunkt" << std::endl
		 << "6)Sechster Menuepunkt" << std::endl
		 << "0)Adminmenue" << std::endl
		 << "=============================" << std::endl
		 << "Bitte Treffen Sie eine Auswahl ";

	std::cin >> eingabe;
	if(eingabe >= 1 && eingabe <=6){
		check = false;
	}
	if(eingabe == 0){
		int status = login();
		adminmenu(status);
	}
	}
	while(check);

	return eingabe;
}

inline void adminmenu(int iStatus){
	int status = iStatus;

	if(!status){
		std::cout << "Willkommen im Adminmenü" << std::endl;

	}
}

inline int login(){
	std::string dbnutzer = "Admin";
	std::string dbpw = "passwort";
	std::string nutzer;
	std::string pw;
	int status = 1;
	int i = 0;
	std::cout << "Bitte melden Sie sich mit Ihren Nutzerdaten an:" << std::endl;
	 while(i <3){
		 std::cout << "Benutzername:";
		 std::cin >> nutzer;
		 std::cout << "Passwort:";
		 std::cin >> pw;

	 if(dbnutzer == nutzer && dbpw == pw){
		 std::cout << "Sie haben sich erfolgreich angemeldet!" << std::endl;
				 status = 0;
				 return status;
	 }
	 i++;
	 std::cout << "Sie haben das Passwort bereits " << i << "mal falsch eingegeben"<< std::endl;
	 std::cout << "Sie haben " << 3-i << " Versuche uebrig" << std::endl;
	 }
	 std::cout << "Sie haben zu oft falsche Daten eingegeben!" << std::endl;
	 std::exit(1);
	 return status;
}

#endif /* FRONTEND_H_ */
