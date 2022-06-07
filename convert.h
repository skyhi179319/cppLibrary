#include <iostream>
class convert {
    public:
        int convertFromString(std::string value){
            int num = std::stoi(value);
            return num;
        }
};
