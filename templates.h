#include <iostream>
#include <map>  
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
/*!
    \brief
    * a user-friendly key and value template
*/
template <class T>
class MAP {
public:
    map<std::string,std::string> getMap(){
        return m;
    }
    void add(std::string key,std::string value){
        getMap().insert(pair<std::string,std::string>(key,value));
    }
    void delete_m(std::string key){
        getMap().erase(key);
    }
    void clear(){
        getMap().clear();
    }
    std::string get(std::string key){
        auto value = getMap().find(key);
        return value;
    }
    int getSize(){
        return getMap().size();
    }
private:
    map<std::string, std::string> m;
};
template<typename T>
class ALGORITHM{
public:
    void Fill(vector<T> vect, T value){
        fill(vect.begin(),vect.end(), value);
    }
    void forEach(vector<T> vect, T func){
        for_each(vect.begin(),vect.end(),func);
    }
    bool search(vector<T> vect, T value){
        return binary_search(vect.begin(),vect.end(), value);
    }
    bool Find(vector<T> vect, T value){
        auto result = find(vect.begin(), vect.end(), value);
        if (result != end(vect)){
            return true;
        }
        else{
            return false;
        }
    }
    bool Find_if(vector<T> vect, bool func){
        auto it = find_if(vect.begin(), vect.end(), func);
        if (it != end(vect)){
            return true;
        }
        else{
            return false;
        }
    }
    bool Includes(vector<T> set1, vector<T> set2, bool func){
        bool result = includes(set1.begin(), set1.end(), set2.begin(), set2.end(), func);
        if (result == true){
           return true;
        }
        else{
            return false;
        }
    }
    bool Is_Sorted(vector<T> vect){
        return is_sorted(vect.begin(),vect.end());
    }
    int Count(vector<T> vect, T value){
        return count(vect.begin(), vect.end(), value);
    }
    int Count_if(vector<T> vect, T value, bool func){
        return count_if(vect, value, func);
    }
};
class templates{
    public:
    // math templates
    template <typename T> T getMax(T x, T y)
    {
        return (x > y) ? x : y;
    }
};