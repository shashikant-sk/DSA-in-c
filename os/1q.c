#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
int value = 5;
int main(){
    pid_t pid;
    pid=fork();
    if(pid==0){
        value +=15;

    }
    else if(pid>0) {
        wait(NULL);
        printf("PARENT: VALUE =%d",value);
        exit(0);
    }

}