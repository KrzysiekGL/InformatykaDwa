//
//  wszystkieFunkcje.cpp
//  Projekt1Struktury
//
//  Created by Krzysztof Szczerbowski on 10/10/2018.
//  Copyright © 2018 Krzysztof Szczerbowski. All rights reserved.
//

#include "wszystkieFunkcje.hpp"

void plytaInit(Plyta& plyta, std::string gatunek){
    std::cout<<"Podja cene plyty: ";
    std::cin>>plyta.cena;
    
    std::cout<<"Podaj ilosc utworow na plycie: ";
    std::cin>>plyta.iloscUtworow;
    
    std::cout<<"Podaj tytul plyty: ";
    std::string tytul;
    std::cin>>tytul;
    plyta.tytul = new char[tytul.size()];
    przepiszTablice(tytul, plyta.tytul);
    
    plyta.gatunek=gatunek;
}

void plytaAutoInit(Plyta& plyta, std::string gatunek, std::string tytul, float cena, int iloscUtworow){
    plyta.gatunek=gatunek;
    plyta.tytul=new char[tytul.size()];
    przepiszTablice(tytul, plyta.tytul);
    plyta.cena=cena;
    plyta.iloscUtworow=iloscUtworow;
}

void plytaDestructor(Plyta& plyta){
    delete plyta.tytul;
}

void wydrukujPlyte(Plyta& plyta){
    std::cout<<"\nPlyta "<<plyta.tytul<<" posiada az "<<plyta.iloscUtworow<<" utworow muzycznych.\n"
    <<"Za marne "<<plyta.cena<<" zlotych to super okazja!\n"
    <<"A juz napewno dla fanow "<<plyta.gatunek<<"!\n\n";
}

void przepiszTablice(std::string& zT, char* doT){
    for(int i=0; i<zT.size(); ++i){
        doT[i]=zT[i];
    }
}

void znajdzNajtanszaPlyte(Plyta* plyta){
    int lowestPrice=plyta[0].cena;
    int lowestPriceIndex=0;
    for(int i=0; i<5; ++i){
        if(plyta[i].cena<lowestPrice){
            lowestPriceIndex=i;
            lowestPrice=plyta[i].cena;
        }
    }
    wydrukujPlyte(plyta[lowestPriceIndex]);
}

void znajdzZPrzedzialuCen(Plyta* plyta, float min, float max){
    for(int i=0; i<5; ++i){
        if(plyta[i].cena>=min && plyta[i].cena<=max)
            wydrukujPlyte(plyta[i]);
    }
}
