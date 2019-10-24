//
// Created by Alexander on 2019-10-21.
//

#include "Vector.h"
#include "Matrix.h"
#include <tuple>
#include <cmath>

using namespace mat_vec;

// Конструирует вектор размера size со значениями value
Vector::Vector(size_t size, double value) {

    vector = new double [size];
    vector_size = size;

    for (int i = 0; i < size; ++i) {
        vector[i] = value;
    }

}

// Конструктор копирования
Vector::Vector(const mat_vec::Vector &src) {

    this -> vector_size = src.vector_size;
    this -> vector = new double [vector_size];

    for (int i = 0; i < this-> vector_size; ++i) {
       this -> vector[i] = src.vector[i];
    }

}

// Оператор присваивания
Vector& Vector::operator=(const mat_vec::Vector &rhs) {

    this -> vector_size = rhs.vector_size;

    delete [](this->vector);

    vector = new double [vector_size];

    for (int i = 0; i < vector_size; ++i) {
        vector[i] = rhs.vector[i];
    }

    return * this;
}

// Деструктор
Vector::~Vector() {
    delete[](this -> vector);

    this -> vector_size = 0;
}

// Возвращает размер вектора
size_t Vector::size() const {

    return (vector_size);
}

// Доступ к n-му элементу вектора
double Vector::operator[](size_t n) const {
    return (vector[n]);
}


double& Vector::operator[](size_t n) {
    return (vector[n]);
}

// L2 норма вектора
double Vector::norm() const {
    double sum = 0;

    for(int i = 0; i < this -> vector_size; ++i){
        sum += pow(this -> vector[i], 2);
    }

    return (sqrt(sum));
}

// Нормализует текущий вектор
void Vector::normalize() {
    for (int i = 0; i < this -> vector_size; ++i) {

        this -> vector[i] = this->vector[i]/vector_size;
    }
}

// Возвращает новый вектор, полученный нормализацией текущего (this)
Vector Vector::normalized() const {
    Vector vec(vector_size);

    for (int i = 0; i < vector_size; ++i) {
        vec.vector[i] = this -> vector[i]/vector_size;
    }

    return (vec);
}

// Поэлементное сложение векторов
Vector Vector::operator+(const mat_vec::Vector &rhs) const {

    Vector res(vector_size);

    for (int i = 0; i < vector_size; ++i) {
        res.vector[i] = this ->vector[i] + rhs.vector[i];
    }

    return (res);
}

Vector& Vector::operator+=(const mat_vec::Vector &rhs) {

    for (int i = 0; i < this -> vector_size; ++i) {
        this ->vector[i] += rhs.vector[i];
    }

    return * this;
}

// Поэлементное вычитание векторов
Vector Vector::operator-(const mat_vec::Vector &rhs) const {

    Vector res(vector_size);

    for (int i = 0; i < vector_size; ++i) {
        res.vector[i] = this ->vector[i] - rhs.vector[i];
    }

    return (res);
}

Vector& Vector::operator-=(const mat_vec::Vector &rhs) {

    for (int i = 0; i < this -> vector_size; ++i) {
        this ->vector[i] -= rhs.vector[i];
    }

    return * this;
}

// Поэлементное умножение векторов
Vector Vector::operator^(const mat_vec::Vector &rhs) const {

    Vector res(vector_size);

    for (int i = 0; i < vector_size; ++i) {
        res.vector[i] = this -> vector[i] * rhs.vector[i];
    }

    return (res);
}

Vector& Vector::operator^=(const mat_vec::Vector &rhs) {

    for (int i = 0; i < this -> vector_size; ++i) {
        this ->vector[i] *= rhs.vector[i];
    }

    return * this;
}

// Скалярное произведение
double Vector::operator*(const mat_vec::Vector &rhs) const {

    double res = 0;

    for (int i = 0; i < this->vector_size; ++i) {
        res += this -> vector[i] * rhs.vector[i];
    }

    return (res);
}

// Умножение всех элементов вектора на скаляр справа (V * k)
Vector Vector::operator*(double k) const {

    Vector res(vector_size);

    for (int i = 0; i < vector_size; ++i) {
        res.vector[i] = this -> vector[i] * k;
    }

    return (res);
}

Vector& Vector::operator*=(double k) {

    for (int i = 0; i < this -> vector_size; ++i) {
        this -> vector[i] *= k;
    }

    return * this;
}

// Деление всех элементов вектора на скаляр
Vector Vector::operator/(double k) const {

    Vector res(vector_size);

    for (int i = 0; i < vector_size; ++i) {
        res.vector[i] = this -> vector[i] / k;
    }

    return (res);

}

Vector& Vector::operator/=(double k) {
    for (int i = 0; i < this -> vector_size; ++i) {
        this -> vector[i] /= k;
    }

    return * this;
}

// Умножение вектора на матрицу

Vector Vector::operator*(const mat_vec::Matrix &mat) const {

    Vector res(vector_size);

    std::pair<size_t, size_t> p = mat.shape();
    size_t n = p.first;
    size_t m = p.second;

    for (int i = 0; i < n; i++)
    {
        res[i] = 0;
        for (int j=0;j<m;j++)
        {
            res[i] += mat.get(i,j) * vector[j];
        }
    }

    return (res);
}

Vector& Vector::operator*=(const mat_vec::Matrix &mat) {
    Vector res(vector_size);

    std::pair<size_t, size_t> p = mat.shape();
    size_t n = p.first;
    size_t m = p.second;

    for (int i = 0; i < n; i++)
    {
        for (int j=0;j<m;j++)
        {
            res[i] += mat.get(i,j)*vector[j];
        }
    }

    for (int i = 0; i < res.size(); ++i) {
        vector[i] = res[i];
    }
    return  * this;
}


// Поэлементное сравнение
bool Vector::operator==(const mat_vec::Vector &rhs) const {

    bool compare = true;

    for (int i = 0; i < this -> vector_size; ++i) {

        if (this -> vector[i] != rhs.vector[i])
            compare = false;
    }

    return (compare);
}

bool Vector::operator!=(const mat_vec::Vector &rhs) const {

    bool compare = true;

    for (int i = 0; i < this -> vector_size; ++i) {

        if (this -> vector[i] == rhs.vector[i])
            compare = false;
    }

    return (compare);
}

