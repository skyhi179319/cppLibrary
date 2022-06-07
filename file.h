#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
class file {
public:
    // Files
    void createFile(std::string file,std::string text){
        std::ofstream MyFile(file);

        // Write to the file
        MyFile << text;

        // Close the file
        MyFile.close();
    }
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
    bool exist(const char *filename){
        std::ifstream file(filename);
        return (bool)file;
    }
    void deleteFile(const char *filename){
        remove(filename);
    }
    // Directory functions
    void mkDir(char dir[100]){
        // Creating a directory
        if (mkdir(dir, 0777) == -1){

        }
        else{

        }

    }
    bool dirExist(const std::string &s)
    {
        struct stat buffer;
        if((stat (s.c_str(), &buffer) == 0) == 1){
            return true;
        } else{
            return false;
        }
    }
};