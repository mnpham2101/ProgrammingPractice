#include "car.h"
#include "iostream"

Car::Car (IProxy * factory){
    factory_ = factory;
};

void Car::build() {
    factory_->provideService();
};

void Car::run() {
    std::cout<<"Car is running !"<<std::endl;
};
