//
// Created by krzysiek on 1/10/19.
//

#ifndef PROJEKT12SZABLONY_TABLICA_H
#define PROJEKT12SZABLONY_TABLICA_H

template<class T>
class Table {
private:
    T *array;
    int size;

public:
    Table(int);
    ~Table() {delete[] array; }

    T&operator[](int index) { return array[index]; }
};


#endif //PROJEKT12SZABLONY_TABLICA_H
