/*Родитель пораждает потомка*/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    pid_t pid;
    int status;

    pid = fork();
    if(pid == -1){
        perror("fork");
	    exit(EXIT_FAILURE);
    }

    if(pid == 0){
        printf("PID потомка %d\n",getpid());
	    exit(EXIT_SUCCESS);
    
    }else{

        if(wait(&status) == -1){
	        perror("wait");
	        exit(EXIT_FAILURE);
	    }
        printf("PID родителя %d\n",getpid());
    }

    exit(EXIT_SUCCESS);
}
