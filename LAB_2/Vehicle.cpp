#include <iostream>
#include "Vehicle.h"

using namespace std;

Engine::Engine()
    : fuelType_("Бензин"), value_(1.6), power_(100)
{
    //Standart realisation
}

Engine::Engine(const string& fuelType, int value, int power)
    : fuelType_(fuelType), value_(value), power_(power)
{
    if (value_ <= 0) value_ =1.0;
    if (power_ <= 0) power_ =50;
} // Proverochka

string Engine::getFuelType() const {return fuelType_;}
int Engine::getValue()       const {return value_;}
int Engine::getPower()       const {return power_;}

bool Engine::setPower(int power){
    if (power <= 0) { return false;}
    power_ = power;
    return true;
}

void Engine::print() const{
    cout << "Двигатель: " << fuelType_
              << ", объём " << value_ << " л"
              << ", мощность " << power_ << " л.с." << std::endl;
}
 // Print характеристик


int Vehicle::object_count = 0;

Vehicle::Vehicle()
    : brand_("Неизвестный"), model_("какая то"), year_(2000), price_(1000000), engine_(), mileage_(200000)
{
    ++object_count;
    cout << "[Vehicle] Успешно создан объект по умолчанию. Всего:" << object_count << endl;
}  // Standart realisation

Vehicle::Vehicle(const string& brand, const string& model, int year, double price, const Engine& engine, int mileage)
    : brand_(brand), model_(model), year_(year), price_(price),engine_(engine), mileage_(mileage)
{
    if (year_ <=1900 || year_ > 2026) year = 2000;
    if (price_ < 1 || price_ > 1000000000) price = 2000000;
    if (mileage_ < 1 || mileage_ > 10000000) mileage = 100000;    
    ++object_count;
    cout << "[Vehicle] Успешно создан параметризованный объект. Всего:" << object_count << endl;
} // Не стандарт с проверкой ввода данных

Vehicle::Vehicle(const Vehicle& other)
    : brand_(other.brand_), model_(other.model_), year_(other.year_), 
      price_(other.price_),engine_(other.engine_), mileage_(other.mileage_)
{
    ++object_count;
    cout << "[Vehicle] Успешно создан объект копирования. Всего:" << object_count << endl;
} // Копирование с другого

Vehicle::~Vehicle(){
    --object_count;
    cout << "[Vehicle] Уничтожен объект " << brand_ << " " << model_
              << ". Осталось: " << object_count << std::endl;    
}

// Гетеры
string Vehicle::getBrand()  const {return brand_; }
string Vehicle::getModel()  const {return model_; }
int Vehicle::getYear()      const {return year_; }
double Vehicle::getPrice()  const {return price_; }
Engine Vehicle::getEngine() const {return engine_; }
int Vehicle::getMileage()   const {return mileage_; }
Engine Vehicle::getEngine() const {return engine_; }    

// Метод езды
bool Vehicle::drive(int km){
    if (km < 0){
        cout << "Ошибочка, нельзя ехать отрицатетльно :D" << endl;
        return false;
    }
    if (mileage_ + km > 10000000){ // Проверка на более 10 000 000км
        cout << "Зверь, поменяй двигатель, ему хана уже" << endl;
        return false;
    }
    mileage_ += km;
    cout << "Машина проехала " << km << "км. Текущий пробег: " << mileage_ << " км."<<  endl;
    return true;
}
    // Смена цены
bool Vehicle::updatePrice(double new_price){
    if (new_price <= 0.0){
        cout << "А ты очень щедрый, но сделай машину подороже" << endl;
        return false;
    }
    price_ = new_price;
    return true;
}
    // Вывод
void Vehicle::print() const{
    cout << "Автомобиль: " << brand_ << " " << model_ << endl;
    cout << "Год выпуска:  " << year_ << " год" << endl;
    cout << "Цена: " << price_ << " руб";
    engine_.print();
    cout << "Пробег: " << mileage_ << " км" << std::endl;
    cout << "Живой ли: " << (isValid() ? "yes" : "no") << endl;
}

    // Кол-во существующего транспорта
int Vehicle::getObjectCount(){
    return object_count;
}

    // Проверочка
bool Vehicle::checkInVariants() const{
    if(year_ < 1900 || year_ > 2026)        return false;
    if(price_ < 1 || price_ > 1000000000)   return false;
    if(mileage_ < 1 || mileage_ > 10000000) return false;
    if(engine_.getPower() < 1)              return false;
    if(engine_.getValue() < 1)              return false;
    return true;
}

bool Vehicle::isValid() const {
    return checkInVariants();
}






//Геттеры сделат
//Различные смены состояние (езда, цена)
// Вывод всего 
//Проверочки надо года, цены и пробега, а также объема и мощности