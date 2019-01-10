//
// Created by krzysiek on 1/10/19.
//

#include "Tablica.h"

template <class T>
Table<T>::Table(int){
    array = new T[size];
    this->size = size;
}

//template <class T>
//Tbl<T>::Tbl(int size) {
//    array = new T[size];
//    this->size = size;
//}