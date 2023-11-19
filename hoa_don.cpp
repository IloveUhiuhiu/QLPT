#include "hoa_don.h"

hoa_don::hoa_don(string bill_id,string room_id, int years,int months,int days, int total_cost, bool status)
    : bill_id(bill_id),room_id(room_id), date(years,months,days), total_cost(total_cost), status(status) {}

hoa_don::~hoa_don() {}

string hoa_don::get_room_id() const
{
    return room_id;
}
string hoa_don::get_bill_id() const
{
    return bill_id;
}
Datetime hoa_don::get_date() const
{
    return date;
}
int hoa_don::get_total_cost() const
{
    return total_cost;
}
bool hoa_don::get_status() const
{
    return status;
}

void hoa_don::set_room_id(string room_id)
{
    this->room_id = room_id;
}
void hoa_don::set_bill_id(string bill_id)
{
    this->bill_id = bill_id;
}
void hoa_don::set_date(int years,int months,int days)
{
    this->date = Datetime(years,months,days);
}
void hoa_don::set_total_cost(int total_cost)
{
    this->total_cost = total_cost;
}
void hoa_don::set_status(bool status)
{
    this->status = status;
}
istream &operator>>(istream &i, hoa_don &obj)
{   
    cout << "Bill_ID: ";
    getline(i, obj.bill_id);
    cout << "Room ID: ";
    getline(i, obj.room_id);
    cout << "Date: ";
    i >> obj.date;
    cout << "Total Cost: ";
    i >> obj.total_cost;
    cout << "Status: ";
    string status;
    getline(cin,status);
    obj.status = Convert::str_to_bool(status);
    return i;
}
// int hoa_don::str_to_int(string str) // hàm chuyển từ kiểu string sang kiểu int
// {
//     int result = 0;
//     for (size_t i = 0; i < str.length(); i++)
//     {
//         result = result * 10 + (str[i] - '0');
//     }
//     return result;
// }
// bool hoa_don::str_to_bool(string str) // hàm chuyển từ kiểu string sang kiểu bool
// {
//     if (str == "Da Dong")
//         return true;
//     return false;
// }
// string hoa_don::int_to_str(int x)
// {
//     string obj1 = "";
//     while (x)
//     {
//         obj1 += (x % 10 + '0');
//         x /= 10;
//     }
//     int l = 0, r = obj1.size() - 1;
//     while (l < r)
//     {
//         swap(obj1[l++], obj1[r--]);
//     }
//     return obj1;
// }
// string hoa_don::bool_to_str(bool ok)
// {
//     string obj2;
//     obj2 = (ok ? ("Da Dong") : ("Chua Dong"));
//     return obj2;
// }
ostream &operator<<(ostream &o, const hoa_don &obj)
{   
    cout << "Bill_ID: ";
    o << obj.bill_id << endl;
    cout << "Room ID: ";
    o << obj.room_id << endl;
    cout << "Date: ";
    o << obj.date << endl;
    cout << "Total Cost: ";
    o << obj.total_cost << endl;
    cout << "Status: ";
    o << ((obj.status)?("Yes") : ("No")) << endl;
    return o;
}

hoa_don hoa_don::Split(string str) // hàm tách chuổi
{
    string room_id, bill_id;
    Datetime date;
    int total_cost;
    bool status;
    str += ',';
    int id = 1;
    int begin = 0, end = 0;
    for (auto x : str)
    {
        if (x == ',')
        {
            if (id == 1)
            {
                room_id = str.substr(begin, end - begin);
            }
            else if (id == 2)
            {
                bill_id = str.substr(begin, end - begin);
            }
            else if (id == 3)
            {
                date = Datetime::Split(str.substr(begin, end - begin));
            }
            else if (id == 4)
            {
                total_cost = Convert::str_to_int(str.substr(begin, end - begin));
            }
            else if (id == 7)
            {
                status = Convert::str_to_bool(str.substr(begin, end - begin));
            }
            ++id;
            begin = end + 1;
        }
        end++;
    }
    return hoa_don(room_id, bill_id, date.get_years(),date.get_months(),date.get_days(), total_cost, status);
}

void hoa_don::write_File(List<string> &L)
{
    ofstream inputFile;
    inputFile.open("hoa_don.txt", std::ios::out | std::ios::trunc);
    if (inputFile.is_open())
    {
        int size = L.getSize();
        if (size)
        {
            for (int i = 0; i < size; i++)
            {
                inputFile << L[i] << '\n';
            }
        }
    }
    else
    {
        cout << "Error Opening File hoa_don.txt" << endl;
    }
}
string hoa_don::Union(hoa_don &obj)
{
    string str = obj.bill_id + "," + obj.room_id + "," + Datetime::Union(obj.date) + "," + Convert::int_to_str(obj.total_cost) + "," + Convert::bool_to_str(obj.status);
    return str;
}
void hoa_don::add_hoa_don()
{
    ifstream inputFile;
    inputFile.open("hoa_don.txt");
    string str, bill_id;
    List<string> L;
    bool add = true;
    while (getline(inputFile, str))
    {
        int end = 0;
        for (auto x : str)
        {
            if (x == ',')
            {
                bill_id = str.substr(0, end);
                break;
            }
            end++;
        }
        if (bill_id == this->bill_id)
        {
            add = false;
        }
        L.push_back(str);
    }
    if (add)
    {
        str = Union(*this);
        L.push_back(str);
    }
    write_File(L);
    if (!add)
    {
        cout << "WARN: ID ALREADY EXIST!!!" << endl;
    }
}

void hoa_don::display()
{
    ifstream inputFile;
    inputFile.open("hoa_don.txt");
    string str;
    while (getline(inputFile, str))
    {
        hoa_don obj = Split(str);
        cout << obj << endl;
    }
}

void hoa_don::view_payment_room()
{
    ifstream inputFile;
    inputFile.open("hoa_don.txt");
    string str;
    while (getline(inputFile, str))
    {
        hoa_don obj = Split(str);
        if (obj.get_status() == true)
        {
            cout << obj << endl;
        }
    }
}
// void hoa_don::find_room(string room_id) // hàm đọc file  và lấy room_id để update hoặc delete
// {
//     ifstream inputFile;
//     inputFile.open("hoa_don.txt");
//     string str;
//     while (getline(inputFile, str))
//     {
//         hoa_don obj = Split(str);
//         if (room_id == obj.room_id)
//         {
//             cout << obj << endl;
//         }
//     }
// }
// void hoa_don::update_hoa_don(string room_idd)
// {
//     List<string> L;
//     ifstream inputFile;
//     inputFile.open("hoa_don.txt");
//     string str, room_id, date, bill_id, total_cost, status;
//     while (getline(inputFile, str))
//     {
//         L.push_back(str);
//     }
//     int size = L.getSize();

//     for (int i = 0; i < size; i++)
//     {
//         hoa_don obj = Split(L[i]);
//         if (obj.get_room_id() == room_idd)
//         {
//             // cin.ignore();
//             // cout << "room_id: ";
//             // getline(cin, room_id);
            
//             cout << "Bill ID: ";
//             getline(cin,bill_id);
//             obj.set_bill_id(bill_id);
            
//             cout << "Date: ";
//             getline(cin, date);
//             obj.set_date(date);
            
//             cout << "Total Cost: ";
//             getline(cin, total_cost);
//             obj.set_total_cost(Convert::str_to_int(total_cost));
            
//             cout << "Status: ";
//             cin >> status;
//             obj.set_status(Convert::str_to_bool(status));
//             str = Union(obj);
//             L[i] = str;
//         }
//     }
//     write_File(L);
// }