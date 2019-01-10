#ifndef OSOBA_H
#define OSOBA_H

#include <string>

class Osoba {
	protected:
		std::string nazwisko;
		int wiek;
		std::string plec;

	public:
		Osoba(std::string nazwisko, int wiek, std::string plec) {
			this->nazwisko = nazwisko;
			this->wiek = wiek;
			this->plec = plec;
		}

		virtual void drukuj() {}
};

#endif //OSOBA_H
