/**
 * @file Laba_1_zad_1.cpp
 * @brief Лабораторная работа №1, задание 1 — статический массив из 10 чисел.
 */

#include <iostream>
#include <random>
#include <windows.h>

using namespace std;

/**
 * @brief Заполняет массив случайными числами в диапазоне 1..99.
 * @param arr Ссылка на массив из 10 элементов.
 */
void fillArray(int (&arr)[10]){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,99);

    for (int& x : arr){
        x = dist(gen);
    }
}

/**
 * @brief Выводит массив на экран через пробел.
 * @param arr Ссылка на массив из 10 элементов.
 */
void printArray(int (&arr)[10]){
    cout << "Получившийся массив: ";
    for (const auto& x : arr){
        cout << x << " ";
    }
    cout << endl;
}

/**
 * @brief Меняет местами два элемента массива по индексам.
 * @param arr Ссылка на массив из 10 элементов.
 * @param i Индекс первого элемента.
 * @param j Индекс второго элемента.
 */
void swapElements(int (&arr)[10], int i, int j){
    int& a = arr[i];
    int& b = arr[j];
    int c = a;
    a = b;
    b = c;
}

/**
 * @brief Умножает каждый элемент массива на 2.
 * @param arr Ссылка на массив из 10 элементов.
 */
void multiplyByTwo(int (&arr)[10]){
    for (int& i : arr)
        i = i * 2;
}

int main(){
    SetConsoleOutputCP(65001);
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8 ,9 ,0 };
    fillArray(arr);
    printArray(arr);
    cout << "После смены по индексам:" << endl;
    swapElements(arr, 2,8);
    printArray(arr);
    cout << "После умножения на два:" << endl;
    multiplyByTwo(arr);
    printArray(arr);
}