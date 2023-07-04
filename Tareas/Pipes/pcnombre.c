#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
    int fd;
    char buf[] = "mensaje";
    mkfifo("/tmp/mi_fifo", 0666);
    fd=open("/tmp/mi_fifo", O_WRONLY);
    write(fd, buf, sizeof(buf));
    return 0;
}