#include <iostream>
using namespace std;
#include "PostacieRPG.h"

int main(int argc, char** argv) {

// TO DO 
// umozliwic ucieczke
// dodac przedmioty
// dodac odzyskiwanie zycia
// dodac walute
// dodac zapisywanie
// sala slaw 
// dodac do postaci ilosc wygranych walk

	Postac postac;
	//Postac postac2("Sanji", 24, 56, 34);
	TworzeniePostaci tworzenie;
	Enemy przeciwnik;
    Walka walka;
	Levelowanie levelowanie;
	
	BazaDanych bazaDanych;
	
	//bazaDanych.tworzeniePliku();
	bazaDanych.odczytywanieDanych();
    
    bool dalszaGra = 0;
    int akcja;
    int wygraneWalki = 0;

    cout << "Witaj w grze RPG!!!" << endl << endl;
	cout << "1. Nowa gra." << endl;
	cout << "2. Wczytanie zapisu." << endl;
	cout << "3. Usuniecie postaci" << endl;
	cout << "Wybor: ";
	cin >> akcja;
	while (dalszaGra == 0){
		switch (akcja){		
		case 1:
			tworzenie.createCharacter(&postac, 100, bazaDanych.getListaPostaci());
			bazaDanych.zapisPostaciDoListy(&postac);
			dalszaGra = 1;
			break;

		case 2:
			bazaDanych.wypisaniePostaci();
			postac = bazaDanych.wyborPostaci();
			dalszaGra = 1;
			break;
			
		case 3:
			bazaDanych.wypisaniePostaci();
			bazaDanych.usuwanieUzytkownika();
			break;

		default:
			cout << "Podales zly znak." << endl;
		}	
	}
	
	while(dalszaGra ==1){
		cout << "Co chcesz zrobic?" << endl;
		cout << "1. Wypisanie statystyk." << endl;
		cout << "2. Walka." << endl;
		cout << "3. Pojscie do swiatyni." << endl;
		cout << "4. Pojscie do sklepu. zamkniete" << endl;
		cout << "5. Pojscie do karczmy. zamkniete" << endl;
		cout << "6. Koniec. Zapis stanu gry" << endl;
		cin >> akcja;
		cout << endl;
		
		switch (akcja){		
			case 1:
				postac.wypisanieUmiejetnosci();
				cout << "Wygrales : " << wygraneWalki << " walek a mistrz kazal Ci ich unikac." << endl << endl;
				break;
				
			case 2:
				przeciwnik.generateEnemy(&postac);
				przeciwnik.wypisanieUmiejetnosci();
				walka.walka(&postac, &przeciwnik);
				
				if(postac.getHealthPoint()<=0){
					cout << "Umarles!!!" << endl;
					dalszaGra = 0;
				}else{
					wygraneWalki += 1;
				}
				break;
			
			case 3:
				levelowanie.nowyLevel(&postac);
				break;

			case 6:
				bazaDanych.zapisDanych(postac);
				dalszaGra = 0;
				break;

			default:
				cout << "Podales zly znak" << endl;
				
		}
	}
	
	cout << "Koniec gry." << endl;
	cout << "Udalo Ci sie pokonac " << wygraneWalki << " przeciwnikow. Robi wrazenie." << endl; 
	cout << "Do zobaczenia nastepnym razem :)";
	
	//postac2.wypisanieUmiejetnosci();
    //postac2.wypisanieUmiejetnosci();
	
	return 0;
}