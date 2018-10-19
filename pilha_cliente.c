#include "pilha.c"

int main(){
	Pilha* pilha = criar();
	Pilha* aux = criar();
	Pilha* pilha2 = criar();
	
	
	pegar_palavra_user(pilha, aux);
	inverter(aux, pilha2);
	mostra_user(verificar_palindrome(pilha, pilha2));	
	liberar(aux);
	retry();
	return(0);
}
