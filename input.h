#include <iostream>
#include "config.h"
class input {
    public:
    void input_text(std::string text){
        std::cout << text;
        std::cout << "\n";
    }
    std::string user_input(std::string input){
        std::cin >> input;
        return before_user_input + input;
    }
    std::string user_input(std::string before, std::string input){
        std::cin >> input;
        return before + input;
    }
};
