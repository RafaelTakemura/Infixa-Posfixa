#include <stdio.h>
#include "pilha.h"

int main()
{
    char inf[50] = "(A+B*(C-D*(E-F)-G*H)-I*3)";
    traduzPosfixa(inf);

    return 0;
}
