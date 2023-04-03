#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWR "/semaphore_writer"
#define SR "/semaphore_reader"


int main(int argc, char* argv[]) {
    char buffered_text[6];
    if (argc != 2) {
        perror("You should enter some text");
        exit(1);
    }

    sem_t *sem_wr;
    sem_t *sem_r;
    size_t size = strlen(argv[1]);
    size_t i = 0;
    FILE *buffer;

    if ((sem_wr = sem_open(SWR, O_CREAT, 0666, 0)) == SEM_FAILED) {
        perror("Couldn't open semaphore writer");
        exit(1);
    }

    if ((sem_r = sem_open(SR, O_CREAT, 0666, 0)) == SEM_FAILED) {
        perror("Couldn't open semaphore reader");
        exit(1);
    }
    while (i < size) {
        sem_wait(sem_wr);
        if ((buffer = fopen("buffer.txt", "w")) < 0) {
            perror("Can't open file for writing");
            exit(1);
        }

        if (i + 5 < size) {
            for (size_t j = 0; j < 5; ++j) {
                buffered_text[j] = argv[1][i + j];
            }
            buffered_text[5] = '\0';
            fprintf(buffer, "%s", buffered_text);
            fprintf(stdout, "Writer wrote %s\n", buffered_text);
            fprintf(stdout, "ok\n");
            i += 5;
            fprintf(stdout, "ok\n");
        } else {
            for (size_t j = 0; j < size - i; ++j) {
                buffered_text[j] = argv[1][i + j];
            }
            buffered_text[size - i] = '\0';
            fprintf(buffer, "%s", buffered_text);
            fprintf(stdout, "Writer wrote %s\n", buffered_text);
            i = size;
        }
        fprintf(stdout, "ok\n");
        fclose(buffer);
        fprintf(stdout, "ok\n");
        fprintf(stdout, "posting semaphore reader\n");
        sem_post(sem_r);
        fprintf(stdout, "ok\n");
        fprintf(stdout, "waiting for semaphort writer\n");
    }
    sem_wait(sem_wr);
    if ((buffer = fopen("buffer.txt", "w")) != 0) {
        perror("Can't open file for writing");
        exit(1);
    }
    sem_wait(sem_wr);
    fprintf(buffer, "exit\n");
    fclose(buffer);
    sem_post(sem_r);
    sem_wait(sem_wr);
    sem_close(sem_wr);
    sem_close(sem_r);
    sem_unlink(SWR);
    sem_unlink(SR);
}