#include "Matrix.h"
#include "Base.h"
#include <tuple>

using namespace mat_vec;

// Конструирует матрицу с размерами size x size, заполненную value
Matrix::Matrix(size_t size, double value) {

    matrica = new double * [size];
    n = size;
    m = size;

    for (int i = 0; i < size; ++i) {
        matrica[i] = new double [size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {

            matrica[i][j] = value;
        }

    }
}

// Возвращает единичную матрицу
Matrix Matrix::eye(size_t size) {

    Matrix mtx (size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j)
                mtx.matrica[i][j]=1;
            else
                mtx.matrica[i][j]=0;
        }
    }

    return (mtx);
}

// Возвращает матрицу с размерами rows x cols, заполненную value
Matrix::Matrix(size_t rows, size_t cols, double value) {

    matrica = new double * [rows];
    n = rows;
    m = cols;

    for (int i = 0; i < rows; ++i) {
        matrica[i] = new double [cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrica[i][j] = value;
        }
    }
}

// Конструктор копировани
Matrix::Matrix(const mat_vec::Matrix &src) {

    n = src.n;
    m = src.m;
    matrica = new double * [n];

    for (int i = 0; i < n; ++i) {
        matrica[i] = new double [m];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrica[i][j] = src.matrica[i][j];
        }
    }
}

// Оператор присваивания
Matrix& Matrix::operator=(const mat_vec::Matrix &rhs) {

    this -> n = rhs.n;
    this -> m = rhs.m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            delete [](this->matrica[i]);
        }
    }
    delete [](this -> matrica);

    matrica = new double * [n];
    for (int i = 0; i < n; ++i) {
        matrica[i] = new double [m];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrica[i][j] = rhs.matrica[i][j];
        }
    }

    return * this;
}

// Деструктор
Matrix::~Matrix() {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            delete [](matrica[i]);
        }
    }
    delete [](matrica);

    this -> n = 0;
    this -> m = 0;
}

void Matrix::reshape(size_t rows, size_t cols) {

    size_t size = rows * cols;

    double mas[size];

    int k=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            mas[k] = matrica[i][j];
            k++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            delete [](matrica[i]);
        }
    }
    delete [](matrica);

    matrica = new double * [rows];
    for (int i = 0; i < n; ++i) {
        matrica[i] = new double [cols];
    }

    k=0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrica[i][j] = k;
            k++;
        }
    }
}

std::pair<size_t, size_t> Matrix::shape() const {

    return {this -> n, this -> m};
}

double Matrix::get(size_t row, size_t col) const {

    return (matrica[row][col]);
}

Matrix Matrix::operator+(const mat_vec::Matrix &rhs) const {
    Matrix mtrx (n,m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            mtrx.matrica[i][j]= matrica[i][j] + rhs.matrica[i][j];
        }
    }

    return (mtrx);
}

Matrix& Matrix::operator+=(const mat_vec::Matrix &rhs) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrica[i][j] += rhs.matrica[i][j];
        }
    }

    return * this;
}

Matrix Matrix::operator-(const mat_vec::Matrix &rhs) const {
    Matrix mtrx (n,m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            mtrx.matrica[i][j]= matrica[i][j] - rhs.matrica[i][j];
        }
    }

    return (mtrx);
}

Matrix& Matrix::operator-=(const mat_vec::Matrix &rhs) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrica[i][j] -= rhs.matrica[i][j];
        }
    }

    return * this;
}

Matrix Matrix::operator*(const mat_vec::Matrix &rhs) const {
    Matrix mtrx (this -> n,rhs.m);

    for (int i = 0; i < this -> n; ++i) {
        for (int j = 0; j < rhs.m; ++j) {
            for (int k = 0; k < this -> m; ++k) {
                mtrx.matrica[i][j]+= matrica[i][k] * rhs.matrica[k][j];
            }

        }
    }

    return (mtrx);
}



Matrix Matrix::operator*(double k) const {

    Matrix mtrx (this -> n, this -> m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            mtrx.matrica[i][j]= matrica[i][j] * k;
        }
    }

    return (mtrx);
}

Matrix& Matrix::operator*=(double k) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrica[i][j]*= k;
        }
    }

    return * this;
}

Matrix Matrix::operator/(double k) const {

    Matrix mtrx (this -> n, this -> m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            mtrx.matrica[i][j]= matrica[i][j] / k;
        }
    }

    return (mtrx);
}

Matrix& Matrix::operator/=(double k) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrica[i][j]/= k;
        }
    }

    return * this;
}

bool Matrix::operator==(const mat_vec::Matrix &rhs) const {

    bool compare = true;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; ++j) {
            if (matrica[i][j] != rhs.matrica[i][j])
                compare = false;
        }
    }

    return (compare);
}

bool Matrix::operator!=(const mat_vec::Matrix &rhs) const {

    bool compare = true;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; ++j) {
            if (matrica[i][j] == rhs.matrica[i][j])
                compare = false;
        }
    }

    return (compare);
}