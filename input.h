#include <iostream>
#include "config.h"
/*!
     \brief
     * class for user input
     \input
     * uses void and string functions
*/
class input {
    public:
    /*!
     \p
     * prints text for input use
    */
    void input_text(std::string text){
        std::cout << text;
        std::cout << "\n";
    }
    /*!
     \p
     * has user input as a string
     \note
     * must have a empty string to connect function
     \return
     * user input
    */
    std::string user_input(std::string input){
        std::cin >> input;
        return before_user_input + input;
    }
    /*!
     \p
     * has user input as a string
     \note
     * must have a empty string to connect function
     \Also
     * has a before string to concat it before it returns as a string
     \return
     * user input
    */
    std::string user_input(std::string before, std::string input){
        std::cin >> input;
        return before + input;
    }
};
