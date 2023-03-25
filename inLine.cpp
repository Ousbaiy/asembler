#include <iostream>

using namespace std;

int main() {
    int i = 0;
    int j = 0;


    __asm {
        mov eax, i
        mov ebx, j
        loop_header:
        cmp eax, 5      ; compare i with 5
        jge loop_end    ; jump tp loop_end if i >= 5
        add ebx, eax    ; add i to j
        inc eax         ; increment i
        jmp loop_header ; jump back to loop_header
        loop_end:
        
    }


    return 0;
}
