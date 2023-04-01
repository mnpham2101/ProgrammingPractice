#include "shop.h"
#include "shop_interface.h"

class ShopProxy : public IShop {
    public:
    ShopProxy();
    virtual ~ShopProxy();
    virtual void provideService(std::string product) override;
    private:
    RealShop * realShop_ = nullptr;    // safe initialization of pointer
};