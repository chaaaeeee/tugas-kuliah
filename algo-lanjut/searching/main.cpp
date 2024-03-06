#include <iostream>

int linear(int arr[5], int cari, int size) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == cari) {
            return i;
        } 
    }
    return -1;
}

int binary(int arr[10], int atas, int bawah, int tengah, int cari) {
    while(bawah <= atas) {
        tengah = bawah + (atas - bawah) / 2;

        if(arr[tengah] == cari) {
            return tengah;  // return index tengah karena sudah sama
        }

        if(arr[tengah] < cari) { // jika cari > arr[tengah] maka elemen arr di bagian kiri tengah dan tengah dihapuskan
            bawah = tengah + 1; // merubah batas bawah menjadi tengah + 1 karena value di index tengah /= yang dicari
        }

        if(arr[tengah] > cari) { // jik ari < arr[tengah] maka elemen arr di bagian kanan tengah dan tengah dihapuskan
            atas = tengah - 1; // merubah batas atas menjadi tengah - 1 karena value di index tengah /= yang dicari
        }
    }

    return -1;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    int bawah = 0;
    int atas = size - 1;
    int tengah;
    int cari;

    std::cout << "angka : "; std::cin >> cari;
    std::cout << std::endl;

    std::cout << "angka " << cari << " ada di index " << binary(arr, atas, bawah, tengah, cari);
    std::cout << std::endl;
    std::cout << "angka " << cari << " ada di index " << linear(arr, cari, size);
}
