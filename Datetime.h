#ifndef DATETIME_H
#define DATETIME_H

#include <ctime>
#include <iostream>
#include "Convert.h"
using namespace std;

class Datetime
{
private:
    int years;
    int months;
    int days;

public:
    Datetime();
    Datetime(int, int, int);
    ~Datetime();

    int get_years();
    int get_months();
    int get_days();

    bool is_mid_month();

    static string Union(Datetime);
    static Datetime Split(string);

    friend ostream &operator<<(ostream &, const Datetime &);
    friend istream &operator>>(istream &, Datetime &);
    bool operator==(const Datetime &other) const;
    bool operator!=(const Datetime &other) const;
    bool operator<(const Datetime &other) const;
    bool operator<=(const Datetime &other) const;
    bool operator>(const Datetime &other) const;
    bool operator>=(const Datetime &other) const;
    static bool isValidDate(int = 0, int = 0, int = 0);
    static bool isValidDate(string);
};
#endif