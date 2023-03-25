#include "factory.h"
#include "proxy.h"

class FactoryProxy : public IProxy {
    public:
    virtual void provideService() override;
    private:
    Factory * factory_; 
};