#include "customer.h"
customer::customer(string customer_id, string room_id, string customer_name, string customer_dateofbirth, string customer_gender,
                   string customer_email, string customer_address, string customer_phone, string user_name, string password)
    : customer_id(customer_id), room_id(room_id), customer_name(customer_name), customer_dateofbirth(customer_dateofbirth),
      customer_gender(customer_gender), customer_email(customer_email), customer_address(customer_address), customer_phone(customer_phone), user(user_name, password)
{
}
customer::~customer()
{
}
string customer::get_customer_id() const
{
    return this->customer_id;
}
void customer::set_customer_id(string customer_id)
{
    this->customer_id = customer_id;
}
string customer::get_room_id() const
{
    return this->room_id;
}
void customer::set_room_id(string room_id)
{
    this->room_id = room_id;
}
string customer::get_customer_name() const
{
    return this->customer_name;
}
void customer::set_customer_name(string customer_name)
{
    this->customer_name = customer_name;
}

string customer::get_customer_dateofbirth() const
{
    return this->customer_dateofbirth;
}
void customer::set_customer_dateofbirth(string customer_dateofbirth)
{
    this->customer_dateofbirth = customer_dateofbirth;
}

string customer::get_customer_gender() const
{
    return this->customer_gender;
}
void customer::set_customer_gender(string customer_gender)
{
    this->customer_gender = customer_gender;
}

string customer::get_customer_email() const
{
    return this->customer_email;
}
void customer::set_customer_email(string customer_email)
{
    this->customer_email = customer_email;
}

string customer::get_customer_address() const
{
    return this->customer_address;
}
void customer::set_customer_address(string customer_address)
{
    this->customer_address = customer_address;
}

string customer::get_customer_phone() const
{
    return this->customer_phone;
}
void customer::set_customer_phone(string customer_phone)
{
    this->customer_phone = customer_phone;
}
istream &operator>>(istream &i, customer &obj)
{
    cout << "customer_id: ";
    getline(i, obj.customer_id);
    cout << "room_id: ";
    getline(i, obj.room_id);
    cout << "customer_name: ";
    getline(i, obj.customer_name);
    cout << "customer_dateofbirth: ";
    getline(i, obj.customer_dateofbirth);
    cout << "customer_gender: ";
    getline(i, obj.customer_gender);
    cout << "customer_email: ";
    getline(i, obj.customer_email);
    cout << "customer_address: ";
    getline(i, obj.customer_address);
    cout << "customer_phone: ";
    getline(i, obj.customer_phone);
    cout << "user_name: ";
    getline(i, obj.user_name);
    cout << "password: ";
    getline(i, obj.password);
    return i;
}
ostream &operator<<(ostream &o, const customer &obj)
{
    cout << "customer_id: ";
    o << obj.customer_id << endl;
    cout << "room_id: ";
    o << obj.room_id << endl;
    cout << "customer_name: ";
    o << obj.customer_name << endl;
    cout << "customer_dateofbirth: ";
    o << obj.customer_dateofbirth << endl;
    cout << "customer_gender: ";
    o << obj.customer_gender << endl;
    cout << "customer_email: ";
    o << obj.customer_email << endl;
    cout << "customer_address: ";
    o << obj.customer_address << endl;
    cout << "customer_phone: ";
    o << obj.customer_phone << endl;
    cout << "user_name: ";
    o << obj.user_name << endl;
    cout << "password: ";
    o << obj.password << endl;
    return o;
}

customer customer::Split(string str)
{
    string customer_id, room_id, customer_name, customer_dateofbirth, customer_gender, customer_email, customer_address,
        customer_phone, customer_password, customer_user_name;
    str += ',';
    int id = 1;
    int begin = 0, end = 0;
    for (auto x : str)
    {
        if (x == ',')
        {
            if (id == 1)
            {
                customer_id = str.substr(begin, end - begin);
            }
            else if (id == 2)
            {
                room_id = str.substr(begin, end - begin);
            }
            else if (id == 3)
            {
                customer_name = str.substr(begin, end - begin);
            }
            else if (id == 4)
            {
                customer_dateofbirth = str.substr(begin, end - begin);
            }
            else if (id == 5)
            {
                customer_gender = str.substr(begin, end - begin);
            }
            else if (id == 6)
            {
                customer_email = str.substr(begin, end - begin);
            }
            else if (id == 7)
            {
                customer_address = str.substr(begin, end - begin);
            }
            else if (id == 8)
            {
                customer_phone = str.substr(begin, end - begin);
            }
            else if (id == 9)
            {
                customer_user_name = str.substr(begin, end - begin);
            }
            else
            {
                customer_password = str.substr(begin, end - begin);
            }
            ++id;
            begin = end + 1;
        }
        end++;
    }
    return customer(customer_id, room_id, customer_name, customer_dateofbirth, customer_gender, customer_email, customer_address,
                    customer_phone, customer_user_name, customer_password);
}
string customer::Union(customer &obj)
{
    string str = obj.customer_id + "," + obj.room_id + "," + obj.customer_name + "," + obj.customer_dateofbirth + "," + obj.customer_gender + "," + obj.customer_email + "," + obj.customer_address + "," + obj.customer_phone + "," + obj.user_name + "," + obj.password;
    return str;
}
bool customer::login()
{
    List<customer> L;
    ifstream inputFile;
    inputFile.open("customer.txt");
    string str;
    if (inputFile.is_open())
    {
        while (getline(inputFile, str))
        {
            L.push_back(Split(str));
        }
        inputFile.close();
        int size = L.getSize();
        for (int i = 0; i < size; i++)
        {
            if (L[i].user_name == this->user_name && L[i].password == this->password)
            {

                for (int j = 0; j <= 100; j = j + 25)
                {
                    cout << "Dang kiem tra thong tin... " << j << "%" << endl;
                    sleep(1);
                    system("cls");
                }
                cout << "Dang Nhap Thanh Cong!" << endl;
                *(this) = L[i];
                return true;
            }
        }
        cout << "Ten Dang Nhap hoac Mat Khau khong dung. Vui long thu lai!!!" << endl;
        return false;
    }
    else
    {
        cout << "Loi Trong Qua Trinh Mo File" << endl;
        return false;
    }
}

void customer::write_File(List<string> &L)
{
    ofstream inputFile;
    inputFile.open("customer.txt", std::ios::out | std::ios::trunc);
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
        cout << "Loi Trong Qua Trinh Mo File" << endl;
    }
}
void customer::add_customer()
{
    ifstream inputFile;
    inputFile.open("customer.txt");
    string str, customer_id;
    List<string> L;
    bool add = true;
    while (getline(inputFile, str))
    {
        int end = 0;
        for (auto x : str)
        {
            if (x == ',')
            {
                customer_id = str.substr(0, end);
                break;
            }
            end++;
        }
        if (customer_id == this->customer_id)
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
}
void customer::find_customer(string customer_id)
{
    ifstream inputFile;
    inputFile.open("customer.txt");
    string str;
    while (getline(inputFile, str))
    {
        customer obj = Split(str);
        if (customer_id == obj.customer_id)
        {
            cout << obj << endl;
        }
    }
}
void customer::find_room(string room_id)
{
    ifstream inputFile;
    inputFile.open("customer.txt");
    string str;
    while (getline(inputFile, str))
    {
        customer obj = Split(str);
        if (room_id == obj.room_id)
        {
            cout << obj << endl;
        }
    }
}
void customer::update_customer(string customer_idd)
{
    List<string> L;
    ifstream inputFile;
    inputFile.open("customer.txt");
    string str, customer_id, room_id, customer_name, customer_dateofbirth, customer_gender, customer_email, customer_address,
        customer_phone, user_name, password;
    while (getline(inputFile, str))
    {
        L.push_back(str);
    }
    int size = L.getSize();

    for (int i = 0; i < size; i++)
    {
        customer obj = Split(L[i]);
        if (obj.get_customer_id() == customer_idd)
        {
            cin.ignore();
            cout << "customer_id: ";
            getline(cin, customer_id);
            cout << "long" << endl;
            obj.set_customer_id(customer_id);
            cout << "room_id: ";
            getline(cin, room_id);
            obj.set_room_id(room_id);
            cout << "customer_name: ";
            getline(cin, customer_name);
            obj.set_customer_name(customer_name);
            cout << "customer_dateofbirth: ";
            getline(cin, customer_dateofbirth);
            obj.set_customer_dateofbirth(customer_dateofbirth);
            cout << "customer_gender: ";
            getline(cin, customer_gender);
            obj.set_customer_gender(customer_gender);
            cout << "customer_email: ";
            getline(cin, customer_email);
            obj.set_customer_email(customer_email);
            cout << "customer_address: ";
            getline(cin, customer_address);
            obj.set_customer_address(customer_address);
            cout << "customer_phone: ";
            getline(cin, customer_phone);
            obj.set_customer_phone(customer_phone);
            cout << "user_name: ";
            getline(cin, user_name);
            obj.set_user_name(user_name);
            cout << "password: ";
            getline(cin, password);
            obj.set_password(password);
            str = Union(obj);
            L[i] = str;
        }
    }
    write_File(L);
}
void customer::delete_customer(string customer_idd)
{
    List<string> L;
    ifstream inputFile;
    inputFile.open("customer.txt");
    string str, customer_id, room_id, customer_name, customer_dateofbirth, customer_gender, customer_email, customer_address,
        customer_phone, user_name, password;
    while (getline(inputFile, str))
    {
        L.push_back(str);
    }
    int size = L.getSize();

    for (int i = 0; i < size; i++)
    {
        customer obj = Split(L[i]);
        if (obj.get_customer_id() == customer_idd)
        {
            L.erase(i);
            i--;
        }
    }
    write_File(L);
}