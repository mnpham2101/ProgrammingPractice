#include "proxy.h"

class Car {
    public:
    Car (IProxy * );
    void build();
    void run();
    private:
    IProxy * factory_;
};

