#include <iostream>
class security{
public:
    class Initialize{
        // creates a random number from bounds
        int newCode(int bounds){
            std::srand(time(0));
            return rand() % bounds;
        }
        // creates a random number from 0 to 1000
        int newCode(){
            std::srand(time(0));
            return rand() % 1000;
        }
    };
    // Initialize class
    Initialize inti;
    // verify Initialized code
    bool verify(int initializeCode,int input) {
        if (Equal(initializeCode,input)) {
            return true;
        } else {
            return false;
        }
    }
    // verifying username and password
    struct{
        std::string username;
        std::string password;
        /*
         * same function as in file.h
         * made mainly to read file for secure reasons
         * must be one line file
         */
        std::string readFile(std::string file){
            std::string myText;
            std::string returnText;
            std::ifstream MyReadFile(file);
            while (getline (MyReadFile, myText)) {
                returnText = myText;
            }
            MyReadFile.close();
            return returnText;
        }
    }info;
    // manually putting the info into one function
    bool verify(std::string user,std::string userAtt, std::string pass, std::string passAtt){
        if(Equal(user,userAtt) && Equal(pass,passAtt)){
            return true;
        } else{
            return false;
        }
    }
    // using the structure to find the info
    bool verify(std::string userAtt, std::string passAtt){
        if(Equal(info.username,userAtt) && Equal(info.password,passAtt)){
            return true;
        } else{
            return false;
        }
    }
private:
    // Equal function for values
    bool Equal(std::string value1, std::string value2){
        if(value1 == value2){
            return true;
        } else{
            return false;
        }
    }
    bool Equal(int value1, int value2){
        if(value1 == value2){
            return true;
        } else{
            return false;
        }
    }
};