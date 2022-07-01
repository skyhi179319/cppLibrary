#include <iostream>
class convert {
    public:
        int stringToInt(std::string value){
            int num = std::stoi(value);
            return num;
        }
};
