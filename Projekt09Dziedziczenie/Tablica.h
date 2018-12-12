#ifndef TABLICAH
#define TABLICAH

#include <iostream>
#include <time.h>
#include <stdio.h>

class Tablica{
	protected:
		int size;
		int *taTablica;

	public:
		Tablica(int size);
		~Tablica();

		void drukuj();
		void wypelnij();
};

#endif //TABLICAH
