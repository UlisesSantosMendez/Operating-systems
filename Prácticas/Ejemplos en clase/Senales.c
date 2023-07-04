#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

void listener(int);

int main(){
    srand(time(NULL));
    int num;
    int i,j,k;
    int n1,n2;
    int mata[n1][n2], matb[n2][n1], matc[n2][n1];
    num=rand()%11+90;
    for(i=1;i<=64;i++){
        signal(i,listener);
    }
    printf("Id del proceso: %d\n",getpid());
    while(1){
        printf("Esperando una señal...\n");
        //sleep(1);
        printf("Ingresa el numero de filas para la matriz A:\n");
        scanf("%d",&n1);
        printf("Ingresa el numero de columnas para la matriz A:\n");
        scanf("%d",&n2);
        for(j=0;j<=n1-1;j++){
            for(k=0;k<=n2-1;k++){
                scanf("%d",&mata[num][num]);
                scanf("%d",&matb[num][num]);
            }  
        }
        for(j=0;j<=n1-1;j++){
            for(k=0;k<=n2-1;k++){
                printf("\t %i",&mata[j][k]);
            }
        }

        
        

    }

    return 0;
}

void listener(int sinal){
    signal(sinal,listener);
    printf("La señal recibida es: %d\n",sinal);
    switch (sinal){
    case 2:
        exit(0);
    break;
    case 9:
        exit(0);
    break;
    case 15:
        exit(0);
    break;
    }
}