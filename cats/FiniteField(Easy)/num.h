//
// Created by Alexander on 26.10.2019.
//

#ifndef FINITEFIELD_EASY__NUM_H
#define FINITEFIELD_EASY__NUM_H

#pragma once

#include <iostream>

class Num {
public:
    Num(int value=0, int modulo=0);
    Num(const Num& other);

    int value;
    int modulo;
};

#endif //FINITEFIELD_EASY__NUM_H
