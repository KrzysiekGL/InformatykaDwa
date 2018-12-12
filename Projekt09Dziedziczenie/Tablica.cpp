#include "Tablica.h"

Tablica::Tablica(int size) {
	this->size = size;
	taTablica = new int[size];

	for(int i=0; i<size; ++i) {
		taTablica[i]=0;
	}	
}

Tablica::~Tablica() {
	delete[] taTablica;
}

void Tablica::drukuj() {
	for(int i=0; i<size; ++i) {
		std::cout<<"Index " << i << ": " << taTablica[i] << std::endl;
	}
}

void Tablica::wypelnij() {
	srand(time(NULL));
	for(int i=0; i<size; ++i) {
		taTablica[i]=rand()% 100;
	}
}
