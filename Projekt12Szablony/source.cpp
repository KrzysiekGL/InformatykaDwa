#include <iostream>
#include <vector>

template<typename T> T minimum(std::vector<T>);


int main() {
	//Zadanie 1.
	std::vector<int> tabl;
	tabl.push_back(2);	
	tabl.push_back(4);

	std::cout << minimum(tabl) << std::endl;

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
