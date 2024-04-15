#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
int dado;
struct nodo *prox;
}Nodo;

typedef struct{
	Nodo *inicio;
}Fila;

Fila *criarFila(){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	f->inicio = NULL;
	return f;
}

void enfileirar(Fila *f, int dado){
	Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
	novo->dado = dado;
	novo->prox = NULL;
	if(f->inicio == NULL){
		f->inicio = novo;
	}
	else{
		Nodo *aux = f->inicio;
		while(aux->prox != NULL){
			aux = aux->prox;
			aux->prox = novo;
		}
	}
}

int desenfileirar(Fila *f){
	if(f->inicio == NULL){
		return -1;
	}
	else{
		Nodo *aux = f->inicio;
		int dado = aux->dado;
		f->inicio = aux->prox;
		free(aux);
		return dado;
	}
}

void imprimir(Fila *f){
	Nodo *aux = f->inicio;
	while(aux != NULL){
		printf("%d ", aux->dado);
		aux = aux->prox;
	}
	printf("\n");
}

int main(){
	Fila *f = criarFila();
	enfileirar(f, 1);
	enfileirar(f, 2);
	enfileirar(f, 3);
	enfileirar(f, 4);
	enfileirar(f, 5);
	imprimir(f);
	return 0;
}