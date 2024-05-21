#include <iostream>
#include <bits/stdc++.h>
#include <unistd.h> // untuk fungsi sleep() di linux

struct DataLayanan {
    std::string Nama;
    int Harga;
    int Lama;
};

struct DataPelanggan {
    int Kode;
    std::string Nama;
    std::string NomorHP;
    DataLayanan Layanan;
};

void daftarMenu(int ada) {
    if (ada == false) {
        std::cout << "Daftar Menu" << std::endl;
        std::cout << "[1]. Input Data Pelanggan" << std::endl;
        std::cout << "[2]. Output Data Pelanggan" << std::endl;
        std::cout << "[3]. Cari Data Pelanggan" << std::endl;
        std::cout << "[4]. Urut Data Pelanggan" << std::endl;
    } else {
        std::cout << "Daftar Menu" << std::endl;
        std::cout << "[1]. Tambah Data Pelanggan" << std::endl;
        std::cout << "[2]. Output Data Pelanggan" << std::endl;
        std::cout << "[3]. Cari Data Pelanggan" << std::endl;
        std::cout << "[4]. Urut Data Pelanggan" << std::endl;
    }
}

void daftarLayanan() {
    std::cout << "Daftar Layanan" << std::endl;
    std::cout << "[1]. Fast Track" << std::endl;
    std::cout << "[2]. Booking" << std::endl;
    std::cout << "[3]. Light Service" << std::endl;
    std::cout << "[4]. Heavy Repair" << std::endl;
    std::cout << "[5]. Claim Service" << std::endl;
}

int main() {
    char utama;
    DataPelanggan temp; 
    DataPelanggan arr[100];
    int jumlah;
    int pilihLayanan = 0;
    int size;
    std::string namaCari;
    bool adaPelanggan = false;
    int i, j;
    int awal, akhir, total = 0;

    do {
        system("clear");
        size = sizeof(arr)/sizeof(arr[0]);
        bool ketemu = false;
        int menu = 0;
        daftarMenu(adaPelanggan);
        std::cout << "Pilih : ";
        std::cin >> menu;
        // jumlah di append

        switch (menu) {
            case 1:
                adaPelanggan = true;
                std::cout << "Masukkan jumlah pasien yang ingin ditambahkan : ";
                std::cin >> jumlah;
                total = awal + jumlah;
                for (i = awal; i < total; i++) {
                    arr[i].Kode = i + 1;
                    std::cout << "Masukkan data pasien dengan ID " << arr[i].Kode << std::endl;
                    std::cout << "Nama : ";
                    std::cin.ignore();
                    getline(std::cin, arr[i].Nama);
                    std::cout << "Nomor HP : ";
                    std::cin >> arr[i].NomorHP;

                    daftarLayanan();
                    std::cout << "Pilih layanan : ";
                    std::cin >> pilihLayanan;
                    switch (pilihLayanan) {
                        case 1:
                            arr[i].Layanan.Nama = "Fast Track";
                            break;
                        case 2:
                            arr[i].Layanan.Nama = "Booking";
                            break;
                        case 3:
                            arr[i].Layanan.Nama = "Light Service";
                            break;
                        case 4:
                            arr[i].Layanan.Nama = "Heavy Repair";
                            break;
                        case 5:
                            arr[i].Layanan.Nama = "Claim Service";
                            break;
                        default: 
                            std::cout << "Input tidak valid, mengeliminasi program...";
                            return 0;
                    }

                    std::cout << "Harga Layanan : ";
                    std::cin >> arr[i].Layanan.Harga;

                    std::cout << "Lama Layanan : ";
                    std::cin >> arr[i].Layanan.Lama;

                }
                awal = awal + jumlah;

                std::cout << "Kembali ke menu utama? (y/n) : ";
                std::cin >> utama;
                switch (utama) {
                    case 'y':
                        std::cout << "Mengembalikan ke menu utama" << std::endl;
                        sleep(1);
                        std::cout << std::endl;
                        break;
                    case 'n':
                        std::cout << "Mengeliminasi program...";
                        return 0;
                    default:
                        std::cout << "Mengeliminasi program...";
                        return 0;
                }
                break;
            case 2:
                system("clear");
                if (adaPelanggan == false) {
                    std::cout << "Data pasien kosong, mengembalikan ke menu utama..."
                        << std::endl;
                    sleep(1);
                    std::cout << std::endl;
                    break;
                }
                std::cout << "DAFTAR PELANGGAN" << std::endl;
                for (int i = 0; i < total; i++) {
                    std::cout << "Kode Pelanggan\t\t" << ": " << arr[i].Kode << std::endl;
                    std::cout << "Nama Pelanggan\t\t" << ": " << arr[i].Nama << std::endl;
                    std::cout << "Nomor HP Pelanggan\t" << ": " << arr[i].NomorHP << std::endl;
                    std::cout << "Pilihan Layanan\t\t" << ": " << arr[i].Layanan.Nama << std::endl;
                    std::cout << "Harga Layanan\t\t" << ": " << arr[i].Layanan.Harga << std::endl;
                    std::cout << "Lama Layanan\t\t" << ": " << arr[i].Layanan.Lama << std::endl;

                    std::cout << std::endl;
                }

                std::cout << "Kembali ke menu utama? (y/n) : ";
                std::cin >> utama;
                switch (utama) {
                    case 'y':
                        std::cout << "Mengembalikan ke menu utama";
                        std::cout << std::endl;
                        break;
                    case 'n':
                        std::cout << "Mengeliminasi program...";
                        return 0;
                    default:
                        std::cout << "Mengeliminasi program...";
                        return 0;
                }
                break;
            case 3:
                std::cout << "Masukkan nama pasien yang ingin dicari : ";
                std::cin.ignore();
                getline(std::cin, namaCari);

                // menggunakan sequential search
                for (int i = 0; i < total; i++) {
                    if (namaCari == arr[i].Nama) { // bisa print lebih dari 1 nama
                        ketemu = true;
                        // cout
                    std::cout << "Kode Pelanggan\t\t" << ": " << arr[i].Kode << std::endl;
                    std::cout << "Nama Pelanggan\t\t" << ": " << arr[i].Nama << std::endl;
                    std::cout << "Nomor HP Pelanggan\t" << ": " << arr[i].NomorHP << std::endl;
                    std::cout << "Pilihan Layanan\t\t" << ": " << arr[i].Layanan.Nama << std::endl;
                    std::cout << "Harga Layanan\t\t" << ": " << arr[i].Layanan.Harga << std::endl;
                    std::cout << "Lama Layanan\t\t" << ": " << arr[i].Layanan.Lama << std::endl;

                    std::cout << std::endl;
                    }
                }

                if (ketemu == false) {
                    std::cout << "Data pasien dengan nama " << namaCari
                        << " tidak ditemukan, mengembalikan ke menu utama..."
                        << std::endl;
                    sleep(1);
                    break;
                }

                std::cout << "Kembali ke menu utama? (y/n) : ";
                std::cin >> utama;
                switch (utama) {
                    case 'y':
                        std::cout << "Mengembalikan ke menu utama";
                        std::cout << std::endl;
                        break;
                    case 'n':
                        std::cout << "Mengeliminasi program...";
                        return 0;
                    default:
                        std::cout << "Mengeliminasi program...";
                        return 0;
                }
                break;
            case 4:
                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - i - 1; j++) {
                        if (arr[j].Nama > arr[j + 1].Nama) {
                            std::swap(arr[j].Kode, arr[j+1].Kode);
                            std::swap(arr[j].Nama, arr[j+1].Nama);
                            std::swap(arr[j].NomorHP, arr[j+1].NomorHP);
                            std::swap(arr[j].Layanan.Nama, arr[j+1].Layanan.Nama);
                            std::swap(arr[j].Layanan.Harga, arr[j+1].Layanan.Harga);
                            std::swap(arr[j].Layanan.Lama, arr[j+1].Layanan.Lama);

                            /*

                            temp.Kode = arr[j].Kode;
                            arr[j].Kode = arr[j+1].Kode;
                            arr[j+1].Kode = temp.Kode;

                            temp.Nama = arr[j].Nama;
                            arr[j].Nama = arr[j+1].Nama;
                            arr[j+1].Nama = temp.Nama;

                            temp.NomorHP = arr[j].NomorHP;
                            arr[j].NomorHP = arr[j+1].NomorHP;
                            arr[j+1].NomorHP = temp.NomorHP;

                            temp.NomorHP = arr[j].NomorHP;
                            arr[j].NomorHP = arr[j+1].NomorHP;
                            arr[j+1].NomorHP = temp.NomorHP;

                            temp.Layanan.Nama = arr[j].Layanan.Nama;
                            arr[j].Layanan.Nama = arr[j+1].Layanan.Nama;
                            arr[j+1].Layanan.Nama = temp.Layanan.Nama;

                            temp.Layanan.Harga = arr[j].Layanan.Harga;
                            arr[j].Layanan.Harga = arr[j+1].Layanan.Harga;
                            arr[j+1].Layanan.Harga = temp.Layanan.Harga;

                            temp.Layanan.Lama = arr[j].Layanan.Lama;
                            arr[j].Layanan.Lama = arr[j+1].Layanan.Lama;
                            arr[j+1].Layanan.Lama = temp.Layanan.Lama;
                            */
                        }
                    }
                }

                for (int i = 0; i < size; i++) {
                    std::cout << "Kode Pelanggan\t\t" << ": " << arr[i].Kode << std::endl;
                    std::cout << "Nama Pelanggan\t\t" << ": " << arr[i].Nama << std::endl;
                    std::cout << "Nomor HP Pelanggan\t" << ": " << arr[i].NomorHP << std::endl;
                    std::cout << "Pilihan Layanan\t\t" << ": " << arr[i].Layanan.Nama << std::endl;
                    std::cout << "Harga Layanan\t\t" << ": " << arr[i].Layanan.Harga << std::endl;
                    std::cout << "Lama Layanan\t\t" << ": " << arr[i].Layanan.Lama << std::endl;

                    std::cout << std::endl;
                };

                std::cout << "Kembali ke menu utama? (y/n) : ";
                std::cin >> utama;
                switch (utama) {
                    case 'y':
                        std::cout << "Mengembalikan ke menu utama";
                        std::cout << std::endl;
                        break;
                    case 'n':
                        std::cout << "Mengeliminasi program...";
                        return 0;
                    default:
                        std::cout << "Mengeliminasi program...";
                        return 0;
                }
                break;
            default:
                std::cout << "Input tidak valid, Mengeliminasi program...";
                return 0;
        }

    } while (true);
    return 0;
}
