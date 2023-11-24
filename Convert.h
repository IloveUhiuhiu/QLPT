#ifndef CONVERT_H
#define CONVERT_H

#include "user.h"
using namespace std;
class Convert
{
public:
    static string int_to_str(int);
    static string bool_to_str(bool);
    static int str_to_int(string);
    static bool str_to_bool(string);
    static string CreateID(const string);
    static string Tolower(const string);
};
#endif