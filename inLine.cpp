#include <iostream>

using namespace std;

float calculate(float a, float b, float c, float d, float e, float f);

int main() {

    float a = 1;
    float b = 2;
    float c = 3;
    float d = 2;
    float e = 1;
    float f = 4;


    cout << "My results: " << calculate( a,  b,  c,  d,  e,  f) << endl;
    return 0;
}

float calculate(float a, float b, float c, float d, float e, float f) {
    float result;
    __asm {
        finit
        fld b
        fmul c
        fadd a
        fld e
        fmul f
        fsubr d
        fdivp st(1), st(0)
        fst result 
    }
    return result;
}
