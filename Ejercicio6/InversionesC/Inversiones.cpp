#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long int largo;

largo inversiones(largo numeros[], largo numerosTemporal[], largo izquierda, largo derecha);
largo merge(largo numeros[], largo numerosTemporal[], largo izquierda, largo centro, largo derecha);

int main(void){   
    largo veces=0;

    //cout<<"Ingresa el numero de casos prueba"<<endl;
    cin>>veces;
    largo resultado[veces];

    for(largo i=0; i<veces; i++){
        largo totalNumeros=0;
        //cout<<"Ingresa la cantidad de numeros a leer"<<endl;
        cin>>totalNumeros;
        largo numeros[totalNumeros];
        largo numerosTemporal[totalNumeros];

        //cout<<"Ingresa los datos al arreglo"<<endl;
        for(largo i=0; i<totalNumeros; i++)
            cin>>numeros[i];
    
        resultado[i]=inversiones(numeros, numerosTemporal, 0, totalNumeros);
    }

    for(largo i=0; i<veces; i++)
        cout<<resultado[i]<<endl;
    return 0;
}

largo inversiones(largo numeros[], largo numerosTemporal[], largo izquierda, largo derecha){
    largo centro, numeroInversiones=0;
    if(derecha>izquierda){
        centro=(derecha+izquierda)/2;
        numeroInversiones=inversiones(numeros, numerosTemporal, izquierda, centro);
        numeroInversiones+=inversiones(numeros, numerosTemporal, centro+1, derecha);
        numeroInversiones+=merge(numeros, numerosTemporal, izquierda, centro+1, derecha);
    }
    return numeroInversiones;
}

largo merge(largo numeros[], largo numerosTemporal[], largo izquierda, largo centro, largo derecha){
    largo i,j,k;
    largo numeroInversiones=0;

    i=izquierda;
    j=centro;
    k=izquierda;

    while((i<=centro-1) && (j<=derecha)){
        if(numeros[i]<=numeros[j]){
            numerosTemporal[k++]=numeros[i++];
        }else {
            numerosTemporal[k++]=numeros[j++];
            numeroInversiones+=(centro-i);
        }
    }

    while(i<=centro-1)
        numerosTemporal[k++]=numeros[i++];

    while(j<=derecha)
        numerosTemporal[k++]=numeros[j++];

    for(i=izquierda; i<=derecha; i++)
        numeros[i]=numerosTemporal[i];
    
    return numeroInversiones;
}