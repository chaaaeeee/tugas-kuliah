#include <iostream>

void change(int arr[], int index, int angka) {
    arr[index] = angka;
}

void swap(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapBeneran(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int linear(int arr[], int size, int cari)
{
    if (size == 0) {
        return -1;
    }
    else if (arr[size - 1] == cari) {
        return size - 1; 
    }
    return linear(arr, size - 1, cari);
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int index = 9;
    int angka = 10;
    change(arr, index, angka); // merubah 0 menjadi 10
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    std::cout << "Angka 3 terdapat pada index : " << linear(arr, sizeof(arr)/sizeof(int), 3);
    std::cout << std::endl;
    int ketemu = linear(arr, sizeof(arr)/sizeof(int), 11);
    if(ketemu == -1) {
        std::cout << "Angka 11 tidak terdapat dalam array";
    }
    else {
        std::cout << "Angka 11 terdapat pada index : " << linear(arr, sizeof(arr)/sizeof(int), 11);
    }

    std::cout << std::endl;
    
    // input(arr, sizeof(arr)/sizeof(int));
    int a = 14;
    int b = 9;
    swap(a, b);
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;

    swapBeneran(a, b);
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;

    return 0;
}
