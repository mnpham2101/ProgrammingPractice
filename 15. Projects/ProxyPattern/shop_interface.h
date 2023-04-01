// needed preprocessor to prevend loop include
#ifndef ISHOP
#define ISHOP
#include "string"

class IShop{
    public:
    IShop(){};
    virtual void provideService(std::string product) = 0;
    virtual ~IShop(){};
};
#endif