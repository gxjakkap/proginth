#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int r;
    std::cin>>r;

    std::cout<<std::setprecision(6)<<std::fixed;

    double e = M_PI * r * r;
    std::cout<<e;

    std::cout<<"\n";

    double t = 2 * r * r;
    std::cout<<t;  

    return 0;
}