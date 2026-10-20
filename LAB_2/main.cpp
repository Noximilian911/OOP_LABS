#include <iostream>
#include <windows.h>
#include "Vehicle.h"

using namespace std;



int main(){
    SetConsoleOutputCP(65001);

    cout << "ТЕСТИРОВАНИЕ КЛАССА VEHICLE " << endl;
    cout << "Начальное количество объектов: "
              << Vehicle::getObjectCount() << endl << endl;

    // 1. Создание объектов тремя разными способами
    cout << "Создание объектов" << endl;

    // Способ 1: конструктор по умолчанию
    Vehicle v1;
    cout << "v1 создан по умолчанию" << endl;

    // Способ 2: параметризованный конструктор
    Engine eng2("Дизель", 2.0, 150);
    Vehicle v2("Toyota", "Priora", 2020, 2500000.0, eng2, 45000);
    cout << "v2 создан параметризованно" << endl;

    // Способ 3: конструктор копирования
    Vehicle v3(v2);
    cout << "v3 создан копированием v2." << endl;

    cout << "\nКоличество объектов после создания: "
              << Vehicle::getObjectCount() << endl;

    // 2. Вывод начального состояния
    cout << "Начальное состояние" << endl;
    v1.print();
    v2.print();
    v3.print();

    // 3. Выполнение корректных операций
    cout << "Корректные операции" << endl;
    cout << "v1: поездка 100 км" << endl;
    v1.drive(100);
    std::cout << "v1: изменение цены на 150000" << endl;
    v1.updatePrice(150000.0);

    std::cout << "v2: поездка 500 км" << endl;
    v2.drive(500);

    
    // 4. Выполнение некорректных операций
    cout << "Некорректные операции " << endl;
    cout << "v1: попытка проехать -50 км" << endl;
    v1.drive(-50); // должно быть отклонено

    cout << "v1: попытка установить цену -100" << endl;
    v1.updatePrice(-100.0); // должно быть отклонено

    
    // 5. Повторный вывод состояния (проверка, что объекты остались корректны)
    cout << "Состояние после операций" << endl;
    v1.print();
    v2.print();
    v3.print();

    // 6. Проверка независимости объектов
    cout << "Проверка независимости" << endl;
    cout << "До изменения v1:" << endl;
    cout << "  v1 пробег: " << v1.getMileage() << endl;
    cout << "  v2 пробег: " << v2.getMileage() << endl;
    cout << "  v3 пробег: " << v3.getMileage() << endl;

    v1.drive(999); // изменяем только v1

    cout << "После изменения v1 (поездка 999 км):" << endl;
    cout << "  v1 пробег: " << v1.getMileage() << endl;
    cout << "  v2 пробег: " << v2.getMileage() << endl;
    cout << "  v3 пробег: " << v3.getMileage() << endl;

    if (v1.getMileage() != v2.getMileage() && v2.getMileage() == v3.getMileage()) {
        cout << " Объекты независимы." << endl;
    } else {
        cout << " Ошибка: объекты зависимы" << endl;
    }

        // 7. Проверка статического счётчика
        cout << "Статический счётчи" << endl;
    cout << "Количество объектов перед завершением: "
              << Vehicle::getObjectCount() << endl;

    cout << "ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << endl;
    return 0;   
}
