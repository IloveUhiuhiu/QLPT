#include "ChuyenDoi.h"
string ChuyenDoi::int_to_str(int x) // hàm chuyển từ kiểu int sang kiểu string
{
    string obj1 = "";
    if (x == 0)
        obj1 = "0";
    bool ok = (x >= 0)?true:false;
    x = abs(x);
    while (x)
    {
        obj1 += (x % 10 + '0');
        x /= 10;
    }
    int l = 0, r = obj1.size() - 1;
    while (l < r)
    {
        swap(obj1[l++], obj1[r--]);
    }
    if (!ok) obj1 = "-" + obj1;
    return obj1;
}
int ChuyenDoi::str_to_int(string str) // hàm chuyển từ kiểu string sang kiểu int
{   
    bool ok = (str[0] != '-')?true:false;
    int result = 0;
    for (int i = (ok)?0:1; i < str.size(); i++)
    {
        result = result * 10 + (str[i] - '0');
    }
    if (!ok) result*= -1;
    return result;
}
string ChuyenDoi::bool_to_str(bool ok) // hàm chuyển từ kiểu bool sang kiểu string
{
    string obj2;
    obj2 = (ok ? ("Yes") : ("No"));
    return obj2;
}
bool ChuyenDoi::str_to_bool(string str) // hàm chuyển từ kiểu string sang kiểu bool
{
    if (str == "Yes")
        return true;
    else if (str == "No")
        return false;
    return false;
}
string ChuyenDoi::CreateID(const string filename)
{
    ifstream inputFile;
    inputFile.open(filename);
    string str, room_id;
    int ID = 0;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            ID = max(ID, ChuyenDoi::str_to_int(str.substr(0, 6)));
        }
    }
    string id = ChuyenDoi::int_to_str(ID + 1);
    while (id.size() < 6)
    {
        id = "0" + id;
    }
    return id;
}

string ChuyenDoi::Tolower(string str)
{
    string ans = "";
    for (auto x : str)
        ans += tolower(x);
    return ans;
}
