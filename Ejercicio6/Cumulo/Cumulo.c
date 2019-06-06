#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int largo;

float distanciaMinima(float* x, float*y, largo inicio, largo fin);
float distancia(float x1, float y1, float x2, float y2);
float minimo(float derecha, float izquierda, float centro);
float* x;
float* y;

int main(void){
    largo estrellas=0;
    scanf("%lld", &estrellas);
    x=(float *) malloc(sizeof(float)*estrellas);
    y=(float *) malloc(sizeof(float)*estrellas);
    
    for(int i=0; i<estrellas; i++){
        scanf("%f", &x[i]);
        scanf("%f", &y[i]);
    }

    printf("%.3f", distanciaMinima(x,y,0,estrellas));
    free(x);
    free(y);
    return 0;
}

float distanciaMinima(float* x, float*y, largo inicio, largo fin){
    if(inicio<fin){
        largo medio=0;
        medio=(inicio+fin)/2;
        float derecha=distanciaMinima(x,y,inicio,medio);
        float izquierda=distanciaMinima(x,y,medio+1,fin);
        float disF=0, centro=0;
        for(largo i=0; i>=inicio; i--){
            for(largo j=medio+1; j<=fin;j++){
 				disF=distancia(x[i],y[i],x[j],y[j]);
 				if(((disF<=centro) | (centro==0))){
 					centro=disF;
 				}
 			}
        }
        return minimo(derecha, izquierda, centro);
    }else {
        return 0;
    }
}

float minimo(float derecha, float izquierda, float centro){
	if(derecha!=0 && izquierda!=0){
		if (derecha<=izquierda && derecha<=centro){
			 return derecha;
		}else if (izquierda<=derecha && izquierda<= centro){
			return izquierda;
		}else{
			return centro;
		}
	}else if(derecha!=0){
		if(derecha<=centro){
			return derecha;
		}else{
			return centro;
		}	
	}else if(izquierda!=0){
		if(izquierda<=centro){
			return izquierda;
		}else{
			return centro;
		}
	}else
		return centro;
}

float distancia(float x1, float y1, float x2, float y2){
    float distancia=0, a=0, b=0, a2=0, b2=0;
    a=x1-x2;
    b=y1-y2;
    a2=pow(a,2);
    b2=pow(b,2);
    distancia=sqrt(a2+b2);
    return distancia;
}