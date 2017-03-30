#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TDA.h"
 
int main()
{
	int opcao, rom, beg, end, d, arab, dec;
	char entrada[20], entrada2[20], menu;
	int result;
	
	while(1)
	{
		if(menu == 'n' || menu == 'N')
			break;
		printf("Pressione a operação desejada:\n\n");
		printf("(1) Converter numeral Romano para Árabe\n");
		printf("(2) Converter numeral Árabe para Romano\n");
		printf("(3) Operações aritméticas com algarismos romanos\n");
		printf("(4) Comparar dois numeros romanos\n");
		printf("(5) Verificar se o numeral romano é válido\n");
		
		scanf("%d", &opcao);
		/*1- Romanos p/ Árabe*/
		if(opcao == 1)
		{
			printf("Insira o numeral romano (000 para sair)\n");
			scanf(" %s", entrada);
			while(strcmp(entrada, "000") != 0)
			{
				if(validade(entrada))
				{
					rom = romToDec(entrada);
					printf("Romanos para decimal: %d\n", rom);	
				}
				else
					printf("Numero romano inválido\n");
				printf("Insira o numero romano: (000 p/ sair)\n");	
				scanf("%s", entrada);
			}
		}
		/*2- Árabe p/ Romanos*/
		if(opcao == 2)
		{
			printf("Insira o numeral árabe (-1 p/ sair)\n");
			scanf("%d", &arab);
			while(arab != -1)
			{
				char *resposta = decToRom(arab);
				if(strcmp(resposta, "-1") == 0) 
				{
					printf("Valores inválidos\n");
				}
				else
					printf("%s", resposta);
				
				printf("\nInsira o numeral árabe (-1 p/ sair)\n");
				scanf("%d", &arab);
			}
		}
		/*3- Operações aritméticas*/
		if(opcao == 3)
		{
			printf("Insira o numeral Romano:\n");
			scanf(" %s", entrada);
			printf("Insira o 2º numeral Romano\n");
			scanf(" %s", entrada2);
			while(strcmp(entrada, "000") != 0 && strcmp(entrada2, "000") != 0)
			{
				operacoes(entrada, entrada2);
				printf("Insira o numeral Romano: (000 p/ sair)\n");	
				scanf(" %s", entrada);
				printf("Insira o 2º numeral Romano: (000 p/ sair)\n");	
				scanf(" %s", entrada2);
			}
			
		
		}
		/*4- Comparar dois numeros romanos*/
		if(opcao == 4)
		{
			printf("Insira o numeral Romano");
			scanf(" %s", entrada);
			printf("Insira o 2º numeral Romano");
			scanf(" %s", entrada2);
			while(strcmp(entrada, "000") != 0 && strcmp(entrada2, "000") != 0)
			{
				if(igualdadeRom(entrada, entrada2))
					printf("Iguais\n");
				else
					printf("Diferentes\n");	
				printf("Insira o numeral Romano: (000 p/ sair)\n");	
				scanf(" %s", entrada);
				printf("Insira o 2º numeral Romano: (000 p/ sair)\n");	
				scanf(" %s", entrada2);
			}
		}
		/*5- Verificar se numero romano é válido*/
		if(opcao == 5)
		{
			printf("Insira o numeral romano (000 para sair)\n");
			scanf(" %s", entrada);
			while(strcmp(entrada, "000") != 0)
			{
				if(validade(entrada))
					printf("Válido\n");
				else
					printf("Inválido\n");
				
				printf("Insira o numero romano: (000 p/ sair)\n");	
				scanf("%s", entrada);
			}
		}			
		printf("\nVoltar ao menu? (S/N)");
		scanf(" %c", &menu);
	}
}