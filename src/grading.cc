#include <iostream>

int main () {
    int a, b, c;
    std::cin>>a;
    std::cin>>b;
    std::cin>>c;

    int ttl = a + b + c;

    if (ttl >= 80){
        std::cout<<"A";
    }
    else if (ttl >= 75) {
        std::cout<<"B+";
    }
    else if (ttl >= 70) {
        std::cout<<"B";
    }
    else if (ttl >= 65) {
        std::cout<<"C+";
    }
    else if (ttl >= 60) {
        std::cout<<"C";
    }
    else if (ttl >= 55) {
        std::cout<<"D+";
    }
    else if (ttl >= 50) {
        std::cout<<"D";
    }
    else {
        std::cout<<"F";
    }

    return 0;
}