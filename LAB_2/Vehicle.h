#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Engine {
private:
    string fuelType_;
    int value_;
    int power_;
public:
    Engine();
    Engine(const string& fuelType, int value, int power); //Тип топлива, кол во топлива, можность двигателя

    // Сеттеры
    string getFuelType() const;
    int getValue()       const;
    int getPower()       const;

    // Гетер с проверочкой
    bool setPower(int power);

    // Вывод
    void print() const;
};


class Vehicle {
private:
    string brand_;
    string model_;
    int year_;
    double price_;
    Engine engine_;
    int mileage_;

    // Приватная проверочка
    bool checkInVariants() const;

public:
    // Счетчик для существующего авто
    static int object_count;

    // Стандартный сеттер
    Vehicle();

    // Параметризованный сеттер
    Vehicle(const string& brand, const string& model, int year, double price, const Engine& engine, int mileage); //Бренд машины, модель, год выпуска
    // ее цена, двигатель и пробег


    // Копия другого объекта
    Vehicle(const Vehicle& other);

    // Дккноструктор
    ~Vehicle();

    // Методы чтения
    string getBrand()  const;
    string getModel()  const;
    int getYear()      const;
    double getPrice()  const;
    Engine getEngine() const;
    int getMileage()   const;

    // Метод езды
    bool drive(int mileage);

    // Смена цены
    bool updatePrice(double price);

    // Вывод
    void print() const;

    // Кол-во существующего транспорта
    static int getObjectCount();

    // Проверочка
    bool isValid() const;
};

// Марка — строка
// Модель — строка
// Год выпуска — целое
// Цена — вещественное
// Пробег — целое

// Поездка (увеличить пробег)
// Изменение цены (например, после торга)

// Год выпуска не может быть меньше 1900 или больше текущего+1
// Цена не может быть отрицательной
// Пробег не может быть отрицательным
// Мощность двигателя ≤ 0 — не варик
#endif