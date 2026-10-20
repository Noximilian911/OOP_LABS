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
    std::cout << "Двигатель: " << fuelType_
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
    if (price_ < 1 || price_ > 10000000000) price = 2000000;
    if (mileage_ < 1 || mileage_ > 1000000) mileage = 100000;    
    ++object_count;
    cout << "[Vehicle] Успешно создан параметризованный объект. Всего:" << object_count << endl;
} // Не стандарт с проверочкой 

Vehicle::Vehicle(const Vehicle& other)
    : brand_(other.brand_), model_(other.model_), year_(other.year_), 
      price_(other.price_),engine_(other.engine_), mileage_(other.mileage_)
{
    ++object_count;
    cout << "[Vehicle] Успешно создан объект копирования. Всего:" << object_count << endl;
} // Копирование с другого

Vehicle::~Vehicle(){
    --object_count;
    std::cout << "[Vehicle] Уничтожен объект " << brand_ << " " << model_
              << ". Осталось: " << object_count << std::endl;    
}