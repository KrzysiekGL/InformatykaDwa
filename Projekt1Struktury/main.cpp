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
        album[i]=*new Plyta; //nowy element tablicy album o type wskaznik do typu Plyta

        plytaAutoInit(album[i], "Rock", "JakisTytul", -1, 2);
        std::cout<<"Podja cene plyty #"<<i<<": ";
        while(album[i].cena<0)
            std::cin>>album[i].cena;
//        wydrukujPlyte(album[i]); //mozna sobie odkomentowac i sprawdzic, ze plyty istnieja
    }
    znajdzNajtanszaPlyte(album);

    //zadanie 3
    //tablica z plytami juz jest (album), takze nie robie kolejnej
    float min, max;
    std::cout<<"Podaj min i max przedzialu cenowego: ";
    std::cin>>min>>max;
    znajdzZPrzedzialuCen(album, min, max);
    
    //zadanie 4
    
    
    plytaDestructor(kazik); //trzeba po sobie posprzatac jak sie uzywa operatora "new"
    return 0;
}
