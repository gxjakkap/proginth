#include <iostream>

int main () {
    int a, in;
    int min = 2000000000;
    int max = -2000000000;
    std::cin>>a;
    for (int i; i<a; i++){
        std::cin>>in;
        if (in > max){
            max = in;
        }
        if (in < min){
            min = in;
        }
    }
    std::cout<<min;
    std::cout<<"\n";
    std::cout<<max;

    return 0;
}