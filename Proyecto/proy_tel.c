#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <string.h>


char numtel(char [],int tama);
void Consumidor(void*);
void Productor(void*,char [], int tama);
pthread_mutex_t mutexProductor; //controla acceso a datos
pthread_mutex_t mutexConsumidor;
int seccionCritica1[1];
int seccionCritica2[1];
//int const numProducciones=40;
int const numProducciones=10;
int const numProductores=3, numConsumidores=2;
int maxdp=numProductores*numProducciones;
int maxdc=numConsumidores*numProducciones;

int main(){
    int i;
    char numcel[10];
    int tama=sizeof(numcel)/sizeof(char);
    //hilos
    pthread_t productores[numProductores];
    pthread_t consumidores[numConsumidores];
    
    //Inicializamos los mutex
    pthread_mutex_init(&mutexProductor, NULL);
    pthread_mutex_init(&mutexConsumidor, NULL);

    //Se cierra ell mutex del consumidor
    pthread_mutex_lock(&mutexConsumidor);
    
    //Hacemos 3 hilos Productores y 2 hilos consumidores
    for(i=0;i<numProductores;i++){
        pthread_create(&productores[i], NULL, (void*)Productor, NULL);
    }
    for(i=0;i<numConsumidores;i++){
        pthread_create(&consumidores[i], NULL, (void*)Consumidor, NULL);
    }
    for(i=0;i<numProductores;i++){
        pthread_join(productores[i],NULL);
    }
    for(i=0; i<numConsumidores;i++){
        pthread_join(consumidores[i],NULL);
    }
    return 0;
}
void Productor(void* arg,char numcel[],int tama){
    numcel[tama];
    int i,j,k;
    for(i=1;i<=numProducciones;i++){
        pthread_mutex_lock(&mutexProductor);
        for(j=0;j<=10;j++){
            seccionCritica1[j]=i;
        }
        printf("TELCEL produjo %s",numcel); 
        pthread_mutex_unlock(&mutexConsumidor);
    }
}
void Consumidor(void* arg){
    int i;
    do{
        if(maxdc==0){
            break;
        }
        pthread_mutex_lock(&mutexConsumidor);
        maxdc--;
        pthread_mutex_unlock(&mutexProductor);
    }while(maxdc);
}
char numtel(char numcel[],int tama){ //Genera el numero telefonico
    int ext= 55;
    int tel[7];
    int i;
    numcel[tama];
    srand(time(NULL));
    for(i=0;i<=7;i++){
        tel[i]=rand()%10;
    }
    sprintf(numcel,"%d%d%d%d%d%d%d%d%d",ext,tel[0],tel[1],tel[2],tel[3],tel[4],tel[5],tel[6],tel[7]);
    printf("%s\n",numcel);
    return numcel[tama];
}   
