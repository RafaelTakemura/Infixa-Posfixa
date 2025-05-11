// Estrutura de Pilha
typedef struct {
    int topo;
    int cap;
    char *valores;
} Pilha;

// Funções Básicas de Pilha
Pilha* criaPilha(int cap); // Cria uma Pilha
void empilhar(Pilha* p, char elem); // Insere um Elemento na Pilha
char desempilhar(Pilha* p); // Retira um Elemento da Pilha
int estaVazia(Pilha* p);  // Verifica se a Pilha está vazia
int estaCheia(Pilha* p);  // Verifica se a Pilha está cheia
void printPilha(Pilha* p);  // Escreve a Pilha na tela
char retornaTopo(Pilha* p);   // Retorna o Topo da Pilha

// Funções Principais
int verificaPrec(char op);   // Verifica a precedência da operação
void traduzPosfixa(char* inf);  // Traduz uma expressão infixa para posfixa
