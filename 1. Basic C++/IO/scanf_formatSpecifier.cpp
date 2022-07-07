#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    int val1;
    long val2;
    char val3;
    float val4;
    double val5;
    // accept int, long, char, float, and double
    scanf("%d %ld %c %f %lf ", &val1, &val2, &val3, &val4, &val5);
    // print
    printf("%d \n%ld \n%c \n%.3f \n%.9lf ", val1, val2, val3, val4, val5);
    return 0;
}