#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	char telefone[14];
	char nome[50];
	int idade;
	short id;
} Registro;

Registro criaContato(Registro *r, int tamanho) {
	
	printf("Entre o nome do contato: ");
	scanf("%s", (*r[tamanho]).nome);

	printf("Entre a idade do contato: ");
	scanf("%d", (*r[tamanho]).idade);
	
	printf("Entre o telefone do contato: ");
	scanf("%s", (*r[tamanho]).telefone);
	
}
