#include "customer.h"
customer::customer(string customer_id, string room_id, string customer_name, Datetime time, string customer_gender,
                   string customer_email, string customer_address, string customer_phone, string user_name, string password)
    : customer_id(customer_id), room_id(room_id), customer_name(customer_name), customer_dateofbirth(time),
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

Datetime customer::get_customer_dateofbirth() const
{
    return this->customer_dateofbirth;
}
void customer::set_customer_dateofbirth(Datetime time)
{
    this->customer_dateofbirth = time;
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
bool customer::find_user_name(string user_name)
{
    ifstream inputFile;
    inputFile.open("customer.txt");
    string str;
    if (inputFile.is_open())
    {
        while (getline(inputFile, str))
        {   
            if (str.size()) {
                customer obj = customer::Split(str);
                if (obj.get_user_name() == user_name)
                {
                    return true;
                }
            }
        }
        
    }
    return false;
}

istream &operator>>(istream &i, customer &obj)
{
    cout << "Enter Name: ";
    cin.ignore();
    getline(i, obj.customer_name);
    Room room;
    do
    {
        cout << "Enter RoomID: ";
        getline(i, obj.room_id);
        room = Room::find_room(obj.room_id);
        if (room.getRoomID() != obj.room_id)
        {
            cout << "Room Not Found.Try Again!" << endl;
        }
    } while (room.getRoomID() != obj.room_id);
    cout << "Enter Date Of Birth(yy-mm-dd): ";
    cin >> obj.customer_dateofbirth;
    
    cout << "Enter Gender: ";
    getline(i, obj.customer_gender);
    cout << "Enter Email: ";
    getline(i, obj.customer_email);
    cout << "Enter Address: ";
    getline(i, obj.customer_address);
    cout << "Enter Phone: ";
    getline(i, obj.customer_phone);
    do {
    cout << "Enter User Name: ";
    getline(i, obj.user_name);
        if (customer::find_user_name(obj.user_name)) {
            cout << "Username already exists! Try again with another username!" << endl;
        }
    } while (customer::find_user_name(obj.user_name));
    cout << "Enter Password: ";
    getline(i, obj.password);
    return i;
}
ostream &operator<<(ostream &o, const customer &obj)
{
    // cout << "customer_id: ";
    o << setw(5) << obj.customer_id;
    cout << " | ";
    // cout << "room_id: ";
    o << setw(5) << obj.room_id << " | ";
    // cout << "customer_name: ";
    o << setw(10) << obj.customer_name << " | ";
    // cout << "customer_dateofbirth: ";
    o << setw(10); o << obj.customer_dateofbirth << " | ";
    // cout << "customer_gender: ";
    o << setw(10) << obj.customer_gender << " | ";
    // cout << "customer_email: ";
    o << setw(10) << obj.customer_email << " | ";
    // cout << "customer_address: ";
    o << setw(10) << obj.customer_address << " | ";
    // cout << "customer_phone: ";
    o << setw(10) << obj.customer_phone << " | ";
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
    Datetime time;
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
                time = Datetime::Split(customer_dateofbirth);
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
    return customer(customer_id, room_id, customer_name,time, customer_gender, customer_email, customer_address,
                    customer_phone, customer_user_name, customer_password);
}
string customer::Union(customer &obj)
{
    string str = obj.customer_id + "," + obj.room_id + "," + obj.customer_name + "," + Datetime::Union(obj.customer_dateofbirth) + "," + obj.customer_gender + "," + obj.customer_email + "," + obj.customer_address + "," + obj.customer_phone + "," + obj.user_name + "," + obj.password;
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
    if (obj.isOccupied() == false)
    {
        Room::delete_room(obj.getRoomID());
        obj.setOccupied(true);
        obj.add_room(0);
        dien_nuoc dn = dien_nuoc::find_nearest_dien_nuoc(room_id); // tìm thằng gần nhất cùng phòng - trả về dien nuoc
        // set lại thằng ni xong add
        if (dn.get_num_electric_after() > 0)
        {
            dn.set_dien_nuoc_id(Convert::CreateID("dien_nuoc.txt"));
            dn.set_num_electric_before(dn.get_num_electric_after());
            dn.set_num_water_before(dn.get_num_water_after());
            dn.set_num_water_after(0);
            dn.set_num_electric_after(0);
            dn.set_cost_water(dien_nuoc::getNewCostWater());
            dn.set_cost_electric(dien_nuoc::getNewCostElectric());
            dn.set_date(0, 0, 0);
            dn.set_status(false);
            dn.add_dien_nuoc();
        }

        hoa_don hd;
        hd.set_bill_id(Convert::CreateID("hoa_don.txt"));
        hd.set_room_id(this->room_id);
        hd.set_total_cost(obj.getCost());
        hd.set_date(0, 0, 0);
        hd.set_status(false);
        hd.add_hoa_don();
    }
}

bool customer::find_customer()
{
    string customer_id, room_id, customer_name, customer_dateofbirth, customer_gender, customer_email, customer_address,
        customer_phone, customer_user_name, customer_password;
    Datetime time;
    cin.ignore();
    cout << "Enter Customer ID: ";
    getline(cin, customer_id);
    cout << "Enter Room ID: ";
    getline(cin, room_id);
    cout << "Enter Customer Name: ";
    getline(cin, customer_name);
    cout << "Enter Customer Date Of Birth(yy-mm-dd): ";
    getline(cin, customer_dateofbirth);
    cout << "Enter Customer Gender: ";
    getline(cin, customer_gender);
    cout << "Enter Customer Email: ";
    getline(cin, customer_email);
    cout << "Enter Customer Address: ";
    getline(cin, customer_address);
    cout << "Enter Customer Phone: ";
    getline(cin, customer_phone);
    cout << "Enter User Name: ";
    getline(cin, customer_user_name);
    cout << "Password: ";
    getline(cin, customer_password);
    ifstream inputFile;
    inputFile.open("customer.txt");
    string str, s, subs;
    int cnt = 0;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            customer obj = customer::Split(str);
            if (customer_id.size() != 0)
            {
                auto found = obj.get_customer_id().find(customer_id);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (room_id.size() != 0)
            {
                s = Convert::Tolower(obj.get_room_id());
                subs = Convert::Tolower(room_id);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (customer_name.size() != 0)
            {
                s = Convert::Tolower(obj.get_customer_name());
                subs = Convert::Tolower(customer_name);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (customer_dateofbirth.size() != 0)
            {
                time = Datetime::Split(customer_dateofbirth);
                if (time.get_years() != 0) {
                    if (time.get_years() != obj.get_customer_dateofbirth().get_years())
                    {
                        continue;
                    }
                }
                if (time.get_months() != 0) {
                    if (time.get_months() != obj.get_customer_dateofbirth().get_months())
                    {
                        continue;
                    }
                }
                if (time.get_days() != 0) {
                    if (time.get_days() != obj.get_customer_dateofbirth().get_days())
                    {
                        continue;
                    }
                }
            }
            if (customer_gender.size() != 0)
            {
                s = Convert::Tolower(obj.get_customer_gender());
                subs = Convert::Tolower(customer_gender);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (customer_email.size() != 0)
            {
                s = Convert::Tolower(obj.get_customer_email());
                subs = Convert::Tolower(customer_email);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (customer_address.size() != 0)
            {
                s = Convert::Tolower(obj.get_customer_address());
                subs = Convert::Tolower(customer_address);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (customer_phone.size() != 0)
            {
                s = Convert::Tolower(obj.get_customer_phone());
                subs = Convert::Tolower(customer_phone);
                auto found = s.find(subs);
                if (found != std::string::npos)
                {
                    cnt++;
                }
                else
                {
                    continue;
                }
            }
            if (customer_user_name.size() != 0)
            {
                if (obj.get_user_name() != customer_user_name)
                {
                    continue;
                }
            }
            if (customer_password.size() != 0)
            {
                if (obj.get_password() != customer_password)
                {
                    continue;
                }
            }
            ++cnt;
            cout << obj << endl;
        }
    }
    if (cnt == 0)
        return false;
    return true;
}
void customer::display()
{
    ifstream inputFile;
    inputFile.open("customer.txt");
    string str;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
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
void customer::update_customer(customer &obj1)
{
    List<string> L;
    ifstream inputFile;
    inputFile.open("customer.txt");
    string str, customer_name, customer_dateofbirth, customer_gender, customer_email, customer_address,
        customer_phone, user_name, password;
    while (getline(inputFile, str))
    {
        if (str.size())
            L.push_back(str);
    }
    int size = L.getSize();
    customer obj;
    for (int i = 0; i < size; i++)
    {
        obj = Split(L[i]);
        if (obj.get_customer_id() == obj1.get_customer_id())
        {
            cout << "Enter Customer Name: ";
            cin.ignore();
            getline(cin, customer_name);
            if (customer_name.size())
                obj1.set_customer_name(customer_name);
            cout << "Enter Customer Date Of Birth (yy-mm-dd): ";
            getline(cin, customer_dateofbirth);
            if (customer_dateofbirth.size()) {
                obj1.set_customer_dateofbirth(Datetime::Split(customer_dateofbirth));
            }
            cout << "Enter Customer Gender: ";
            getline(cin, customer_gender);
            if (customer_gender.size())
                obj1.set_customer_gender(customer_gender);
            cout << "Enter Customer Email: ";
            getline(cin, customer_email);
            if (customer_email.size())
                obj1.set_customer_email(customer_email);
            cout << "Enter Customer Address: ";
            getline(cin, customer_address);
            if (customer_address.size())
                obj1.set_customer_address(customer_address);
            cout << "Enter Customer Phone: ";
            getline(cin, customer_phone);
            if (customer_phone.size())
                obj1.set_customer_phone(customer_phone);
            cout << "Enter User Name: ";
            getline(cin, user_name);
            if (user_name.size())
                obj1.set_user_name(user_name);
            cout << "Enter Password: ";
            getline(cin, password);
            if (password.size())
                obj1.set_password(password);
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
        }
        else
        {
            room_id = obj.get_room_id();
        }
    }
    write_File(L);
    int size = L.getSize();
    for (int i = 0; i < size; i++)
    {
        customer obj = Split(L[i]);
        if (obj.get_room_id() == room_id)
        {
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

// void customer::change_room(string roomid1, string roomid2)
// {
//     // set lại customer
//     ifstream inputFile;
//     inputFile.open("customer.txt");
//     string str, customer_id;
//     List<string> L;
//     while (getline(inputFile, str))
//     {   
//         if (str.size()) {
//             customer obj = customer::Split(str);
//             if (obj.get_room_id() == roomid1)
//             {
//                 obj.set_room_id(roomid2);
//                 str = Union(obj);
//             }
//             L.push_back(str);
//         }
//     }
//     write_File(L);
//     // hủy phòng
//     // sử lí điện nước
//     // Hủy phòng
//     Room obj1 = Room::find_room(roomid1);
//     Roon obj2 = Room::find_room(roomid2);
//     obj1.setOccupied(false);
//     obj2.setOccupied(true);
//     Room::delete_room(roomid1);
//     Room::delete_room(roomid2);
//     obj1.add_room(0);
//     obj2.add_room(0);

//     // Sử lí điện nước
//     dien_nuoc dn1 = dien_nuoc::find_nearest_dien_nuoc(roomid1);
//     dien_nuoc dn2 = dien_nuoc::find_nearest_dien_nuoc(roomid2);
//     dien_nuoc dn3;
//     dn3.set_dien_nuoc_id(Convert::CreateID("dien_nuoc.txt"));
//     dn3.set_num_electric_before(dn1.get_num_electric_after() - );
//     dn3.set_dien_nuoc_price(dn1.get_dien_nuoc_price());
//     dn3.set_status(false);
//     dn1.set_dien_nuoc_id(dn2.get_dien_nuoc_id());
//     if (dn1.get_status()) {
//         dn1.Pay_dien_nuoc(dn1);
//     }

//     if (dn2.get_status()) {
//         dn2.Pay_dien_nuoc(dn2);
//     }
//     // TODO: Add code here to handle electricity and water processing
//     // sử lí hóa đơn

    
//     write_File(L);

// }