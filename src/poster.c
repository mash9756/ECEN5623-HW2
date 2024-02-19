/**
 *  @name   poster.c
 *  @brief  simple process to post a semaphore
 * 
 *  @cite   https://stackoverflow.com/questions/36755003/initialise-semaphores-using-sem-open
 * 
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h> 
#include <unistd.h>

#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
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

    printf("\nPosting Semaphore...");
    sem_post(sema);
    printf("Done!\n\n");
}