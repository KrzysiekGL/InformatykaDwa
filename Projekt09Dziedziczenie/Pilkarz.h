#ifndef PILKARZH 
#define PILKARZH 

#include "Osoba.h"

class Pilkarz: public Osoba {
	protected:
		int liczbaMeczy;
		int liczbaGoli;

	public:
		Pilkarz(int liczbaMeczy, int liczbaGoli, int wiek, std::string plec, std::string nazwisko);
		void drukuj();
};

#endif //PILKARZH
