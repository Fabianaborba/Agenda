#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	char telefone[14];
	char nome[50];
	int idade;
	short id;
} Registro;

void criaContato(Registro student[], int posicao) {
	
	printf("Entre o nome do contato: ");
	scanf("%s", student[posicao].nome);

	printf("Entre a idade do contato: ");
	scanf("%d", &student[posicao].idade);
	
	printf("Entre o telefone do contato: ");
	scanf("%s", student[posicao].telefone);
	
}
