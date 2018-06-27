#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_TELEFONE 14
#define MAX_NOME 50
#define MAX_ALUNOS 40

typedef struct {
	char telefone[MAX_TELEFONE];
	char nome[MAX_NOME];
	int idade;
	short id;
} Registro;

void criaContato(Registro student[], int posicao) {
	
	printf("Entre o nome do contato: ");
	scanf("%s", student[MAX_ALUNOS].nome);

	printf("Entre a idade do contato: ");
	scanf("%d", &student[MAX_ALUNOS].idade);
	
	printf("Entre o telefone do contato: ");
	scanf("%s", student[MAX_ALUNOS].telefone);
	
}

void listarTodos(Registro student[], int tamanho) {
	int i;
	puts("Lista de Contatos\n");
	puts("ID\tNome\tIdade\tTelefone\n");
	
	for (i = 0; i <= tamanho; i++) {
		printf("%d\t%s\t%d\t%s\n", student[i].nome, student[i].idade, student[i].telefone);
	}
}

void excluiContato(Registro student[], int posicao){
     student[posicao].idade = 0;
     
     memset(&student[posicao].nome, 0 ,sizeof(student[posicao].nome));
     
     memset(&student[posicao].telefone, 0 ,sizeof(student[posicao].telefone));
}

void listaContato(Registro student[], int tamanho) {
    system("cls");
	printf("Contatos %d\n", tamanho);
	printf("Nome\tIdade\tTelefone\n");
	printf("%s\t%d\t%s\n", student[tamanho].nome, student[tamanho].idade, student[tamanho].telefone);
	system("pause");
}

void excluiContato(Registro student[], int posicao){
     system("cls");
     
     student[posicao].idade = 0;
     
     memset(&student[posicao].nome, 0,sizeof(student[posicao].nome));
     
     memset(&student[posicao].telefone, 0,sizeof(student[posicao].telefone));

}


