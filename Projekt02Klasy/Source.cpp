#include <iostream>
#include <math.h>

#include "Wynik.h"

int main() {
	Wynik wynik;
	
	std::cout << "------------------------------\n";
	wynik.printDane();
	std::cout << "------------------------------\n";
	wynik.pushBackToDane(3.1415);
	wynik.printDane();
	std::cout << "------------------------------\n";
	wynik.popBackFromDane();
	wynik.printDane();
	std::cout << "------------------------------\n";

	system("pause");
	return 0;
}