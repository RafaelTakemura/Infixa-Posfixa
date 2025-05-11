#include <stdio.h>
#include "pilha.h"

int main()
{
    char inf[50] = "(A+B*(C-D*(E-F)-G*H)-I*3)";
    char aux[50];

    aux[50] = inf;

    traduzPosfixa(inf);

    printf("Apresentando o programa!\n");
    printf("Enter para continuar...");

    getchar();

    puts("Expressao que sera traduzida:");
    printf("%s\n", aux);

    puts("Traducao da Expressao:");
    printf("%s\n", inf);

    char teste[10];
    return 0;
}
