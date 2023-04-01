#include "shop.h"
#include "iostream"
using namespace std;

void RealShop::provideService(string product) {
    cout<<"    shop is building "<<product<<" in warehouse"<<endl;
    if (specialOrder_ == true){
        specialService("Minh");
    }
    collectMaterial();
}

void RealShop::collectMaterial() {
    cout<<"    collect material to build product"<<endl;
}

RealShop::RealShop(){
    cout<<"    RealShop constructor"<<endl;
}

RealShop::~RealShop(){
    cout<<"    RealShop destructor"<<endl;
}

void RealShop::specialService(string customer){
    std::cout<<"provide custom order to customer "<<customer<<std::endl;
    customerName_ = customer;
}