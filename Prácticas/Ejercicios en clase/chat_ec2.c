#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

#define SIZE1 50
#define SIZE2 50

int main(int argc, char **argv){
    int e[2], readbytes;
    int r[2];
    char ein[SIZE1];
    char rin[SIZE2];
    pid_t pid;
    pipe(e);
    pipe(r);
    if((pid=fork())==-1){
        printf("ERROR");
    }
    if((pid=fork())==0){ //hijo
        do{
            scanf("%s",&ein);
            close(e[1]);
            close(r[0]);
            readbytes=read(e[0],ein,SIZE1);
            write(r[1],rin,strlen(rin));
            close(e[0]);
            close(r[1]);

        }
        while(ein != 'fin');
    }
    else{
        do{
            scanf("%s",&rin);
            close(e[0]);
            close(r[1]);
            write(e[1], ein, strlen(rin));
            readbytes=read(r[0],rin, SIZE2);
            close(e[1]);
            close(r[0]);
        }
        while(rin != 'fin');
    }
    
    return 0;
}