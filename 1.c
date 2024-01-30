#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main(){

    pid_t parent_pid = getpid();
    pid_t pid= fork();

    if(pid == -1){
        printf("Fork failed");
    }
    else if(pid>0){
        int status;
        printf("parent id is: %d", getpid());
        waitpid(pid,&status,0);
    }
    else{
        printf("child process id: %d", (int)pid);
        printf("parent process id: %d",getpid());
        execl("/bin/ls","ls","-s","-l","-h",NULL);
        _exit(EXIT_FAILURE);
    }
}