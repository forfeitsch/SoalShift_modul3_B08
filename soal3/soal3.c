#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int WakeUp_Status = 0; // Status yang dimiliki Agmal
int Spirit_Status = 100; // Status yang dimiliki Iraj
int count_bangun = 0; // Untuk menghitung berapa kali perintah "WakeUp_Status" diterima berturut-turut
int count_tidur = 0; // Untuk menghitung berapa kali perintah "Spirit_Status" diterima berturut-turut

// Mutex untuk penanda sebuah fitur bisa dipakai atau tidak
int stun_agmal = 0;
int stun_iraj = 0;

// Fungsi thread untuk mendisable fitur "WakeUp_Status" untuk sementara waktu
void *suspend_WakeUp(void *argv){
	stun_agmal = 1;
	sleep(10);
	stun_agmal = 0;
}

// Fungsi thread untuk mendisable fitur "Spirit_Status" untuk sementara waktu
void *suspend_Spirit(void *argv){
	stun_iraj = 1;
	sleep(10);
	stun_iraj = 0;
}

int main(){
	pthread_t tid[2];

	while(1){
		// Untuk menangkap command
		char cmd[100];
		scanf("%[^\n]s", cmd);
		getchar();

		// Untuk mengubah status Agmal
		if(strcmp(cmd, "Agmal Ayo Bangun") == 0 && stun_agmal == 0){
			WakeUp_Status += 15;
			count_bangun++;
			if(count_bangun == 3){
				count_bangun == 0;
				pthread_create(&(tid[0]), NULL, suspend_Spirit, NULL);
			}
			printf("Agmal Telah Mendengarmu\n\n");
		}

		// Untuk mengubah status Iraj
		else if(strcmp(cmd, "Iraj Ayo Tidur") == 0 && stun_iraj == 0){
			Spirit_Status -= 20;
			count_tidur++;
			if(count_tidur == 3){
				count_tidur == 0;
				pthread_create(&(tid[1]), NULL, suspend_WakeUp, NULL);
			}
			printf("Iraj Telah Mendengarmu\n\n");
		}

		// Untuk menampilkan semua status
		else if(strcmp(cmd, "All Status") == 0){
			printf("Agmal WakeUp_Status = %d\n", WakeUp_Status);
			printf("Iraj Spirit_Status = %d\n", Spirit_Status);
			printf("\n");
		}

		if(stun_agmal == 1) printf("Fitur Agmal Ayo Bangun disabled 10 s\n\n");
		if(stun_iraj == 1) printf("Fitur Iraj Ayo Tidur disabled 10 s\n\n");

		// Ketika target tercapai, maka keluar dari program
		if(WakeUp_Status >= 100){
			printf("Agmal Terbangun, mereka bangun pagi dan berolahraga\n\n");
			break;
		}
		if(Spirit_Status <= 0){
			printf("Iraj ikut tidur, dan bangun kesiangan bersama Agmal\n\n");
			break;
		}
	}
	return 0;
}

