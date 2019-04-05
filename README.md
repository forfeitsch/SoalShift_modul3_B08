# SoalShift_modul3_B08

## Soal
1. Buatlah program C yang bisa menghitung faktorial secara parallel lalu menampilkan hasilnya secara berurutan

   Contoh:

    ./faktorial 5 3 4
    
    3! = 6
    
    4! = 24
    
    5! = 120

2. Pada suatu hari ada orang yang ingin berjualan 1 jenis barang secara private, dia memintamu membuat program C dengan spesifikasi sebagai berikut:
   1. Terdapat 2 server: server penjual dan server pembeli
   2. 1 server hanya bisa terkoneksi dengan 1 client
   3. Server penjual dan server pembeli memiliki stok barang yang selalu sama
   4. Client yang terkoneksi ke server penjual hanya bisa menambah stok
      - Cara menambah stok: client yang terkoneksi ke server penjual mengirim string “tambah” ke server lalu stok bertambah 1
   5. Client yang terkoneksi ke server pembeli hanya bisa mengurangi stok
      - Cara mengurangi stok: client yang terkoneksi ke server pembeli mengirim string “beli” ke server lalu stok berkurang 1
   6. Server pembeli akan mengirimkan info ke client yang terhubung dengannya apakah transaksi berhasil atau tidak berdasarkan ketersediaan stok
      - Jika stok habis maka client yang terkoneksi ke server pembeli akan mencetak “transaksi gagal”
      - Jika stok masih ada maka client yang terkoneksi ke server pembeli akan mencetak “transaksi berhasil”
   7. Server penjual akan mencetak stok saat ini setiap 5 detik sekali
   8. **Menggunakan thread, socket, shared memory**

    
3. Agmal dan Iraj merupakan 2 sahabat yang sedang kuliah dan hidup satu kostan, sayangnya mereka mempunyai gaya hidup yang berkebalikan, dimana Iraj merupakan laki-laki yang sangat sehat,rajin berolahraga dan bangun tidak pernah kesiangan sedangkan Agmal hampir menghabiskan setengah umur hidupnya hanya untuk tidur dan ‘ngoding’. Dikarenakan mereka sahabat yang baik, Agmal dan iraj sama-sama ingin membuat satu sama lain mengikuti gaya hidup mereka dengan cara membuat Iraj sering tidur seperti Agmal, atau membuat Agmal selalu bangun pagi seperti Iraj. Buatlah suatu program C untuk menggambarkan kehidupan mereka dengan spesifikasi sebagai berikut:
   1. Terdapat 2 karakter Agmal dan Iraj
   2. Kedua karakter memiliki status yang unik
      - Agmal mempunyai WakeUp_Status, di awal program memiliki status 0
      - Iraj memiliki Spirit_Status, di awal program memiliki status 100
      - Terdapat 3 Fitur utama
        - All Status, yaitu menampilkan status kedua sahabat
          
          Ex: 
          ```
              Agmal WakeUp_Status = 75 
              Iraj Spirit_Status = 30
          ```
        - “Agmal Ayo Bangun” menambah WakeUp_Status Agmal sebesar 15 point
        - “Iraj Ayo Tidur” mengurangi Spirit_Status Iraj sebanyak 20 point
      - Terdapat Kasus yang unik dimana:
        - Jika Fitur “Agmal Ayo Bangun” dijalankan sebanyak 3 kali, maka Fitur “Iraj Ayo Tidur” Tidak bisa dijalankan selama 10 detik (Dengan mengirim pesan ke sistem “Fitur Iraj Ayo Tidur disabled 10 s”)
        - Jika Fitur  “Iraj Ayo Tidur” dijalankan sebanyak 3 kali, maka Fitur “Agmal Ayo Bangun” Tidak bisa dijalankan selama 10 detik (Dengan mengirim pesan ke sistem “Agmal Ayo Bangun disabled 10 s”)
      - Program akan berhenti jika Salah Satu :
        - WakeUp_Status Agmal >= 100 (Tampilkan Pesan “Agmal Terbangun,mereka bangun pagi dan berolahraga”)
        - Spirit_Status Iraj <= 0 (Tampilkan Pesan “Iraj ikut tidur, dan bangun kesiangan bersama Agmal”)


      - **Syarat Menggunakan Lebih dari 1 Thread**

4. Buatlah sebuah program C dimana dapat menyimpan list proses yang sedang berjalan (ps -aux) maksimal 10 list proses. Dimana awalnya list proses disimpan dalam di 2 file ekstensi .txt yaitu  SimpanProses1.txt di direktori /home/Document/FolderProses1 dan SimpanProses2.txt di direktori /home/Document/FolderProses2 , setelah itu masing2 file di  kompres zip dengan format nama file KompresProses1.zip dan KompresProses2.zip dan file SimpanProses1.txt dan SimpanProses2.txt akan otomatis terhapus, setelah itu program akan menunggu selama 15 detik lalu program akan mengekstrak kembali file KompresProses1.zip dan KompresProses2.zip 

   **Dengan Syarat :**
   * Setiap list proses yang di simpan dalam masing-masing file .txt harus berjalan bersama-sama
   * Ketika mengkompres masing-masing file .txt harus berjalan bersama-sama
   * Ketika Mengekstrak file .zip juga harus secara bersama-sama
   * Ketika Telah Selesai melakukan kompress file .zip masing-masing file, maka program akan memberi pesan “Menunggu 15 detik untuk mengekstrak kembali”
   * Wajib Menggunakan Multithreading
   * Boleh menggunakan system



5. Angga, adik Jiwang akan berulang tahun yang ke sembilan pada tanggal 6 April besok. Karena lupa menabung, Jiwang tidak mempunyai uang sepeserpun untuk membelikan Angga kado. Kamu sebagai sahabat Jiwang ingin membantu Jiwang membahagiakan adiknya sehingga kamu menawarkan bantuan membuatkan permainan komputer sederhana menggunakan program C. Jiwang sangat menyukai idemu tersebut. Berikut permainan yang Jiwang minta. 
   1. Pemain memelihara seekor monster lucu dalam permainan. Pemain dapat  memberi nama pada monsternya.
   2. Monster pemain memiliki hunger status yang berawal dengan nilai 200 (maksimalnya) dan nanti akan berkurang 5 tiap 10 detik.Ketika hunger status mencapai angka nol, pemain akan kalah. Hunger status dapat bertambah 15 apabila pemain memberi makan kepada monster, tetapi banyak makanan terbatas dan harus beli di Market.
   3. Monster pemain memiliki hygiene status yang berawal dari 100 dan nanti berkurang 10 tiap 30 detik. Ketika hygiene status mencapai angka nol, pemain akan kalah. Hygiene status' dapat bertambah 30 hanya dengan memandikan monster. Pemain dapat memandikannya setiap 20 detik(cooldownnya 20 detik).
   4. Monster pemain memiliki health status yang berawal dengan nilai 300. Variabel ini bertambah (regenerasi)daa 5 setiap 10 detik ketika monster dalam keadaan standby.
   5. Monster pemain dapat memasuki keadaan battle. Dalam keadaan ini, food status(fitur b), hygiene status'(fitur c), dan ‘regenerasi’(fitur d) tidak akan berjalan. Health status dari monster dimulai dari darah saat monster pemain memasuki battle. Monster pemain akan bertarung dengan monster NPC yang memiliki darah 100. Baik monster pemain maupun NPC memiliki serangan sebesar 20. Monster pemain dengan monster musuh akan menyerang secara bergantian. 
   6. Fitur shop, pemain dapat membeli makanan sepuas-puasnya selama stok di toko masih tersedia.
      - Pembeli (terintegrasi dengan game)
        * Dapat mengecek stok makanan yang ada di toko.
        * Jika stok ada, pembeli dapat membeli makanan.
      - Penjual (terpisah)
        * Bisa mengecek stok makanan yang ada di toko
        * Penjual dapat menambah stok makanan.
   
   Spesifikasi program:
   1. Program mampu mendeteksi input berupa key press. (Program bisa berjalan tanpa perlu menekan tombol enter)
   2. Program terdiri dari 3 scene yaitu standby, battle, dan shop.
   3. Pada saat berada di standby scene, program selalu menampilkan health status, hunger status, hygiene status, stok makanan tersisa, dan juga status kamar mandi (“Bath is ready” jika bisa digunakan, “Bath will be ready in [bath cooldown]s” jika sedang cooldown). Selain itu program selalu menampilkan 5 menu, yaitu memberi makan, mandi, battle, shop, dan exit. Contoh :

      Standby Mode
      Health : [health status]
      Hunger : [hunger status]
      Hygiene : [hygiene status]
      Food left : [your food stock]
      Bath will be ready in [cooldown]s
      Choices
      1.Eat
      2.Bath
      3.Battle
      4.Shop
      5.Exit

   4. Pada saat berada di battle scene, program selalu menampilkan health status milik pemain dan monster NPC. Selain itu, program selalu menampilkan 2 menu yaitu serang atau lari. Contoh :

      Battle Mode
      Monster’s Health : [health status]
      Enemy’s Health : [enemy health status]
      Choices
      1.Attack
      2.Run

   5. Pada saat berada di shop scene versi pembeli, program selalu menampilkan food stock toko dan milik pemain. Selain itu, program selalu menampilkan 2 menu yaitu beli dan kembali ke standby scene. Contoh :

      Shop Mode
      Shop food stock : [shop food stock]
      Your food stock : [your food stock]
      Choices
      1.Buy
      2.Back

   6. Pada program penjual, program selalu menampilkan food stock toko. Selain itu, program juga menampilkan 2 menu yaitu restock dan exit. Contoh :

      Shop
      Food stock : [shop food stock]
      Choices
      1.Restock
      2.Exit

   6. Pastikan terminal hanya mendisplay status **detik ini** sesuai scene terkait (hint: menggunakan system(“clear”))


## Jawaban
1. Source code: [soal1.c](https://github.com/forfeitsch/SoalShift_modul3_B08/blob/master/soal1/soal1.c)
   
   **Penjelasan:**
   
   Program ini adalah program multithread dimana jumlah threadnya tergantung pada jumlah angka yang menjadi input program ini. Program ini memiliki satu variabel global yaitu ```luong res[100];``` untuk menampung hasil faktorial berupa long long int. Terdapat satu fungsi thread dan dua fungsi utama, yaitu:
   - ```void *factorial(void* argv)``` : Fungsi thread untuk menghitung faktorial secara paralel menggunakan pointer dari angka yang akan diproses sebagai inputnya
   - ```void sort(luong *numbers, int count)``` : Fungsi untuk mengurutkan bilangan-bilangan dalam sebuah array long long int.
   - ```void print(luong *arr, int count)``` : Fungsi untuk mencetak hasil program ke dalam terminal
   
   **Cara kerja:**
   - Pertama-tama untuk menangkap input angka-angka saat hendak mengeksekusi program, perlu ada penyesuaian di fungsi main(), sehingga menjadi ```int main(int argc, char *argv[])```
     - ```int argc``` : Argument count. Jumlah argumen yang ditangkap (termasuk nama program tersebut)
       Contoh: ```./soal1 6 3 4```, maka ```argc``` memiliki nilai 4
     - ```char argv[]``` : Argument vector. Vektor yang berisi argumen-argumen yang masuk.
       Contoh: ```./soal1 6 3 4```, maka isi ```argv[]``` adalah ```("soal1", "6", "3", "4")```
   - Buat array untuk menampung angka-angka tersebut dan juga thread yang diperlukan sebanyak ```argc - 1```
     ```
     luong in[argc - 1];
     pthread_t tid[argc - 1];
     ```
   - Sebelum dimasukkan ke dalam array ```in[argc - 1]```, convert dulu isi ```argv[]``` dari string menjadi long long int menggunakan ```atoll()```
     ```
     for(int i = 0; i < argc - 1; i++)
        in[i] = atoll(argv[i + 1]);
     ```
   - Setelah itu urutkan angka-angka tersebut dengan cara ```sort(in, argc - 1);```
   - Buat loop untuk membuat thread sebanyak jumlah angka yang dimasukkan. Thread yang telah dibuat akan sekaligus dijoinkan
     ```
     for(int i = 0; i < argc - 1; i++) {
        luong *ptr = &in[i];
        pthread_create(&(tid[i]), NULL, factorial, ptr);
        pthread_join(tid[i], NULL);
     }
     ```
   - Terakhir, cetak outputnya dengan cara ```print(in, argc - 1);```
2. asd
 
3. Source code: [soal3.c](https://github.com/forfeitsch/SoalShift_modul3_B08/blob/master/soal3/soal3.c)
   
   **Penjelasan:**
   
   Program ini adalah program dimana 2 orang bernama Agmal dan Iraj saling bersaing dalam mempengaruhi kebiasaan masing-masing. Program ini menggunakan 2 thread dalam eksekusinya. Program ini menggunakan bermacam-macam variabel global yang berfungsi sebagai stat. Di antaranya adalah:
   - ```int WakeUp_Status``` : Status awal Agmal. Diinisialisasi dengan nilai awal 0
   - ```int Spirit_Status``` : Status awal Iraj. Diinisialisasi dengan nilai awal 100
   - ```int count_bangun``` : Untuk menghitung berapa kali perintah "Agmal Ayo Bangun" dipanggil. Diinisialisasi dengan nilai awal 0
   - ```int count_tidur``` : Untuk menghitung berapa kali perintah "Iraj Ayo Tidur" dipanggil. Diinisialisasi dengan nilai awal 0
   - ```int stun_agmal``` : Sebagai penanda perintah "Agmal Ayo Bangun" tidak bisa dilakukan.
   - ```int stun_iraj``` : Sebagai penanda perintah "Iraj Ayo Tidur" tidak bisa dilakukan.
   
   Fungsi thread yang dipakai terdiri dari:
   - ```void *suspend_WakeUp(void *argv)``` : Fungsi untuk mendisable fitur "Agmal Ayo Bangun" selama 10 detik
   - ```void *suspend_Spirit(void *argv)``` : Fungsi untuk mendisable fitur "Iraj Ayo Tidur" selama 10 detik
   
   **Cara Kerja:**
   - Tangkap inputnya yang berupa string
     ```
     char cmd[100];
     scanf("%[^\n]s", cmd);
     getchar();
     ```
   - Jika yang tertangkap adalah perintah "Agmal Ayo Bangun", WakeUp_Status bertambah 15 poin, count_bangun diincrement. Ketika count_bangun menyentuh angka 3, thread ```suspend_Spirit``` akan dipanggil. Ketika perintah berhasil dijalankan, program akan mencetak "Agmal Telah Mendengarmu"
     ```
     if(strcmp(cmd, "Agmal Ayo Bangun") == 0 && stun_agmal == 0){
	 WakeUp_Status += 15;
	 count_bangun++;
	 if(count_bangun == 3){
		count_bangun == 0;
		pthread_create(&(tid[0]), NULL, suspend_Spirit, NULL);
	 }
     	 printf("Agmal Telah Mendengarmu\n\n");
     }
     if(stun_agmal == 1) printf("Fitur Agmal Ayo Bangun disabled 10 s\n\n");
     ```
   - Jika yang tertangkap adalah perintah "Iraj Ayo Tidur", Spirit_Status berkurang 20 poin, count_tidur diincrement. Ketika count_tidur menyentuh angka 3, thread ```suspend_WakeUp``` akan dipanggil. Ketika perintah berhasil dijalankan, program akan mencetak "Iraj Telah Mendengarmu"
     ```
     else if(strcmp(cmd, "Iraj Ayo Tidur") == 0 && stun_iraj == 0){
	 Spirit_Status -= 20;
	 count_tidur++;
	 if(count_tidur == 3){
	     count_tidur == 0;
   	     pthread_create(&(tid[1]), NULL, suspend_WakeUp, NULL);
	 }
         printf("Iraj Telah Mendengarmu\n\n");
     }
     if(stun_iraj == 1) printf("Fitur Iraj Ayo Tidur disabled 10 s\n\n");
     ```
   - Program akan melakukan 2 poin di atas berkali-kali hingga WakeUp_Status menyentuh angka 100 atau Spirit_Status menyentuh angka 0. Program akan mencetak output berikut sebelum berhenti.
     ```
     if(WakeUp_Status >= 100){
	 printf("Agmal Terbangun, mereka bangun pagi dan berolahraga\n\n");
	 break;
     }
     if(Spirit_Status <= 0){
         printf("Iraj ikut tidur, dan bangun kesiangan bersama Agmal\n\n");
	 break;
     }
     ```

4. Source code: [soal4.c](https://github.com/forfeitsch/SoalShift_modul3_B08/blob/master/soal4/soal4.c)
	
   **Penjelasan**
   
   Program ini adalah sebuah program C dimana dapat dimana dapat menyimpan list proses yang sedang berjalan (ps -aux) maksimal 10 list proses. Dimana awalnya list proses disimpan dalam di 2 file ekstensi .txt yaitu  SimpanProses1.txt di direktori /home/Document/FolderProses1 dan SimpanProses2.txt di direktori /home/Document/FolderProses2 , setelah itu masing2 file di  kompres zip dengan format nama file KompresProses1.zip dan KompresProses2.zip dan file SimpanProses1.txt dan SimpanProses2.txt akan otomatis terhapus
   
   ``` system("mkdir Documents/FolderProses1"); ```
   ``` system("ps -aux | head -11 > Documents/FolderProses1/SimpanProses1.txt");```
   ``` system("zip Documents/FolderProses1/KompresProses1.zip Documents/FolderProses1/SimpanProses1.txt");```
   ``` system("rm Documents/FolderProses1/SimpanProses1.txt"); ```
   
   , setelah itu program akan menunggu selama 15 detik lalu program akan mengekstrak kembali file KompresProses1.zip dan KompresProses2.zip 

   ```  
    sleep(15);
    system("unzip Documents/FolderProses2/KompresProses2.zip");
    system("rm Documents/FolderProses2/KompresProses2.zip");
    
   ```
     Kesuluruhan dari pekerjaan kami menggunakan system, menggunakan 2 fungsi sebagai thread. Lalu pada ```main``` kami panggil : 
   ```
    pthread_create(&(tid1), NULL, sys1, NULL);
    pthread_create(&(tid2), NULL, sys2, NULL);
    
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
   ```


5. Source code: [game.c](https://github.com/forfeitsch/SoalShift_modul3_B08/blob/master/soal5/game.c)
   
   **Penjelasan:**
   
   Program ini adalah game multithread tentang sebuah monster. Pemain bisa melakukan apa saja dengan mosnter ini. Yang pasti jika monster ini tidak dirawat dengan baik, monster akan mati dan pemain dinyatakan kalah. Terdapat banyak variabel global yang memuat stat dari monster dan juga mekanisme dalam game seperti:
   - ```int alive``` : Sebagai penanda apakah monster ini masih hidup atau tidak
   - ```int hunger_status``` : Pengukur seberapa butuhnya monster ini terhadap makanan. Diinisialisasi dengan nilai awal 200
   - ```int hygiene_status``` : Pengukur kebersihan si monster. Diinisialisasi dengan nilai awal 100
   - ```int health_status``` : Jumlah nyawa si monster. Diinisialisasi dengan nilai awal 300
   - ```int food_stock``` : Stok makanan yang dimiliki pemain untuk memberi makan monster. Diberikan 5 stok makanan pada awal permainan
   - ```int bath_cooldown``` : Cooldown untuk memandikan monster
   - ```int battle_status``` : Penanda apakah monster berada dalam keadaan battle atau tidak
   - ```int enemy_health_status``` : Jumlah nyawa monster lawan. Direfresh menjadi 100 setiap awal battle
   - ```int *shop_stock``` : Stok makanan di shop. Hanya bisa diisi ulang stoknya di program shop dari penjual (terpisah dari game)
   
   Fungsi threadnya terdiri dari:
   - ```void *hunger_degen(void *argv)``` : Thread untuk degenerate ```hunger_status``` sebanyak 5 poin tiap 10 detik. Disable ketika battle
   - ```void *hygiene_degen(void *argv)``` : Thread untuk degenerate ```hygiene_status``` sebanyak 10 poin tiap 30 detik. Disable ketika battle
   - ```void *health_regen(void *argv)``` : Thread untuk regenerate ```health_status``` sebanyak 5 poin tiap 10 detik. Disable ketika battle
   - ```void *counting_down(void *argv)``` : Thread untuk countdown ```bath_cooldown``` tiap detiknya
   
   Fungsi utama terdiri dari:
   - ```int mygetch(void)``` : Fungsi untuk menangkap input tanpa menggunakan tombol enter
   - ```void standby_mode()``` : Fungsi untuk mencetak main menu dalam Standby Mode
   - ```void battle_mode(int myhealth)``` : Fungsi untuk mencetak main menu dalam Battle Mode
   - ```void shop_mode()``` : Fungsi untuk mencetak main menu dalam Shop Mode
   
   **Cara Kerja:**
   - Siapkan variabel untuk menampung nama, mode menu, dan penanda-penanda untuk error dan kondisi tertentu
     ```
     char name[21];
     char mode = '1', input;
     int bath_error = 0, input_error = 0, stock_error = 0, full = 0, eat = 0, bath = 0, att = 0, def = 0, win = 0;
     ```
   - Variabel ```shop_stock``` adalah variabel yang akan dipakai untuk 2 program, maka metode yang dilakukan adalah Shared Memory. Kita inisialisasi dulu lalu isi ```shop_stock``` diberi nilai awal 5
     ```
     key_t key = 1234;

     int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
     shop_stock = shmat(shmid, NULL, 0);

     *shop_stock = 5;
     ```
   - Akan muncul nama gamenya, lalu program meminta pemain memasukkan nama untuk monsternya. Nama ini akan dipakai untuk keperluan game nantinya
   - Semua thread yang berisi regenerasi dan degenerasi dibuat di sini
     ```
     pthread_t tid[4];
     pthread_create(&(tid[0]), NULL, hunger_degen, NULL);
     pthread_create(&(tid[1]), NULL, hygiene_degen, NULL);
     pthread_create(&(tid[2]), NULL, health_regen, NULL);
     ```
   - Setiap memunculkan menu tertentu, program akan selalu membersihkan tampilan terminal menggunakan ```system("clear")```
   - Sebelum memunculkan menu, semua bentuk error atau notifikasi akan dicetak terlebih dahulu
     
     Contoh: Input error
     ```
     if(input_error == 1) {
            printf("Input invalid!\n\n");
            input_error = 0;
     }
     ```
   - Setiap mode main menu akan menampilkan menu-menu yang tersedia dengan memanggil fungsi masing-masing mode, lalu menangkap input dari pemain
     
     Contoh: Standby Mode
     ```
     standby_mode();
     input = mygetch();
     ```
   - Cara tiap mode meresponi input dari pemain berbeda-beda, di antaranya:
     - **Standby Mode**
       - Jika inputnya 1, maka monster akan diberi makan, menambah ```hunger_status``` dan mengurangi ```food_stock```. Jika monster kenyang, monster akan menolak untuk makan, sehingga tidak ada perubahan apapun. Demikian pula ketika stok makanan habis
       - Jika inputnya 2, maka monster akan dimandikan, menambah ```hygiene_status``` dan mengaktifkan thread ```counting_down```. Selama cooldown aktif, monster tidak bisa dimandikan
       - Jika inputnya 3, maka monster akan memasuki Battle Mode. Semua thread regen dan degen yang berjalan akan dihentikan sementara hingga monster keluar dari Battle Mode
       - Jika inputnya 4, maka pemain akan dibawa ke dalam Shop Mode, di mana pemain bisa membeli makanan hingga stok makanan di toko habis. Stok di toko hanya bisa diisi ulang lewat program yang terpisah
       - Jika inputnya 5, pemain akan keluar dari permainan dengan menerima pesan "Thank You For Playing!"
     - **Battle Mode**
       - Jika inputnya 1, maka monster pemain akan menyerang monster lawan. Jika masih ada sisa nyawa dari monster lawan, monster pemain juga akan diserang. Jika nyawa monster pemain habis, maka pemain dinyatakan kalah
       - Jika inputnya 2, maka monster pemain akan dikembalikan ke Standby Mode. Thread-thread regen dan degen akan kembali berjalan dengan semestinya
     - **Shop Mode**
       - Jika inputnya 1, maka stok makanan toko akan berkurang seiringan dengan pertambahan stok makanan pemain hingga stok makanan di toko habis.
       - Jika inputnya 2, maka pemain akan dikembalikan ke Standby Mode
   - Jika input yang diterima bukan angka-angka yang telah disebutkan di atas, maka main menu akan ditampilkan ulang dengan pesan input error
   - Jika program sempat keluar dari loop, maka monster dianggap mati. Pesan kematian akan ditampilkan di sini
     ```
     printf("\nYour monster is dead because of ");
     if(health_status == 0) printf("running out of health. ");
     else if(hunger_status <= 0) printf("starvation. ");
     else if(hygiene_status <= 0) printf("your carelessness of hygiene. ");
     printf("Game Over.\n");
     ```
   - Shared memory diakhiri di sini sebelum program berakhir
     ```
     shmdt(shop_stock);
     shmctl(shmid, IPC_RMID, NULL);
     ```
   Source code: [shop.c](https://github.com/forfeitsch/SoalShift_modul3_B08/blob/master/soal5/shop.c)
   
   **Penjelasan:**
   
   Program ini adalah program khusus untuk penjual di shop pada game.c. Program ini hanya memuat beberapa fungsi dan variabel yang dimiliki oleh program game.c seperti ```int *shop_stock``` dan ```int mygetch(void)```. Fungsi baru yang dimiliki oleh program ini adalah ```restock()```, untuk menampilkan main menu Shop Mode versi penjual.
   
   **Cara Kerja:**
   - Siapkan variabel untuk menampung input, berikut dengan penanda errornya. Kemudian inisialisasi metode Shared Memory seperti berikut:
     ```
     char input;
     int input_error = 0;
     key_t key = 1234;

     int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
     shop_stock = shmat(shmid, NULL, 0);
     ```
   - Jika inputnya 1, stok makanan di toko akan langsung dikembalikan ke nilai default = 5
   - Jika inputnya 2, maka program akan melakukan proses terminasi
   - Input selain di atas akan memunculkan pesan error
   - Proses terminasinya adalah mengakhiri metode Shared Memory dengan cara sebagai berikut:
     ```
     shmdt(shop_stock);
     shmctl(shmid, IPC_RMID, NULL);
     ```
     
