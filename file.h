#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
/*!
     \brief
     * file class
     \class
     \code
     creates and deletes files
     makes sure a file and directory exists
     creates a directory
     \endcode
*/
class file {
public:
    // Files
    /*!
     \p
     * creates a file
    */
    void createFile(std::string file,std::string text){
        std::ofstream MyFile(file);

        // Write to the file
        MyFile << text;

        // Close the file
        MyFile.close();
    }
    /*!
     \p
     * reads a file
     \return
     * returns the file's text
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
    /*!
     \p
     * checks if the file exist
    */
    bool exist(const char *filename){
        std::ifstream file(filename);
        return (bool)file;
    }
    /*!
     \p
     * deletes the file
    */
    void deleteFile(const char *filename){
        remove(filename);
    }
    // Directory functions
    /*!
     \p
     * makes the directory
    */
    void mkDir(char dir[100]){
        // Creating a directory
        if (mkdir(dir, 0777) == -1){

        }
        else{

        }

    }
    /*!
     \p
     * checks if directory exist
    */
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