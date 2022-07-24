#ifndef _FRONTEND_H_
#define _FRONTEND_H_
#include <iostream>
int mainmenu();
void adminmenu();
int login();
int geldautomat();
class frontenduser{ //temporary to check function of login
private:
	std::string username;
	std::string passwort;
	int admin;
public:
	frontenduser(std::string iUsername,std::string iPasswort,int admin){
	username = iUsername;
	passwort = iPasswort;
	this->admin = admin;
}
	std::string getusername(){
		return username;
	};
	std::string getpasswort(){
		return passwort;
	}
	int getadmin(){
		return admin;
	}
};
int mainmenu(){
	int eingabe;
	bool check = true;
	do{
	std::cout << "=======Banksystem V0.01======" << std::endl
		 << "==========Hauptmenü=========="<< std::endl
		 << "1)Lade Dateien" << std::endl
		 << "2)Testbenutzer laden" << std::endl
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
		switch(status){
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 0:
			adminmenu();
			break;
		default:
			exit(1);
			break;
		}

	}
	}
	while(check);
}

inline void adminmenu(){
		std::cout << "Willkommen im Adminmenü" << std::endl;
		exit(1);

	}


inline int login(){
	std::vector<frontenduser> user;
	user.push_back(frontenduser("Admin","passwort",1));
	user.push_back(frontenduser("Root","root",1));
	user.push_back(frontenduser("Normalo","doof",0));
	std::string dbnutzer;
	std::string dbpw;
	std::string nutzer;
	std::string pw;
	int status = 1;
	std::cout << "Bitte melden Sie sich mit Ihren Nutzerdaten an:" << std::endl;
		 std::cout << "Benutzername:";
		 std::cin >> nutzer;
		 int nutzervalid = 1;
		 int field = -1;

		 for(int j=0;j<=user.size();j++){
			 if(nutzer == user[j].getusername()){
				 nutzervalid = 0;
				 field = j;
				 std::cout << "Benutzer gefunden: "<< std::endl;
				 std::cout <<  "Bitte Passwort:" << std::endl;
				 std::cin >> pw;

				 if(nutzervalid == 0 && user[field].getpasswort() == pw){
					 std::cout << "Sie haben sich erfolgreich angemeldet!" << std::endl;
					 status = 0;
					 if(user[field].getadmin())
					 return status;
					 else {
						 return 1;
					 }
				 }
				 else{

					 std::cout << "Sie haben das Passwort bereits " << j << "mal falsch eingegeben"<< std::endl;
					 std::cout << "Sie haben " << 3-j << " Versuche uebrig" << std::endl;
				 }

				 }
		 	 	 }
			 	 if (nutzervalid == 0){
			 		std::cout << "Benutzer nicht gefunden" << std::endl;

			 	 }

				 std::cout << "Sie haben zu oft falsche Daten eingegeben!" << std::endl;
				 std::exit(1);
				 return 0;
	 }
int geldautomat(){

return 0;
}


#endif /* FRONTEND_H_ */
