/**
 * @file Laba_1_zad_4.cpp
 * @brief Лабораторная работа №1, задание 4 — матрица через int**.
 */

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

/**
 * @brief Выделяет память под матрицу rows x cols.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return Указатель на матрицу (int**).
 */
int** allocateMatrix(int rows, int cols){
    int** matrix = new int*[rows];
    for(int i = 0; i < rows; i++){
        matrix[i] = new int[cols];
    }
    return matrix;
}

/**
 * @brief Заполняет матрицу числами по формуле i * cols + j.
 * @param matrix Указатель на матрицу.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 */
void fillMatrix(int** matrix, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrix[i][j] = i * cols + j;
        }
    }
}

/**
 * @brief Выводит матрицу на экран с рамкой и заголовком.
 * @param matrix Указатель на матрицу.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @param showBorders Рисовать рамку (по умолчанию true).
 * @param title Заголовок над матрицей (по умолчанию "Matrix").
 */
void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, string title = "Matrix"){

    int pad = (cols * 2) + 2;
    for(int i = 0; i < (pad/2) - 3; i++){
        cout << " ";
    }
    cout << title << endl;

    if(showBorders){
        cout << string(pad, '-') << endl;
    }

    for(int i = 0; i < rows; i++){
        if (showBorders){
            cout << "|" << " ";
        }
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        if(showBorders){
            cout << "|";
        }
        cout << endl;
    }
    if(showBorders){
        cout << string(pad, '-') << endl;
    }
    cout << endl;
}

/**
 * @brief Освобождает память матрицы.
 *
 * Сначала удаляет строки, потом массив указателей.
 *
 * @param matrix Указатель на матрицу.
 * @param rows Количество строк.
 */
void freeMatrix(int** matrix, int rows){
    for(int i = 0; i < rows; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main(){
    SetConsoleOutputCP(65001);

    int** myMatx = allocateMatrix(3, 3);
    fillMatrix(myMatx, 3, 3);
    printMatrix(myMatx, 3, 3, false, "");
    printMatrix(myMatx, 3, 3, false);
    printMatrix(myMatx, 3, 3, true);

    freeMatrix(myMatx, 3);
    myMatx = nullptr;
}