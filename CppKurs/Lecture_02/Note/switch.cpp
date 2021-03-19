#include <iostream>
#include <map>

#include<iomanip>
#include<sstream>

int main(){

    enum class RGB { RED, GREEN, BLUE };
    RGB color = RGB::GREEN;

    switch (color){
        case RGB::RED:      std::cout << "red\n"; break;
        case RGB::GREEN:    std::cout << "green\n"; break;
        case RGB::BLUE:     std::cout << "blue\n"; break;
    }

    // Pythonic iteration over dict:
    std::map <char, int> my_dict{{'a', 1}, {'b', 2}};
    for (const auto& [key, value] : my_dict){
        std::cout << key << " has value " << value << std::endl;
    }


    // Split strings:
    std::stringstream filename{"0025.txt"};

    int number = 0;
    std::string extension;

    filename >> number >> extension;

    std::cout << "Number, extension: " << number << " , " << extension << std::endl;

    return 0;
}