#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <termios.h>

int *shop_stock;

int mygetch(void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void restock() {
    printf("Shop\n");
    printf("Food stock : %d\n", *shop_stock);
    printf("Choices:\n");
    printf("1. Restock\n");
    printf("2. Exit\n");
}

int main() {
    char input;
    int input_error = 0;
    key_t key = 1234;

    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    shop_stock = shmat(shmid, NULL, 0);

    while(1) {
        system("clear");
        if(input_error == 1) {
            printf("Input invalid!\n\n");
            input_error = 0;
        }
        restock();
        input = mygetch();
        if(input == '1') *shop_stock = 5;
        else if(input == '2') break;
        else input_error = 1;
    }

    shmdt(shop_stock);
    shmctl(shmid, IPC_RMID, NULL);

}
