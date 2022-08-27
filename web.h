#include <iostream>
#include <sstream>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
//#include <chrono>

using namespace std;
/*!
 \brief
 * configs for web server
*/
#define PORT 3000
class Script{
public:
    void addCustom(std::string code){
        javascript.append(code);
    }
    void newLine(){
        javascript.append("\n");
    }
    std::string returnScript(){
        return javascript;
    }
private:
    std::string javascript;
};
/*!
     \brief
     * stylesheet functions
*/
class Stylesheet{
public:
    /*!
     \brief
     * adds the selector to the stylesheet
    */
    void startStyle(std::string property){
        css.append(property + start());
    }
    /*!
     \brief
     * ends the style in the stylesheet
    */
    void endStyle(){
        css.append(end());
    }
    /*!
     \brief
     * adds a property to a selector to the stylesheet
    */
    void addStyle(std::string type, std::string value){
        css.append(type + colon() + value + semicolon());
    }
    /*!
     \brief
     * creates a new line in the stylesheet
    */
    void newLine(){
        css.append("\n");
    }
    /*!
     \brief
     * returns the css with a style tag
    */
    std::string returnCSS(){
        return "<style>" + css + "</style>";
    }
private:
    std::string css;
    std::string semicolon() {
        return ";";
    }
    std::string colon() {
        return ":";
    }
    std::string start() {
        return "{";
    }
    std::string end() {
        return "}";
    }
};
/*!
     \brief
     * web functions class
*/
class web{
public:
    /*!
     \brief
     * elements class for certain elemnts
    */
    class elements{
    public:
        /*!
         \brief
         * starts a div element
        */
        std::string startDiv(){
            return "<div>";
        }
        /*!
         \brief
         * starts a div element
        */
        std::string startDiv(std::string property, std::string propertyValue){
            return "<div " + property + "=" + quote() + propertyValue + quote() + ">" + "\n";
        }
        /*!
         \brief
         * ends the div element
        */
        std::string endDiv(){
            return "</div>";
        }
        /*!
         \brief
         * adds a paragraph element
        */
        std::string p(std::string text){
            return "<p>" + text + "</p>";
        }
        /*!
         \brief
         * adds a paragraph element with only one property
        */
        std::string p(std::string text, std::string property, std::string propertyValue){
            return "<p " + property + "=" + quote() + propertyValue + quote() + ">" + text + "</p>";
        }
        /*!
         \brief
         * adds a h1 element
        */
        std::string h1(std::string text){
            return "<h1>" + text + "</h1>";
        }
        /*!
         \brief
         * adds a h1 element with only one property
        */
        std::string h1(std::string text, std::string property, std::string propertyValue){
            return "<h1 " + property + "=" + quote() + propertyValue + quote() + ">" + text + "</h1>";
        }
        /*!
         \brief
         * adds a h2 element
        */
        std::string h2(std::string text){
            return "<h2>" + text + "</h2>";
        }
        /*!
         \brief
         * adds a h2 element with only one property
        */
        std::string h2(std::string text, std::string property, std::string propertyValue){
            return "<h2 " + property + "=" + quote() + propertyValue + quote() + ">" + text + "</h2>";
        }
        /*!
         \brief
         * adds a h3 element
        */
        std::string h3(std::string text){
            return "<h3>" + text + "</h3>";
        }
        /*!
         \brief
         * adds a h3 element with only one property
        */
        std::string h3(std::string text, std::string property, std::string propertyValue){
            return "<h3 " + property + "=" + quote() + propertyValue + quote() + ">" + text + "</h3>";
        }
        /*!
         \brief
         * adds a h4 element
        */
        std::string h4(std::string text){
            return "<h4>" + text + "</h4>";
        }
        /*!
         \brief
         * adds a h4 element with only one property
        */
        std::string h4(std::string text, std::string property, std::string propertyValue){
            return "<h4 " + property + "=" + quote() + propertyValue + quote() + ">" + text + "</h4>";
        }
        /*!
         \brief
         * adds a img element with
         @param path
         * path of file
         @param w
         * width of image
         @param h
         * height of image
        */
        std::string img(std::string path, std::string w, std::string h){
            return "<img src=" + quote() + path + quote() + " width=" + quote() + w + quote() +
                   " height=" + quote() + h + quote() + ">";
        }
        /*!
         \brief
         * starts a table element
        */
        std::string startTable(){
            return "<table>";
        }
        /*!
         \brief
         * ends the table element
        */
        std::string endTable(){
            return "</table>";
        }
        /*!
         \brief
         * starts a tr element
        */
        std::string startRow(){
            return "<tr>";
        }
        /*!
         \brief
         * ends a tr element
        */
        std::string endRow(){
            return "</tr>";
        }
        /*!
         \brief
         * adds a th element
        */
        std::string addTableHeader(std::string value){
            return addSelector("th",value);
        }
        /*!
         \brief
         * adds a td element
        */
        std::string addTableData(std::string value){
            return addSelector("td",value);
        }
    private:
        std::string quote() {
            return "\"";
        }
        std::string addSelector(std::string selector, std::string value){
            return "<" + selector +">" + value + "</" + selector + ">";
        }
    };
    /*!
     \brief
     * has functions to create web pages with no server
    */
    class noServer{
    public:
        /*!
         \brief
         * starts html document
        */
        void start_document(){
            html.append("<!DOCTYPE html>");
            html.append("\n");
            html.append("<html>");
        }
        /*!
         \brief
         * ends html doucment
        */
        void end_document(){
            html.append("</html>");
        }
        /*!
         \brief
         * starts head of html document
        */
        void start_head(){
            html.append("<head>");
            html.append("\n");
        }
        /*!
         \brief
         * ends head of html document
        */
        void end_head(){
            html.append("</head>");
        }
        /*!
         \brief
         * adds stylesheet to html document
        */
        void addStylesheet(std::string path){
            html.append("<link rel=" + quote() + "stylesheet" + quote() + " href=" + quote() +
                        path + quote());
            html.append("\n");
        }
        /*!
         \brief
         * applies custom style with actual css without to the document
        */
        void applyStylesheet(Stylesheet style){
            std::string s = style.returnCSS();
            html.append(s);
        }
        /*!
         \brief
         * adds script to the html document
        */
        void addScript(std::string path){
            html.append("<script src=" + quote() + path + quote() + "></script>");
            html.append("\n");
        }
        void applyScript(Script script){
            html.append("<script>");
            html.append("\n");
            html.append(script.returnScript());
            html.append("\n");
            html.append("</script>");
        }
        /*!
         \brief
         * starts the body of the html document
        */
        void start_body(){
            html.append("<body>");
            html.append("\n");
        }
        /*!
         \brief
         * ends the body of the html document
        */
        void end_body(){
            html.append("</body>");
            html.append("\n");
        }
        /*!
         \brief
         * adds a selector to the html document
        */
        void addSelector(std::string selector){
            html.append("<" + selector +">" + "</" + selector + ">");
        }
        /*!
         \brief
         * adds a selector to the html document
        */
        void addSelector(std::string selector, std::string value){
            html.append("<" + selector +">" + value + "</" + selector + ">");
        }
        /*!
         \brief
         * adds a selector to the html document
        */
        void addSelector(std::string selector, std::string property, std::string propertyValue,
                         std::string value){
            html.append("<" + selector + " " + property + "=" + quote() + propertyValue + quote()
                        + ">" + value + "</" + selector + ">");
        }
        /*!
         \brief
         * elements class to add certain elements to the html document
        */
        elements elements;
        /*!
         \brief
         * adds element from the elements class
         \note
         * must use a string from the elements class to use this function
        */
        void addElement(std::string element){
            html.append(element);
        }
        std::string returnHTML(){
            return html;
        }
    private:
        std::string html;
        // returns quotes mark
        std::string quote() {
            return "\"";
        }
    };
    /*!
     \brief
     * has functions to create web pages with server
    */
    class server{
    public:
        /*!
         \brief
         * html class
        */
        class HTML{
        public:
            /*!
             \brief
             * starts html document
            */
            void start_document(){
                html.append("<!DOCTYPE html>");
                html.append("\n");
                html.append("<html>");
            }
            /*!
             \brief
             * ends html doucment
            */
            void end_document(){
                html.append("</html>");
            }
            /*!
             \brief
             * starts head of html document
            */
            void start_head(){
                html.append("<head>");
                html.append("\n");
            }
            /*!
             \brief
             * ends head of html document
            */
            void end_head(){
                html.append("</head>");
            }
            /*!
             \brief
             * adds stylesheet to html document
            */
            void addStylesheet(std::string path){
                html.append("<link rel=" + quote() + "stylesheet" + quote() + " href=" + quote() +
                            path + quote());
                html.append("\n");
            }
            /*!
             \brief
             * applies custom style with actual css without to the document
            */
            void applyStylesheet(Stylesheet style){
                std::string s = style.returnCSS();
                html.append(s);
            }
            /*!
             \brief
             * adds script to the html document
            */
            void addScript(std::string path){
                html.append("<script src=" + quote() + path + quote() + "></script>");
                html.append("\n");
            }
            void applyScript(Script script){
                html.append("<script>");
                html.append("\n");
                html.append(script.returnScript());
                html.append("\n");
                html.append("</script>");
            }
            /*!
             \brief
             * starts the body of the html document
            */
            void start_body(){
                html.append("<body>");
                html.append("\n");
            }
            /*!
             \brief
             * ends the body of the html document
            */
            void end_body(){
                html.append("</body>");
                html.append("\n");
            }
            /*!
             \brief
             * adds a selector to the html document
            */
            void addSelector(std::string selector){
                html.append("<" + selector +">" + "</" + selector + ">");
            }
            /*!
             \brief
             * adds a selector to the html document
            */
            void addSelector(std::string selector, std::string value){
                html.append("<" + selector +">" + value + "</" + selector + ">");
            }
            /*!
             \brief
             * adds a selector to the html document
            */
            void addSelector(std::string selector, std::string property, std::string propertyValue,
                             std::string value){
                html.append("<" + selector + " " + property + "=" + quote() + propertyValue + quote()
                            + ">" + value + "</" + selector + ">");
            }
            /*!
             \brief
             * elements class to add certain elements to the html document
            */
            elements elements;
            /*!
             \brief
             * adds element from the elements class
             \note
             * must use a string from the elements class to use this function
            */
            void addElement(std::string element){
                html.append(element);
            }
            std::string returnHTML(){
                return html;
            }
        private:
            std::string html;
            // returns quotes mark
            std::string quote() {
                return "\"";
            }
        };
        /*!
         \brief
         * sets the server
        */
        void set() {
            if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
                perror("In socket");
                exit(EXIT_FAILURE);
            }
            address.sin_family = AF_INET;
            address.sin_addr.s_addr = INADDR_ANY;
            address.sin_port = htons(PORT);
            memset(address.sin_zero, '\0', sizeof address.sin_zero);


            if (::bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
                perror("In bind");
                exit(EXIT_FAILURE);
            }
            if (listen(server_fd, 10) < 0) {
                perror("In listen");
                exit(EXIT_FAILURE);
            }
        }
        /*!
         \brief
         * runs the server
        */
        void run(char* message){
            while(1)
            {
                printf("\n+++++++ Waiting for new connection ++++++++\n\n");
                if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
                {
                    perror("In accept");
                    exit(EXIT_FAILURE);
                }
                char buffer[30000] = {0};
                valread = read( new_socket , buffer, 30000);
                printf("%s\n",buffer );
                write(new_socket , message , strlen(message));
                printf("------------------Server Event Sent-------------------\n");
                close(new_socket);
            }
        }
        /*!
         \brief
         * string to char
        */
        char* toChar(std::string c){
            return &c[0];
        }
        /*!
         \brief
         * HTML class
        */
        HTML HTML;
        /*!
         \brief
         * elements class
        */
        elements elements;
        /*!
         \brief
         * httpRequest class
        */
        class httpRequest{
        public:
            void setDir(std::string Dir){
                dir = Dir;
            }
            std::string GET(std::string f){
                if(dirExist(dir)){
                    std::string file = dir + f;
                    if(exist(file.c_str()) == true){
                        std::string str = readFile(file);
                        content = str;
                        return content;
                    }
                    else{
                        return content;
                    } 
                }
                else{
                    return "<h1>directory not found</h1>";
                }
            }
            std::string message_m(std::string c){
                std::ostringstream oss;
                oss << "HTTP/1.1 " << 200 << " OK\r\n";
                oss << "Cache-Control: no-cache, private\r\n";
                oss << "Content-Type: text/html\r\n";
                oss << "Content-Length: " << c.size() << "\r\n";
                oss << "\r\n";
                oss << c;
                return oss.str();
            }
            std::string getDir(){
                return dir;
            }
        private:
            std::string dir;
            std::string readFile(std::string file){
                std::ifstream MyReadFile(file);
                std::string str((std::istreambuf_iterator<char>(MyReadFile)), std::istreambuf_iterator<char>());
                return str;
            }
            bool exist(const char *filename){
                std::ifstream file(filename);
                return (bool)file;
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
            std::string content = "<h1>404 Not Found</h1>";
        };
        httpRequest httpRequest;
    private:
        int server_fd, new_socket; long valread;
        struct sockaddr_in address;
        int addrlen = sizeof(address);
    };
    /*!
     \brief
     * has functions to create web pages with no server
    */
    noServer noServer;
    /*!
    \brief
    * has functions to create web pages with server
    */
    server server;
};