#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int maximo(int func1, int func2);
int lcs(char cadenaA[], char cadenaB[], int indiceA, int indiceB, int dimA, int dimB, int dp[dimA][dimB]);

int main(void){
    char cadenaA[1000]; 
    char cadenaB[1000];
    int dimA, dimB;
    int indiceA=0, indiceB=0;
    int resultado=0;

    /*cadenaA=(char *) malloc(sizeof(char)*1000);
    cadenaB=(char *) malloc(sizeof(char)*1000);*/
    scanf("%s", cadenaA);
    scanf("%s", cadenaB);
    //printf("%s\n%s\n",cadenaA, cadenaB);

    dimA=strlen(cadenaA);
    dimB=strlen(cadenaB);
    int dp[dimA][dimB];
    /*dp=(int **) malloc(sizeof(int*)*dimA);
    for(int i=0; i<dimB; i++)
        dp[i]=(int *) malloc(sizeof(int)*dimB);*/

    for(int i=0; i<dimA; i++){
        for(int j=0; j<dimB; j++){
            dp[i][j]=-1;
        }
    }
    
    resultado=lcs(cadenaA, cadenaB, indiceA, indiceB, dimA, dimB, dp);
    printf("%d\n", resultado);

    /*free(cadenaA);
    free(cadenaB);
    free(dp);*/
    return 0;
}

int lcs(char cadenaA[], char cadenaB[], int indiceA, int indiceB, int dimA, int dimB, int dp[dimA][dimB]){
    if(indiceA==dimA || indiceB==dimB)
        return 0;

    if(dp[indiceA][indiceB]!=-1)
        return dp[indiceA][indiceB];

    if(cadenaA[indiceA]==cadenaB[indiceB])
        dp[indiceA][indiceB]=1+lcs(cadenaA, cadenaB, indiceA+1, indiceB+1, dimA, dimB, dp);
    else 
        dp[indiceA][indiceB]=maximo(lcs(cadenaA, cadenaB, indiceA, indiceB+1, dimA, dimB, dp), lcs(cadenaA, cadenaB, indiceA+1, indiceB, dimA, dimB, dp));
    
    return dp[indiceA][indiceB];
}

int maximo(int func1, int func2){
    if(func1>func2)
        return func1;
    else
        return func2;
}