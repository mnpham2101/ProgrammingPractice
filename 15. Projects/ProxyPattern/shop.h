#include "shop_interface.h"
#include "string"

class RealShop: public IShop {
    public:
    RealShop();
    virtual ~RealShop();
    virtual void provideService(std::string product) override ;
    static const bool specialOrder_ = true;            // newly added
    private:
    void collectMaterial();
    void specialService(std::string customerName);     // newly added
    std::string customerName_;
};
