#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#define PORT 8087

int *st, new_socket;

void *beli( void *ptr ){ //program untuk menjalankan pengurangan

    char buffer[1024], *input;

    while(1){
        read( new_socket , buffer, 1024);

         if(!strcmp(buffer, "beli")){
            if(*st > 0){
                *st = *st - 1;
                input = "transaksi berhasil";
            }
            else input = "transaksi gagal";

            send(new_socket , input , strlen(input) , 0 );
         }
    }
}

int main(int argc, char const *argv[]) {
    int server_fd, valread;
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

    pthread_t threads;
    pthread_create(&threads, NULL, beli, NULL);
    pthread_join(threads, NULL);

    shmdt(st);
    shmctl(shmid, IPC_RMID, NULL);
    
    return 0;
}

