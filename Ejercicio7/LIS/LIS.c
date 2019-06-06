#include<stdio.h>
#include<stdlib.h>

int maximo(int numero1, int numero2);
int LongIncSec(int* numeros, int* dp, int tam);

int main(void){
    int tam;
    scanf("%d", &tam);
    int* numeros=(int *) malloc(sizeof(int)*tam);
    int* dp=(int *) malloc(sizeof(int)*tam);

    for(int i=0; i<tam; i++){
        scanf("%d", &numeros[i]);
        dp[i]=-1;
    }
    
    printf("%d\n", LongIncSec(numeros, dp, tam));

    free(numeros);
    free(dp);
    return 0;
}

int LongIncSec(int* numeros, int* dp, int tam){
    dp[0]=1;

    for(int i=1; i<tam; i++){
        for(int j=0; j<tam; j++){
            if(numeros[j]<numeros[i] && dp[j]>dp[i]){
                dp[i]=dp[j];
            }
        }
        dp[i]++;
    }

    int lista=0;

    for(int i=0; i<tam; i++){
        lista=maximo(lista,dp[i]);
    }

    return lista;
}

int maximo(int numero1, int numero2){
    return (numero1>numero2)?numero1:numero2;
}