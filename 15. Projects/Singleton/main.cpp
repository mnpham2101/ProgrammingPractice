#include "iostream"
#include "mutex"
#include "thread"

class Singleton {
private:
    static Singleton * instance;
    static std::mutex mtx;
    static int Count;                       // a count variable to indicate that all call of singleton modify the same values

    Singleton(){};
    Singleton( const Singleton & ) = delete;
public:
    static Singleton * getInstance(){
        std::lock_guard<std::mutex> lock(mtx);
        if (!instance)
        {
            instance = new Singleton();
            std::cout<<"create singleton"<<std::endl;
            Count++;                        // Count must be static to be included in a static function
            std::cout<<"    count: "<<Count<<std::endl;
        }
        else {
            std::cout<<"singleton already run"<<std::endl;
        }
    }
};

// static member requires initialization outside of the class, using scope resolution
Singleton* Singleton::instance = nullptr  ;         
std::mutex Singleton::mtx;
int Singleton::Count = 0; 

int main(){
    std::thread t1([]() {
        Singleton * s1 = Singleton::getInstance();
        Singleton * s2 = Singleton::getInstance();
    });
    std::thread t2([]() {
        Singleton * s3 = Singleton::getInstance();
        Singleton * s4 = Singleton::getInstance();
    });
    t1.join();
    t2.join();

    return 0; 
}