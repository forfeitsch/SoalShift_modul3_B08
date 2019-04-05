#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid1, tid2;
int status;
int nomor;
 
void* sys1(void *arg)
{
    // int ret,ret2;
    // char str[1000];
    system("mkdir Documents/FolderProses1");
    system("ps -aux | head -11 > Documents/FolderProses1/SimpanProses1.txt");
    system("zip Documents/FolderProses1/KompresProses1.zip Documents/FolderProses1/SimpanProses1.txt");
    system("rm Documents/FolderProses1/SimpanProses1.txt");
    printf("\nMenunggu 15 detik\n");
    sleep(15);
    system("unzip Documents/FolderProses1/KompresProses1.zip");    
    system("rm Documents/FolderProses1/KompresProses1.zip");    
    return NULL;
}

void* sys2(void *arg)
{
 
    // int ret,ret2;
    // char str[1000];
    system("mkdir Documents/FolderProses2");
    system("ps -aux | head -11 > Documents/FolderProses2/SimpanProses2.txt");
    system("zip Documents/FolderProses2/KompresProses2.zip Documents/FolderProses2/SimpanProses2.txt");
    system("rm Documents/FolderProses2/SimpanProses2.txt");
    sleep(15);
    system("unzip Documents/FolderProses2/KompresProses2.zip");
    system("rm Documents/FolderProses2/KompresProses2.zip");
    return NULL;
}

// void* sys_status(void *arg)
// {
//     while(status != 1)
//     {

//     }

//     printf("Nomor %d\n", nomor);
// }
 
int main(void)
{
    
    pthread_create(&(tid1), NULL, sys1, NULL);
    pthread_create(&(tid2), NULL, sys2, NULL);
    
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    return 0;
}
// int main() {
//   int return_value;
//   char str[1000],str2[1000];
//   FILE *fptr, *fptr2;
//   return_value = system("ps -aux | head -11 /");
//   strcpy(str, return_value);
// //   return return_value;
  
//   fptr = fopen(" /home/Document/FolderProses1/SimpanProses1.txt","w+");
//   strcpy(str2,str);
//   system("zip KompresProses1.zip SimpanProses1.txt /");
//   fptr = fopen(" /home/Document/FolderProses2/SimpanProses2.txt","w+");
//   strcpy(str2,str);
//   system("zip KompresProses2.zip SimpanProses2.txt /");
//   fclose(fptr); 
//   fclose(fptr2);
// }