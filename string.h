#ifndef STRING_H
#define STRING_H

#include "string_global.h"
#include "unique_ptr.h"
#include "func.cpp"

class StringIterator
{
private:
    char* it;
public:
    StringIterator():it(nullptr){};
    StringIterator(char* _it):it(_it){};
    ~StringIterator(){};
    StringIterator& operator++(){
        ++it;
        return *this;
    }
    StringIterator operator++(int){
        StringIterator _it = *this;
        ++it;
        return _it;
    }
    StringIterator& operator--(){
        --it;
        return *this;
    }
    StringIterator operator--(int){
        StringIterator _it = *this;
        --it;
        return _it;
    }
    char& operator*() const{
        return *it;
    }
    char* operator->() const{
        return it;
    }
    bool operator==(const StringIterator& _it){
        return it==_it.it;
    }
    bool operator!=(const StringIterator& _it){
        return it!=_it.it;
    }
    StringIterator& operator=(const StringIterator& _it){
        it = _it.it;
        return *this;
    }
    StringIterator& begin();
    StringIterator& end();
};

class STRING_EXPORT String : public StringIterator
{
private:
    unique_ptr string;
    int size;
    int capacity;
public:
    String(){
        size=0;
        capacity=1;
        string = unique_ptr(new char[1]);
        *string.get()='\0';
    }
    String(const char* str){
        size = strlen(str);
        capacity = size+1;
        string = unique_ptr(new char[capacity]);
        strncpy(string.get(),str,capacity);
    }
    String(const String& str){
        size = str.size;
        capacity = str.capacity;
        string = unique_ptr(new char[capacity]);
        strncpy(string.get(), str.string.get(),capacity);
    }
    String(String&& str){
        string = std::move(str.string);
        size = str.size;
        capacity = str.capacity;
        str.size = 0;
        str.capacity = 0;
    }
    size_t get_size(){
        return strlen(string.get());
    }
    void reserve(int n){
        if(n>capacity){
            unique_ptr new_str(capacity);
            memcpy(new_str.get(), string.get(), size+1);
            string = std::move(new_str);
            capacity = n;
        }
    }
    void resize(int n){
        if(n>size){
            reserve(n);
            memset(string.get()+size,'\0',n-size);
        }
        size=n;
    }
    void resize(int n, char c){
        if(n>size){
            reserve(n);
            memset(string.get()+size,c,n-size);
        }
        size=n;
    }
    void clear();
    void push_back(char c);
    void append(int n, char c);
    void appeng(String str);
    void append(String str, int pos, int count);
    void erase(int pos);
    void erase(int pos, int count);
    void insert(int i, int n, char c);
    void insert(int i, String str);
    void insert(int i, String str, int pos, int count);
    String substr(int pos);
    String substr(int pos, int count);
    void replace(int pos, int count, int n, char c);
    void replace(int pos, int count, String str);
    void replace(int pos, int count, String str, int pos2, int count2);
    int find(String str, int pos = 0);
    int find(String str, int pos, int n);
};

#endif // STRING_H
