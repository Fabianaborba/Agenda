#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define clear() puts("\x1B[2J")
#define MAX_AGENDA 50

typedef struct {
	char nome[50];
	int idade;
	char telefone[14];
} Registro;

void imprimeMenu() {
	puts("Agenda eletronica");
	puts("\n");
	puts("1 - Novo Contato");
	puts("2 - Lista Contatos");
	puts("S - Sair");
	puts("\n");
	printf("Escolha uma opcao: ");
}

void criaContato(Registro r[], int *tamanho) {
	int indice = *tamanho;
	
	printf("Entre o nome do contato: ");
	scanf("%s", r[indice].nome);

	printf("Entre a idade do contato: ");
	scanf("%d", &r[indice].idade);
	
	printf("Entre o telefone do contato: ");
	scanf("%s", r[indice].telefone);
	*tamanho = *tamanho + 1;
	
}

void listaContatos(Registro r[], int *tamanho) {
	int tam = *tamanho;
	int i;
	puts("Lista de Contatos\n");
	puts("Nome\tIdade\tTelefone\n");
	
	for (i = 0; i < tam; i++) {
		printf("%s\t%d\t%s\n", r[i].nome, r[i].idade, r[i].telefone);
	}
}

void processaOpcao(int opcao, Registro r[], int *tamanho) {
	switch(opcao) {
		case '1':
			criaContato(r, tamanho);
			break;
		case '2':
			listaContatos(r, tamanho);
			break;
		case 's':
			puts("Encerrando...\n");
			break;
		default:
			puts("Opcao invalida!\n");
			break;
	}
}

int main() {
	FILE *arquivo;
	char *nome_arquivo = "arquivo.txt";
	char op;

	Registro agenda[MAX_AGENDA];

	int tamanho = 0;
	// lê o arquivo e carrega seu conteúdo para o vetor "agenda", se existir
	arquivo = fopen(nome_arquivo, "rb");
	if (arquivo != NULL) {
		fread(&tamanho, sizeof(int), 1, arquivo);
		fread(agenda, sizeof(Registro), MAX_AGENDA, arquivo);
		fclose(arquivo);
	} else {
		puts("Sem arquivo!");
	}

	do {
		clear(); // limpa a tela - multiplataforma
		imprimeMenu();
		op = tolower(getchar());
		processaOpcao(op, agenda, &tamanho);
		fflush(stdin); // limpa o buffer do teclado (para remover lixos)
		getchar();
	} while (op != 's');

	// grava o arquivo, com o conteúdo do vetor, ao sair
	arquivo = fopen(nome_arquivo, "wb");
	fwrite(&tamanho, sizeof(int), 1, arquivo);
	fwrite(agenda, sizeof(Registro), MAX_AGENDA, arquivo);
	fclose(arquivo);
    system("pause");
	return 0;
}
