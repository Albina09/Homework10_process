#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1){
        perror("fork");
	    exit(EXIT_FAILURE);
    }

    if (pid == 0){
	    char *child[] = {"./child", NULL};
        execvp(child[0], child);
        
        exit(EXIT_SUCCESS);

    }else{
        
        if(wait(&status) == -1){
	        perror("wait");
	        exit(EXIT_FAILURE);
	    }
	    printf("PID родтеля %d\n", getpid());
    }
   
    exit(EXIT_SUCCESS);
}

