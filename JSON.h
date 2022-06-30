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
        //assert(document["parameterB"][0]["status"].GetBool() == true);
        return query(file,pointer1)[pointer2].GetString();
    }
    std::string getObj(std::string file, char pointer1[100], char pointer2[100],int pointer){
        return Obj(file, pointer1,pointer2,pointer);
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
    std::string Obj(std::string file,char v[100], char value1[100], int pointer){
        ifstream ifs(file);
        rapidjson::IStreamWrapper isw(ifs);
        rapidjson::Document doc;
        doc.ParseStream(isw);
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<StringBuffer> writer(buffer);
        std::string v1;
        if(doc.IsObject()) {
            if (doc.HasMember(v)) {
                const rapidjson::Value &a = doc[v];  // you are missing this
                assert(a.IsArray());
                const rapidjson::Value &atomicObject = a[pointer];

                if (atomicObject.HasMember(value1)) {
                    const rapidjson::Value &name = atomicObject[value1];
                    v1 = name.GetString();
                }
            }
        }
        return v1;
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
// nested class
class nested{
public:
    int v;
    std::string n1;
    std::string n2;
    std::string n3;
    std::string n4;
    std::string n5;
    nested(std::string name1){
        n1 = name1;
        v = 1;
    }
    nested(std::string name1,std::string name2){
        n1 = name1;
        n2 = name2;
        v = 2;
    }
    nested(std::string name1,std::string name2,std::string name3){
        n1 = name1;
        n2 = name2;
        n3 = name3;
        v = 3;
    }
    nested(std::string name1,std::string name2,std::string name3,std::string name4){
        n1 = name1;
        n2 = name2;
        n3 = name3;
        n4 = name4;
        v = 4;
    }
    nested(std::string name1,std::string name2,std::string name3,std::string name4,std::string name5){
        n1 = name1;
        n2 = name2;
        n3 = name3;
        n4 = name4;
        n5 = name5;
        v = 5;
    }
    std::string put(std::string value1){
        return "\"" + n1 + "\"" + ":" + "\"" + value1 + "\"";
    }
    std::string put(std::string value1, std::string value2){
        return "\"" + n1 + "\"" + ":" + "\"" + value1 + "\"" + "," + "\"" + n2 + "\"" + ":" + "\"" + value2 + "\"";
    }
    std::string put(std::string value1, std::string value2,std::string value3){
        return "\"" + n1 + "\"" + ":" + "\"" + value1 + "\"" + "," + "\"" + n2 + "\"" + ":" + "\"" + value2 + "\"" +  ","
        + "\"" + n3 + "\"" + ":" + "\"" + value3 + "\"";
    }
    std::string put(std::string value1, std::string value2,std::string value3,std::string value4){
        return "\"" + n1 + "\"" + ":" + "\"" + value1 + "\"" + "," + "\"" + n2 + "\"" + ":" + "\"" + value2 + "\"" +  ","
               + "\"" + n3 + "\"" + ":" + "\"" + value3 + "\"" +  "," + "\"" + n4 + "\"" + ":" + "\"" + value4 + "\"";
    }
    std::string put(std::string value1, std::string value2,std::string value3,std::string value4,std::string value5){
        return "\"" + n1 + "\"" + ":" + "\"" + value1 + "\"" + "," + "\"" + n2 + "\"" + ":" + "\"" + value2 + "\"" +  ","
               + "\"" + n3 + "\"" + ":" + "\"" + value3 + "\"" +  "," + "\"" + n4 + "\"" + ":" + "\"" + value4 + "\"" +
               "," + "\"" + n5 + "\"" + ":" + "\"" + value5 + "\"";
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
    // return single attribute as string
    std::string createAttributeString(std::string key, std::string value){
        std::string j = quote() + key + quote() + ":" + quote() + value + quote();
        return j;
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
    // start nested objects
    void startNestedObj(){
        text.append(start());
    }
    // creates nested objects
    void createNestedObj(nested n, std::string value1){
        text.append(n.put(value1));
    }
    void createNestedObj(nested n, std::string value1,std::string value2){
        text.append(n.put(value1,value2));
    }
    void createNestedObj(nested n, std::string value1,std::string value2,std::string value3){
        text.append(n.put(value1,value2,value3));
    }
    void createNestedObj(nested n, std::string value1,std::string value2,std::string value3,std::string value4){
        text.append(n.put(value1,value2,value3,value4));
    }
    void createNestedObj(nested n, std::string value1,std::string value2,std::string value3,std::string value4,std::string value5){
        text.append(n.put(value1,value2,value3,value4,value5));
    }
    // get nested object
    std::string getObj(char v[100], char value[100], int pointer){
        return JSON.getObj(File,v,value,pointer);
    }
    // end nested objected
    void endNestedObj(){
        text.append(end());
    }
    // start and end nested object
    void startNested(std::string value){
        std::string t = start() + quote() + value + quote() + ":" + array_Before();
        text.append(t);
    }
    void endNested(){
        text.append(array_After() + end());
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
    void save() {
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