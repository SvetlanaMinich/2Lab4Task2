#include <stdio.h>

size_t strlen(const char* s){
    size_t size = 0;
    while(s[size]!='\0'){
        size++;
    }
    return size;
}
void* memcpy(void* s1, const void* s2, size_t n){
    char* str = (char*)s1;
    char* _str = (char*)s2;
    for(int i=0;i<n;i++){
        *(str+i)=*(_str+i);
    }
    return str;
}
void* memmove(void* s1, const void* s2, size_t n){
    char* str = (char*)s1;
    char* _str = (char*)s2;
    char* buf = new char[n];
    for(int i=0;i<n;i++){
        *(buf+i) = *(str+i);
    }
    for(int i=0;i<n;i++){
        *(_str+i)=*(buf+i);
    }
    delete[] buf;
    return str;
}
char* strcpy(char* s1, const char* s2){
    size_t length = strlen(s2);
    for(int i=0;i<length;i++){
        s1[i]=s2[i];
    }
    s1[length]='\0';
    return s1;
}
char* strncpy(char* s1, const char* s2, size_t n){
    int length = strlen(s2);
    for(int i=0;i<n;i++){
        for(int j=0;j<length;j++){
            s1[j]=s2[j];
            i++;
        }
        s1[i]='\0';
    }
    return s1;
}
char* strcat(char* s1, const char* s2){
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    int i = 0;
    for(int j=length1; j<length1+length2;j++){
        s1[j]=s2[i++];
    }
    s1[length1+length2]='\0';
    return s1;
}
char* strncat(char* s1, const char* s2, size_t n){
    int length1 = strlen(s1);
    int i=0;
    for( int j=0;j<length1+n;j++){
        s1[j] = s2[i++];
    }
    return s1;
}
int memcmp(const void* s1, const void* s2, size_t n){
    unsigned char* str = (unsigned char*)s1;
    unsigned char* _str = (unsigned char*)s2;
    if(str==_str) return 0;
    while(n--){
        if(*str!=*_str){
            return (*str>*_str)?1:-1;
        }
        str++;
        _str++;
    }
    return 0;
}
int strcmp(const char* s1, const char* s2){
    if(s1==s2) return 0;
    while(*s1!='\0' && *s2!='\0'){
        if(*s1!=*s2){
            return (*s1>*s2)?1:-1;
        }
        s1++;
        s2++;
    }
    return 0;
}
int strcoll(const char* s1, const char* s2);
int strncmp(const char* s1, const char* s2, size_t n){
    if(s1==s2) return 0;
    while(n-- && *s1!='\0' && *s2!='\0'){
        if(*s1!=*s2){
            return (*s1>*s2)?1:-1;
        }
        s1++;
        s2++;
    }
    return 0;
}
size_t strxfrm(char* s1, const char* s2, size_t n);
char* strtok(char* s1, const char* s2);
void* memset(void* s, int c, size_t n){
    unsigned char* str = (unsigned char*)s;
    for(int i=0;i<n;i++){
        str[i] = (unsigned char)c;
    }
    return str;
}
char* strerror(int errnum);
