#include "factory.h"
#include "proxy.h"
#include "iostream"


void Factory::provideService() {
    std::cout<<"NEW CHANGES are made on public function of Factory"<<std::endl;
    collectBOM();
}

std::vector<std::string> Factory::collectBOM() {
    std::cout<<"NEW CHANGES are made on private function of Factory"<<std::endl;
    std::cout<<"call factory to build car"<<std::endl;
    buildModel(4,5);
    std::vector<std::string> bom;
    bom.push_back("Engine");
    bom.push_back("Transmission");
    bom.push_back("Brakes");
    
    return bom;
}

void Factory::buildModel(int model, int type){
    model_ = model;
    type_  = type;
    std::cout<<"build new model "<<model_<<" type "<<type_<<std::endl;
}