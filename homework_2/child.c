#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(char * argv[])
{
   printf("PID потомка %d\n",getpid());
   exit(EXIT_SUCCESS);

   return 0;
}
