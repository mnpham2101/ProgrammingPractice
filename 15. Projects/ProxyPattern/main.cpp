#include "shop_interface.h"
#include "shop_proxy.h"

int main()
{
    std::string requestProduct1 = "REQUEST 1: a doll";
    IShop * myShopProxy = new ShopProxy();
    // myShopProxy creates RealShop
    myShopProxy->provideService(requestProduct1);
    // myShopProxy already has RealShop, and can provide service.
    std::string requestProduct2 = "REQUEST 2: a toy";
    myShopProxy->provideService(requestProduct2);

    // delete myShopProxy will delete RealShop and data saved in memory
    delete myShopProxy;

    // create new proxy
    std::string requestProduct3 = "REQUEST 3: a fan";
    IShop * myShopProxy2 = new ShopProxy();
    // myShopProxy has to create new RealShop again and reload data.
    myShopProxy2->provideService(requestProduct3);

    delete myShopProxy2;
}