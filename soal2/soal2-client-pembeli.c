#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8087
#define MAX_STRING_LEN 80

char input[MAX_STRING_LEN];
int st_Beli;

int beli(){
    struct sockaddr_in address;
    int valread;
    struct sockaddr_in serv_addr;
    if ((st_Beli = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
      
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
  
    if (connect(st_Beli, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

}

int main(int argc, char const *argv[]) {
    // int sock = 0, valread;
    // struct sockaddr_in serv_addr;
   char buffer[1024] = {0};

    beli();
    
    while(1) {
        scanf("%s",input);
        if(strcmp(input,"beli") == 0) {
            send(st_Beli , input , strlen(input) , 0 );
            printf("Pemesanan untuk membeli telah terkirim \n");
            read( st_Beli , buffer, 1024);
            printf("%s\n",buffer );
        }
    }
    
    return 0;

}

