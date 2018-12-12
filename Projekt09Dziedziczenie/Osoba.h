#ifndef OSOBAH
#define OSOBAH

#include <string>
#include <iostream>

class Osoba {
	protected:
		int wiek;
		std::string plec;
		std::string nazwisko;

	public:
		Osoba(int wiek, std::string plec, std::string nazwisko);
		
		void drukuj();
};

#endif //OSOBAH
