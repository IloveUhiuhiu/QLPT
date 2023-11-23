#include "Datetime.h"
Datetime::Datetime()
{
    // Lấy thời gian hiện tại
    time_t currentTime = time(nullptr);

    // Chuyển đổi thời gian thành cấu trúc tm
    tm *localTime = localtime(&currentTime);

    // Gán giá trị cho các thành viên của lớp
    this->years = localTime->tm_year + 1900;
    this->months = localTime->tm_mon + 1;
    this->days = localTime->tm_mday;

    // In ra ngày giờ hoàn chỉnh
    // cout << this->years << '-' << this->months << '-' << this->days << ' ' << this->hours << ':' << this->minutes << ':' << this->seconds << endl;
}
Datetime::Datetime(int years, int months, int days)
    : years(years), months(months), days(days)
{
}
Datetime::~Datetime()
{
}

int Datetime::get_years()
{
    return this->years;
}
int Datetime::get_months()
{
    return this->months;
}
int Datetime::get_days()
{
    return this->days;
}


bool Datetime::is_mid_month()
{
    if (this->months == 2)
    {
        if (this->days >= 15)
            return true;
        return false;
    }
    if (this->days >= 16)
        return true;
    return false;
}

Datetime Datetime::Split(string str) // hàm tách chuổi
{
    int years, months, days, hours, minutes, seconds;
    str += ':';
    int id = 1;
    int begin = 0, end = 0;
    for (auto x : str)
    {
        if (x == '-')
        {
            if (id == 1)
            {
                years = Convert::str_to_int(str.substr(begin, end - begin));
            }
            else if (id == 2)
            {
                months = Convert::str_to_int(str.substr(begin, end - begin));
            }
            else
            {
                days = Convert::str_to_int(str.substr(begin, end - begin));
            }
            ++id;
            begin = end + 1;
        }
        end++;
    }
    return Datetime(years, months, days);
}
string Datetime::Union(Datetime &obj)
{
    string res = Convert::int_to_str(obj.get_years()) +"-"+ Convert::int_to_str(obj.get_months()) + "-" + Convert::int_to_str(obj.get_days());
    return res;
}
ostream &operator<<(ostream &o, const Datetime &obj)
{
    o << obj.years << '-'
      << obj.months << '-'
      << obj.days;
    return o;
}
istream& operator>>(istream& i, Datetime &obj)
{
    cout << "Years: ";
    i >> obj.years;
    cout << "Months: ";
    i >> obj.months;
    cout << "Days: ";
    i >> obj.days;
    return i;
}
<<<<<<< HEAD
bool Datetime::operator==(const Datetime& other) const {
    return (years == other.years) && (months == other.months) && (days == other.days);
}

bool Datetime::operator!=(const Datetime& other) const {
    return !(*this == other);
}

bool Datetime::operator<(const Datetime& other) const {
    if (years != other.years)
        return years < other.years;
    if (months != other.months)
        return months < other.months;
    return days < other.days;
}

bool Datetime::operator<=(const Datetime& other) const {
    return (*this < other) || (*this == other);
}

bool Datetime::operator>(const Datetime& other) const {
    return !(*this <= other);
}

bool Datetime::operator>=(const Datetime& other) const {
    return !(*this < other);
}
=======


>>>>>>> 5e06760843fe4aa94b2d2f791e75dc4e5bd75acc
