//
// Created by Alexander on 28.10.2019.
//

#include "num.h"

Num::Num(int value, int modulo) {
    this->value = value;
    this->modulo = modulo;
    if (modulo == 0) {
        this->value = value;
    } else {
        this->value = value % modulo;
    }
}
//Num& Num::operator=(const Num &other) {
//    this->value = other.value;
//}
