#include<iostream>
using namespace std;

class A {
public:
    A() {
        m_x = 0;
        m_y = new int(5);
    };
    // use parameterized constructor or copy constructor to make deep copy


    void setX(int x) { m_x = x; };
    void setY(int y) { *m_y = y; };
    int getX() { return m_x; };
    int getY() { return *m_y; };

private:
    int m_x;
    int* m_y;
};

int main() {
    A objA1;                                // initially: objA1.m_x=0, *(objA1.m_y) = 5
    A objA2;
    int *y = new int(1000);
    objA2.setX(1000);
    objA2.setY(10000000);
    objA1 = objA2;
    cout << objA1.getX() << endl;
    cout << objA1.getY() << endl;           // after copying, objA1 now has values stored in memory location that objA2 also stores its values

    objA2.setX(20000);
    objA2.setY(22222);
    cout << objA1.getX() << endl;
    cout << objA1.getY() << endl;           // because of shallow copy change in heap in objA2 is reflected to change in objA1 => getY returns *m_y as 22222
}