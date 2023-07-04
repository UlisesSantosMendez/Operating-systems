#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    int fd[2];
    char buf[10];
    int fr = fork();
    int n;
    if(pipe(fd) == -1){
        fprintf(stderr,"ERROR EN PIPE\n");
    }
    else{
        switch (fr){
            case -1:
                fprintf(stderr,"ERROR AL CREAR PROCESO");
            break;
            case 0:
                close(fd[0]);//cierra descriptor de fichero de solo lectura
                write(fd[1], "HOLA", 10);
                close(fd[1]);
                exit(0);
            break;
            default:
                close(fd[1]);//cierra descriptor de fichero de escritura
                printf("El padre lee el PIPE\n");
                n = read(fd[0], buf, sizeof(buf));
                printf("Padre lee: %s\n", buf);
                close(fd[0]);
            break;
        }
    }
    return 0;
}