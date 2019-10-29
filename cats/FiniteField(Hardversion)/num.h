//
// Created by Alexander on 28.10.2019.
//

#ifndef FINITEFIELD_HARDVERSION__NUM_H
#define FINITEFIELD_HARDVERSION__NUM_H

#pragma once

class Num {
public:
    Num(int value, int modulo);

//    Num& operator=(const Num& other);
//
//    Num operator+(const Num& other);
//    Num operator-(const Num& other);
//    Num operator*(const Num& other);
//    Num operator+(int num);
//    Num operator-(int num);
//    Num operator*(int num);
//
//    Num& operator+=(const Num& other);
//    Num& operator-=(const Num& other);
//    Num& operator*=(const Num& other);
//    Num& operator+=(int num);
//    Num& operator-=(int num);
//    Num& operator*=(int num);

    int value;
    int modulo;
};

#endif //FINITEFIELD_HARDVERSION__NUM_H
