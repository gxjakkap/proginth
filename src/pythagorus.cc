#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double a, b, c;
    std::cin>>a>>b;
    c = sqrt((a * a) + (b * b));
    std::cout<<std::setprecision(6)<<std::fixed<<c;
}