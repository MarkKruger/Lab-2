#pragma once
#include <stdlib.h>
#include "Vector.h"
class Matrix
{
private:
    int x_length;
    int y_length;
    float** matrix_array;

public:
    Matrix(int x_len, int y_len) {
        Init(x_len, y_len);
    }
    ~Matrix() {
        for (size_t i = 0; i < x_length; i++) {
            delete[] matrix_array[i];
        }
        delete[] matrix_array;
    }
    void Init(int x_len, int y_len) {
        matrix_array = new float* [x_len];
        for (size_t i = 0; i < x_len; i++) {
            matrix_array[i] = new float[y_len];
        }
        x_length = x_len;
        y_length = y_len;
    }

    Vector toVector() {
        Vector v(x_length * y_length);
        for (size_t i = 0; i < x_length; i++) {
            for (size_t j = 0; j < y_length; j++) {
                v[i * y_length + j];
            }
        }
        return v;
    }

    float at(int x, int y) {
        return matrix_array[x][y];
    }
    void setAt(int x, int y, float value) {
        matrix_array[x][y] = value;
    }

    int GetLength() {
        return x_length * y_length;
    }
    int GetLength(int X) {
        return y_length;
    }

    Matrix& operator ++ () {
        for (int i = 0; i < x_length; i++)
            for (int j = 0; j < y_length; j++)
                matrix_array[i][j]++;
        return *this;
    }
    Matrix& operator ++ (int) {
        Matrix temp_array(x_length, y_length);
        for (int i = 0; i < x_length; i++)
            for (int j = 0; j < y_length; j++)
                temp_array[i][j] = matrix_array[i][j]++;
        return temp_array;
    }

    Matrix& operator -- () {
        for (int i = 0; i < x_length; i++) {
            for (int j = 0; j < y_length; j++) {
                matrix_array[i][j]--;
            }
        }
        return *this;
    }
    Matrix& operator -- (int) {
        Matrix temp_array(x_length, y_length);
        for (int i = 0; i < x_length; i++) {
            for (int j = 0; j < y_length; j++) {
                temp_array[i][j] = matrix_array[i][j]--;
            }
        }
        return temp_array;
    }

    float* operator [] (int i) {
        return matrix_array[i];
    }
    float operator = (float value) {
        return value;
    }
};