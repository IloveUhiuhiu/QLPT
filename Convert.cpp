#include "Convert.h"
string Convert::int_to_str(int x) // hàm chuyển từ kiểu int sang kiểu string
{
    string obj1 = "";
    if (x == 0) obj1 = "0";
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
    return obj1;
}
int Convert::str_to_int(string str) // hàm chuyển từ kiểu string sang kiểu int
{
    int result = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        result = result * 10 + (str[i] - '0');
    }
    return result;
}
string Convert::bool_to_str(bool ok) // hàm chuyển từ kiểu bool sang kiểu string
{
    string obj2;
    obj2 = (ok ? ("Yes") : ("No"));
    return obj2;
}
bool Convert::str_to_bool(string str) // hàm chuyển từ kiểu string sang kiểu bool
{
    if (str == "Yes")
        return true;
    else if (str == "No")
        return false;
    return false;
}
string Convert::CreateID(const string filename)
{
    ifstream inputFile;
    inputFile.open(filename);
    string str,room_id;
    int ID = 0;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            ID = max(ID, Convert::str_to_int(str.substr(0, 6)));
        }
    }
    string id = Convert::int_to_str(ID+1);
    while (id.size() < 6)
    {
        id = "0"+id;
    }
    return id;
}

