#include "shop_proxy.h"
#include "iostream"

void ShopProxy::provideService(std::string product) {
    if ( realShop_ == nullptr  ) {                  
        std::cout<<"Proxy creates RealShop on request"<<std::endl;     
        realShop_ = new RealShop();                               //create RealShop, call RealShop to do service
        realShop_ -> provideService(product);
    } 
    else{
        std::cout<<"Proxy can provide service"<<std::endl;
        // RealShop is available in Proxy's memory.
        // don't have to reload, just run logic
        realShop_ ->provideService(product);                              
    }
};


ShopProxy::ShopProxy() 
{
    std::cout<<"**ShopProxy Constructor**"<<std::endl;
}

ShopProxy::~ShopProxy() 
{
    std::cout<<"**ShopProxy Destructor**"<<std::endl;
    delete realShop_;
    realShop_ = nullptr;     // safe delete of member pointer
}