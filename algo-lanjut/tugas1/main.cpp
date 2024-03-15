#include <iostream>
#include <iomanip>
#include <unistd.h> // untuk fungsi sleep() di linux


struct DataPasien {
    int Id;
    std::string Nama;
    int Umur;
    std::string Penyakit;   
};

void daftarMenu() {
    std::cout << "Daftar Menu" << std::endl;
    std::cout << "[1]. Tambah Pasien" << std::endl;
    std::cout << "[2]. Daftar Pasien" << std::endl;
    std::cout << "[3]. Cari Pasien" << std::endl;
    std::cout << "[4]. Keluar" << std::endl;
}

int main() {
    char utama;
    DataPasien arr[100];
    bool adaPasien = false;
    int jumlah;

    do {
        system("clear");
        bool ketemu = false;
        int menu = 0;
        daftarMenu();
        std::cout << "Pilih : ";
        std::cin >> menu;
        // jumlah di append
        
        switch(menu) {
            case 1:
                adaPasien = true;
                std::cout << "Masukkan jumlah pasien yang ingin ditambahkan : ";
                std::cin >> jumlah;
                for(int i = 0; i < jumlah; i++) {
                    arr[i].Id = i + 1;
                    std::cout << "Masukkan data pasien dengan ID " << arr[i].Id << std::endl;
                    std::cout << "Nama : ";
                    std::cin.ignore();
                    getline(std::cin, arr[i].Nama);
                    std::cout << "Penyakit : ";
                    getline(std::cin, arr[i].Penyakit);
                    std::cout << "Umur : ";
                    std::cin >> arr[i].Umur;
                }

                std::cout << "Kembali ke menu utama? (y/n) : ";
                std::cin >> utama;
                switch(utama) {
                    case 'y':
                        std::cout << "Mengembalikan ke menu utama" << std::endl;
                        sleep(2);
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
                if(adaPasien == false) {
                    std::cout << "Data pasien kosong, mengembalikan ke menu utama..." << std::endl;
                    sleep(2);
                    std::cout << std::endl;
                    break;
                }
                std::cout << "DAFTAR PASIEN" << std::endl;
                for(int i = 0; i < jumlah; i++) {
                    std::cout << "ID\t\t" << ": " << arr[i].Id << std::endl;
                    std::cout << "Nama\t\t" << ": " << arr[i].Nama << std::endl;
                    std::cout << "Umur\t\t" << ": " << arr[i].Umur << std::endl;
                    std::cout << "Penyakit\t"<< ": " << arr[i].Penyakit << std::endl;
                    std::cout << std::endl;
                }

                std::cout << "Kembali ke menu utama? (y/n) : ";
                std::cin >> utama;
                switch(utama) {
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
                std::cout << "Cari Data Pasien Menggunakan? " << std::endl;
                std::cout << "[1]. ID" << std::endl;
                std::cout << "[2]. Nama" << std::endl;
                int menuCari;
                std::cin >> menuCari;

                switch(menuCari) {
                    case 1:
                        int idCari;
                        std::cout << "Masukkan Id pasien yang ingin dicari : ";
                        std::cin >> idCari;

                        // sekedar cek apakah datanya ada atau tidak
                        for(int i = 0; i < jumlah; i++) {
                            if(arr[idCari - 1].Id == arr[i].Id) {
                                ketemu = true;
                                std::cout << "ID\t\t" << ": " << arr[i].Id << std::endl;
                                std::cout << "Nama\t\t" << ": " << arr[i].Nama << std::endl;
                                std::cout << "Umur\t\t" << ": " << arr[i].Umur << std::endl;
                                std::cout << "Penyakit\t"<< ": " << arr[i].Penyakit << std::endl;
                                std::cout << std::endl;
                            }
                        }

                        if(ketemu == false) {
                            std::cout << "Data pasien dengan Id " << idCari << " tidak ditemukan, mengembalikan ke menu utama..." << std::endl; 
                            sleep(2);
                        }

                        std::cout << "Kembali ke menu utama? (y/n) : ";
                        std::cin >> utama;
                        switch(utama) {
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
                    case 2:
                        break;
                    default: 
                        std::cout << "Input tidak valid, mengeliminasi program";
                        return 0;
                }


                break;
            case 4:
                std::cout << "Mengeliminasi progra...";
                return 0;
                break;
            default:
                std::cout << "Input tidak valid, Mengeliminasi program...";
                return 0;
        }

    }while(true);
    return 0;
}
