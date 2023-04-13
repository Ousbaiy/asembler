#include <iostream>

using namespace std;

float calculate(float a, float b, float c) {
    float result1, result2;
    __asm {
        // Load coefficients a, b, and c onto the stack
        fld a
        fld b
        fld c

        // Calculate discriminant b^2 - 4ac
        fmul            // b * a
        fld a
        fmul            // a * c
        fld c
        fmul            // c * c
        fld c
        fmul            // c * c * a
        fmul            // b^2 - 4ac
        fsub            // subtract from b^2

        // Check if the discriminant is negative
        fcomp           // compare to 0
        fstsw ax        // store the status word in ax
        sahf            // transfer ax to flags register
        jp imaginary    // jump to imaginary roots if the PF flag is set

        // Calculate real roots
        fld st(0)       // duplicate the discriminant on top of the stack
        fsqrt           // take the square root
        fld b
        fchs            // negate b
        fadd            // add to the root of the discriminant
        fld a
        fmul            // multiply a by 2
        fdiv            // divide by 2a
        fstp result1    // store the first root
        fld st(2)       // duplicate the discriminant and a on the stack
        fchs            // negate the discriminant
        fsub            // subtract from -b
        fld a
        fmul            // multiply a by 2
        fdiv            // divide by 2a
        fstp result2    // store the second root
        jmp done        // jump to the end of the function

        imaginary :
        // Calculate imaginary roots
        fld st(0)       // duplicate the discriminant on top of the stack
        fchs            // negate the discriminant
        fsqrt           // take the square root
        fld b
        fchs            // negate b
        fld st(0)       // duplicate the root of the discriminant
        fdiv            // divide b by the root
        fld a
        fmul            // multiply a by 2
        fdiv            // divide by 2a
        fstp result1    // store the first root
        fld b
        fld st(0)       // duplicate the root of the discriminant
        fdiv            // divide b by the root
        fld a
        fmul            // multiply a by 2
        fdiv            // divide by 2a
        fchs            // negate the second root
        fstp result2    // store the second root (negated)

            done :
        // Clear the FPU stack
        fstp st(0)
        fstp st(0)
        fstp st(0)
    }

    // Return the first root
    return result1;
}

int main(float a, float b, float c) {
    cout << "a = " << endl;
    cout << "b = " << endl;
    cout << "c = " << endl; 
    cin >> a;
    cin >> b;
    cin >> c;
    float root1 = calculate(a, b, c);  // calculate the first root
    cout << "Roots of the equation " << a << "x^2 + " << b << "x + " << c;
}