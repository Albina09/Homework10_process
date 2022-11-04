#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    pid_t pid;
    int status;

    if(argc == 1){
       printf("Введите команду\n");
       exit(EXIT_SUCCESS);
    }
  
    pid = fork();
    if(pid == -1){
        perror("fork");
	    exit(EXIT_FAILURE);
    }

    if(pid == 0){
        execvp(argv[1], &argv[1]);
	    exit(EXIT_SUCCESS);

    }else{

        if(wait(&status) == -1){
	        perror("wait");
	        exit(EXIT_FAILURE);
	    }

        
    }
    
    exit(EXIT_SUCCESS);
}
