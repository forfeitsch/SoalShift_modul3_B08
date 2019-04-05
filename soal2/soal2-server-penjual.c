#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#define PORT 8088

int cek_st_TimerStart, readBuffer;
int new_socket;
int *st;

void *tambah( void *ptr ){

    char buffer[1024];

    while(1){
        read( new_socket , buffer, 1024);
        if(!strcmp(buffer, "tambah"))
            *st = *st + 1;
    }

}

void *cek_st( void *ptr ){

    while(1){
        cek_st_TimerStart = 1;
        sleep(5);
        printf("Stok : %d\n", *st);
        cek_st_TimerStart = 0;
    }
    
}



int main(int argc, char const *argv[]) {
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
      
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
      
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    key_t key = 1234;

    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    st = shmat(shmid, NULL, 0);
    *st = 0;

    pthread_t threads[2];

    pthread_create(&(threads[0]), NULL, cek_st, NULL);
    pthread_create(&(threads[1]), NULL, tambah, NULL);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    shmdt(st);
    shmctl(shmid, IPC_RMID, NULL);
    
    return 0;
}

