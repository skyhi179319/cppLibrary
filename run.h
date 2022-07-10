#include <iostream>
#include <fstream>
using namespace std;
/*!
 \brief
 * the run class can run and create command scripts within the program
 */
class run{
public:
    /*!
     \brief
     the bash class has the functions to run and create bash scripts within the program
     */
    class bash{
    public:
        /*!
         \brief
         * the file class contains functions to create and delete bash files
         \attention
         * must save file with the save function
         */
        class File{
        public:
            /*!
             \p
             * begins bash program
             */
            void start(){
                text.append("#!/bin/bash");
                this->newLine();
            }
            /*!
             \p
             * creates a new line in the document
             */
            void newLine(){
                text.append("\n");
            }
            /*!
             * creates a echo statement in the document
             */
            void echo(std::string x){
                char c[100] =  "\"";
                std::string s;
                s = c;
                text.append("echo " + s + x + s);
            }
            /*!
             \p
             * creates curl command with the option of -o in the document
             */
            void curl(std::string link){
                text.append("curl -o " + link);
            }
            /*!
             *\p creates command in the document
             */
            void command(std::string command){
                text.append(command);
            }
            /*!
             \p
             * saves bash file
             */
            void save(std::string filename){
                std::ofstream MyFile(filename);

                // Write to the file
                MyFile << text;

                // Close the file
                MyFile.close();
                std::string c = "chmod +x ./" +filename;
                char arr[c.length() + 1];
                for (int x = 0; x < sizeof(arr); x++) {
                    arr[x] = c[x];
                }
                const char* ch = arr;
                std::system(ch);
            }
        private:
            std::string text;
        };
        /*!
         \brief
         the run class has the function to run the script
         */
        class Run{
        public:
            /*!
                \p
                * runs the bash script
                \note
                * must add ./ to locate file properly
             */
            void run(char file[100]){
                const char * f = file;
                std::system(f);
            }
        };
        /*!
         \brief
         * the file class contains functions to create and delete bash files
         \attention
         * must save file with the save function
         */
        File File;
        /*!
         \brief
         the run class has the function to run the script
         */
        Run Run;
    };
    /*!
     \brief
     *the bash class has the functions to run and create bash scripts within the program
     */
    bash bash;
};