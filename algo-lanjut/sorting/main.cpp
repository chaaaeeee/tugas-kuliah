#include <iostream>

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
};

int main() {
   int n = 5;
   int arr[5] = {80, 10, 30, 90, 40}; 
   int lowest;
   lowest = arr[0];

   for(int i = 0; i < n; i++) {
       for(int j = 0; j < n; j++) {
           if(arr[j] < lowest){
               lowest = arr[j];
           } 
       }
       swap(lowest, arr[0]);
   }

   for(int k = 0; k < n; k++) {
       std::cout << arr[k];
   }

   return 0;
}
