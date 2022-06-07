#include <iostream>
#include <fstream>
// RAPIDJSON lib
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include "rapidjson/reader.h"
#include "rapidjson/filereadstream.h"
using namespace rapidjson;
using namespace std;
class JSON {
public:
    // gets JSON String
    std::string getDocument(std::string File){
        ifstream ifs(File);
        rapidjson::IStreamWrapper isw(ifs);
        rapidjson::Document doc;
        doc.ParseStream(isw);
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<StringBuffer> writer(buffer);
        doc.Accept(writer);
        return buffer.GetString();
    }
    // gets JSON object and puts it in a string
    std::string getStringValue(std::string file,char v[100]){
        return queryString(file,v);
    }
    // gets JSON object and puts it in an int
    int getIntValue(std::string file,char v[100]){
        return queryInt(file,v);
    }
    // gets JSON by an int
    std::string get(std::string file, char pointer1[100], int pointer2){
        return query(file,pointer1)[pointer2].GetString();
    }
private:
    // returns array from JSON
    rapidjson::GenericValue<rapidjson::UTF8<> >::Array query(std::string file, char v[100]){
        ifstream ifs(file);
        rapidjson::IStreamWrapper isw(ifs);
        rapidjson::Document doc;
        doc.ParseStream(isw);
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<StringBuffer> writer(buffer);
        doc.Accept(writer);
        assert(doc.HasMember(v));
        assert(doc[v].IsArray());
        return doc[v].GetArray();
    }
    // returns a single attribute
    std::string queryString(std::string file, char v[100]){
        ifstream ifs(file);
        rapidjson::IStreamWrapper isw(ifs);
        rapidjson::Document doc;
        doc.ParseStream(isw);
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<StringBuffer> writer(buffer);
        doc.Accept(writer);
        assert(doc.HasMember(v));
        assert(doc[v].IsString());
        return doc[v].GetString();
    }
    // returns a single attribute
    int queryInt(std::string file, char v[100]){
        ifstream ifs(file);
        rapidjson::IStreamWrapper isw(ifs);
        rapidjson::Document doc;
        doc.ParseStream(isw);
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<StringBuffer> writer(buffer);
        doc.Accept(writer);
        assert(doc.HasMember(v));
        assert(doc[v].IsInt());
        return doc[v].GetInt();
    }

};
// Creates and Reads JSON Files
class JSON_CREATOR {
public:
    std::string File;
    std::string text = "";
    JSON_CREATOR(std::string file){
        File = file;
    }
    // must start document
    void start_Document(){
        text.append(start());
    }
    /*
     * adding comma to text
     * must add after each entry
     */
    void addComma(){
        text.append(",");
    }
    // creates single attribute
    void createAttribute(std::string key, std::string value){
        std::string j = quote() + key + quote() + ":" + quote() + value + quote();
        text.append(j);
    }
    // creates array attribute
    void createArrayAttribute(std::string key,std::string values[]){
        std::string start =  quote() + key + quote() + ":" + array_Before();
        // creates middle
        std::string middle = "";
        for (int i = 0; i < values->length(); i++) {
            std::string x = quote() + values[i] + quote();
            middle.append(x + ",");
        }
        middle.erase(std::prev(middle.end()));
        std::string end = array_After();
        // creating actual string
        std::string v = start + middle + end;
        text.append(v);
    }
    // must end document
    void end_Document(){
        text.append(end());
    }
    // Gets Filename
    std::string getFilename(){
        return File;
    }
    // saves file
    void save(){
        std::ofstream MyFile(File);

        // Write to the file
        MyFile << text;

        // Close the file
        MyFile.close();
    }
    // gets document string
    std::string getText(){
        return text;
    }
    /*
     * All functions below are return values from the JSON class
     * Mainly to use as a JSON object and to simplify the user use
     * Also able to use after creating document
     */
    // gets doc
    std::string getDoc(){
        return JSON.getDocument(File);
    }
    // get string value
    std::string getString(char value[100]){
        return JSON.getStringValue(File,value);
    }
    // gets int value
    int getInt(char value[100]){
        return JSON.getIntValue(File,value);
    }
    // get function from JSON
    std::string get(char value[100],int value2){
        return JSON.get(File,value,value2);
    }
private:
    // creating start of JSON Document
    std::string start() {
        return "{";
    }
    // creating end of JSON Document
    std::string end() {
        return "}";
    }
    // return parts of array for JSON
    std::string array_Before() {
        return "[";
    }
    std::string array_After() {
        return "]";
    }
    // returns quotes mark
    std::string quote() {
        return "\"";
    }
    // JSON Class
    JSON JSON;
};