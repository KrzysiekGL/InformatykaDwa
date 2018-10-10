//
//  wszystkieFunkcje.hpp
//  Projekt1Struktury
//
//  Created by Krzysztof Szczerbowski on 10/10/2018.
//  Copyright © 2018 Krzysztof Szczerbowski. All rights reserved.
//

#ifndef wszystkieFunkcje_hpp
#define wszystkieFunkcje_hpp

#include <iostream>
#include "Plyta.hpp"

void plytaInit(Plyta& plyta, std::string gatunek);
void plytaAutoInit(Plyta& plyta, std::string gatunek, std::string tytul, float cena, int iloscUtworow);
void plytaDestructor(Plyta& plyta);

void wydrukujPlyte(Plyta& plyta);

void przepiszTablice(std::string& zT, char* doT); //instrukcja kopiowania lancuchow (w zasadzie bez senus, ale takie polecenie zeby "skopiowac lanuch"...)
void znajdzNajtanszaPlyte(Plyta* plyta);

#endif /* wszystkieFunkcje_hpp */
