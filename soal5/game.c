#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int alive = 1;
int hunger_status = 200;
int hygiene_status = 100;
int health_status = 300;
int food_stock = 5;
int bath_cooldown = 0;
int battle_status = 0;
int enemy_health_status = 100;
int *shop_stock;

void *hunger_degen(void *argv) {
    while(1) {
        if(battle_status == 0) {
            if(hunger_status <= 0) alive = 0;
            sleep(10);
            hunger_status -= 5;
        }
        else while(battle_status == 1);
    }
}

void *hygiene_degen(void *argv) {
    while(1) {
        if(battle_status == 0) {
            if(hygiene_status <= 0) alive = 0;
            sleep(30);
            hunger_status -= 10;
        }
        else while(battle_status == 1);
    }
}

void *health_regen(void *argv) {
    while(1) {
        if(battle_status == 0) {
            sleep(10);
            health_status += 5;
            if(health_status > 300) health_status = 300;
        }
        else while(battle_status == 1);
    }
}

void *counting_down(void *argv) {
    while(bath_cooldown > 0) {
        sleep(1);
        bath_cooldown--;
    }
}

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

void standby_mode() {
    printf("Standby Mode\n");
    printf("Health: %d\n", health_status);
    printf("Hunger: %d\n", hunger_status);
    printf("Hygiene: %d\n", hygiene_status);
    printf("Food left: %d\n", food_stock);
    printf("Bath will be ready in %d s\n", bath_cooldown);
    printf("Choices:\n");
    printf("1. Eat\n");
    printf("2. Bath\n");
    printf("3. Battle\n");
    printf("4. Shop\n");
    printf("5. Exit\n");
}

void battle_mode(int myhealth) {
    printf("Battle Mode\n");
    printf("Monster's Health : %d\n", myhealth);
    printf("Enemy’s Health : %d\n", enemy_health_status);
    printf("Choices:\n");
    printf("1. Attack\n");
    printf("2. Run\n");
}

void shop_mode() {
    printf("Shop Mode\n");
    printf("Shop food stock : %d\n", *shop_stock);
    printf("Your food stock : %d\n", food_stock);
    printf("Choices:\n");
    printf("1. Buy\n");
    printf("2. Back\n");
}


int main() {
    char name[21];
    char mode = '1', input;
    int bath_error = 0, input_error = 0, stock_error = 0, att = 0, def = 0, win = 0;

    key_t key = 1234;

    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    shop_stock = shmat(shmid, NULL, 0);

    *shop_stock = 5;

    system("clear");
    printf("=============\n");
    printf("MONSTER WORLD\n");
    printf("=============\n\n");
    printf("You got a new monster!\n");
    printf("Your monster's name is: (max 20 char)\n");
    scanf("%[^\n]s", name);
    getchar();
    printf("\n");

    pthread_t tid[4];
    pthread_create(&(tid[0]), NULL, hunger_degen, NULL);
    pthread_create(&(tid[1]), NULL, hygiene_degen, NULL);
    pthread_create(&(tid[2]), NULL, health_regen, NULL);

    while(alive == 1) {
        system("clear");
        if(input_error == 1) {
            printf("Input invalid!\n\n");
            input_error = 0;
        }
        if(mode == '1' || mode == '2') {
            if(food_stock < 0) {
                food_stock = 0;
                printf("Your food stock is empty. Buy some more at Shop.\n\n");
            }
            if(bath_error == 1) {
                printf("Bath is not ready yet.\n\n");
                bath_error = 0;
            }
            standby_mode();
            input = mygetch();
            if(input == '1') {
                mode = input;
                food_stock--;
                if(food_stock >= 0) {
                    hunger_status += 15;
                    if(hunger_status > 200) hunger_status = 200;
                }
            }
            else if(input == '2') {
                mode = input;
                if(bath_cooldown == 0) {
                    hygiene_status += 30;
                    if(hygiene_status > 100) hygiene_status = 100;
                    bath_cooldown = 20;
                    pthread_create(&(tid[3]), NULL, counting_down, NULL);
                }
                else bath_error = 1;
            }
            else if(input == '3' || input == '4') mode = input;
            else if(input == '5') {
                printf("\nThank You For Playing!\n");
                shmdt(shop_stock);
                shmctl(shmid, IPC_RMID, NULL);
                return 0;
            }
            else input_error = 1;
        }

        else if(mode == '3') {
            int myhealth = health_status;
            system("clear");
            battle_status = 1;
            if(att == 1) {
                printf("%s attacks the enemy monster. It's super effective!\n\n", name);
                att = 0;
            }
            if(def == 1) {
                printf("%s is under attack!\n\n", name);
                def = 0;
            }
            if(win == 1)
                printf("YOU WON! You have defeated the enemy monster!\n\n");
            else if(win > 1)
                printf("The monster has been defeated. Let's go home\n\n");

            battle_mode(myhealth);
            if(myhealth == 0) break;
            input = mygetch();
            if(input == '1') {
                if(enemy_health_status > 0) att = 1;
                enemy_health_status -= 20;
                if(enemy_health_status > 0) {
                    def = 1;
                    myhealth -= 20;
                }
                else {
                    enemy_health_status = 0;
                    win++;
                }
                if(myhealth < 0) myhealth = 0;
            }
            else if(input == '2') {
                mode = '1';
                enemy_health_status = 100;
            }
            else input_error = 1;
            health_status = myhealth;
            if(mode != '3') {
                battle_status = 0;
                win = 0;
            }
        }

        else if(mode == '4') {
            system("clear");
            if(stock_error == 1) {
                printf("Food sold out.\n\n");
                stock_error = 0;
            }
            shop_mode();
            input = mygetch();
            if(input == '1') {
                if(*shop_stock > 0) {
                    *shop_stock -= 1;
                    food_stock++;
                }
                else stock_error = 1;
            }
            else if(input == '2') mode = '1';
            else input_error = 1;
        }
    }
    printf("\nYour monster is dead because of ");
    if(health_status == 0) printf("running out of health. ");
    else if(hunger_status <= 0) printf("starvation. ");
    else if(hygiene_status <= 0) printf("your carelessness of hygiene. ");
    printf("Game Over.\n");

    shmdt(shop_stock);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
