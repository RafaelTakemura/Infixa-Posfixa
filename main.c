#include <stdio.h>
#include "pilha.h"
#include <string.h>

int main()
{
    char inf[50] = "(A+B*(C-D*(E-F)-G*H)-I*3)";

    printf("Apresentando o programa!\n");
    printf("Enter para continuar...");

    getchar();

    puts("Expressao que sera traduzida:");
    printf("%s\n", inf);

    puts("Traducao da Expressao:");
    traduzPosfixa(inf);


    return 0;
}
