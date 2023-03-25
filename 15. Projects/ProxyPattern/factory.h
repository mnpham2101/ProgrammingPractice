#include "proxy.h"
#include "vector"
#include "string"

class Factory: public IProxy {
    public:
    virtual void provideService() override ;
    private:
    std::vector<std::string> collectBOM() ;
    void buildModel(int, int);
    int model_;
    int type_; 
};
