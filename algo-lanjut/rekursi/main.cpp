#include <iostream>

void rekursif(int n) {
    std::cout << "recursion has to be self centered cuz why are you calling yourself" << std::endl;    
    rekursif(n);
}

int faktorial(int x) {
    if(x <= 1) {
        return x;
    } else {
        return x * faktorial(x-1);
    }
}

int fib(int n, int first, int second) {
  if (n <= 1) {
      return n;
  } else {
    return fib(n - 1, second, fib(n - 2, first, second) + second);
  }
}

int fibonacci(int x) {
    if(x <= 1) {
        return x;
    }
    else {
        return fibonacci(x-1) + fibonacci(x-2);
    }
}
int main() {
    int x, y, z; // limit
    std::cout << "deret brp :"; std::cin >> x;
    std::cout << fibonacci(x);
}
