#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cmath>
/*!
     \brief
     * Random class
     \note
     * Has more functions than just the one
 */
class Random{
public:
    /*!
     \p
     * starts the random function properly
    */
    void start(){
        std::srand(time(0));
    }
    /*!
     \p
     * generates a random number from the low and high numbers
    */
    int random(int high,int low){
        return rand() % high + low;
    }
    /*!
     \p
     * returns the random number as a string
    */
    std::string toString(int high,int low){
        return std::to_string(random(high,low));
    }
};
/*!
     \brief
     * math function class
*/
class math {       
  public:
    /*
     * random class
     * made with more functions instead of just one
     */
    /*!
     \p
     * has the Random class
    */
    Random random_c;
    // custom math functions
    /*!
     \p
     * adds two numbers
    */
    int add(int x,int y){
        return x + y;
    }
    /*!
     \p
     * multiplies two numbers
    */
    int multiply(int x, int y){
      return x * y;
    }
    /*!
     \p
     * subtracts two numbers
    */
    int subtract(int x,int y){
      return x - y;
    }
    /*!
     \p
     * divides two numbers
     \note
     * may return 0 because theres no exception clause
    */
    int divide(int x,int y){
      return x / y;
    }
    /*!
     \p
     * generates random number
     \also
     * uses the Random class as of July 8th, 2022
    */
    int random(int high,int low){
        random_c.start();
        return random_c.random(high,low);
    }
    // actual math functions
    /*!
     \p
     * returns sin
    */
    int sin_m(int x){
        return sin(x);
    }
    /*!
     \p
     * returns power
    */
    int power(float x, float y){
        return pow(x,y);
    }
    /*!
     \p
     * returns tan
    */
    int tan_m(int x){
        return tan(x);
    }
    /*!
     \p
     * returns floor
    */
    int floor_m(int x){
        return floor(x);
    }
    /*!
     \p
     * returns cos
    */
    int cos_m(int x){
        return cos(x);
    }
    /*!
     \p
     * returns ceil
    */
    int ceil_m(int x){
        return ceil(x);
    }
    /*!
     \p
     * returns abs
    */
    int abs_m(float x){
        return abs(x);
    }
    /*!
     \p
     * returns rounded number
    */
    int round_m(float x){
        return round(x);
    }
    /*!
     \p
     * returns log
    */
    int log_m(float x){
        return log(x);
    }
    /*!
     \p
     * returns square root
    */
    int sqRoot(float x){
        return sqrt(x);
    }
    /*!
     \p
     * returns max
    */
    int max_m(int x, int y){
        return fmax(x,y);
    }
    /*!
     \p
     * returns min
    */
    int min_m(int x, int y){
        return fmin(x,y);
    }
};