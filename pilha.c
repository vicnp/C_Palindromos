#include "pilha.h"

int 
estah_vazia(Pilha *pilha)
{
	return (!pilha || !pilha->topo ? 1 : 0);
}

Pilha *
criar(void) 
{
	Pilha *pilha = (Pilha *) malloc(sizeof(Pilha)); 
					
	pilha->topo = NULL; 

	return (pilha);
}

void
empilhar(Pilha *pilha, char info)
{
	Lista *lista = (Lista *) malloc(sizeof(Lista));  
	lista->info = info; 
	lista->prox = pilha->topo;
	
	pilha->topo = lista;
}

void
empilhar_dupla(Pilha *pilha,Pilha *aux,char info) 
{
	Lista *lista = (Lista *) malloc(sizeof(Lista));
	Lista *listaaux = (Lista *) malloc(sizeof(Lista));

	lista->info = info;
	listaaux->info = info;

	lista->prox = pilha->topo;
	listaaux->prox = aux->topo;
	

	pilha->topo = lista;
	aux->topo = listaaux;
}
char
desempilhar(Pilha *pilha)
{
	char info;
	Lista *lista;

	if (estah_vazia(pilha))
	{
		printf("A pilha esta vazia.\n");
		exit(1);
	}

	lista = pilha->topo;
	info = lista->info;
	pilha->topo = lista->prox;
	free(lista);

	return (info);
}

char
reusar(Pilha *pilha)
{	

	char info;
	Lista *lista;

	if (estah_vazia(pilha))
	{
		printf("A pilha esta vazia.\n");
		exit(1);
	}

	lista = pilha->topo;
	info = lista->info;
	pilha->topo = lista->prox;

	return (info);
}


void 
liberar(Pilha *pilha)
{
	Lista *lista = pilha->topo;
	Lista *lista_auxiliar = NULL;

	while (lista != NULL)
	{
		lista_auxiliar = lista->prox;
		free(lista);
		lista = lista_auxiliar;
	}
	free(pilha);
}

void 
inverter(Pilha* pilha1Original, Pilha* pilha2Copia)
{
	while(pilha1Original->topo){
		empilhar(pilha2Copia, reusar(pilha1Original));
	}
}

int 
verificar_palindrome(Pilha *pilha1Original, Pilha* pilha2Copia)
{
	int verifica = 0;
	while(pilha1Original->topo){
		if(pilha1Original->topo->info == pilha2Copia->topo->info){

		}else{
			verifica = verifica+1;
		}
		pilha1Original->topo = pilha1Original->topo->prox;
		pilha2Copia->topo = pilha2Copia->topo->prox;
	}
	return verifica;
}

void
 mostra_user(int palindrome)
 {
	if(palindrome == 0){
		printf("A palavra digitada e um palindrome !\n");
	}else{
		printf("A palavra digitada nao e um palindrome !\n");
	}
}

void pegar_palavra_user(Pilha *pilha,Pilha *aux){
	int x,i;
	char palavra[100];
	printf("Digite uma palavra para ser verificada:\n>> ");
	scanf("%s", palavra);
	
	for(i = 0; palavra[i]; i++){
  		palavra[i] = tolower(palavra[i]);
	}
	
 	for(x = 0; x < (int)strlen(palavra); x++){
	 	empilhar_dupla(pilha,aux, palavra[x]);
	}
}


void retry(){
	int op = 0;
	setbuf(stdin, NULL);
	printf("Testar outra palavra ?\n1(SIM) -- 0(NAO)\n >>");
	scanf("%d", &op);
	if(op == 1){
		system("clear");
		main();
	}else if(op == 0){
		exit(0);
	}else{
		system("clear");
		retry();
	}
}







