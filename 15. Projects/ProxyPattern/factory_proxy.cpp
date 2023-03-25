#include "factory_proxy.h"
#include "iostream"

void FactoryProxy::provideService() {
    if ( factory_ == nullptr ) {
        std::cout<<"Proxy creates Factory on request"<<std::endl;
        factory_ = new Factory();
        factory_ -> provideService();
    } 
    else{
        std::cout<<"Proxy can provide service"<<std::endl;
        factory_->provideService();
    }
        
};


