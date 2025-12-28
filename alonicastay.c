#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int umurUser, passwordUser, hargaKamar, dipilihKamar;
int pilihAloniCard, lihatKartu, buatKartu, nomorKartu, passwordAlonica, denganAloniCard;
int lamaMenginap, opsiLanjutan, simpanOpsiLanjutan;
int passwordKonfirmasi;
char namaUser[20], namaUser1[20];
int pilihanUser = 0;
int punyaAkun = 0;
int punyaAloniCard = 0;
int hasilHitungKamar;
int passwordSignIn;
int nomorKamar;
char *jenisKamarDipilih = NULL;

void header_Menu_Awal() {
    printf("==================================\n");
    printf("~            MyAlonica           ~\n");
    printf("~          Alonica Hotel         ~\n");
    printf("~  Selamat Datang, Alonifriends  ~\n");
    printf("==================================\n");
}

void header_Menu_Utama() {
    printf("==================================\n");
    printf("~            MyAlonica           ~\n");
    printf("~         Alonica's Hotel        ~\n");
    printf("==================================\n");
    printf("</Halo, %s!>\n", namaUser);
    printf("mau ngapain nih hari ini..\n");
}

void tampilan_Menu_Awal() {
    printf("1. Login\n");
    printf("2. Buat Akun\n");
    printf("3. Exit\n");
    
    printf("Pilih 1-3! : ");
    scanf("%d", &pilihanUser);

        if(pilihanUser < 1 || pilihanUser > 3) {
            printf("Maaf, pilihan tidak valid! :(\n\n");
            header_Menu_Awal();
            tampilan_Menu_Awal();
        }
}

void tampilan_Buat_Akun() {
    printf("~~======' Buat Akun '======~~\n");
    printf("Buat Username :: ");
    scanf("%s", namaUser1);
    printf("Buat Password :: ");
    scanf("%d", &passwordUser);
    punyaAkun = 1;
    printf("Akun berhasil dibuat! Silahkan login.\n");
}

void tampilan_Menu_Utama() {
    printf("1. Pesan Kamar\n");
    printf("2. Lihat Pesanan\n");
    printf("3. AloniCard\n");
    printf("4. Log Out\n");

    printf("Pilih Menu :: ");
    scanf("%d", &pilihanUser);
}

int tampilan_Login() {
    printf("~~======' Log In '======~~\n");
    printf("Masukkan Username :: ");
    scanf("%s", namaUser);
    printf("Masukkan Password :: ");
    scanf("%d", &passwordSignIn);

        if(strcmp(namaUser, namaUser1) == 0 && passwordUser == passwordSignIn){
            printf("Anda berhasil login\n");
            return 1;
        }
        else {
            printf("Username atau Password tidak valid!\n");
            return 0;
        }
}

void aloni_Card() {
    printf("~~======' AloniCard  '======~~\n");
    printf("1. Lihat Kartu\n");
    printf("2. Buat Kartu\n");
    printf("3. Kembali\n");

    printf("Pilih :: ");
    scanf("%d", &pilihAloniCard);

    switch(pilihAloniCard) {
        case 1:
            if(punyaAloniCard) {
                printf("Nama        : %s\n", namaUser);
                printf("Nomor Kartu : %d\n", nomorKartu);
            }
            else{
                printf("Kamu belum punya AloniCard! Silahkan buat dulu ^.^\n");
            }
            break;
            
        case 2:
            if(punyaAloniCard) {
                printf("Kamu udah punya AloniCard!\n");
            }
            else{
                printf("Custom Nomor Kartu Kamu :: ");
                scanf("%d", &nomorKartu);
                printf("Masukkan Password Log In :: ");
                scanf("%d", &passwordAlonica);

                    if(passwordAlonica == passwordUser) {
                        printf("Yeay, Kamu Berhasil Bikin AloniCard ^.^\n");
                        printf("No. Kartu : %d\n", nomorKartu);
                        punyaAloniCard = 1;
                    }
                    else {
                        printf("Maaf, Password Salah!\n");
                    }
            }
            break;
                
        case 3:
            printf("Kembali ke menu..\n");
            return;
                
        default:
            printf("Waduh, Gak ada di pilihan nih:(\n");
            break;
    }
}

int proses_Pemesanan_Kamar() {
    printf("Lama Menginap :: ");
    if(scanf("%d", &lamaMenginap) != 1) return -1;

    printf("Pilih!\n");
    printf("1. Gunakan AloniCard\n");
    printf("2. Lanjut Penyelesaian Pesanan\n");
    printf("3. Batal..\n");

    printf("Masukkan Pilihan :: ");
    if(scanf("%d", &simpanOpsiLanjutan) != 1) return -1;
    return simpanOpsiLanjutan;
}

void pake_Aloni_Card(int *totalHarga) {
    int masukkanNo;
    printf("Masukkan No. Kartu : ");
    scanf("%d", &masukkanNo);
        if(masukkanNo == nomorKartu && punyaAloniCard) {
            printf("Yeayy, Kamu dapet diskon 10%%!\n");
            *totalHarga *= 0.9; 
        }
        else {
            printf("Maaf, nomor kartu tidak valid atau tidak ada :(\n");
        }
}

int konfirmasi_Pemesanan() {
    printf("~~======' Konfirmasi Pemesanan '======~~\n");
    printf("Masukkan Password : ");
    scanf("%d", &passwordKonfirmasi);
    return (passwordKonfirmasi == passwordUser);
}

int random_Nomor_Kamar() {
    return (rand() % 20) + 1;
}

void dalam_Proses_Pemesanan(int totalHarga) {
    printf("Total Harga = Rp%d\n", totalHarga);
    
        if (konfirmasi_Pemesanan()) {
            nomorKamar = random_Nomor_Kamar();
            printf("~*  Wah, pesanan berhasil dibuat nihh!  *~\n");
            printf("Nomor Kamar Kamu : %d\n", nomorKamar);
                if(jenisKamarDipilih != NULL) {
                    printf("Jenis Kamar     : %s\n", jenisKamarDipilih);
                }
                if(denganAloniCard) {
                    printf("Makasih Udah Pake AloniCard ^.^\n");
                }
        } 
        else {
            printf("Password Salah :(!\n");
                free(jenisKamarDipilih);
                jenisKamarDipilih = NULL;
        }
}

void tampilan_Menu_Pesan_Kamar() {
    printf("~~======' Pesan Kamar '======~~\n");
    printf("1. Kamar Standar   Rp100.000\n");
    printf("2. Kamar Deluxe    Rp350.000\n");
    printf("3. Kamar Suite     Rp750.000\n");
    printf("4. Kamar VIP       Rp1.500.000\n");
    
    int hargaKamar[] = {100000, 350000, 750000, 1500000};
    char *namaKamar[] = {"Standar", "Deluxe", "Suite", "VIP"};
    
    printf("Pilih Kamar :: ");
    scanf("%d", &dipilihKamar);

        if(dipilihKamar < 1 || dipilihKamar > 4) {
            printf("Waduh, Gak ada di pilihan nih :(\n");
            return;
        }

    jenisKamarDipilih = (char*)malloc(20 * sizeof(char));
    strcpy(jenisKamarDipilih, namaKamar[dipilihKamar-1]);
    
    printf("~~ %s\n", jenisKamarDipilih);
    
    int opsi = proses_Pemesanan_Kamar();
        if(opsi == -1) {
                free(jenisKamarDipilih);
                jenisKamarDipilih = NULL;
            return;
        }
    
    hasilHitungKamar = lamaMenginap * hargaKamar[dipilihKamar-1];
    denganAloniCard = 0;
    
        if(opsi == 1) {
            pake_Aloni_Card(&hasilHitungKamar);
            denganAloniCard = 1;
        }
        else if(opsi == 3) {
            printf("Pemesanan dibatalkan..\n");
                free(jenisKamarDipilih);
                jenisKamarDipilih = NULL;
            return;
        }
    
    dalam_Proses_Pemesanan(hasilHitungKamar);
}

void lihat_Pesanan() {
    printf("~~======' Lihat Pesanan '======~~\n");
    printf("Pesanan Atas Nama :: %s\n", namaUser);
        if(nomorKamar != 0 && jenisKamarDipilih != NULL) {
            printf("Jenis Kamar      :: %s\n", jenisKamarDipilih);
            printf("Nomor Kamar      :: %d\n", nomorKamar);
        }
        else {
            printf("Belum ada pesanan nih!\n");
        }
}

int main() {
    int udahLogin = 0;
    srand(time(NULL));
    
    while(1) {
        if(!udahLogin) {
            header_Menu_Awal();
            tampilan_Menu_Awal();
            
            switch(pilihanUser) {
                case 1: 
                    if(punyaAkun) {
                        if(tampilan_Login()) {
                            udahLogin = 1;
                        }
                    }
                    else {
                        printf("Kamu belum punya akun! Silahkan buat akun :)\n");
                    }
                    break;

                case 2:
                    tampilan_Buat_Akun();
                    break;
                
                case 3:
                    free(jenisKamarDipilih);
                    printf("Makasihh udah menggunakan layanan Alonica Hotel! ^>^\n");
                    return 0;
            }
        }
        else {
            header_Menu_Utama();
            tampilan_Menu_Utama();
            
            switch(pilihanUser) {
                case 1:
                    tampilan_Menu_Pesan_Kamar();
                    break;
                case 2:
                    lihat_Pesanan();
                    break;
                case 3:
                    aloni_Card();
                    break;
                case 4:
                    printf("Kamu berhasil log out!\n");
                    udahLogin = 0;
                    break;
                default:
                    printf("Waduh, gak ada di pilihan nih :(\n");
                    break;
            }
        }
    }
    return 0;
}