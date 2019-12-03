#include<stdio.h>
#include <string.h>

int main(){
	
	struct cadastroBanda{
   		char nome[100];
   		char tipo[100];
   		int integrantes;
   		int qtdAlbum;
   };
   
	struct cadastroBanda banda[30];
   
	int op, i, contador = 0, linha = 1, opcao;
	
	char buffer[100], nomeB[100], tipoB[100];
	
	FILE *arq;
	arq = fopen("bandas.txt", "r");
	
  	if (arq != NULL){
	    i = 1;
	  	while (!feof(arq)){ 
	     	if (fgets(buffer, 100, arq) != NULL){
				if(linha == 5) linha = 1;
				if(linha == 1){
			 		strncpy(banda[contador].nome, buffer, strlen(buffer)-1);	
			 	}
				 
				if(linha == 2){
			 		strncpy(banda[contador].tipo, buffer, strlen(buffer)-1);
				 }
				
				if(linha == 3){
			 		banda[contador].integrantes = strtol(buffer, NULL, 10);
				}
				 
				if(linha == 4){
			 		banda[contador].qtdAlbum = strtol(buffer, NULL, 10);		 	
			 		contador++;
				}
				
				linha++;
		     	i++;
			}
	 
 		}
 		
 		arq = fopen("bandas.txt", "a");
		
	    for(;;){
	    	printf("---------------------------\n");
			printf("\tMENU BANDAS\n");
			printf("---------------------------\n\n");
			printf("1 - Cadastrar banda\n");
			printf("2 - Consultar banda\n");
			printf("3 - Consultar tipo de musica\n");
			printf("4 - Listar bandas\n");
			printf("5 - Sair\n\n");
			printf("Digite a opcao desejada: ");
			scanf("%d", &op);
		   
		   	system("cls");
		   
		    switch(op){
		   		
		   		case 1:
		   			do{
		   				printf("----------------------------------------------\n");
			   			printf("\t    CADASTRO DE BANDA\n");
			   			printf("----------------------------------------------\n\n");
			   			
				   		printf("Digite o nome da banda: ");
				   		scanf("%s", &banda[contador].nome);
				   		fprintf(arq, "%s\n", banda[contador].nome);
				   		
				   		printf("Digite o tipo de musica da banda: ");
				   		scanf("%s", &banda[contador].tipo);
				   		fprintf(arq, "%s\n", banda[contador].tipo);
				   		
				   		printf("Digite o numero de integrantes: ");
				   		scanf("%d", &banda[contador].integrantes);
				   		fprintf(arq, "%d\n", banda[contador].integrantes);
				   		
				   		printf("Digite quantos albuns a banda possui: ");
				   		scanf("%d", &banda[contador].qtdAlbum);
				   		fprintf(arq, "%d\n", banda[contador].qtdAlbum);
				   		
				   		printf("\n\n0 para sair 1 para continuar: ");
				   		scanf("%d", &opcao);
				   		
				   		system("cls");
				   		
				   		contador++;
		   		
					   }while(opcao == 1);
		   			
				break;
		   		
		   		case 2:
		   			do{
		   				printf("----------------------------------------------\n");
			   			printf("\t    CONSULTA DE BANDA\n");
			   			printf("----------------------------------------------\n\n");
				   		printf("Digite o nome da banda a ser buscada: ");
				   		scanf("%s", &nomeB);
				   		
				   		for(i = 0; i < contador; i++){
				   			if(strcmp(nomeB, banda[i].nome) == 0){
								printf("Nome da banda: %s\n", banda[i].nome);
								printf("Tipo de musica: %s\n", banda[i].tipo);
								printf("Numero de integrantes: %d\n", banda[i].integrantes);
								printf("Quantidade de albuns: %d\n", banda[i].qtdAlbum);   	
						    }
						}
						
						printf("\n\n0 para sair 1 para continuar: ");
						scanf("%d", &opcao);
						
						system("cls");
					
					}while(opcao == 1);
			   		
					
		   		break;
		   		
		   		case 3:
			   		do{
			   			printf("----------------------------------------------\n");
			   			printf("\t CONSULTA DE TIPO DE MUSICA\n");
			   			printf("----------------------------------------------\n\n");
				   		printf("Digite o tipo de musica a ser buscado: ");
				   		scanf("%s", &tipoB);
				   		printf("\n");
				   		
				   		for(i = 0; i < contador; i++){
				   			if(strcmp(tipoB, banda[i].tipo) == 0){
								printf("Nome da banda: %s\n", banda[i].nome);
						    }
						}
						
						printf("\n\n0 para sair 1 para continuar: ");
						scanf("%d", &opcao);

						system("cls");
						
					   }while(opcao == 1);
			   		
		   		break;
		   		
		   		case 4:
		   			printf("----------------------------------------------\n");
		   			printf("\t LISTAGEM DAS BANDAS\n");
		   			printf("----------------------------------------------\n\n");
		   			for(i = 0; i < contador; i++){
		   				printf("ID banda: %d\n", i + 1);
		   				printf("Nome da banda: %s\n", banda[i].nome);
		   				printf("Tipo de musica: %s\n", banda[i].tipo);
		   				printf("Numero de integrantes: %d\n", banda[i].integrantes);
		   				printf("Quantidade de albuns: %d\n", banda[i].qtdAlbum);
		   				
		   				if(i != (contador - 1)){
		   					printf("\n");
						   }
					   }
					   
					   printf("\n");
					   system("pause");
					   system("cls");
					   
		   		break;
		   		
		   		case 5:
		   			printf("---------------------------\n");
					printf("\tMENU BANDAS\n");
					printf("---------------------------\n\n");
					printf("1 - Cadastrar banda\n");
					printf("2 - Consultar banda\n");
					printf("3 - Consultar tipo de musica\n");
					printf("4 - Listar bandas\n");
					printf("5 - Sair\n\n");
		   			printf("\nObrigado pela visita!");
		   			return 1;
		   		break;
		   		
		   }
		   
		   
	   }

		
 	 }else{
 	 	printf("Problemas ao abrir arquivo");
 	 	return 1;
	  }
  	
	
     
}
