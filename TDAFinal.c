#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TDA.h"

/*romano p/ decimal*/
int romToDec(char *entrada) 
{
	int decimal[10] = {1, 5, 10, 50, 100, 500, 1000};
	char romanos[20] = "IVXLCDM"; /*todos caracteres romanos*/
	int n = 0, i, j, z = 0;
	/*To Upper*/
	while(entrada[z])
		{
			entrada[z] = toupper(entrada[z]);
			z++;
		}
	i = strlen(entrada) - 1;
	n = n + decimal[comparaRom(entrada[i])];
	j = i;
	i--;
	
	while(i >= 0)
	{
		if(comparaRom(entrada[i]) >= comparaRom(entrada[j]))
			n = n + decimal[comparaRom(entrada[i])];
		else
			n = n - decimal[comparaRom(entrada[i])];
		i--;
		j--;
	}
	return n;
}
/*compara o vetor dos numerais árabes 
com vetor o de numerais romanos*/
int comparaRom(char x)
{
	int decimal[10] = {1, 5, 10, 50, 100, 500, 1000};
	char romanos[20] = "IVXLCDM"; /*todos caracteres romanos*/
	int cont;
	for(cont = 0; cont < 7; cont++)
	{
		if (romanos[cont] == x)
			return cont;
	}
	return -1;
}
/*checa se é um numero romano válido
com problemas ao detectar a validade de xviiiiiii*/
int validade(char *entrada)
{
	int decimal[10] = {1, 5, 10, 50, 100, 500, 1000};
	char romanos[20] = "IVXLCDM"; /*todos caracteres romanos*/
	int cont, z = 0, cont2;
	while(entrada[z])
		{
			entrada[z] = toupper(entrada[z]);
			z++;
		}
	for(cont2 = 0; cont2 < strlen(entrada); cont2++)
	{
		for(cont = 0; cont < strlen(romanos); cont++)
		{
			if(entrada[cont2] == romanos[cont])
				break;
		}
		if(cont == strlen(romanos))
			return 0;
	}
	for(cont = 0; cont < strlen(entrada) - 1; cont++)
	{	
		if((decimal[comparaRom(entrada[cont])] * 10 < decimal[comparaRom(entrada[cont + 1])] || 
		(entrada[cont] != 'I' && entrada[cont] != 'X' && entrada[cont] != 'C')) 
		&& (decimal[comparaRom(entrada[cont])] < decimal[comparaRom(entrada[cont + 1])]))
		return 0;
	}
	return 1;
}

/*decimal p/ romano*/
char* decToRom(int arab) 
{
	int decimal[10] = {1, 5, 10, 50, 100, 500, 1000};
	char romanos[20] = "IVXLCDM"; /*todos caracteres romanos*/
	int beg, end, d, dec;
	char *resposta = malloc(sizeof(char) * 1000);
	if(arab < 0)
	{
		strcpy(resposta, "-1");
		return resposta;
	}
	else if(arab == 0)
	{
		strcpy(resposta, "Nulla");
		return resposta;
	}
	else if(arab >= 4000)
	{
		strcpy(resposta, "-1");
		return resposta;
	}
	else
	{
		strcpy(resposta, "");
		/*Encontrar limite*/
		while(arab > 0)
		{
			for(beg = 6; beg > 0; beg--)
			{
				if(arab >= decimal[beg])
					break;
			}
			
			for(end = 0; end < 7; end++)
			{
				if(arab <= decimal[end])
					break;							
			}
			/*get left most digit in arab whatever this means*/
			d = arab;
			while(d != 0)
			{
				d = d / 10;
				if(d < 10)
					break;
			}
			/*printar numero romano*/
			char aux[3]; 
			if(arab < 10 && arab == 4)
			{
				aux[0] = romanos[beg];
				aux[1] = romanos[end];
				aux[2] = '\0';
				
				strcat(resposta, aux);
				arab = 0;
			}
			else if(arab > 10 && d == 4)
			{
				aux[0] = romanos[beg];
				aux[1] = romanos[end];
				aux[2] = '\0';
				
				strcat(resposta, aux);
				arab = arab - (decimal[end] - decimal[beg]);
			}
			else if(arab < 10 && arab == 9)
			{
				aux[0] = romanos[beg - 1];
				aux[1] = romanos[end];
				aux[2] = '\0';
				
				strcat(resposta, aux);
				//printf("%c%c", romanos[beg - 1], romanos[end]);
				arab = 0;
			}	
			else if(arab > 10 && d == 9)
			{
				aux[0] = romanos[beg - 1];
				aux[1] = romanos[end];
				aux[2] = '\0';
				
				strcat(resposta, aux);
				//printf("%c%c", romanos[beg - 1], romanos[end]);
				arab = arab - (decimal[end] - decimal[beg -1]);
			}
			else
			{
				aux[0] = romanos[beg];
				aux[1] = '\0';
				//printf("%c", romanos[beg]);
				strcat(resposta, aux);
				arab = arab - decimal[beg];
			}
		}
		return resposta;
	}	
}
/*Verificação de igualdade entre dois numeros romanos*/
int igualdadeRom(char *entrada, char *entrada2)
{
	if(strcmp(entrada, entrada2) == 0)
		return 1;
	else
		return 0;
}
/*Operações aritméticas*/
void operacoes(char *entrada, char *entrada2)
{
	int numRom1, numRom2, mult, add, sub, div;
	char addRom[20], multRom[20], subRom[20], divRom[20];
	
	numRom1 = romToDec(entrada);
	numRom2 = romToDec(entrada2);
	
	add = numRom1 + numRom2;
	sub = numRom1 - numRom2;
	mult = numRom1 * numRom2;
	div = numRom1 / numRom2;
	
	strcpy(addRom, decToRom(add));
	strcpy(subRom, decToRom(sub));
	stpcpy(multRom, decToRom(mult));
	strcpy(divRom, decToRom(div));
	
	printf("Resultados em numerais Arabes\n");
	printf("-Adicao: %d\n", add);
	printf("-Subtracao: %d\n", sub);
	printf("-Multiplicacao: %d\n", mult);
	printf("-Divisao: %d\n", div);
	puts("");
	
	printf("Resultados em numerais Romanos\n");
	printf("-Adicao: %s\n", addRom);
	printf("-Subtracao: %s\n", subRom);
	printf("-Multiplicacao: %s\n", multRom);
	printf("-Divisao: %s\n", divRom);
}