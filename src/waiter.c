/**
 *  @name   process.c
 *  @brief  simple process to wait on a semaphore
 * 
 *  @cite   https://stackoverflow.com/questions/36755003/initialise-semaphores-using-sem-open
 * 
*/

#include <stdio.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h> 
#include <unistd.h>

#include <fcntl.h>        
#include <sys/stat.h>
#include <semaphore.h>


sem_t *sema;
  
int main() 
{ 
    sema = sem_open("/sema", O_CREAT, 0644, 0);
    if (sema == SEM_FAILED) {
        sem_close(sema);
        perror("Failed to open semphore");
        exit(-1);
    }

    printf("\nWaiting for Semaphore... pid = %d\n", getpid());
    while(1){
        sem_wait(sema);
        printf("Semaphore obtained. Exiting...\n\n");
        break;
    }
    sem_close(sema);
    exit(0);
}