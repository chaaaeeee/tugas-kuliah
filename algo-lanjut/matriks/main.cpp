#include <iostream>

struct matriks {
    int baris;
    int kolom;
};

bool bisaDitambahKurang(int ab, int ak, int bb, int bk) { 
   if(ab != bb && ak != bk) {
       return false;
   };

   return true;
};

bool bisaDikali(int ak, int bb) {
    if(ak != bb) {
        return false;
    };
    return true;
};

void input(int a[100][100], int b[100][100], int ab, int ak, int bb, int bk) {
    std::cout << "masukkan elemen matriks\n";
    std::cout << "matriks a : \n";
    for(int i = 0; i < ab; i++) {
        for(int j = 0; j < ak; j++) {
            std::cout << "masukkin elemen [" << i << "][" << j << "] :\n";
            std::cin >> a[i][j];
        };
    };

    std::cout << std::endl;

    std::cout << "matriks b : \n";
    for(int i = 0; i < bb; i++) {
        for(int j = 0; j < bk; j++) {
            std::cout << "masukkin elemen [" << i << "][" << j << "] :\n";
            std::cin >> b[i][j];
        };
    };
};

void output(int sum[100][100], int sb, int sk) {
    std::cout << "hasilnya adalah : \n";
    for(int i = 0; i < sb; i++) {
        for(int j = 0; j < sk; j++) {
            if(j == 0) {
                std::cout << "( " << sum[i][j] << "     ";
            }
            else if(j == sk - 1) {
                std::cout << sum[i][j] << " )";
            }
            else {    
                std::cout << sum[i][j] << "     ";
            };
        };

        std::cout << std::endl;
    };
};

void tambah(int a[100][100], int b[100][100], int sum[100][100], int ab, int ak, int bb, int bk) {
    for(int i = 0; i < ab; i++) {
        for(int j = 0; j < ak; j++) {
            sum[i][j] = a[i][j] + b[i][j];           
        };
    };

    std::cout << std::endl;
};

void kurang(int a[100][100], int b[100][100], int sum[100][100], int ab, int ak, int bb, int bk) {    
    for(int i = 0; i < ab; i++) {
        for(int j = 0; j < ak; j++) {
            sum[i][j] = a[i][j] - b[i][j];           
        };
    };

    std::cout << std::endl;
};

void kali(int a[100][100], int b[100][100], int sum[100][100], int ab, int ak, int bb, int bk) {    
    for(int i = 0; i < ab; i++) {
        for(int j = 0; j < bk; j++) {
            for(int k = 0; k < ak; k++) {
                sum[i][j] += a[i][k] * b[k][j];
            } 
        }
    }

    std::cout << std::endl;
};

int main() {
    matriks A, B, res; // res result
    int a[100][100], b[100][100], sum[100][100];

    std::cout << "baris, kolom a :\n";
    std::cin >> A.baris >> A.kolom;

    std::cout << "baris, kolom b :\n";
    std::cin >> B.baris >> B.kolom;
   
    system("clear");

    int menu;
    std::cout << "operasi\n1. Tambah\n2. Kurang\n3. Kali\n"; 
    std::cin >> menu;

    switch(menu) {
        case 1:
            if(!bisaDitambahKurang(A.baris, A.kolom, B.baris, B.kolom)) {
                std::cout << "tidak dapat dilakukan operasi tambah maupun kurang\n";
                return 0;
            }

            system("clear");

            res.baris = A.baris;
            res.kolom = A.kolom;

            input(a, b, A.baris, A.kolom, B.baris, B.kolom);
            tambah(a, b, sum, A.baris, A.kolom, B.baris, B.kolom);
            output(sum, res.baris, res.kolom);

            break;
        case 2: 
            if(!bisaDitambahKurang(A.baris, A.kolom, B.baris, B.kolom)) {
                return 0;
            };

            system("clear");

            res.baris = A.baris;
            res.kolom = A.kolom;

            input(a, b, A.baris, A.kolom, B.baris, B.kolom);
            kurang(a, b, sum, A.baris, A.kolom, B.baris, B.kolom);
            output(sum, res.baris, res.kolom);

            break;
        case 3:
            if(!bisaDikali(A.kolom, B.baris)) {
                std::cout << "tidak dapat dilakukan operasi perkalian\n";
                return 0;
            };

            system("clear");
            
            res.baris = A.baris;
            res.kolom = B.kolom;

            input(a, b, A.baris, A.kolom, B.baris, B.kolom);
            kali(a, b, sum, A.baris, A.kolom, B.baris, B.kolom);
            output(sum, res.baris, res.kolom);

            break;
        default:
            std::cout << "pilih yg ada aja bang";
            return 0;
    };

    return 0;
}
