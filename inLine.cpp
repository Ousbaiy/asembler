#include <iostream>

using namespace std;

int main() {
    int a = 5;
    int b = 3;
    int c = 0;
    int result = 0;
    char test = 0;

    __asm {
        xor edx, edx
        mov eax, a
        sub eax, b; subtract b from a
        cmp eax, 0
        setg dl; set lower byte of eax to 1 if a - b > 0
        cmp c, 0; compare c with 0
        seten test
        and dl, test
        mov result, edx


    }

    cout << "Result: " << result << endl;

    return 0;
}
