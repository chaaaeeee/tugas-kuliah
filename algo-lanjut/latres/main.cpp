#include <iostream>
#include <fstream>

#if defined(WIN32)
    #include <windows.h>
#elif defined(__linux__)
    #include <unistd.h>
#endif

void clearConsole() {
    #if defined(WIN32)
        std::sytem("cls")
    #elif defined(__linux__)
        std::system("clear");
    #else
        std::cerr << "Unsupported OS" << std::endl;
    #endif
}

struct penduduk {
    int Nomor;
    std::string Nama;
    std::string JenisKelamin;
    std::string TanggalLahir;
};

void daftarMenu() {
    std::cout << "Aplikasi Data Kependudukan" << std::endl;
    std::cout << "[1]. Input data" << std::endl;
    std::cout << "[2]. Output data" << std::endl;
    std::cout << "[3]. Exit" << std::endl;
};

void daftarMenuOutputData() {
    std::cout << "Output Data" << std::endl;
    std::cout << "[1]. Tampilkan data" << std::endl;
    std::cout << "[2]. Cari data" << std::endl;
    std::cout << "[3]. Kembali" << std::endl;
};

void inputData() {
    int jumlah;
    penduduk penduduk[100]; 
    std::ofstream file;
    file.open("file.txt", std::ios::app);
    if(!file) { // file doesnt exist
        file.open("file.txt", std::ios::trunc);
    };

    std::cout << "Masukkan berapa jumlah data yang ingin diinput : ";
    std::cin >> jumlah;

    for(int i = 0; i < jumlah; i++) {
        std::cout << "Nomor : ";
        std::cin >> penduduk[i].Nomor;
        file << penduduk[i].Nomor << std::endl;

        std::cin.ignore();
        std::cout << "Nama : ";
        getline(std::cin, penduduk[i].Nama);
        file << penduduk[i].Nama << std::endl;

        std::cout << "Jenis Kelamin : ";
        getline(std::cin, penduduk[i].JenisKelamin);
        file << penduduk[i].JenisKelamin << std::endl;

        std::cout << "Tanggal Lahir (format : YYYY-MM-DD): ";
        std::cin >> penduduk[i].TanggalLahir;
        file << penduduk[i].TanggalLahir << std::endl;
    }
};

void sortData(int jumlah, penduduk penduduk[]) {
    for (int i = 0; i < jumlah -1; ++i) {
        for (int j = 0; j < jumlah - i - 1; ++j) {
            if (penduduk[j].Nomor > penduduk[j + 1].Nomor) {
                std::swap(penduduk[j], penduduk[j + 1]);
            }
        }
    }
}

int getData(penduduk penduduk[]) {
    std::ifstream file;
    file.open("file.txt", std::ios::app);
    if(!file) {
        file.open("file.txt", std::ios::app);
    }

    std::string nomor, nama, jenisKelamin, tanggalLahir;
    int index = 0;
    while(
        getline(file, nomor) &&
        getline(file, nama) && 
        getline(file, jenisKelamin) &&
        getline(file, tanggalLahir)
    ) {
        penduduk[index].Nomor = stoi(nomor);
        penduduk[index].Nama = nama;
        penduduk[index].JenisKelamin = jenisKelamin;
        penduduk[index].TanggalLahir = tanggalLahir;
        
        index++;
    }

    sortData(index, penduduk);

    return index;
};

void showData() {
    penduduk penduduk[100];
    int jumlah;
    jumlah = getData(penduduk);
    for(int i = 0; i < jumlah; i++) {
        std::cout << "Nomor\t\t: " << penduduk[i].Nomor << std::endl;
        std::cout << "Nama\t\t: " << penduduk[i].Nama << std::endl;
        std::cout << "Jenis Kelamin\t: " << penduduk[i].JenisKelamin << std::endl;
        std::cout << "Tanggal Lahir\t:" << penduduk[i].TanggalLahir << std::endl;

        std::cout << std::endl;
    }

    std::cout << "Berhasil menampilkan data, mengembalikan ke menu utama dalam 10 detik..." << std::endl;
    sleep(10);
}

void searchData() {
    int jumlah;
    penduduk penduduk[100];
    jumlah = getData(penduduk);

    std::string cari;
    std::string cariTanggalLahir;
    int key;
    bool found = false;
    std::cout << "Masukkan Tanggal Lahir yang dicari (format : YYYY-MM-DD) yang ingin dicari : ";
    std::cin >> cariTanggalLahir;

    for(int i = 0; i < jumlah; i++) {
        if(cariTanggalLahir == penduduk[i].TanggalLahir) {
            found = true;
            key = i;
            break;
        }
    }

    if(found != true) {
        std::cout << "Data tidak ditemukan, mengembalikan ke menu utama..." << std::endl;
        sleep(3);
        return;
    }

    std::cout << "Nomor\t\t: " << penduduk[key].Nomor << std::endl;
    std::cout << "Nama\t\t: " << penduduk[key].Nama << std::endl;
    std::cout << "Jenis Kelamin\t: " << penduduk[key].JenisKelamin << std::endl;
    std::cout << "Tanggal Lahir\t:" << penduduk[key].TanggalLahir << std::endl;
    std::cout << std::endl;
    std::cout << "Data ditemukan, mengembalikan ke menu utama dalam 10 detik..." << std::endl;

    sleep(10);
}

int main() {
    int menu;
    int outputMenu;
    do{
        clearConsole();
        daftarMenu();
        std::cout << "Pilih :" << std::endl;
        std::cin >> menu;
        switch(menu) {
            case 1:
                clearConsole();
                inputData();
                break;
            case 2:
                clearConsole();
                daftarMenuOutputData();
                std::cout << "Pilih : ";
                std::cin >> outputMenu;
                switch(outputMenu) {
                    case 1:
                        clearConsole();
                        showData();
                        break;
                    case 2:
                        clearConsole();
                        searchData();
                        break;
                    case 3:
                        clearConsole();
                        std::cout << "Mengembalikan ke menu utama..." << std::endl;
                        sleep(3);
                        break;
                }
                break;
            case 3:
                clearConsole();
                std::cout << "Mengeliminasi program..." << std::endl;
                return 0;
                break;
            default:
                clearConsole();
                std::cout << "Input tidak valid, mengeliminasi program..." << std::endl;
                return 0;
        }
    }while(true);

    return 0;
}
