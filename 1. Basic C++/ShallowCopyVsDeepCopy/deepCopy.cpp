#include<iostream>
using namespace std;

class A {
public:
    A() {
        m_x = 0;
        m_y = new int(5);
    };
    // use parameterized constructor or copy constructor to make deep copy
    A(A& a) {
        m_x = a.m_x;
        // deep copy: (1) make new memory location and (2) assign value to the memory location.
        m_y = new int;                  // step1: allocate new memory in heap for m_y
        *(m_y) = *(a.m_y);              // step2: dereferincing value at the new memory m_y is assigned to the copied value
    }

    void setX(int x) { m_x = x; };
    void setY(int y) { *m_y = y; };
    int getX() { return m_x; };
    int getY() { return *m_y; };

    ~A(){ delete m_y;}

private:
    int m_x;
    int* m_y;                               // pointer is created in heap, thus deep copy is needed to fully copy obj
};

int main() {
    A objA2;
    objA2.setX(1000);
    objA2.setY(10000000);

    A objA1 = objA2;                        // create objA1 and make deep copy
    cout << objA1.getX() << endl;
    cout << objA1.getY() << endl;           // after copying, objA1 now has values stored in memory location that objA2 also stores its values

    objA2.setX(20000);
    objA2.setY(22222);

    cout << objA1.getX() << endl;
    cout << objA1.getY() << endl;           // because of deep copy, change in objA
}