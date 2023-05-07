#include <iostream>

using namespace std;

int main()
{
    // plain enum 
    // underlying type is integer
    // associated values can be assigned but not be larger than int
    enum Color { red=12, green=20, blue=214 };
    // associated values are red_card=0, green_card=1, yellow_card=2
    enum Card { red_card, green_card, yellow_card };    
    
    
    Color color = Color::blue;
    Card card = Card::green_card;
    
    int num = color;             // enum is implicitly-convertible to integral types
    cout<<sizeof(num)<<endl;     // sizeof enumerator is int size
    // print associated values
    cout<<"Color::blue="<<num<<endl;
    cout<<"Card::green_card="<<card<<endl;
    // scope of 
    cout<<"Color::blue+Card::green_card="<<num+card<<endl;             //not type safe
    
    // error: enumerator value for ‘food’ must have integral or unscoped enumeration type
    // enum MyEnum { food = 1.1, house='h', wife=3 };

    enum MyEnum { food = 1, house='h', wife=3 };
    MyEnum e = MyEnum::house;
    // print out int value, ascii value of 'h'=104
    cout<<"MyEnum::house="<<e<<endl;
    
    enum class MyEnum2 { food = 1, house='h', wife=3 };
    MyEnum2 ee = MyEnum2::food;
    // error
    // cout<<"MyEnum2::food="<<ee<<endl;

    return 0;
}