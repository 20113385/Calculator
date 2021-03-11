/*
* Presentasi Algoritma Pemrograman
* Judul program : Sistem Peminjaman Buku diperpustakaan
* Kelompok 12
* kelas : IF-02
* Anggota:
* Nugraha Sentosa    20.11.3806
* Ihsan Rizqi        20.11.3787
* Wisnu Dwi Handono  20.11.3422
* Fariz Firmansyah   20.11.3380
* Indah Mega Lestari 20.11.3385
*/


#include <iostream> 
#include <conio.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


using namespace std;
void garis() {
    cout << " \t====================================================== \n";
}
int main() {
    char user[20], pass[6], status;
    int balik;
    int a, b, c, d, e, f, j, k, i;
    int pil;

    //struct untuk menggabungkan beberapa data dengan tipe data yang berbeda
    struct buku {
        int kodeB;
        char judul[30];
        int sewa;
        int stock;
    }z[100];

    struct daftar {
        int kodeP;
        char nama[50];
        char tlp[20];
    } y[100];

    struct pinjam {
        int kp;
        int kb;
        int noPinjam;
        char tglP[20];
        char tglU[20];
    } x[100];
    c = 0;
    e = 0;

    garis();
    cout << " \tSelamatDatang Di Aplikasi Peminjaman Buku Perpustakaan \n";
    garis();
    cout << endl;
atas:
    cout << " Silakan Login \n";
    cout << " Username : "; cin >> user;
    cout << " Password : "; cin >> pass;
    if (strcmp(pass, "070701") == 0) {
        cout << " User Berhasil Login\n";
        garis();
        cout << endl;
        system("cls");

    }
    else {
        cout << "Password Salah\n";
        cout << endl;
        goto atas;
    }

menu:
    garis();
    cout << " \t\tPilihan Menu Peminjaman\n";
    cout << " 1. Input Data Buku\n";
    cout << " 2. Daftar Buku \n";
    cout << " 3. Pendaftaran Anggota\n";
    cout << " 4. Data Anggota\n";
    cout << " 5. Peminjaman Buku\n";
    cout << " 6. Pengembalian Buku\n";
    cout << " 7. Rekap Buku\n";
    cout << " 8. Keluar\n";
    cout << " Masukan Pilihan Anda : "; cin >> pil;
    system("cls");
    switch (pil) {
    case 1:
        goto input;
        break;
    case 2:
        goto book;
        break;
    case 3:
        goto daf;
        break;
    case 4:
        goto data;
        break;
    case 5:
        goto pjm;
        break;
    case 6:
        goto bali;
        break;
    case 7:
        goto rekap;
        break;
    case 8:
        cout << " Terimakasih Telah menggunakan aplikasi ini\n";
        cout << endl;
        goto end;
        break;
    default:
        cout << " Pilihan tidak tersedia\n";
        cout << endl;
        goto menu;
        break;
    }

input:
    cout << " Masukan Banyaknya buku yang akan diinputkan : "; cin >> a;
    for (b = 0; b < a; b++) {
        cout << " Masukan data buku ke- " << b + 1 << endl;
        cout << " Kode buku\t ";
        cin >> z[b].kodeB;
        cout << " Judul buku\t ";
        cin >> z[b].judul;
        cout << " Jumlah buku\t ";
        cin >> z[b].stock;
        cout << endl;
    }
    system("cls");
    goto menu;

book:
    garis();
    cout << " ======================Daftar Buku=====================\n";
    garis();
    cout << " | Kode Buku\t| Judul Buku | Jumlah | \n";
    garis();
    for (b = 0; b < a; b++) {
        cout << " |\t" << z[b].kodeB << "\t| " << z[b].judul << "\t\t|\t" << z[b].stock << endl;
    }
    garis();
    cout << endl;
    goto menu;


daf:
    for (d = c; d < c + 1; d++) {
        cout << " Kode Peminjaman (angka): ";
        cin >> y[d].kodeP;
        cout << " Nama : ";
        cin >> y[d].nama;
        cout << " Nomor Telepon : ";
        cin >> y[d].tlp;
        cout << endl;
    }
    c = c + 1;
    k = c;
    cout << " Ingin menginputkan data lagi? (y/n) : "; cin >> status;
    if (status == 'Y' || status == 'y') {
        goto daf;
    }
    else {
        system("cls");
        goto menu;
    }

data:
    garis();
    cout << " ==================Data Nama Anggota===================\n";
    garis();
    cout << " | Kode Peminjaman\t| Nama | No. Telepon | \n";
    garis();
    for (d = 0; d < c; d++) {
        cout << " |\t" << y[d].kodeP << "\t| " << y[d].nama << "\t\t|\t" << y[d].tlp << endl;

    }
    goto menu;

pjm:
    for (f = e; f < e + 1; f++) {
        cout << " Nomor Peminjaman : ";
        cin >> x[f].noPinjam;
        cout << " Kode Peminjam : ";
        cin >> x[f].kp;
        for (d = 0;d < c - 1;d++) {
            if (y[d].kodeP == x[f].kp) {
                cout << " Nama peminjam : " << y[d].nama << endl;
                break;
            }
            else {
                cout << " Data tidak ditemukan " << endl;
                cout << " Ingin menginputkan data lagi? (y/n) : "; cin >> status;
                if (status == 'Y' || status == 'y') {
                    goto pjm;
                }
                else {
                    system("cls");
                    goto menu;
                }
            }
        }
        cout << " Kode buku : "; cin >> x[f].kb;
        for (b = 0; b < a; b++) {
            if (z[b].kodeB == x[f].kb) {
                cout << " Judul buku : " << z[b].judul << endl;
                break;
            }
            else {
                cout << " Data tidak ditemukan " << endl;
                goto pjm;

            }
        }
        cout << " Tanggal Pinjam : ";
        cin >> x[f].tglP;
        cout << " Tanggal Kembali : ";
        cin >> x[f].tglU;
        cout << endl;
    }
    cout << " Ingin menginputkan data lagi? (y/n) : "; cin >> status;
    if (status == 'Y' || status == 'y') {
        goto pjm;
    }
    else {
        e = e + 1;
        system("cls");
        goto menu;
    }

bali:
    cout << " Masukan kode peminjaman : ";
    cin >> balik;
    for (f = 0; f < e; f++)
        if (x[f].kp == balik) {
            cout << " Kode buku : " << x[f].kb << endl;
            cout << " Tanggal Pinjam : " << x[f].tglP << endl;
            cout << " Tanggal Kembali : " << x[f].tglU << endl;
        }
        else {
            cout << " Kode yang anda masukan salah " << endl;
            goto bali;
        }
    cout << endl;
    goto menu;


rekap:
    cout << endl;
    for (j = 0; j < e; j++) {
        cout << " Nomor Peminjaman : " << x[j].noPinjam << endl;
        cout << " Kode Peminjam : " << x[j].kp << endl;
        for (i = 0; i < k; i++) {
            if (y[i].kodeP == x[j].kp) {
                cout << " Nama Peminjam : " << y[i].nama << endl;
            }
        }
        cout << " Kode Buku : " << x[j].kb << endl;
        for (b = 0; b < a; b++) {
            if (z[b].kodeB == x[j].kb) {
                cout << " Judul Buku : " << z[b].judul << endl;
            }
        }
        cout << " Tanggal Pinjam : " << x[j].tglP << endl;
        cout << " Tanggal Kembali : " << x[j].tglU << endl;
        cout << endl;

    }
    cout << "Ingin Kembali Ke Menu Utama? <Y/N>";cin >> status;
    if (status == 'Y' || status == 'y') {
        system("cls");
        goto menu;
    }
    else {
        goto rekap;
    }

end:
    system("pause");
    return 0;
}