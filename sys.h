#include <iostream>
#include "math.h"
#include "input.h"
#include "convert.h"
#include "file.h"
#include <stdlib.h>
#include "JSON.h"
#include "security.h"
#include "run.h"
/*!
     \brief
     * System class
     \note
     * Has each file need to run the whole library
 */
class sys {
  public:
    // imports all header class
    math math;
    input input;
    convert convert;
    file file;
    run run;
    /*!
     \brief
     * data structure
     \note
     * has the libraries for data processing
    */
    struct{
        JSON JSON;
    }data;
    /*!
     \p
     * security class
    */
    security security;
    // console methods
    /*!
     \p
     * log values
    */
    void log(std::string x){
        std::cout << x;
        std::cout << "\n";
    }
    /*!
     \p
     * log values
    */
    void log(int x){
      std::cout << x;
      std::cout << "\n";
    }
    // array
    /*!
     \p
     * prints array
    */
    void printArray(std::string arr[]){
        for (int i = 0; i < 4; i++) {
            std::cout << arr[i] << "\n";
        }
    }
    // create line for console
    /*!
     \p
     * creates a line in the terminal
    */
    void createLine(int x){
        std::string line;
        for (int i = 0; i < x; i++) {
            line.append("-");
        }
        std::cout << line;
        std::cout << "\n";
    }
};