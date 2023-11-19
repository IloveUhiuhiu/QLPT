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
    cout << "Name: ";
    cin.ignore();
    getline(i, obj.customer_name);
    cout << "RoomID: ";
    getline(i, obj.room_id);
    cout << "Date Of Birth(yy-mm-dd): ";
    getline(i, obj.customer_dateofbirth);
    cout << "Gender: ";
    getline(i, obj.customer_gender);
    cout << "Email: ";
    getline(i, obj.customer_email);
    cout << "Address: ";
    getline(i, obj.customer_address);
    cout << "Phone: ";
    getline(i, obj.customer_phone);
    cout << "user_name: ";
    getline(i, obj.user_name);
    cout << "password: ";
    getline(i, obj.password);
    return i;
}
ostream &operator<<(ostream &o, const customer &obj)
{
    // cout << "customer_id: ";
    o << setw(5) << obj.customer_id; cout << " | ";
    // cout << "room_id: ";
    o << setw(5) << obj.room_id << " | ";
    // cout << "customer_name: ";
    o << setw(10) << obj.customer_name << " | ";
    // cout << "customer_dateofbirth: ";
    o << setw(10) << obj.customer_dateofbirth << " | ";
    // cout << "customer_gender: ";
    o << setw(10) << obj.customer_gender << " | ";
    // cout << "customer_email: ";
    o << setw(10) << obj.customer_email << " | ";
    // cout << "customer_address: ";
    o << setw(10) << obj.customer_address << " | ";
    // cout << "customer_phone: ";
    o << setw(10) <<  obj.customer_phone << " | ";
    // cout << "user_name: ";
    o << setw(10) << obj.user_name << " | ";
    // cout << "password: ";
    o << setw(10) << obj.password << " | ";
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
                    cout << "Checking Information... " << j << "%" << endl;
                    sleep(1);
                    system("cls");
                }
                cout << "Login successfully!" << endl;
                *(this) = L[i];
                return true;
            }
        }
        cout << "Username or password is incorrect. Please try again!!!" << endl;
        return false;
    }
    else
    {
        cout << "Error Open File" << endl;
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
        cout << "Error Opening File customer.txt" << endl;
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
    Room obj = Room::find_room(this->room_id);
    if (obj.isOccupied() == false) {
        Room::delete_room(obj.getRoomID());
        obj.setOccupied(true);
        obj.add_room(0);   
    } 
}

bool customer::find_namecustomer(string name)
{
    ifstream inputFile;
    inputFile.open("customer.txt");
    string str;
    int cnt = 0;
    while (getline(inputFile, str))
    {   
        if (str.size()) {
            customer obj = customer::Split(str);
            if (obj.get_customer_name() == name)
            {   
                ++cnt;
                cout << obj << endl;
            }
        }
    }
    if (cnt == 0) return false;
    return true;
}
void customer::display()
{
    ifstream inputFile;
    inputFile.open("customer.txt");
    string str;
    while (getline(inputFile, str))
    {   
        if (str.size()) {
        customer obj = customer::Split(str);
        cout << obj << endl;
        }
    }
}
customer customer::find_idcustomer(string customer_id)
{
    ifstream inputFile;
    inputFile.open("customer.txt");
    string str;
    customer obj;
    while (getline(inputFile, str))
    {
        obj = Split(str);
        if (customer_id == obj.customer_id)
        {
            return obj;
        }
    }
    return obj;
}
void customer::update_customer(customer& obj1)
{
    List<string> L;
    ifstream inputFile;
    inputFile.open("customer.txt");
    string str, customer_name, customer_dateofbirth, customer_gender, customer_email, customer_address,
        customer_phone, user_name, password;
    while (getline(inputFile, str))
    {
        if (str.size()) L.push_back(str);
    }
    int size = L.getSize();
    customer obj;
    for (int i = 0; i < size; i++)
    {
       obj = Split(L[i]);
        if (obj.get_customer_id() == obj1.get_customer_id())
        {
            cout << "customer_name: ";
            cin.ignore();
            getline(cin, customer_name);
            if (customer_name.size()) obj1.set_customer_name(customer_name);
            cout << "customer_dateofbirth: ";
            getline(cin, customer_dateofbirth);
            if(customer_dateofbirth.size())obj1.set_customer_dateofbirth(customer_dateofbirth);
            cout << "customer_gender: ";
            getline(cin, customer_gender);
            if(customer_gender.size())obj1.set_customer_gender(customer_gender);
            cout << "customer_email: ";
            getline(cin, customer_email);
            if(customer_email.size())obj1.set_customer_email(customer_email);
            cout << "customer_address: ";
            getline(cin, customer_address);
            if(customer_address.size())obj1.set_customer_address(customer_address);
            cout << "customer_phone: ";
            getline(cin, customer_phone);
            if(customer_phone.size())obj1.set_customer_phone(customer_phone);
            cout << "user_name: ";
            getline(cin, user_name);
            if(user_name.size())obj1.set_user_name(user_name);
            cout << "password: ";
            getline(cin, password);
            if(password.size())obj1.set_password(password);
            str = Union(obj1);
            L[i] = str;
        }
    }
    write_File(L);
}
void customer::delete_customer(string customer_id)
{
    List<string> L;
    ifstream inputFile;
    inputFile.open("customer.txt");
    string str;
    string room_id;
    int cnt = 0;
    while (getline(inputFile, str))
    {   
        customer obj = Split(str);
        if (obj.get_customer_id() != customer_id)
        {
            L.push_back(str);
        } else {
            room_id = obj.get_room_id();
        }
        
    }
    write_File(L);
    int size = L.getSize();
    for (int i=0; i<size; i++) {
        customer obj = Split(L[i]);
        if (obj.get_room_id() == room_id) {
            cnt++;
        }
    }
    if (cnt == 0)
    {
        Room obj = Room::find_room(room_id);
        obj.setOccupied(false);
        Room::delete_room(room_id);
        obj.add_room(0);
    }
}