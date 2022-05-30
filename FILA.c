/*Implementar em linguagem C, utilizando vetores, a estrutura FILA:

Funcionalidades a serem implementadas na estrutura FILA:

Insercao, remocao, exibicao dos elementos e suas respectivas posicoes na 
fila, verificacao se a fila esta vazia, verificacao se a fila esta cheia, localizacao de um
 elemento, retornando -1 se nao estiver na fila e, a posicao do elemento caso esteja na
 FILA.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define TAM 6

	int fila[TAM];
	int inicio,fim,num,i=0;
	char opcao, resp='S';

void inicializa(){
	inicio=0;
	fim=-1;
}

bool verifica_fila_vazia(){
	if(inicio>fim){
        return true;
    }else{
        return false;
    }
}

bool verifica_fila_cheia(){
    if(fim==TAM-1){
        return true;
    }else{
        return false;
    }
}

bool inserir_elemento(int num){
	if(verifica_fila_cheia()){
		printf("\n A fila ja esta cheia, nao foi possivel inserir um novo elemento.\n");
        return false;
	}else{
		fim++;
        fila[fim]=num;
        printf("\n Ok, o elemento %d foi inserido na fila.\n", num);
        return true;
    }
}

bool remover_elemento(){
	

	if(verifica_fila_vazia()){
		printf("\n Fila vazia. Nao foi possivel remover.\n");
    	return false;
    }else{
	    
		 	inicio++;
		 	if(inicio<=fim){
	     	printf("\n Elemento removido! \n");    
	   	 	return true;
   		}	
	}
   		  
}

void exibe_fila(){
	printf("\n===========FILA===========\n");
	for(i=inicio; i<TAM; i++){
		printf("\n Posicao: |%d| Elemento|%d|\n", i, fila[i]);
	}
}

void localiza_elemento(int num){
	int loclz=0;
	for(i=0; i<TAM; i++){
	   if(fila[i]==num){
	    	printf("\n O elemento |%d| foi encontrado na posicao |%d|\n", num, i);
	    	loclz=1;
	   	}
	}
	
	if(loclz==0){
		printf("\n Elemento nao encontrado\n");
	}	
}

int main (){
	
	inicializa();
	
	while (resp =='S'){
		printf("\n\nMENU DE OPCOES: \n\n");
		printf("[A] - INSERIR ELEMENTO \n");
		printf("[B] - REMOVER ELEMENTO \n");
		printf("[C] - EXIBIR FILA \n");
		printf("[D] - VERIFICAR FILA VAZIA \n");
		printf("[E] - VERIFICAR FILA CHEIA \n");
		printf("[F] - LOCALIZAR ELEMENTO \n");
		printf("\n\nInforme a opcao escolhida: \n\n");
		fflush(stdin);
		scanf("%c", &opcao);
		opcao = toupper (opcao);
			//system("pause");
		system("cls");
	
		switch(opcao){
			case 'A':
			printf("\nINSERIR ELEMENTO: \n");
			printf("\nInforme o elemento que sera inserido: \n");
			scanf("%d", &num);
			inserir_elemento(num);
			printf("\n Digite 'S' para continuar ou 'N' para finalizar!\n");
			fflush(stdin);
			scanf("%c", &resp);
			resp = toupper (resp);
			break;
			
			case 'B':
			printf("\nREMOVER ELEMENTO: \n");
			remover_elemento();
			exibe_fila();
			printf("\n Digite 'S' para continuar ou 'N' para finalizar!\n");
			fflush(stdin);
			scanf("%c", &resp);
			resp = toupper (resp);
			break;
			
			case 'C':
			printf("\nEXIBIR FILA: \n");
			exibe_fila();
			printf("\n Digite 'S' para continuar ou 'N' para finalizar!\n");
			fflush(stdin);
			scanf("%c", &resp);
			resp = toupper (resp);
			break;
			
			case 'D':
			printf("\nVERIFICAR FILA VAZIA: \n");
			if(verifica_fila_vazia()){
				printf("\n A fila esta vazia \n");
			}else{
				printf("\n A fila nao esta vazia \n");
			}
			printf("\n Digite 'S' para continuar ou 'N' para finalizar!\n");
			fflush(stdin);
			scanf("%c", &resp);
			resp = toupper (resp);
			break;
			
			case 'E':
			printf("\nVERIFICAR FILA CHEIA: \n");
			if(verifica_fila_cheia()){
				printf("\n A fila esta cheia \n");
			}else{
				printf("\n A fila nao esta cheia \n");
			}
			printf("\n Digite 'S' para continuar ou 'N' para finalizar!\n");
			fflush(stdin);
			scanf("%c", &resp);
			resp = toupper (resp);
			break;
			
			case 'F':
			printf("\nLOCALIZAR ELEMENTO: \n");
			printf("\nInforme qual elemento deseja localizar: \n");
			scanf("%d", &num);
			localiza_elemento(num);
			printf("\n Digite 'S' para continuar ou 'N' para finalizar!\n");
			fflush(stdin);
			scanf("%c", &resp);
			resp = toupper (resp);
			break;
					
			defaut:
			printf("\n Opção invalida\n");
			fflush(stdin);
			resp='N';
			resp = toupper (resp);
		}
		system("cls");
	}
	
	printf("\n\nFIM!!!\n\n");

	system("pause");
	return 0;
}
