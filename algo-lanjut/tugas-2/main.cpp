#include <iostream>
#include <fstream>
#include <iomanip>

// melakukan if condition pada OS yang digunakan karena saya menggunakan linux dan library untuk fungsi sleep adalah platform-independent artinya beda antara windows dan linux
#if defined(WIN32)
    #include <windows.h>
#elif defined(__linux__)
    #include <unistd.h>
#endif

// melakukan if condition pada OS yang digunakan karena command yang digunakan untuk menghapus console berbeda dengan windows
void clearConsole() {
    #if defined(WIN32)
        std::sytem("cls")
    #elif defined(__linux__)
        std::system("clear");
    #else
        std::cerr << "Unsupported OS" << std::endl;
    #endif
}

struct jadwal {
    std::string Jurusan;
    int Jam;
    int Durasi;
};

void daftarMenu() {
    std::cout << "aplikasi pertemuan" << std::endl;
    std::cout << "menu : " << std::endl;
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
    sleep(2);
};

void outputJadwal() { 
    clearConsole();
    jadwal jadwal[100];
    std::ifstream file;
    file.open("file1.txt");
    if(!file) {
        std::cout << "Tidak ada jadwal terdaftar" << std::endl;
        sleep(2);
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
    sleep(10);

    file.close();
};

void hasilJadwal() {

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
                hasilJadwal();
                break;
            case 4:
                std::cout << "Mengeliminasi program...";
                return 0;
            default:
                std::cout << "Input tidak valid, mengembalikan ke menu utama..." << std::endl;
                std::flush(std::cout);
                sleep(2);
                break;
        }

    }while(true);
    return 0;
}
