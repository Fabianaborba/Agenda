#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	char telefone[14];
	char nome[50];
	int idade;
	short id;
} Registro;

void criaContato(Registro student[], int posicao) {
    system("cls"); 
    	
	printf("Entre o nome do contato: ");
	scanf("%s", student[posicao].nome);

	printf("Entre a idade do contato: ");
	scanf("%d", &student[posicao].idade);
	
	printf("Entre o telefone do contato: ");
	scanf("%s", student[posicao].telefone);
	
	
}

void listaContato(Registro student[], int tamanho) {
    system("cls");
	int i;
	puts("Lista de Contatos\n");
	puts("Nome\tIdade\tTelefone\n");
	
	for (i = 0; i <= tamanho; i++) {
		printf("%s\t%d\t%s\n", student[i].nome, student[i].idade, student[i].telefone);
	}
	
	system("pause");
}

void excluiContato(Registro student[], int posicao){
     system("cls");
     
     student[posicao].idade = 0;
     
     memset(&student[posicao].nome, 0 ,sizeof(student[posicao].nome));
     
     memset(&student[posicao].telefone, 0 ,sizeof(student[posicao].telefone));

}

int main (int argc, char*argv[]){
      Registro alunos[40];
      int escolha = 0;
      int id = 0;
      FILE *arquivo;
      char *nome_arquivo = "dados.bin";
      int tamanho = 0;
      
      arquivo = fopen(nome_arquivo, "rb");
      if (arquivo != NULL) {
		fread(&tamanho, sizeof(int), 1, arquivo);
		fread(alunos, sizeof(Registro), 40, arquivo);
		fclose(arquivo);
	  } else {
		puts("Sem arquivo!");
	  }
	  
	  
      do {
         system("cls");
         printf ("1-Criar contato: ");
         printf ("\n2-Listar contato: ");
         printf ("\n3-Excluir contato: ");
         printf ("\n4-Editar contato: ");
         printf ("\n0 - Sair");
         printf ("\nInforme a operação desejada: ");
         scanf ("%d", &escolha);
         switch(escolha) {
           case 1:
               printf ("Informe seu iD: ");
               scanf ("%d", &id); 
			   criaContato(alunos, id);
			   tamanho++;
			   break;
		   case 2:
               printf ("Informe seu iD: ");
               scanf ("%d", &id); 
			   listaContato(alunos, id);
			   break;
		   case 3:
			   excluiContato(alunos, id);
			   tamanho--;
			   break;
		   case 4:
               printf ("Informe seu iD: ");
               scanf ("%d", &id); 
			   criaContato(alunos, id);
			   break;
		   case 0:
                printf ("Finalizando");
                break;
           default:
			   puts("Opcao invalida!\n");
			   break;
	     }
      } while (escolha != 0);
      
      arquivo = fopen(nome_arquivo, "wb");
	  fwrite(&tamanho, sizeof(int), 1, arquivo);
	  fwrite(alunos, sizeof(Registro), 40, arquivo);
	  fclose(arquivo);
      system ("pause");
      return 0;
}
