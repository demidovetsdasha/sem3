#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    time_t now;
    time(&now);


    pid_t parentPid = getpid();
    pid_t firstChildPid, secondChildPid;

    firstChildPid = fork(); // Создание первого дочернего процесса

    if (firstChildPid < 0) {
        perror("Ошибка при создании первого дочернего процесса");
        exit(1);
    } else if (firstChildPid == 0) {
        printf("Первый дочерний процесс PID: %d, PPID: %d\n", getpid(), getppid());

        printf("Текущее время: %s", ctime(&now));
        exit(0);
    } else {
        secondChildPid = fork(); // Создание второго дочернего процесса

        if (secondChildPid < 0) {
            perror("Ошибка при создании второго дочернего процесса");
            exit(1);
        } else if (secondChildPid == 0) {
            printf("Второй дочерний процесс PID: %d, PPID: %d\n", getpid(), getppid());
            printf("Текущее время: %s", ctime(&now));
            exit(0);
        } else {
            printf("Родительский процесс PID: %d\n", parentPid);
            printf("Первый дочерний процесс PID: %d\n", firstChildPid);
            printf("Второй дочерний процесс PID: %d\n", secondChildPid);

            system("ps -x");

            // Ожидание завершения двух дочерних процессов
            wait(NULL);
            wait(NULL);

            printf("Родительский процесс завершен\n");
            exit(0);
        }
    }
}