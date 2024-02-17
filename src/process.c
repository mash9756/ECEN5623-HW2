/**
 *  @name   process.c
 *  @brief  simple function to create a process that waits on a semaphore
 * 
 *  @cite   Example code for creating processes with fork()
 *          https://www.geeksforgeeks.org/using-fork-produce-1-parent-3-child-processes/
 * 
 *  @cite   Previous code I wrote for AESD that uses processes
 *          https://github.com/cu-ecen-aeld/assignments-3-and-later-mash9756/blob/assignment-6-part-1-complete/server/aesdsocket.c
 * 
 *  @cite   https://stackoverflow.com/questions/8860029/how-do-you-create-a-process-in-c-that-runs-after-the-parent-has-died
 * 
 *  @note   currently doesn't work, semaphore is in shared memory
 *          fork() creates a copy of the current process, so its a copy not the same one
 *          need to use process semaphore, see below 
 *              https://stackoverflow.com/questions/8359322/how-to-share-semaphores-between-processes-using-shared-memory
*/

#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>

sem_t semaphore;
  
int main() 
{ 
    pid_t pid; 
    pid_t child_sid = 0;
    sem_init(&semaphore, 0, 0);
    int status;
   
    printf("\nMain creating a new process...\n");
    pid = fork(); 

    if (pid == 0) { 
        printf("I'm the lil kiddo, pid = %d\n", getpid());
        sem_wait(&semaphore);
        printf("\nGot semaphore we good\n");
    }
    else {
        printf("I'm the dad, pid = %d\n", getpid());
        sem_post(&semaphore);
        printf("Waiting on child pid %d\n", pid);
        waitpid(pid, &status, 0);
        printf("\nBoth done!\n");
    }
}