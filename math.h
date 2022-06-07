#include <iostream>
#include <time.h>
#include <stdlib.h>
class math {       
  public:
    int add(int x,int y){
        return x + y;
    }
    int multiply(int x, int y){
      return x * y;
    }
    int subtract(int x,int y){
      return x - y;
    }
    int divide(int x,int y){
      return x / y;
    }
    int random(int high,int low){
        srand(time(0));
        return rand() % high + low;
    }
};