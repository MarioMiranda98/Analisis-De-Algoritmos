#include<stdio.h>
#include<stdlib.h>


void mezclaMerge(int* numeros, int bajo, int mitad, int alto);
void ordenamientoMerge(int* numeros, int bajo, int alto);

int main(){
    int *numeros;
    numeros=NULL;
    int totalNumeros=0;

    printf("Ingresa una cantidad de numeros a ordenar\n");
    scanf("%i", &totalNumeros);
    numeros=(int *) malloc(sizeof(int)*totalNumeros);

    printf("Ingresa los numeros del arreglo a ordenar\n");
    for(int i=0; i<totalNumeros; i++)   
        scanf("%i", &numeros[i]);
    
    ordenamientoMerge(numeros, 0, totalNumeros);


    printf("Arreglo ordenado\n");
    for(int i=1; i<=totalNumeros; i++)
        printf("%i, ", numeros[i]);

    free(numeros);
    return 0;
}

void ordenamientoMerge(int* numeros, int bajo, int alto){
    if(bajo<alto){
        int mitad=bajo+(alto-bajo)/2;
        ordenamientoMerge(numeros, bajo, mitad);
        ordenamientoMerge(numeros, mitad+1, alto);
        mezclaMerge(numeros, bajo, mitad, alto);
    }
}

void mezclaMerge(int* numeros, int bajo, int mitad, int alto){
    int dimension1=mitad-bajo+1;
    int dimension2=alto-mitad;
    int i,j,k;
    int A[dimension1], B[dimension2];

    for(i=0; i<dimension1; i++)
        A[i]=numeros[bajo+i];
    for(j=0; j<dimension2; j++)
        B[j]=numeros[mitad+1+j];

    i=0;
    j=0;
    k=bajo;

    while(i<dimension1 && j<dimension2){
        if(A[i]<=B[j]){
            numeros[k]=A[i];
            i++;
        }else{
            numeros[k]=B[j];
            j++;
        }
        k++;
    }

    while(i<dimension1){
        numeros[k]=A[i];
        k++;
        i++;
    }

    while(j<dimension2){
        numeros[k]=B[j];
        k++;
        j++;
    }

}




