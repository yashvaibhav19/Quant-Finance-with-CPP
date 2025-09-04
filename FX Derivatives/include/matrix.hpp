#ifndef SDE56_Y345Y_SDA76
#define SDE56_Y345Y_SDA76

// matrix.hpp
#pragma once
#include <vector>

// Basic matrix type using std::vector
template <typename T>
using matrix = std::vector<std::vector<T>>;

// Resizing function for matrices
template <typename T>
void matrix_resize(matrix<T> &mat, int rows, int cols)
{
    mat.resize(rows);
    for (int i = 0; i < rows; ++i)
    {
        mat[i].resize(cols);
    }
}

#endif /* SDE56_Y345Y_SDA76 */