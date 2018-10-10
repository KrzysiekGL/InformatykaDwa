//
//  main.cpp
//  Projekt1Struktury
//
//  Created by Krzysztof Szczerbowski on 10/10/2018.
//  Copyright © 2018 Krzysztof Szczerbowski. All rights reserved.
//

#include <iostream>
#include <string>

struct Plyta{
    int iloscUtworow;
    char* tytul;
    float cena;
    std::string gatunek;
};

typedef struct Plyta2{} Plyta2; //przestarzale, robi roznice w jezyku C, ale C++ radzi sobie juz bez tej osobliwosci (jak widac ponizej)

void plytaInit(Plyta& plyta, std::string gatunek);
void plytaAutoInit(Plyta& plyta, std::string gatunek, std::string tytul, float cena, int iloscUtworow);
void plytaDestructor(Plyta& plyta);

void wydrukujPlyte(Plyta& plyta);

void przepiszTablice(std::string& zT, char* doT); //instrukcja kopiowania lancuchow (w zasadzie bez senus, ale takie polecenie zeby "skopiowac lanuch"...)
void znajdzNajtanszaPlyte(Plyta* plyta);


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

    
    
    
    plytaDestructor(kazik); //trzeba po sobie posprzatac jak sie uzywa operatora "new"
    return 0;
}



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
    std::cout<<"Plyta "<<plyta.tytul<<" posiada az "<<plyta.iloscUtworow<<" utworow muzycznych.\n"
    <<"Za marne "<<plyta.cena<<" zlotych to super okazja!\n"
    <<"A juz napewno dla fanow "<<plyta.gatunek<<"!\n";
}

void przepiszTablice(std::string& zT, char* doT){
    for(int i=0; i<zT.size(); ++i){
        doT[i]=zT[i];
    }
}
