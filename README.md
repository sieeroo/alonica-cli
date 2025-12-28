# ALONICA - Hotel Management
**Alonica** adalah aplikasi manajemen hotel berbasis _Command Line Interface_ yang ditulis dalam bahasa pemrograman C. Program ini memungkinkan pengguna untuk membuat akun, melakukan reservasi kamar dengan berbagai tipe, dan memiliki fitur loyalitas khusus yang disebut AloniCard.

## Fitur
* **Sistem Autentikasi** : Fitur Buat Akun dan Login untuk keamanan data pengguna.
* **Reservasi Kamar** : Mendukung berbagai tipe kamar dengan harga yang bervariasi.
* **Manajemen Pesanan** : Pengguna dapat melihat detail pesanan aktif, termasuk nomor kamar yang dihasilkan secara acak.
* **Alokasi Kamar Otomatis** : Sistem memberikan nomor kamar secara random (1-20) setelah pembayaran dikonfirmasi.

## Teknologi yang Digunakan
* **Bahasa Pemrograman** : C
* **Library** : stdio.h, stdlib.h, string.h, time.h.
* **Konsep Pemrograman** : I/O, Variabel, Pointer, Array, Looping, Tipe Data, Conditional.
  
## Cara Menjalankan
1. Install compiler C, seperti GCC atau MinGW
2. Clone repository ini : 
   ```bash
   git clone https://github.com/sieeroo/alonica-cli.git
3. Compile Program :
   ```bash
   gcc alonicastay.c -o alonicastay
4. Jalankan Program :
   ```bash
   ./alonicastay
