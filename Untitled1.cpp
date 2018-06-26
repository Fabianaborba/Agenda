#include <stdio.h>
#include <stdlib.h>

int main(){
	int num,num2,soma;
	char nome[10];
	
	FILE *fptr;
	
	fptr = fopen ("programa.txt","w");
	if (fptr == NULL){
		printf("Erro!");
		exit(1);
	}
	printf("Digite o nome:");
	scanf("%s",&nome);	
	printf("entre com um  numero :");
	scanf("%d",&num);
	printf("entre com um numero:");
	scanf("%d",&num2);

	soma=num+num2;
	fprintf(fptr,"nome:%s \n%d + %d = %d",nome,num,num2,soma);
	fclose(fptr);
	return 0;
}
