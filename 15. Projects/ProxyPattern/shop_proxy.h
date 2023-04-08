#include "shop.h"
#include "shop_interface.h"

class ShopProxy : public IShop {
    public:
    ShopProxy();
    virtual ~ShopProxy();
    virtual void provideService(std::string product) override;
    
    private:
    void (RealShop::* provideService_proxy )(std::string product);
    void init_RealService ( std::string product );
    RealShop * realShop_ = nullptr;    // safe initialization of pointer
};