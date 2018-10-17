#include "Wynik.h"

int Wynik::countDane(){
	return dane.size();
}

void Wynik::pushBackToDane(float number){
	dane.push_back(number);
}

void Wynik::popBackFromDane(){
	dane.pop_back();
}

void Wynik::printDane(){
	for (float number : dane) {
		std::cout << number << '\n';
	}
}
