/**
 * @file Laba_1_zad_3.cpp
 * @brief Лабораторная работа №1, задание 3 — структура SafeArray и работа с ней.
 */

#include <iostream>
#include <windows.h>

using namespace std;

/**
 * @brief Безопасный массив: указатель на данные + размер.
 */
struct SafeArray {
    int* data;   
    int size;    
};

/**
 * @brief Создаёт SafeArray заданного размера, заполненный нулями.
 * @param size Размер нового массива.
 * @return Структура SafeArray с выделенной памятью.
 */
SafeArray createArray(int size){
    SafeArray arr;
    arr.data = new int[size]{};
    arr.size = size;
    return arr;
}

/**
 * @brief Возвращает ссылку на элемент по индексу с проверкой границ.
 *
 * Если индекс вне диапазона [0, size-1] — выводит ошибку и возвращает
 * ссылку на статическую заглушку (безопасное поведение без краша).
 *
 * @param arr Ссылка на SafeArray.
 * @param index Индекс элемента.
 * @return Ссылка на элемент или на статическую заглушку.
 */
int& getElement(SafeArray& arr, int index ){
    static int buff = 0;
    if (index < 0 || index >= arr.size){
        cout << "Ошибка: индекс " << index << " вне массива" << endl;
        return buff;
    }
    return arr.data[index];
}

/**
 * @brief Выводит массив SafeArray на экран.
 * @param arr Константная ссылка на SafeArray (печать не меняет данные).
 */
void printSafe(const SafeArray& arr){
    for (int i = 0; i < arr.size; i++){
        cout << arr.data[i] << " ";
    }
    cout << endl;
}

/**
 * @brief Изменяет размер массива с текущего на M.
 *
 * Если M меньше текущего размера — выводит удаляемые элементы.
 * Если больше — новые элементы заполняются нулями.
 * Освобождает старую память и обновляет arr.data и arr.size.
 *
 * @param arr Ссылка на SafeArray.
 * @param M Новый размер массива.
 */
void reSizeArray(SafeArray& arr, int M){
    if (M < arr.size){
        cout << "Удаленные элементы" << endl;
        for(int i = M; i < arr.size; i++){
            cout << arr.data[i] << " ";
        }
        cout << endl;
    }

    int* newData = new int[M]{};

    int copySize;
    if(M < arr.size){
        copySize = M;
    } else {
        copySize = arr.size;
    }
    for (int i = 0; i < copySize; i++) {
        newData[i] = arr.data[i];
    }

    delete[] arr.data;

    arr.data = newData;
    arr.size = M;
}

int main(){
    SetConsoleOutputCP(65001);

    SafeArray myArr = createArray(5);
    getElement(myArr, 2) = 999;
    printSafe(myArr);

    SafeArray testArr = createArray(5);
    for (int i = 0; i < testArr.size; i++){
        getElement(testArr, i) = i + 1;
    }
    printSafe(testArr);

    reSizeArray(testArr, 3);
    printSafe(testArr);

    reSizeArray(testArr, 7);
    printSafe(testArr);

    delete[] myArr.data;
    myArr.data = nullptr;

    delete[] testArr.data;
    testArr.data = nullptr;
}