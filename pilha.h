#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Tipo_Lista Lista;
struct Tipo_Lista
{
	char info;
	Lista *prox;
};

typedef struct Tipo_Pilha Pilha;
struct Tipo_Pilha
{
	Lista *topo;
};

int main();

int 
estah_vazia(Pilha *pilha);

Pilha *
criar(void);

void
empilhar(Pilha *pilha, char info);

void
empilhar_dupla(Pilha *pilha,Pilha *aux,char info);

char
desempilhar(Pilha *pilha);

char
reusar(Pilha *pilha);

void
imprimir(Pilha *pilha);

void 
liberar(Pilha *pilha);

void 
inverter(Pilha* pilha1Original, Pilha* pilha2Copia);

int 
verificar_palindrome(Pilha *pilha1Original, Pilha* pilha2Copia);

void
mostra_user(int palindrome);

void 
pegar_palavra_user(Pilha *pilha,Pilha *aux);

void retry();
