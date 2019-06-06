#include<stdio.h>
#include<stdlib.h>

int minimo(int numero1, int numero2);
int camino(int** matriz, int** dp, int posX, int posY, int fila, int columna, int suma);

int main(void){
    int fila, columna;
    int** matriz;
    int** dp;

    scanf("%d %d", &fila, &columna);

    matriz=(int **) malloc(sizeof(int*)*fila);
    dp=(int **) malloc(sizeof(int*)*fila);

    for(int i=0; i<columna; i++){
        matriz[i]=(int *) malloc(sizeof(int)*columna);
        dp[i]=(int *) malloc(sizeof(int)*columna);
    }

    for(int i=0; i<fila; i++){
        for(int j=0; j<columna; j++){
            scanf("%d", &matriz[i][j]);
            dp[i][j]=0;
        }
    }

    printf("%d\n", camino(matriz, dp, 0, 0, fila, columna, 0));
    
    free(matriz);
    free(dp);
    return 0;
}

int camino(int** matriz, int** dp, int posX, int posY, int fila, int columna, int suma){
    if(posX==fila-1 && posY==columna-1){
        if(dp[posX][posY]!=0){
            return suma+dp[posX][posY];
        }else{
            dp[posX][posY]=matriz[posX][posY];
        }
        return suma+matriz[posX][posY];
    }

    if(posX<fila-1 && posY<columna-1){
        if(dp[posX][posY]!=0){
            return suma+dp[posX][posY];
        }else{
            dp[posX][posY]=matriz[posX][posY]+minimo(camino(matriz, dp, posX+1, posY, fila, columna, suma), camino(matriz, dp, posX, posY+1, fila, columna, suma));
        }
        return suma+dp[posX][posY];
    }

    if(posX<fila-1 && posY==columna-1){
        if(dp[posX][posY]!=0){
			return suma+dp[posX][posY];
		}else{
		    dp[posX][posY]=matriz[posX][posY]+camino(matriz, dp, posX+1, posY, fila, columna, suma);
	    }
		return suma+dp[posX][posY];
    }

    if(posX==fila-1 && posY<columna-1){
        if(dp[posX][posY]!=0){
			return suma+dp[posX][posY];
		}else{
		    dp[posX][posY]=matriz[posX][posY]+camino(matriz, dp, posX, posY+1, fila, columna, suma);
	    }
		return suma+dp[posX][posY];
    }

}

int minimo(int numero1, int numero2){
    if(numero1<numero2){
        return numero1;
    }else if(numero1>numero2){
        return numero2;
    }else{
        return numero1;
    }
}