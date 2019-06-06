#include<stdio.h>
#include<stdlib.h>

int maximo(int valor1, int valor2);

int main(){
    int capacidad, articulos;
    scanf("%d %d", &capacidad, &articulos);
    int peso[articulos], valor[articulos];
    int dp[articulos+1][capacidad+1];

    for(int i=1; i<articulos+1; i++)
        scanf("%d %d", &peso[i], &valor[i]);


    //printf("Exito3\n");
    for(int i=0; i<articulos+1; i++)
        dp[i][0]=0;
    for(int j=0; j<capacidad+1; j++)
        dp[0][j]=0;

    //printf("Exito4\n");
    for (int i=1; i<=articulos; i++) { 
		for (int j=1; j<=capacidad; j++) { 
			if (peso[i]>j) {
				dp[i][j]=dp[i-1][j];
			} else {
				dp[i][j]=maximo(dp[i-1][j], valor[i]+dp[i-1][j-peso[i]]);
			}
		}
	}
    //printf("Exito Final\n");
    printf("%d\n", (dp[articulos][capacidad]));
    return 0;
}

int maximo(int valor1, int valor2) {  
    return (valor1>valor2)?valor1:valor2; 
}
