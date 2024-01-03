#ifndef ThoiGian_H
#define ThoiGian_H

#include <ctime>
#include <iostream>
#include "ChuyenDoi.h"
using namespace std;

class ThoiGian
{
private:
    int years;
    int months;
    int days;

public:
    ThoiGian();
    ThoiGian(int, int, int);
    ~ThoiGian();

    int get_years();
    int get_months();
    int get_days();

    bool is_mid_month();

    static string Union(ThoiGian);
    static ThoiGian Split(string);

    friend ostream &operator<<(ostream &, const ThoiGian &);
    friend istream &operator>>(istream &, ThoiGian &);
    bool operator==(const ThoiGian &other) const;
    bool operator!=(const ThoiGian &other) const;
    bool operator<(const ThoiGian &other) const;
    bool operator<=(const ThoiGian &other) const;
    bool operator>(const ThoiGian &other) const;
    bool operator>=(const ThoiGian &other) const;
    static bool isValidDate(int = 0, int = 0, int = 0);
    static bool isValidDate(string);
};
#endif