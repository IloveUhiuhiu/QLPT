#pragma once
#ifndef USER_H
#define USER_H
#include <iostream>
#include "List.cpp"
#include <fstream>
#include <unistd.h>
#include <iomanip>
#include "Console.h"

using namespace std;
class User
{
protected:
    string user_name;
    string password;

public:
    User(string = "", string = "");
    ~User();

    string get_user_name() const;
    void set_user_name(string);

    string get_password() const;
    void set_password(string);

};

#endif