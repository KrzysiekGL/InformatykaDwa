#include <iostream>

#include "Osoba.h"
#include "Pilkarz.h"
#include "Tablica.h"

void zamien(double& a, double& b);

int main() {
std::cout << "Zadanie 1.\n";
Osoba osoba(45, "gostek", "Janusz");
osoba.drukuj();

std::cout << "Zadanie 2.\n";
Pilkarz pilkarz(10, 7, 31, "gostek", "Jarek");
pilkarz.drukuj();

std::cout << "Zadanie 3.\n";
Tablica *array=new Tablica(10);
array->drukuj();
array->wypelnij();
array->drukuj();
delete array;
array->drukuj();

std::cout << "Zadanie 4.\n";
double a,b;
a=99.99;
b=0.01;
std::cout << a << " " << b << "\n";
zamien(a, b);
std::cout << a << " " << b << "\n";

return 0;
}

void zamien(double& a, double& b) {
	double temp=a;
	a=b;
	b=temp;	
}
