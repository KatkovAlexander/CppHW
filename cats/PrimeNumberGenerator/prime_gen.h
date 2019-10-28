//
// Created by Alexander on 27.10.2019.
//

#ifndef PRIMENUMBERGENERATOR_PRIME_GEN_H
#define PRIMENUMBERGENERATOR_PRIME_GEN_H

class PrimeNumberGenerator {
public:
    bool IsNumberSimple(int number) {
        if (number == 1) {
            return false;
        }
        for (int i = 2; i < number / 2 + 1; ++i) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

    explicit PrimeNumberGenerator(int start) { num = start; }

    int GetNextPrime() {
        if (count != 0) {
            num++;
        }
        while (!IsNumberSimple(num)) {
            num++;
        }
        count++;
        return num;
    }

private:
    int num;
    int count = 0;
};



#endif //PRIMENUMBERGENERATOR_PRIME_GEN_H
