#pragma once
#ifndef USER_H
#define USER_H
#include <iostream>
#include <conio.h>
#include <windows.h>
// #include "List.h"
#include "List.cpp"
#include <fstream>
#include <unistd.h>
#include <iomanip>

using namespace std;
class user
{
protected:
    string user_name;
    string password;

public:
    user(string = "", string = "");
    ~user();

    string get_user_name() const;
    void set_user_name(string);

    string get_password() const;
    void set_password(string);
};

#endif