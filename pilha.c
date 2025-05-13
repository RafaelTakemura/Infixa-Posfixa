#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pilha.h"

Pilha* criaPilha(int cap) {    //Declara que criaPilha irá retornar uma pilha, recebe capacidade
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));   // Aloca dinamicamente a memória para p
    p->topo = -1;  // O topo é igual a -1 quando a pilha está vazia
    p->cap = cap;    //atribui a capacidade recebida para a própria da pilha
    p->valores = (char*) malloc(cap * sizeof(char));  // Aloca dinamicamente a memória para valores
    return p;  // Retorna p
}

void empilhar(Pilha* p, char elem) { //Declara que Empilhar não irá retornar nada, recebe um ponteiro para pilha, e um elemento 
    p->topo++;  // Incrementa o Topo da Pilha
    p->valores[p->topo] = elem;  // Adiciona o elemento no topo
}

char desempilhar(Pilha* p) {     //Declara que desempilhar irá retornar um character, recebendo o ponteiro para pilha
    char elem = p->valores[p->topo];   // elem recebe o valor do topo da pilha
    p->topo--;  // Diminui o topo
    return elem;  // Retorna elem
}

int estaVazia(Pilha* p) {    // declara que estaVazia vai retornar um numero inteiro, recebendo um ponteiro para pilha
    int resp=0;   // Assume que a pilha não está vazia
    if (p->topo == -1)   // Verifica se o topo é igual a -1
        resp = 1;           //atribui verdadeiro para a resposta
    return resp;   // Retorna resp
}

int estaCheia(Pilha* p) {  //declara que estaCheia vai retornar um numero inteiro, recebendo um ponteiro para pilha
    int resp=0;    // Assume que a pilha não está cheia
    if (p->topo == (p->cap - 1))    // Verifica se o topo é igual a capacidade-1
        resp = 1;        //atribui verdadeiro a resposta
    return resp;    // Retorna resp
}

void printPilha(Pilha* p) {    //declara que printPilha não vai rerotnar nada, recebendo um ponteiro para pilha
    for(int i=p->topo; i >= 0; i--) {  // Itera i do Topo da Pilha até a Base
        printf("%d\n", p->valores[i]);  // Escreve o valor na posição i do vetor valores
    }
}

char retornaTopo(Pilha* p) {    //declara que retornaTopo vai retornar um character
    return p->valores[p->topo];   // Retorna o valor situado no Topo da Pilha
}

int verificaPrec(char op) { //declara que verificaPrec vai retornar um inteiro, recebendo um character op, o operante
    int prec=0;   // Assume a precedencia como 0
    if(op == '*' || op == '/')  // Se a operação for * ou /, a precedencia é igual a 2
        prec = 2; //atribui 2 à precedencia
    else if (op == '+' || op == '-') // Se a operação for + ou -, a precedencia é igual a 1
        prec = 1;        //atribui 1 à precedencia
    return prec;        //retorna a precedencia da operação recebida
}

void traduzPosfixa(char* inf) {        //declara que traduzPosfixa não vai retornar nada, recebe uma string
    int tam = strlen(inf);   // Guarda o tamanho da string inf em tam
    char posfixa[tam], aux, op;  //declara a posfixa, um auxiliar e uma operação
    int j=0;        //declara um indice    
    Pilha* p;        //declara um ponteiro p para pilha
    p = criaPilha(tam);    //cria a pilha dentro do ponteiro p
    // Percorre a string inf
    for(int i=0; i<tam; i++) {    //percorre o tamanho da string recebida
        aux = inf[i];    // aux recebe um caractere da string inf na posição i
        // Se aux for um número, adiciona ele na string posfixa
        if(isalnum(aux)) {
            posfixa[j] = aux;
            j++;
        }
        // Se aux for igual a (, empilha ele em p
        else if (aux == '(') {
            empilhar(p, aux);
        }
        // Se aux for igual a ), desempilha o topo até que ele seja igual a ( ou a lista fique vazia
        else if (aux == ')') {
            while(p->topo != -1 && p->valores[p->topo] != '(') {
                op = desempilhar(p);
                posfixa[j] = op;
                j++;
            }
            op = desempilhar(p);  // desempilha o ( e não o adiciona na string
        }
        else {
            // Enquanto a precedência de aux for menor ou igual a precedencia do valor no topo da pilha, desempilha
            while(p->topo != -1 && (verificaPrec(aux) < verificaPrec(p->valores[p->topo]) || verificaPrec(aux) == verificaPrec(p->valores[p->topo]))) {
                posfixa[j] = desempilhar(p);
                j++;
            }
            empilhar(p, aux); // Empilha aux
        }
    }
    // Desempilha até que a pilha fique vazia
    while(estaVazia(p) == 0) {
        posfixa[j] = desempilhar(p);
        j++;
    }
    posfixa[j] = '\0';   // Adiciona '\0' no final da string
    printf("%s", posfixa);  // Printa a string posfixa na tela
}
