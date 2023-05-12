#ifndef STRING_H
#define STRING_H

#include "string_global.h"
#include "unique_ptr.h"

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
};

#endif // STRING_H
