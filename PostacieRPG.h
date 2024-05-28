#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

class Character{
private:
	
public:
	string name;
	int strength;
	int speed;
	int agility;
    int healthPoint;
	
Character(string defalutName = "Noname", int defalutStrength = 1, int defaultSpeed = 1, int defaultAgility = 1, int defaultHealthPoint = 100)
	:name(defalutName), strength(defalutStrength), speed(defaultSpeed), agility(defaultAgility), healthPoint(defaultHealthPoint) {}
	
		
string getName(){
	return name;
}

void setName(string n){
	name = n;
}

int getStrength(){
	return strength;
}

void setStrength(int s){
	strength = s;
}

int getSpeed(){
	return speed;
}

void setSpeed(int s){
	speed = s;
}

int getAgility(){
	return agility;
}

void setAgility(int a){
	agility = a;
}

int getHealthPoint(){
	return healthPoint;
}

void setHealthPoint(int hp){
	healthPoint = hp;
}


void wypisanieUmiejetnosci(){
	cout << "Nazwa: " << getName() << endl;
	cout << "Sila: " << getStrength() << endl;
	cout << "Predkosc: " << getSpeed() << endl;
	cout << "Zwinnosc: " << getAgility() << endl;
    cout << "Punkty zycia " << getHealthPoint() << endl << endl;
}

};

class Postac : public Character{
private:

public:

Postac(string name = "Noname", int strength = 1, int speed = 1, int agility = 1, int healthPoint = 100)
	:Character(name, strength, speed, agility, healthPoint){}
	
};

class Enemy : public Character{
private:
	vector<string> imionaPrzeciwnikow = {"Wikolak" , "Goblin" , "Wampir"};
public:

Enemy(string name = "Enemy", int strength = 1, int speed = 1, int agility = 1, int healthPoint = 100)
	:Character(name, strength, speed, agility, healthPoint){}
	
void generateEnemy(){
	srand (time(NULL));
	setName(imionaPrzeciwnikow[rand()%imionaPrzeciwnikow.size()]);
	setStrength(rand()%40+10);
	setSpeed(rand()%40+10);
	setAgility(rand()%40+10);
    setHealthPoint(rand()%100+50);
}

};

class TworzeniePostaci{
private:
	int zmiennaWartosc = 0;
	int wyborWzmocnienia = 0;
	string nowaNazwa;
	
public:
	
void createCharacter(Character *character, int iloscPuktowDoRozdysponowania){
	cout << "Tworzysz nowa postac." << endl;
	cout << "Podaj nazwe:";
	cin >> nowaNazwa;
	character -> setName(nowaNazwa);
	cout << endl;
	while(iloscPuktowDoRozdysponowania > 0){
		cout << endl;
		cout << "Masz do rozdysponowania " << iloscPuktowDoRozdysponowania << " punktow." << endl;
		cout << "1. Dodaj punkty sily." << endl;
		cout << "2. Dodaj punkty predkosci." << endl;
		cout << "3. Dodaj punkty zrecznosci." << endl;
		cout << "Wybor: ";
		cin >> wyborWzmocnienia;
		switch (wyborWzmocnienia){
			case 1:
				cout << "Podaj liczbe punktow do dodania: ";
				cin >> zmiennaWartosc;
				if(zmiennaWartosc<=iloscPuktowDoRozdysponowania){
					character -> setStrength(character -> getStrength() + zmiennaWartosc);
					cout << "Nowa wartosc sily wynosi: " << (character -> getStrength()) << endl;
					iloscPuktowDoRozdysponowania -= zmiennaWartosc;
				}else{
					cout<< "Nie masz tylu punkow." << endl;
				}
				break;
			
			case 2:
				cout << "Podaj liczbe punktow do dodania: ";
				cin >> zmiennaWartosc;
				if(zmiennaWartosc<=iloscPuktowDoRozdysponowania){
					character -> setSpeed(character -> getSpeed() + zmiennaWartosc);
					cout << "Nowa wartosc predkosci wynosi: " << (character -> getSpeed()) << endl;
					iloscPuktowDoRozdysponowania -= zmiennaWartosc;
				}else{
					cout<< "Nie masz tylu punkow." << endl;
				}
				break;
				
			case 3:
				cout << "Podaj liczbe punktow do dodania: ";
				cin >> zmiennaWartosc;
				if(zmiennaWartosc<=iloscPuktowDoRozdysponowania){
					character -> setAgility(character -> getAgility() + zmiennaWartosc);
					cout << "Nowa wartosc zwinnosci wynosi: " << (character -> getAgility()) << endl;
					iloscPuktowDoRozdysponowania -= zmiennaWartosc;
				}else{
					cout<< "Nie masz tylu punkow.";
				}
				break;	
			default:
				cout << "Podales zla liczbe. Podaj jeszcze raz" << endl;
				break;
		}
	}
	cout << "Stworzyles postac " << endl << endl;
}
	
};


class Walka
{
private:
    bool ktoSzybszy = 0;
    int szczescieAtakujacego = 1;
    int szczescieBroniacego = 1;
    bool szybszy = 0;
public:
void walka(Postac *postac, Enemy *przeciwnik){
    srand (time(NULL));

    cout << "O bogowie WALKA!!!" << endl << endl;

    while (postac->getHealthPoint()>0 && przeciwnik->getHealthPoint()>0){
        ktoSzybszy = sprawdzenieKtoSzybszy(postac, przeciwnik);
        if(ktoSzybszy == 1){
            cout << postac->getName() << " probuje zadac cios" << endl;
            cios(postac, przeciwnik);
        }else{
            cout << przeciwnik->getName() << " probuje zadac cios" << endl;
            cios(przeciwnik, postac);
        }
    }
    
    cout << endl << "Koniec walki!!!" << endl;
    if(sprawdzenieKtoWygral(postac) == 1){
        cout << "Walke wygral: " << postac->getName() << " i zostalo mu " << postac->getHealthPoint() << " hp." << endl;
    }else{
        cout << "Walke wygral: " << przeciwnik->getName() << " i zostalo mu " << przeciwnik->getHealthPoint() << " hp." << endl;
    }

}

void cios(Character *atakujacy, Character *broniacy){
    if(broniacy->getAgility() < rand()%100){ // ustawianie szans na unik
        broniacy->setHealthPoint(broniacy->getHealthPoint()-atakujacy->getStrength());
        cout << atakujacy->getName() << " zadal cios i " << broniacy->getName() << " zostalo " << broniacy->getHealthPoint() << " hp." << endl;
    }else{
        cout << "Unik" << endl;
    }
}

bool sprawdzenieKtoSzybszy(Character *atakujacy, Character *broniacy){
    szybszy = 0;
    szczescieAtakujacego = rand()%5; // ustawianie szans na zmienienie szybkosci
    szczescieBroniacego = rand()%5;
    if((atakujacy->getSpeed()*szczescieAtakujacego) > (broniacy->getSpeed()*szczescieBroniacego)){ 
        szybszy = 1;
    }else{
        szybszy = 0;
    }

    return szybszy;
}

bool sprawdzenieKtoWygral(Character *atakujacy){
    bool zwyciesca = 0;
    if (atakujacy->getHealthPoint()>0)
    {
        zwyciesca = 1;
    }else{
        zwyciesca = 0;
    }
    
    return zwyciesca;
}

};