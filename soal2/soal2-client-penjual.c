#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8088
#define MAX_STRING_LEN 80

char input[MAX_STRING_LEN];
int st_Tambah;

int tambah(){

    struct sockaddr_in address;
    int valread;
    struct sockaddr_in serv_addr;
    if ((st_Tambah = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
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
  
    if (connect(st_Tambah, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
        }
    
}
int main(int argc, char const *argv[]) {
    // int sock = 0, valread;
    // struct sockaddr_in serv_addr;
    // char buffer[1024] = {0};

    tambah();
    
    while(1) {
        scanf("%s",input);
        if(strcmp(input,"tambah") == 0) {
            send(st_Tambah , input , strlen(input) , 0 );
            printf("Tambah message sent\n");
        }
    }
    
    return 0;

}

