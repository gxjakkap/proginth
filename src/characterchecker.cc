#include <iostream>
#include <string>

int main() {
    std::string s;
    bool allSmall = true;
    bool allCaps = true;
    std::cin>>s;
    for(int i = 0; i<s.length(); i++){
        if (isupper(s[i])){
            allSmall = false;
        }
        if (islower(s[i])){
            allCaps = false;
        }
        if (!allSmall && !allCaps){
            break;
        }
    }
    if (allCaps){
        std::cout<<"All Capital Letter";
    }
    else if (allSmall){
        std::cout<<"All Small Letter";
    }
    else {
        std::cout<<"Mix";
    }
    return 0;
}