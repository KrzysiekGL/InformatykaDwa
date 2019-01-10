#ifndef PILKARZ_H
#define PILKARZ_H

#include <iostream>

#include "Osoba.h"

class Pilkarz: public Osoba {
	protected:
		int liczbaMeczy;
		int liczbaGoli;

	public:
		Pilkarz(std::string nazwisko, int wiek, std::string plec, int liczbaMeczy, int liczbaGoli): Osoba(nazwisko, wiek, plec) {
			this->liczbaMeczy = liczbaMeczy;
			this->liczbaMeczy = liczbaMeczy;
		}

		virtual void drukuj();
};

#endif //PILKARZ_H
