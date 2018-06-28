#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	char telefone[14];
	char nome[50];
	int idade;
} Registro;

void criaContato(Registro student[], int posicao) {
    system("cls"); 

	printf("Entre o nome do contato: ");
	scanf("%s", student[posicao].nome);
	
    do {
    	printf("Entre a idade do contato: ");
    	scanf("%d", &student[posicao].idade);
    } while (student[posicao].idade == 0); 
	
	printf("Entre o telefone do contato: ");
	scanf("%s", student[posicao].telefone);
	
	
}

void listaContato(Registro student[], int tamanho) {
    system("cls");
	printf("Contatos %d\n", tamanho);
	printf("ID\tNome\tIdade\tTelefone\n");
	printf("%d\t%s\t%d\t%s\n", tamanho, student[tamanho].nome, student[tamanho].idade, student[tamanho].telefone);
	system("pause");
}

void listarTodos(Registro student[]) {
    system("cls");
    int i;
	//printf("Contatos %d\n", tamanho);
	printf("ID\tNome\tIdade\tTelefone\n");
	for (i = 0; i < 40; i++){
        if (student[i].idade != 0){
	       printf("%d\t%s\t%d\t%s\n", i, student[i].nome, student[i].idade, student[i].telefone);
        }
     }
	system("pause");
}

void excluiContato(Registro student[],int posicao){
    system("cls");
   
     student[posicao].idade = 0;
     
     memset(&student[posicao].nome, 0,sizeof(student[posicao].nome));
     
     memset(&student[posicao].telefone, 0,sizeof(student[posicao].telefone));

}

int main (int argc, char*argv[]){
      Registro alunos[40];
      int escolha = 0;
      int id = 0;
      int i;
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
	  
	  /*
	  for (i = 0; i <= 39; i++){
          strcpy(alunos[i].nome, "Alunos");
          alunos[i].idade = 0;
	      strcpy(alunos[i].telefone, "11223344");
      }*/
	  
      do {
         system("cls");
         printf ("1-Criar contato: ");
         printf ("\n2-Listar contato: ");
         printf ("\n3-Excluir contato: ");
         printf ("\n4-Editar contato: ");
         printf ("\n5-Listar todos");
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
		   		printf ("Informe seu iD: ");
               scanf ("%d", &id); 
			   excluiContato(alunos,id);
			   tamanho--;
			   break;
		   case 4:
               printf ("Informe seu iD: ");
               scanf ("%d", &id); 
			   criaContato(alunos, id);
			   break;
		   case 5:
                listarTodos(alunos);
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
