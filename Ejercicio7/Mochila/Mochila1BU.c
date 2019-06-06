#include<stdio.h>
#include<stdlib.h>

int maximo(int valor1, int valor2);
int mochila(int capacidad, int articulos, int peso[], int valor[]);

int main(){
    int capacidad, articulos;
    scanf("%d %d", &capacidad, &articulos);
    int peso[articulos], valor[articulos];

    for(int i=0; i<articulos; i++)
        scanf("%d %d", &peso[i], &valor[i]);

    printf("%d\n", mochila(capacidad, articulos, peso, valor));

    return 0;
}

int mochila(int capacidad, int articulos, int peso[], int valor[]){
    if(capacidad==0 || articulos==0)
        return 0;
    if(peso[articulos-1]>capacidad)
        return mochila(capacidad, articulos-1, peso, valor);
    else 
        maximo(valor[articulos-1]+mochila(capacidad-peso[articulos-1], articulos-1, peso, valor), mochila(capacidad, articulos-1, peso, valor));
}

int maximo(int valor1, int valor2){
    return (valor1>valor2)?valor1:valor2;
}