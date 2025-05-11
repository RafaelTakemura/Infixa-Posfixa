#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pilha.h"

Pilha* criaPilha(int cap) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = -1;
    p->cap = cap;
    p->valores = (char*) malloc(cap * sizeof(char));
    return p;
}

void empilhar(Pilha* p, char elem) {
    p->topo++;  // Incrementa o Topo da Pilha
    p->valores[p->topo] = elem;  // Adiciona o elemento no topo
}

char desempilhar(Pilha* p) {
    char elem = p->valores[p->topo];   // elem recebe o valor do topo da pilha
    p->topo--;  // Diminui o topo
    return elem;  // Retorna elem
}

int estaVazia(Pilha* p) {
    int resp=0;   // Assume que a pilha não está vazia
    if (p->topo == -1)   // Verifica se o topo é igual a -1
        resp = 1;
    return resp;   // Retorna resp
}

int estaCheia(Pilha* p) {
    int resp=0;    // Assume que a pilha não está cheia
    if (p->topo == (p->cap - 1))    // Verifica se o topo é igual a capacidade-1
        resp = 1;
    return resp;    // Retorna resp
}

void printPilha(Pilha* p) {
    for(int i=p->topo; i >= 0; i--) {  // Itera i do Topo da Pilha até a Base
        printf("%d\n", p->valores[i]);  // Escreve o valor na posição i do vetor valores
    }
}

char retornaTopo(Pilha* p) {
    return p->valores[p->topo];   // Retorna o valor situado no Topo da Pilha
}

int verificaPrec(char op) {
    int prec=0;   // Assume a precedencia como 0
    if(op == '*' || op == '/')  // Se a operação for * ou /, a precedencia é igual a 2
        prec = 2;
    else if (op == '+' || op == '-') // Se a operação for + ou -, a precedencia é igual a 1
        prec = 1;
    return prec;
}

void traduzPosfixa(char* inf) {
    int tam = strlen(inf);
    char posfixa[tam], aux, op;
    int j=0;
    Pilha* p;
    p = criaPilha(tam);
    for(int i=0; i<tam; i++) {
        aux = inf[i];
        if(isalnum(aux)) {
            posfixa[j] = aux;
            j++;
        }
        else if (aux == '(') {
            empilhar(p, aux);
        }
        else if (aux == ')') {
            while(p->topo != -1 && p->valores[p->topo] != '(') {
                op = desempilhar(p);
                posfixa[j] = op;
                j++;
            }
            op = desempilhar(p);
        }
        else {
            while(p->topo != -1 && (verificaPrec(aux) < verificaPrec(p->valores[p->topo]) || verificaPrec(aux) == verificaPrec(p->valores[p->topo]))) {
                posfixa[j] = desempilhar(p);
                j++;
            }
            empilhar(p, aux);
        }
    }
    while(estaVazia(p) == 0) {
        posfixa[j] = desempilhar(p);
        j++;
    }
    posfixa[j] = '\0';
    printf("%s", posfixa);
}
