#include <iostream>

struct Pelanggan {
    int KodeBooking;
    std::string Nama;
    std::string NIK;
    int NoKamar;
    int HariBooking;
    int JumlahOrang;
};

void daftarMenu() {
    std::cout << "RESERVASI HOTEL" << std::endl;
    std::cout << "1. Check In" << std::endl;
    std::cout << "2. Cari Tamu" << std::endl;
    std::cout << "3. Exit" << std::endl;
}

int main() {
    int menu;
    std::string kamar[10][10];
    int inkremen = 1; // mulai dari 1
    int kodeBooking = 0;

    Pelanggan arr[100];

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            kamar[i][j] = std::to_string(inkremen);
            inkremen += 1; //inkremen sampai 100
        }
    }

    do{
        daftarMenu();

        std::cout << "Pilih : ";
        std::cin >> menu;
        switch(menu) {
            case 1:
                kodeBooking += 1;
                inkremen = 1;
                std::cout << "CHECK IN KAMAR" << std::endl;

                for(int i = 0; i < 10; i++) {
                    for(int j = 0; j < 10; j++) {
                        std::cout << kamar[i][j] << "\t";
                    }
                    std::cout << std::endl;
                }
                
                std::cout << "INPUT DATA" << std::endl;
                std::cout << "Nama : ";
                std::cin.ignore();
                getline(std::cin, arr[kodeBooking].Nama);
                std::cout << "NIK : ";
               getline(std::cin, arr[kodeBooking].NIK);
                std::cout << "No Kamar : ";
                std::cin >> arr[kodeBooking].NoKamar;
                std::cout << "Hari Booking : ";
                std::cin >> arr[kodeBooking].HariBooking;
                std::cout << "Jumlah Orang : ";
                std::cin >> arr[kodeBooking].JumlahOrang;
 
                for(int i = 0; i < 10; i++) {
                    for(int j = 0; j < 10; j++) {
                        if (kamar[i][j] == std::to_string(arr[kodeBooking].NoKamar)) {
                            kamar[i][j] = "XX";
                        }
                        std::cout << kamar[i][j] << "\t";
                    }
                    std::cout << std::endl;
                }

                std::cout << "Kode Booking mu adalah : " << kodeBooking;
                break;
            case 2:
                break;
            case 3:
                std::cout << "mengeliminasi program...";
                return 0;
            default:
                std::cout << "invalid input, try again";
                break;
        }
    }while(true);



    return 0;
}
