#include "ThoiGian.h"
ThoiGian::ThoiGian()
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
ThoiGian::ThoiGian(int years, int months, int days)
    : years(years), months(months), days(days)
{
}
ThoiGian::~ThoiGian()
{
}

int ThoiGian::get_years()
{
    return this->years;
}
int ThoiGian::get_months()
{
    return this->months;
}
int ThoiGian::get_days()
{
    return this->days;
}


bool ThoiGian::is_mid_month()
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

ThoiGian ThoiGian::Split(string str) // hàm tách chuổi
{
    int years, months, days;
    str += '-';
    int id = 1;
    int begin = 0, end = 0;
    for (auto x : str)
    {
        if (x == '-')
        {
            if (id == 1)
            {
                years = ChuyenDoi::str_to_int(str.substr(begin, end - begin));
            }
            else if (id == 2)
            {
                months = ChuyenDoi::str_to_int(str.substr(begin, end - begin));
            }
            else
            {
                days = ChuyenDoi::str_to_int(str.substr(begin, end - begin));
            }
            ++id;
            begin = end + 1;
        }
        end++;
    }
    return ThoiGian(years, months, days);
}
string ThoiGian::Union(ThoiGian obj)
{
    string res = ChuyenDoi::int_to_str(obj.get_years()) +"-"+ ChuyenDoi::int_to_str(obj.get_months()) + "-" + ChuyenDoi::int_to_str(obj.get_days());
    return res;
}
ostream &operator<<(ostream &o, const ThoiGian &obj)
{
    o << obj.years << '-'
      << obj.months << '-'
      << obj.days;
    return o;
}
istream& operator>>(istream& i, ThoiGian &obj)
{
    cout << "Years: ";
    i >> obj.years;
    cout << "Months: ";
    i >> obj.months;
    cout << "Days: ";
    i >> obj.days;
    return i;
}
bool ThoiGian::operator==(const ThoiGian& other) const {
    return (years == other.years) && (months == other.months) && (days == other.days);
}

bool ThoiGian::operator!=(const ThoiGian& other) const {
    return !(*this == other);
}

bool ThoiGian::operator<(const ThoiGian& other) const {
    if (years != other.years)
        return years < other.years;
    if (months != other.months)
        return months < other.months;
    return days < other.days;
}

bool ThoiGian::operator<=(const ThoiGian& other) const {
    return (*this < other) || (*this == other);
}

bool ThoiGian::operator>(const ThoiGian& other) const {
    return !(*this <= other);
}

bool ThoiGian::operator>=(const ThoiGian& other) const {
    return !(*this < other);
}
bool ThoiGian::isValidDate(int year, int month, int day)
{
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        return false;
    }

    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            if (day > 29)
            {
                return false;
            }
        }
        else if (day > 28)
        {
            return false;
        }
    }

    return true;
}

bool ThoiGian::isValidDate(string date)
{
    int cnt = 0;
    bool ok = 1;
    int vt1 = -1, vt2 = -1;
    for (int i = 0; i < date.size(); i++) {
        cnt+= (date[i] == '-');
        if (date[i] != '-') {
            if (date[i] < '0' || date[i] > '9') ok = false;
        } else {
            if (vt1 == -1) vt1 = i;
            else vt2 = i;
        }
    }
    if (cnt == 2 && ok) {
        int year = 0, month = 0, day = 0;
        year = ChuyenDoi::str_to_int(date.substr(0,vt1));
        month = ChuyenDoi::str_to_int(date.substr(vt1+1,vt2-vt1-1));
        day = ChuyenDoi::str_to_int(date.substr(vt2+1,date.size()-vt2-1));
        if (isValidDate(year,month,day)) return true;
        else return false;
    } else {
        return false;
    }
}
