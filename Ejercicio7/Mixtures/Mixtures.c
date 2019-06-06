#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

long long int mezclar(int Mixtures[], int dp[100][100], int inicio, int final);
long long int minimo(long long int numero1, long long int numero2);
long long int suma(int Mixtures[], long long int inicio, long long int final);

int main(void){
    int noCasos=0;
    int dp[100][100];
    long long int resultado[100];
    int contador=0;

    while(scanf("%d", &noCasos)==1){
        int Mixtures[noCasos];
        for(int i=0; i<noCasos; i++){
            scanf("%d", &Mixtures[i]);
        }

        for(int i=0; i<100; i++)
            dp[i][0]=-1;

        for(int j=0; j<100; j++)
            dp[0][j]=-1;

        printf("%lld\n", mezclar(Mixtures, dp,0, noCasos-1));
    }
    
    return 0;
}

long long int mezclar(int Mixtures[], int dp[100][100], int inicio, int final){
    if(inicio>=final){
        return 0;
    }

    if(dp[inicio][final]!=-1){
        return dp[inicio][final];
    }

    dp[inicio][final]=INT_MAX;
    for(int i=inicio; i<=final; i++){
        dp[inicio][final]=minimo(dp[inicio][final],(mezclar(Mixtures, dp, inicio, i)+mezclar(Mixtures, dp, i+1, final)+(suma(Mixtures, inicio, i)*suma(Mixtures, i+1,final))));
    }

    return dp[inicio][final];
}

long long int suma(int Mixtures[], long long int inicio, long long int final){
    long long int res=0;
    for(int i=inicio; i<=final; i++){
        res+=Mixtures[i];
        res%=100;
    }
    return res;
}

long long int minimo(long long int numero1, long long int numero2){
    if(numero1<numero2){
        return numero1;
    }else if(numero1>numero2){
        return numero2;
    }else{
        return numero1;
    }
}