//
//  main.cpp
//  Projekt1Struktury
//
//  Created by Krzysztof Szczerbowski on 10/10/2018.
//  Copyright © 2018 Krzysztof Szczerbowski. All rights reserved.
//

#include "Plyta.hpp"
#include "wszystkieFunkcje.hpp"



typedef struct Plyta2{} Plyta2; //przestarzale, robi roznice w jezyku C, ale C++ radzi sobie juz bez tej osobliwosci (jak widac ponizej)




int main(int argc, const char * argv[]) {
    //zadanie 1
    Plyta kazik;
    plytaInit(kazik, "Rock and Roll");
    wydrukujPlyte(kazik);
    
    //zadanie 2
//    Plyta2 zolteDzikieKaczki;
    
    Plyta album[5];
    
    for(int i=0; i<5; ++i){
        album[i]=*new Plyta;

        plytaAutoInit(album[i], "Rock", "JakisTytul", 99999, 2);
        std::cout<<"Podja cene plyty #"<<i<<": ";
        std::cin>>album[i].cena;
//        wydrukujPlyte(album[i]); //mozna sobie odkomentowac i sprawdzic, ze plyty istnieja
    }
    
    znajdzNajtanszaPlyte(album);

    plytaDestructor(kazik); //trzeba po sobie posprzatac jak sie uzywa operatora "new"
    return 0;
}




