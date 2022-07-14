#include <iostream>
#include "bankhintergrund.h"
#include <stdlib.h>
#include <cstdlib>
using namespace std;
void mainmenu();
int main(){
	mainmenu();
}
void mainmenu(){
	//system("clear");
	cout << "==========Hauptmenü=========="<< endl
		 << "\t1)Erster Menuepunkt" << endl
		 << "\t2)Zweiter Menuepunkt" << endl
		 << "\t3)Dritter Menuepunkt" << endl
		 << "\t4)Vierter Menuepunkt" << endl
		 << "\t5)Fuenfter Menuepunkt" << endl
		 << "\t6)Sechster Menuepunkt" << endl
		 << "=============================";
	char delscreen;
	cin >> delscreen;
	cout <<"\033c";
	return;
}
