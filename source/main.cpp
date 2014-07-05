/*
Allgemeiner Keybinder zum Testen
(c) by elyday (2014)
*/

// Include
#include <iostream>
#include <ctime>
#include <Windows.h>
#include "main.h"

// Namespaces
using namespace std;

// Variablen
time_t keypresstime;

// Prototypes
int KeyPressed(BYTE);

// Main
int main() {
	cout << "Mit F3 kannst du dir alle noetigen Sachen ausgeben lassen\n(Spieler Name, Leben, Ruestung, Derzeitige Waffen ID, Server IP)." << endl << endl;
	while (true) {
		if (KeyPressed(VK_F3) && time(0) > keypresstime) {
			//
			char user[25] = { 0 };
			char *p = (char*)user;
			API_GetPlayerName(p);
			//
			char serverip[25] = { 0 };
			char *p2 = (char*)serverip;
			API_GetServerIP(p2);
			//
			cout << "-------------------------------------------------------" << endl;
			cout << "Dein Spieler Name lautet: " << user << endl;
			cout << "Leben: " << API_GetPlayerHealth() << endl;
			cout << "Ruestung: " << API_GetPlayerArmour() << endl;
			cout << "Server IP: " << serverip << endl;

			keypresstime = time(0) + 1;
		}
	}

	return 0;
}

int KeyPressed(BYTE keyboardKey) {
	return((GetAsyncKeyState(keyboardKey) & (1 << 16)) != 0);
}