#include <iostream>

using namespace std;

int main()
{
    int a = 5;
    int b = 3;
    int result;

    __asm
    {
        mov eax, a      ; move a into eax
        dec eax         ; subtract 1 from a
        shr eax, 1      ; divide a by 2 using right shift
        mov ebx, b      ; move b into ebx
        inc ebx         ; add 1 to b
        shl ebx, 2      ; multiply b by 4 using left shift
        add eax, ebx    ; add the results of the previous calculations
        mov result, eax ; move the result into the variable 'result'
    }

    cout << "(a-1)/2 + 4*(b+1) = " << result << endl;

    return 0;
}

