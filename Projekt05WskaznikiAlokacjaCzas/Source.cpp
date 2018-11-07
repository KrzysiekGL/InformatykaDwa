#include <iostream>
#include <random>

#include <stdlib.h> /*malloc(), free()*/

#include <SFML/System.hpp>

double a;

int main() {
	int b;
	static char c;

	sf::Clock clock;
	float timeElapsed;

	for (int i = 0; i < 10000000; ++i) {
		//
	}
	timeElapsed = clock.restart().asMilliseconds();
	std::cout << "Time elapsed: " << timeElapsed << " [ms]\n";
	std::cout << "That is " << 10000000 / timeElapsed << " loop iterations in 1 [ms]\n\n";

	for (int i = 0; i < 1000000000; ++i) {
		//
	}
	timeElapsed = clock.restart().asMilliseconds();
	std::cout << "Time elapsed: " << timeElapsed << " [ms]\n";
	std::cout << "That is " << 1000000000 / timeElapsed << " loop iterations in 1 [ms]\n\n";

	for (int i = 0; i < 10; ++i) {
		std::cout << "Random number: " << rand() % 10 << '\n';
	}
	std::cout << "\n\n";

	double* wa = &a;
	int* wb = &b;
	char* wc = &c;

	std::cout << "&a = " << wa
				<< "\n&b = " << wb
				<< "\n&c = " << wc;

	std::cout << "\nwa - wb = " << (int)wa - (int)wb
				<< "\nwb - wa = " << (int)wb - (int)wa;


	int i = 0;
	while(true) {
		i = 100000;
		int* buffer = (int*)malloc(i*8);
		if (*buffer != NULL) {
			std::cout << buffer << '\n';
			free(buffer);
		}
		else {
			std::cout << "Too much!\n";
			free(buffer);
			break;
		}
	}

	getchar();
	return 0;
}