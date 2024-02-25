#include <iostream>

int main() {
    int n;
    int data[100] = {};

    std::cout << "berapa : ";
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        std::cout << "ke " << i+1 << std::endl;
        std::cin >> data[i];
    };

    for(int i = 0; i < n; i++) {
        std::cout << "i adalah : " <<  i << std::endl;
        for(int j = 0 + n; j < 0; j--) {
            std::cout << "j adalah : " << j << std::endl;
        };

    };

    return 0;
}
