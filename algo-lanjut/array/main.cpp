#include <iostream>

int main() {
    int arr[3][2][2] = 
    {
        {
            {1, 2},
            {3, 4}
        },
        {
            {5, 6},
            {7, 8}
        },
        {
            {9, 10},
            {11, 12}
        }
    };

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            std::cout << "|";
            for(int k = 0; k < 2; k++) {
                std::cout << " " <<  arr[i][j][k] << " ";
            }
            std::cout << "|";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
