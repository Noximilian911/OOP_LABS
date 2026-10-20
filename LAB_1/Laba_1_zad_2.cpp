/**
 * @file Laba_1_zad_2.cpp
 * @brief Лабораторная работа №1, задание 2 — динамический массив и new/delete.
 */

#include <iostream>
#include <windows.h>

using namespace std;

/**
 * @brief Ищет первый отрицательный элемент. Если он есть — обрезает массив до него.
 *
 * Создаёт новый массив размера badNumber (кол-во элементов до первого
 * отрицательного), копирует туда данные, освобождает старую память и
 * переводит указатель arr на новый блок. Выводит результат на экран.
 *
 * @param arr Ссылка на указатель на массив. Меняется внутри функции.
 * @param size Размер исходного массива.
 */
void process (int*& arr, int size){
    int badNumber = -1;
    int newsize = size;

    for (int i = 0; i < size; i++){
        if (arr[i] < 0){
            cout << "Ошибка, отрицательное число" << endl;
            badNumber = i;
            break;
        }
    }

    if (badNumber != -1 ){
        int* newArr = new int[badNumber]{};
        newsize = badNumber;
        for(int i = 0; i < newsize; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    cout << "Проверенный массив:" << endl;
    for (int i = 0; i < newsize; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    SetConsoleOutputCP(65001);

    int N;
    cout << "Введите размер массива ниже:" << endl;
    cin >> N;

    int* arr = new int[N]{};

    cout << "Введите числа для массива размером " << N << " через пробел" << endl;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    process(arr, N);

    cout << endl;

    delete[] arr;
    arr = nullptr;

    if (arr != nullptr){
        cout << arr[0] << endl;
    } else {
        cout << "Указатель пуст, обращение пропущено" << endl;
    }
}