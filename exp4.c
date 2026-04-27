#include <stdio.h>

int flag[2] = {0, 0};
int turn;
int shared = 0;

void process1() {
    flag[0] = 1;
    turn = 1;

    while (flag[1] == 1 && turn == 1);

    printf("\n--- Process 1 entered Critical Section ---\n");
    shared++;
    printf("Shared Value incremented by P1: %d\n", shared);
    printf("--- Process 1 leaving Critical Section ---\n");

    flag[0] = 0;
}

void process2() {
    flag[1] = 1;
    turn = 0;

    while (flag[0] == 1 && turn == 0);

    printf("\n--- Process 2 entered Critical Section ---\n");
    shared++;
    printf("Shared Value incremented by P2: %d\n", shared);
    printf("--- Process 2 leaving Critical Section ---\n");

    flag[1] = 0;
}

int main() {
    printf("Starting Peterson's Algorithm Simulation...\n");

    process1();
    process2();

    printf("\nFinal Shared Value: %d\n", shared);
    return 0;
}