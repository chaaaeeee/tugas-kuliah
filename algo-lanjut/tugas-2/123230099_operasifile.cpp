#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

void clearConsole() {
    std::system("cls");
}

struct jadwal {
    std::string Jurusan;
    int Jam;
    int Durasi;
};

struct direksi {
    std::string Nama;
    int Jam;
    int Durasi;
};

bool valid(int jam) {
    if(jam < 0 || jam > 24) {
        return false;
    }

    return true;
}

void daftarMenu() {
    std::cout << "Aplikasi Penunjang Rapat" << std::endl;
    std::cout << "Menu : " << std::endl;
    std::cout << "[1]. Input" << std::endl;
    std::cout << "[2]. Output" << std::endl;
    std::cout << "[3]. Hasil" << std::endl;
    std::cout << "[4]. Exit" << std::endl;
}

void inputJadwal() {
    clearConsole();
    int jumlah;
    jadwal jadwal[100];
    std::cout << "Masukkan jumlah jadwal yang ingin ditambahkan : ";
    std::cin >> jumlah;

    std::ofstream file;
    file.open("file1.txt", std::ios::app);
    if(!file) {
        file.open("file1.txt", std::ios::trunc);
    };

    for(int i = 0; i < jumlah; i++) {
        std::cin.ignore();
        std::cout << "Jurusan : ";
        getline(std::cin, jadwal[i].Jurusan);
        file << jadwal[i].Jurusan;

        file << std::endl;

        std::cout << "Jam : ";
        std::cin >> jadwal[i].Jam;
        file << jadwal[i].Jam;

        file << std::endl;

        std::cout << "Durasi : ";
        std::cin >> jadwal[i].Durasi;
        file << jadwal[i].Durasi;

        file << std::endl;
    };

    file.close();

    std::cout << "Data berhasil di input, mengembalikan ke menu utama..." << std::endl;
    std::system("pause");
};

void outputJadwal() { 
    clearConsole();
    jadwal jadwal[100];
    std::ifstream file;
    file.open("file1.txt");
    if(!file) {
        std::cout << "Tidak ada jadwal terdaftar" << std::endl;
        std::system("pause");
        return;
    };

    int index = 0;
    std::string jurusan, jam, durasi;
    while(
        getline(file, jurusan) &&
        getline(file, jam) &&
        getline(file, durasi)
    ){
        jadwal[index].Jurusan = jurusan;
        jadwal[index].Jam = stoi(jam);
        jadwal[index].Durasi = stoi(durasi);
        index++;
    }

    int total = index;
    
    system("clear");
    std::cout << std::left << std::setw(30) << "Jurusan" << std::setw(10) << "Jam" << std::setw(10) << "Durasi" << std::endl;
    for(int i = 0; i < total; i++) {
        std::cout << std::left << std::setw(30) << jadwal[i].Jurusan << std::setw(10) << jadwal[i].Jam << std::setw(10) << jadwal[i].Durasi<< std::endl;
    }

    std::cout << std::endl << "Data berhasil ditampilkan, mengembalikan ke menu utama dalam 10 detik..." << std::endl;
    std::system("pause");

    file.close();
};

void hasilJadwal() {
    clearConsole();
    jadwal jadwal[100];
    direksi direksi[100];
    std::fstream file;
    file.open("file1.txt");
    if(!file) {
        std::cout << "Tidak ada jadwal terdaftar" << std::endl;
        std::system("pause");
        return;
    };

    std::string jurusan, jam, durasi;

    int index = 0;
    while(
        getline(file, jurusan) &&
        getline(file, jam) &&
        getline(file, durasi)
    ){
        jadwal[index].Jurusan = jurusan;
        jadwal[index].Jam = stoi(jam);
        jadwal[index].Durasi = stoi(durasi);

        index++;
    }

    bool sama;
    int lowest;
    std::string nomorDireksi;
    int jumlahDireksi;
    int jumlahSama;

    // dibagi 3 karena ada 3 data tiap jadwal
    for(int i = 0; i < index/3; i++) {

        sama = false;
        jumlahSama = 0;
        for(int j = 1; j < index/3; j++) {
            // kalau ada jam yang sama
            if(jadwal[i].Jam == jadwal[j].Jam) {
                sama = true;
                jumlahSama++;
                // cari jam terrendah
                if(jadwal[i].Durasi < jadwal[j].Durasi) {
                    lowest = i;
                } else if(jadwal[i].Durasi > jadwal[j].Durasi) {
                    lowest = j;
                } else {
                    lowest = i;
                } }
        }

        jumlahDireksi = index/3 - jumlahSama;
        nomorDireksi = std::to_string(i + 1);
        direksi[i].Nama = "Direksi " + nomorDireksi;
        // cek kalo ada yg sama
        if(sama == true) {
            direksi[i].Jam = jadwal[lowest].Jam;
            direksi[i].Durasi = jadwal[lowest].Durasi;
        }

        /*
        std::cout << "Jurusan : " << direksi[i].Nama << std::endl;
        std::cout << "Jam : " << direksi[i].Jam << std::endl;
        std::cout << "Durasi : " << direksi[i].Durasi << std::endl;
        */
    }


    std::cout << "menu ini belum selesai" << std::endl;
    std::system("pause");
};

int main() {
    int menu;
    int jumlah;
    
    do{
        clearConsole();
        daftarMenu();
        std::cout << "Pilih : ";
        std::cin >> menu;
        
        // this code won't execute if i enter number 2 for the menu, but it is okay if i enter 1, 3, 4, 5, or more

        switch(menu) {
            case 1:
                inputJadwal();
                break;
            case 2:
                outputJadwal();
                break;
            case 3:
                // tidak selesai
                hasilJadwal();
                break;
            case 4:
                std::cout << "Mengeliminasi program...";
                return 0;
            default:
                std::cout << "Input tidak valid, mengembalikan ke menu utama..." << std::endl;
                std::flush(std::cout);
                std::system("pause");
                break;
        }

    }while(true);
    return 0;
}
