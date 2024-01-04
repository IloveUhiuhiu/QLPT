#ifndef String_H
#define String_H
#include"List.cpp"
#include<iostream>
#include<fstream>
using namespace std;
class String
{
    private:
    char *p;
    public:
    String();
    String(const char*);
    String(String&);
    ~String();
    int Getsize();
    const String& operator=(String&);
    const String& operator=(const char*);
    friend ostream& operator<<(ostream&, String&);
    friend fstream& operator<<(fstream&, String&);
    friend istream& operator>>(istream&, String&);
    friend fstream& operator>>(fstream&, String&);
    bool operator==(String&);
    bool operator==(const char*);
    bool operator!=(String&);
    bool operator!=(const char*);
    char& operator[](const int& );
    void lltos(long long);
};
#endif