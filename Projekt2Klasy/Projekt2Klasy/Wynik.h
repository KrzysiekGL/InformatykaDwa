#pragma once
#include <vector>
#include <iostream>
#include <math.h>

class Wynik{
	//MARK: - Private Fields

	std::vector<float> dane;

	//MARK: - Private Methods

	int countDane();

public:
	//MARK: - Constructor

	Wynik() {
		for (int i = 0; i < 20;) {
			dane.push_back(std::sin(++i) * 10);
		}
	}

	//MARK: - Public Fileds

	//MARK: - Public Methods

	void pushBackToDane(float number);
	void popBackFromDane();
	void printDane();
};

