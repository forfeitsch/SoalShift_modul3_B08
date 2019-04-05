#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
typedef long long int luong;

luong res[100];

// Fungsi mencari faktorial
void *factorial(void* argv) {
    luong num = *((long long*)argv);
    res[0] = 1;
    res[1] = 1;
    for(int i = 2; i <= num; i++)
        res[i] = i * res[i-1];
}

// Fungsi insertion sort
void sort(luong *arr, int count) {
    luong temp;
    int i, j;

    for(i = 1; i <= count - 1; i++) {
        j = i;

        while(j > 0 && arr[j-1] > arr[j]) {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}
void print(luong *arr, int count) {
    for(int i = 0; i < count; i++)
        printf("%lld! = %lld\n", arr[i], res[arr[i]]);
}

int main(int argc, char *argv[]) {
    // Karena nama program termasuk ke dalam argumen, argument count dikurangi 1
    luong in[argc - 1];
    pthread_t tid[argc - 1];

    // Convert angka-angka dalam argumen ke dalam int
    for(int i = 0; i < argc - 1; i++)
        in[i] = atoll(argv[i + 1]);

    // Urutkan argumennya dari terbesar ke terkecil
    sort(in, argc - 1);

    // Bikin thread untuk tiap argumen lalu dijoin sebelum diprint
    for(int i = 0; i < argc - 1; i++) {
        luong *x = &in[i];
        pthread_create(&(tid[i]), NULL, factorial, x);
        pthread_join(tid[i], NULL);
    }
//    luong *x = malloc(sizeof(*x));
//    *x = in[argc - 2];
//    pthread_create(&(tid[0]), NULL, factorial, x);
//
//    pthread_join(tid[0], NULL);

    print(in, argc - 1);
    return 0;
}
