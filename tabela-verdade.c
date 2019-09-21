#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void geraTabelaVerdade(int num_linhas, int num_colunas, bool **matriz);

void printaTabela(int num_linhas, int num_colunas, bool **matriz);

int main(int argc, char *argv[]){

    int colunas;
    printf("Digite quantas entradas tem a tabela Verdade: ");
    scanf("%d", &colunas);
    
    unsigned long linhas = pow(2, colunas);

    bool **matriz;
	matriz = (bool **) malloc (linhas * sizeof (bool *));
	for(int i = 0; i < linhas; i++){
		matriz[i] = (bool *) malloc (colunas * sizeof(bool));
	}

	geraTabelaVerdade(linhas, colunas, matriz);
    printaTabela(linhas, colunas, matriz);

	return 0;
}

void printaTabela(int num_linhas, int num_colunas, bool **matriz){

    for(int i = 0; i < num_linhas; i++){
        for(int j = 0; j < num_colunas; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void geraTabelaVerdade(int num_linhas, int num_colunas, bool **matriz){
	int cont = 0, soma = 0;
	bool bit = false;

	for(int j = num_colunas-1; j >= 0; j--){
		for(int i = 0; i < num_linhas; i++){
			if(soma == pow(2,cont)){
				bit = !bit;
				soma = 0;
			}
			if(bit){
				matriz[i][j] = true;
			}
			else{
				matriz[i][j] = false;
			}
			soma++;		
		}
		soma = 0;
		bit = false;
		cont++;
	}
}
