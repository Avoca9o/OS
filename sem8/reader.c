#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SWR "/semaphore_writer"
#define SR "/semaphore_reader"

int main() {
    sem_t *sem_wr;
    sem_t *sem_r;
    FILE *buffer;
    char buffered_text[6];

    if ((sem_wr = sem_open(SWR, O_CREAT, 0666, 0)) == SEM_FAILED) {
        perror("Couldn't open semaphore writer");
        exit(1);
    }

    if ((sem_r = sem_open(SWR, O_CREAT, 0666, 0)) == SEM_FAILED) {
        perror("Couldn't open semaphore reader");
        exit(1);
    }
    fprintf(stdout, "posting sem writer\n");
    sem_post(sem_wr);
    while (1) {
        fprintf(stdout, "waiting for sem reader\n");
        sem_wait(sem_r);
        fprintf(stdout, "reader can do something\n");
        if ((buffer = fopen("buffer.txt", "r")) < 0) {
            perror("Can't open file for reading");
            exit(1);
        }
        fread(buffered_text, 1, 6, buffer);
        fprintf(stdout, "Reader read %s\n", buffered_text);
        if (strcmp(buffered_text, "exit\n") == 0) {
            sem_post(sem_wr);
            fclose(buffer);
            sem_close(sem_wr);
            sem_close(sem_r);
            sem_unlink(SWR);
            sem_unlink(SR);
            fprintf(stdout, "exit\n");
            break;
        }

        fclose(buffer);
        fprintf(stdout, "posting semaphore writer\n");
        sem_post(sem_wr);
    }
}