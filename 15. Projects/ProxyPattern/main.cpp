#include "proxy.h"
#include "factory_proxy.h"
#include "car.h"

int main()
{
    IProxy * factory = new FactoryProxy();
    Car * car = new Car (factory);
    car->build();
    car->run();
    Car * anotherCar = new Car (factory);
    anotherCar->build();
    car->run();
}