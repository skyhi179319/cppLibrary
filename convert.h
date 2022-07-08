#include <iostream>
/*!
     \brief
     * conversion functions class
*/
class convert {
    /*!
     \p
     * makes string to int
    */
    public:
        int stringToInt(std::string value){
            int num = std::stoi(value);
            return num;
        }
};
