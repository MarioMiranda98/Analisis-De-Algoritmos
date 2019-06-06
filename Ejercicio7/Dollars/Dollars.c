#include<stdio.h>
#include<stdlib.h>

int main(void){
    int monedas[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
    long long int dp[30001];
    int bandera=1;
    float monedaCambio;
    int conversion;
    float monedasFinal[1000];
    long long int cambio[1000];
    int contador=0;

    for(int i=0; i<30001; i++)
        dp[i]=0;

    dp[0]=1;//Caso base donde se introduce 0.00 como moneda

    for(int i=0; i<11; i++){
        for(int j=monedas[i]; j<=30001; j++){
            dp[j]+=dp[j-monedas[i]];
        }
    }

    /*for(int i=0; i<100; i++)
        printf("%lld\n", dp[i]);*/

    while(bandera){
        scanf("%f", &monedaCambio);
        if(monedaCambio!=0.00){
            conversion=(int)(monedaCambio*100);
            //printf("%d\n", conversion);
            monedasFinal[contador]=monedaCambio;
            cambio[contador]=dp[conversion];
            contador++;
        } else{
            bandera=0;
        }
    }

    for(int i=0; i<contador; i++)
        printf("%.2f\t%lld\n", monedasFinal[i], cambio[i]);

    return 0;
}