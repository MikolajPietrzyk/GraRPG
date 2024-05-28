#include <iostream>
using namespace std;
#include "PostacieRPG.h"

int main(int argc, char** argv) {

	Postac postac;
	Postac postac2("Sanji", 10, 50, 50);
	TworzeniePostaci tworzenie;
	Enemy przeciwnik("Bob", 10, 50, 50, 100);
    Walka walka;
	
	//przeciwnik.generateEnemy();
	przeciwnik.wypisanieUmiejetnosci();
	//postac.wypisanieUmiejetnosci();
	postac2.wypisanieUmiejetnosci();
	//tworzenie.createCharacter(&postac, 100);
	//postac.wypisanieUmiejetnosci();
    walka.walka(&postac2, &przeciwnik);
	
	return 0;
}