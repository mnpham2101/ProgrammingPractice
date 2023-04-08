#include "shop_proxy.h"
#include "iostream"

void ShopProxy::provideService(std::string product) {
        if ( realShop_ == nullptr  ) {                  
                
            //create RealShop, call RealShop to do service
            // provideService_proxy = (void (*)(std::string))init_RealService (product);            
            init_RealService (product);
        } 
        else{
            std::cout<<"Proxy can provide service"<<std::endl;
            // RealShop is available in Proxy's memory.
            // don't have to request another function call, and add to stack
            // save stack memory by using function pointer. 
            (realShop_->*provideService_proxy)(product);                 
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

void ShopProxy::init_RealService(std::string product){
    std::cout<<"Proxy creates RealShop on request"<<std::endl; 
    realShop_ = new RealShop();
    std::cout<<"init_RealService saves realShop_->provideService to function pointer"<<std::endl; 
    provideService_proxy = &RealShop::provideService;          
    (realShop_->*provideService_proxy)(product);
}