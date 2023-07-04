#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
    int fd;
    char buf[30];
    int n;
    fd = open("/tmp/mi_fifo",O_RDONLY);
    n = read(fd,buf,sizeof(buf));
    printf("No bytes: %d \n", n);
    printf("Se lee: %s \n", buf);
    close(fd);
    return 0;
}