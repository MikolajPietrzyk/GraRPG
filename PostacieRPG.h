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
    int luck;
	
Character(string defalutName = "Noname", int defalutStrength = 1, int defaultSpeed = 1, int defaultAgility = 1, int defaultHealthPoint = 100, int defaultluck = 1)
	:name(defalutName), strength(defalutStrength), speed(defaultSpeed), agility(defaultAgility), healthPoint(defaultHealthPoint), luck(defaultluck) {}
	
		
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

int getLuck(){
	return luck;
}

void setLuck(int sz){
	luck = sz;
}


virtual void wypisanieUmiejetnosci(){
	cout << "Nazwa: " << getName() << endl;
	cout << "Sila: " << getStrength() << endl;
	cout << "Predkosc: " << getSpeed() << endl;
	cout << "Zwinnosc: " << getAgility() << endl;
    cout << "Punkty zycia: " << getHealthPoint() << endl;
    cout << "Szczescie: " << getLuck() << endl << endl;
}

};

class Postac : public Character{
private:
	int doswiadczenie = 0;
	int poziom = 1;

public:

Postac(string name = "Noname", int strength = 1, int speed = 1, int agility = 1, int healthPoint = 100, int luck = 1, int doswiadczenie = 0, int poziom = 1)
	:Character(name, strength, speed, agility, healthPoint, luck){}
	
int getDoswiadczenie(){
	return doswiadczenie;
}

void setDoswiadczenie(int d){
	doswiadczenie = d;
}

int getPoziom(){
	return poziom;
}

void setPoziom(int p){
	poziom = p;
}

virtual void wypisanieUmiejetnosci() override{
	cout << endl;
	cout << "Nazwa: " << getName() << endl;
	cout << "Sila: " << getStrength() << endl;
	cout << "Predkosc: " << getSpeed() << endl;
	cout << "Zwinnosc: " << getAgility() << endl;
    cout << "Punkty zycia: " << getHealthPoint() << endl;
    cout << "Szczescie: " << getLuck() << endl;
	cout << "Poziom: " << getPoziom() << endl;
    cout << "Doswiadczenie: " << getDoswiadczenie() << endl << endl;
    
}

};

class Enemy : public Character{
private:
	vector<string> imionaPrzeciwnikow = {"Wikolak" , "Goblin" , "Wampir" , "Wiwerna", "Ogr", "Bob", "Kosciotrup", "Leszy"};
public:

Enemy(string name = "Enemy", int strength = 1, int speed = 1, int agility = 1, int healthPoint = 100, int luck = 1)
	:Character(name, strength, speed, agility, healthPoint, luck){}
	
void generateEnemy(Postac *postac){
	srand (time(NULL));
	setName(imionaPrzeciwnikow[rand()%imionaPrzeciwnikow.size()]);
	setStrength(rand()%40 + 10 * postac->getPoziom());
	setSpeed(rand()%40 + 10 * postac->getPoziom());
	setAgility(rand()%40 + 10 * postac->getPoziom());
    setHealthPoint(rand()%100 + 50 + 10 * postac->getPoziom());
	if(getName() == "Bob"){
		cout << "Zbliza sie cos bardzo niebezpiecznego. Lepiej uciekaj!!!" << endl;
		setLuck(10);
		setStrength(getStrength() + 20);
		setSpeed(getSpeed() + 20);
		setAgility(getAgility() + 20);
 	   	setHealthPoint(getHealthPoint() + 50);
	}
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
	dodawaniePunktow(character, iloscPuktowDoRozdysponowania);
	cout << "Stworzyles postac " << endl << endl;
}

void dodawaniePunktow(Character *character, int iloscPuktowDoRozdysponowania){
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
}	
};


class Levelowanie{
private:
	int wynikStatystyk;
	TworzeniePostaci ulepszenieStatystyk;
	int hp = 100;
	
public:
void zdobyteDoswiadczenie(Postac *postac, Character *przeciwnik){
	wynikStatystyk = (przeciwnik->getStrength() + przeciwnik->getSpeed() + przeciwnik -> getAgility());
	postac->setDoswiadczenie(postac->getDoswiadczenie() + wynikStatystyk);
	cout << "Po ciezkiej walce zdobyles nowe doswiadczenie: " << postac->getDoswiadczenie() << endl;
}

void nowyLevel(Postac *postac){
	cout << "Wstepujesz do swiatyni szukajac ukojenia." << endl;
	if(postac->getDoswiadczenie() > 100*postac->getPoziom()){
		postac->setDoswiadczenie(postac->getDoswiadczenie() - 100*postac->getPoziom());
		postac->setPoziom(postac->getPoziom()+1);
		cout << "Czujesz przyplyw mocy i nowej sily." << endl;
		postac->setHealthPoint(hp);
		cout << "Gdzie sie najbardziej rozwinales? " << endl;
		ulepszenieStatystyk.dodawaniePunktow(postac, 10);
	}else{
		cout << "Po chwili spedzonej w swiatyni odzyskujesz spokoj umyslu." << endl;
	}
	cout << endl <<  "Z nowa sila wychodzisz z swiatyni, z nadzieja na przezycie nowych przygod" << endl << endl;
}
	
};

class Walka{
private:
    bool ktoSzybszy = 0;
    int szczescieAtakujacego = 1;
    int szczescieBroniacego = 1;
    bool szybszy = 0;
    
    Levelowanie levelowanie;
    
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
        levelowanie.zdobyteDoswiadczenie(postac, przeciwnik);
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
    szczescieAtakujacego = rand()%4+atakujacy->getLuck(); // ustawianie szans na zmienienie szybkosci
    szczescieBroniacego = rand()%4+broniacy->getLuck();
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