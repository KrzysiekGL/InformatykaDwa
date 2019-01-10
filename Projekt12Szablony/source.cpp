#include <iostream>
#include <vector>

#include "Tablica.h"

template<typename T> T minimum(std::vector<T>);

//dziwna klasa w source.cpp

template <class T>
		class Tbl {
		private:
			T *array;
			int size;
		public:
			Tbl(int);
			~Tbl(){delete[] array;}
			T&operator[](int index) {return array[index];}
		};

template <class T>
		Tbl<T>::Tbl(int size) {
			array = new T[size];
			this->size = size;
		}

		int main() {
	//Zadanie 1.
	std::vector<int> tabl;
	tabl.push_back(2);	
	tabl.push_back(4);
	std::cout << minimum(tabl) << std::endl;

	std::vector<int> tabl2 = {99, 1, 23, 13, 4};
	std::cout << minimum(tabl2) << std::endl;

	std::vector<std::string> tabl3 = {"ala", "ma", "kota"};
	std::cout << minimum(tabl3) << std::endl;

	//Zadanie 2.
	Tbl<float> tbl(3);
	for(int i = 0; i<3; i++)
		tbl[i] = (float)i/2;
	std::cout << tbl[1] << std::endl;

	//Dlaczego to nie działa?
//	Table<float> table(3);
//	for(int i=0; i<3; i++)
//		table[i] = (float)i/3;
//	std::cout << table[1] << std::endl;

	//Zadanie 3.
	/*
	 * The Standard Template Library (STL) is a set of C++
	 * template classes to provide common programming data
	 * structures and functions such as lists, stacks, arrays,
	 * etc. It is a library of container classes, algorithms
	 * and iterators. It is a generalized library and so, its
	 * components are parameterized. A working knowledge of template
	 * classes is a prerequisite  for working with STL.
	 *
	 * Różnica między vectorem, a list jest taka że vector jest zbudowany
	 * na "prymitywnej" tablicy, a lista działa w następujący sposób:
	 * każdy element listy zawiera wskaźnik do wartości/wartość oraz wskaźnik do
	 * następnego elementu tablicy. Dzięki czemu podczas dodawania/usuwania
	 * elementów pozostałe nie muszą być przesuwane w pamięci (tak jak w vecotrze).
	 * a jedyne co to następuje zmiana we wskaźiku do kelejnego elementu.
	 */

	return 0;
}

template<typename T>
T minimum(std::vector<T> array) {
	//Sortowanie Shella (Knuth, tom 3, str 84) -> znaleziono w książce "Język C++ kompedium Wiedzy" wydanie 4. Bjarne Stroustrup
	const size_t n = array.size();
	
	for(int gap=n/2; 0<gap; gap/=2) 
		for(int i=gap; i<n; i++) 
			for(int j=i-gap; 0<=j; j-=gap) 
				if( array.at(j+gap) < array.at(j) )
					std::swap(array.at(j), array.at(j+gap) );
	return array.at(0);
}
