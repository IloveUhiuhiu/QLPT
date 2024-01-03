#include "NguoiThue.h"
NguoiThue::NguoiThue(string customer_id, string room_id, string customer_name, ThoiGian customer_dateofbirth, ThoiGian check_in, string customer_gender,
                   string customer_email, string customer_address, string customer_phone, string user_name, string password)
    : customer_id(customer_id), room_id(room_id), customer_name(customer_name), customer_dateofbirth(customer_dateofbirth), check_in(check_in), customer_gender(customer_gender), customer_email(customer_email), customer_address(customer_address), customer_phone(customer_phone), User(user_name, password)
{
}
NguoiThue::~NguoiThue()
{
}
string NguoiThue::get_customer_id() const
{
    return this->customer_id;
}
void NguoiThue::set_customer_id(string customer_id)
{
    this->customer_id = customer_id;
}
string NguoiThue::get_room_id() const
{
    return this->room_id;
}
void NguoiThue::set_room_id(string room_id)
{
    this->room_id = room_id;
}
string NguoiThue::get_customer_name() const
{
    return this->customer_name;
}
void NguoiThue::set_customer_name(string customer_name)
{
    this->customer_name = customer_name;
}

ThoiGian NguoiThue::get_customer_dateofbirth() const
{
    return this->customer_dateofbirth;
}
void NguoiThue::set_customer_dateofbirth(ThoiGian time)
{
    this->customer_dateofbirth = time;
}

ThoiGian NguoiThue::get_check_in() const
{
    return this->check_in;
}
void NguoiThue::set_check_in(ThoiGian time)
{
    this->check_in = time;
}
string NguoiThue::get_customer_gender() const
{
    return this->customer_gender;
}
void NguoiThue::set_customer_gender(string customer_gender)
{
    this->customer_gender = customer_gender;
}

string NguoiThue::get_customer_email() const
{
    return this->customer_email;
}
void NguoiThue::set_customer_email(string customer_email)
{
    this->customer_email = customer_email;
}

string NguoiThue::get_customer_address() const
{
    return this->customer_address;
}
void NguoiThue::set_customer_address(string customer_address)
{
    this->customer_address = customer_address;
}

string NguoiThue::get_customer_phone() const
{
    return this->customer_phone;
}
void NguoiThue::set_customer_phone(string customer_phone)
{
    this->customer_phone = customer_phone;
}

int NguoiThue::NumOfCustomer()
{
    int ans = 0;
    string str;
    ifstream inputFile;
    inputFile.open("NguoiThue.txt");
    if (inputFile.is_open())
    {
        while (getline(inputFile, str))
        {
            if (str.size())
            {
                ans++;
            }
        }
        inputFile.close();
    }
    return ans;
}
void NguoiThue::change_user_name(string room_id)
{

    string user_name, password;
    gotoXY(4, 6);
    cout << "Enter user name: ";
    getline(cin, user_name);
    gotoXY(4, 7);
    cout << "Enter password: ";
    getline(cin, password);
    ifstream inputFile;
    inputFile.open("NguoiThue.txt");
    string str;
    NguoiThue obj;
    List<string> L;
    if (inputFile.is_open())
    {
        while (getline(inputFile, str))
        {
            if (str.size())
            {
                obj = NguoiThue::Split(str);
                if (obj.get_room_id() == room_id)
                {
                    if (user_name.size())
                        obj.set_user_name(user_name);
                    if (password.size())
                        obj.set_password(password);
                    str = Union(obj);
                }

                L.push_back(str);
            }
        }
        inputFile.close();
    }
    write_File(L);
}
bool NguoiThue::find_user_name(string user_name)
{
    ifstream inputFile;
    inputFile.open("NguoiThue.txt");
    string str;
    NguoiThue obj;
    if (inputFile.is_open())
    {
        while (getline(inputFile, str))
        {
            if (str.size())
            {
                obj = NguoiThue::Split(str);
                if (obj.get_user_name() == user_name)
                {
                    return true;
                }
            }
        }
        inputFile.close();
    }
    return false;
}
void NguoiThue::find_idroom(string room_id, List<NguoiThue> &L)
{
    ifstream inputFile;
    inputFile.open("NguoiThue.txt");
    string str;
    if (inputFile.is_open())
    {
        while (getline(inputFile, str))
        {
            if (str.size())
            {
                NguoiThue obj = NguoiThue::Split(str);
                if (ChuyenDoi::Tolower(obj.get_room_id()) == ChuyenDoi::Tolower(room_id))
                {
                    L.push_back(obj);
                }
            }
        }
        inputFile.close();
    }
    else
    {
        cout << "Error Opening File NguoiThue.txt" << endl;
    }
}

istream &operator>>(istream &i, NguoiThue &obj)
{
    gotoXY(4, 5);
    cout << "Enter Name: ";
    cin.ignore();
    getline(i, obj.customer_name);
    List<Phong> room;
    List<NguoiThue> L;
    do
    {
        xoa(4, 6, 40);
        xoa(4, 7, 40);
        gotoXY(4, 6);
        cout << "Enter Room ID: ";
        getline(i, obj.room_id);
        Phong::find_idroom(obj.room_id, room);
        if (!room.getSize())
        {
            gotoXY(4, 7);
            cout << "Room Not Found. Try Again!" << endl;
            getch();
        }
    } while (!room.getSize());
    string customer_dateofbirth;
    do
    {
        xoa(4, 7, 40);
        xoa(4, 8, 40);
        gotoXY(4, 7);
        cout << "Enter Date Of Birth(yy-mm-dd): ";
        getline(cin, customer_dateofbirth);
        if (!ThoiGian::isValidDate(customer_dateofbirth))
        {
            gotoXY(4, 8);
            cout << "Date is inValid. Try Again!" << endl;
            getch();
        }
    } while (!ThoiGian::isValidDate(customer_dateofbirth));
    obj.customer_dateofbirth = ThoiGian::Split(customer_dateofbirth);
    ThoiGian check_in;
    obj.check_in = check_in;
    gotoXY(4, 8);
    cout << "Enter Gender: ";
    getline(i, obj.customer_gender);
    gotoXY(4, 9);
    cout << "Enter Email: ";
    getline(i, obj.customer_email);
    gotoXY(4, 10);
    cout << "Enter Address: ";
    getline(i, obj.customer_address);
    gotoXY(4, 11);
    cout << "Enter Phone: ";
    getline(i, obj.customer_phone);
    if (!room[0].isOccupied())
    {
        do
        {
            xoa(4, 12, 40);
            xoa(4, 13, 40);
            gotoXY(4, 12);
            cout << "Enter User Name: ";
            getline(i, obj.user_name);
            if (NguoiThue::find_user_name(obj.user_name))
            {
                gotoXY(4, 13);
                cout << "Username already exists! Try again with another username!" << endl;
                getch();
            }
        } while (NguoiThue::find_user_name(obj.user_name));
        gotoXY(4, 13);
        cout << "Enter Password: ";
        getline(i, obj.password);
    }
    else
    {
        NguoiThue::find_idroom(obj.room_id, L);
        obj.user_name = L[0].get_user_name();
        obj.password = L[0].get_password();
    }
    return i;
}

NguoiThue NguoiThue::Split(string str)
{
    string customer_id, room_id, customer_name, customer_dateofbirth, check_in, customer_gender, customer_email, customer_address,
        customer_phone, customer_password, customer_user_name;
    ThoiGian time_customer_dateofbirth, time_check_in;
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
                time_customer_dateofbirth = ThoiGian::Split(customer_dateofbirth);
            }
            else if (id == 5)
            {
                check_in = str.substr(begin, end - begin);
                time_check_in = ThoiGian::Split(check_in);
            }
            else if (id == 6)
            {
                customer_gender = str.substr(begin, end - begin);
            }
            else if (id == 7)
            {
                customer_email = str.substr(begin, end - begin);
            }
            else if (id == 8)
            {
                customer_address = str.substr(begin, end - begin);
            }
            else if (id == 9)
            {
                customer_phone = str.substr(begin, end - begin);
            }
            else if (id == 10)
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
    return NguoiThue(customer_id, room_id, customer_name, time_customer_dateofbirth, time_check_in, customer_gender, customer_email, customer_address,
                    customer_phone, customer_user_name, customer_password);
}
string NguoiThue::Union(NguoiThue &obj)
{
    string str = obj.customer_id + "," + obj.room_id + "," + obj.customer_name + "," + ThoiGian::Union(obj.customer_dateofbirth) + "," + ThoiGian::Union(obj.check_in) + "," + obj.customer_gender + "," + obj.customer_email + "," + obj.customer_address + "," + obj.customer_phone + "," + obj.user_name + "," + obj.password;
    return str;
}

bool NguoiThue::login()
{
    List<NguoiThue> L;
    ifstream inputFile;
    inputFile.open("NguoiThue.txt");
    string str;
    if (inputFile.is_open())
    {
        while (getline(inputFile, str))
        {   
            if (str.size())
            L.push_back(Split(str));
        }
        inputFile.close();
        int size = L.getSize();
        for (int i = 0; i < size; i++)
        {
            if (L[i].user_name == this->user_name && L[i].password == this->password)
            {

                *(this) = L[i];
                return true;
            }
        }
        return false;
    }
    else
    {
        cout << "Error Open File NguoiThue.txt" << endl;
        return false;
    }
}

void NguoiThue::write_File(List<string> &L)
{
    ofstream inputFile;
    inputFile.open("NguoiThue.txt", std::ios::out | std::ios::trunc);
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
        cout << "Error Opening File NguoiThue.txt" << endl;
    }
}
void NguoiThue::add_customer()
{
    ifstream inputFile;
    inputFile.open("NguoiThue.txt");
    string str, customer_id;
    List<string> L;
    List<Phong> room;
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
    Phong::find_idroom(this->room_id, room);
    ThoiGian now;

    if (room[0].isOccupied() == false)
    {

        Phong::delete_room(room[0].getRoomID(), 1);
        room[0].setOccupied(true);
        room[0].add_room(0);
        DienNuoc dn = DienNuoc::find_nearest_dien_nuoc(room_id); // tìm điện nước gần nhất cùng phòng - trả về điện nước
        // cout << room_id << endl;
        // cout << dn.get_dien_nuoc_id() << endl;
        // set lại thằng ni xong add
        if (dn.get_num_electric_after() > 0)
        {
            dn.set_dien_nuoc_id(ChuyenDoi::CreateID("dien_nuoc.txt"));
            dn.set_num_electric_before(dn.get_num_electric_after());
            dn.set_num_water_before(dn.get_num_water_after());
            dn.set_num_water_after(0);
            dn.set_num_electric_after(0);
            dn.set_cost_water(DienNuoc::getNewCostWater());
            dn.set_cost_electric(DienNuoc::getNewCostElectric());
            dn.set_date(ThoiGian(now.get_years(), now.get_months(), 0));
            dn.set_status(false);
            dn.add_dien_nuoc();
        }

        HoaDon hd;
        hd.set_bill_id(ChuyenDoi::CreateID("hoa_don.txt"));
        hd.set_room_id(this->room_id);
        hd.set_total_cost(room[0].getCost());
        hd.set_date(ThoiGian(now.get_years(), now.get_months(), 0));
        hd.set_status(false);
        hd.add_hoa_don();
    }
}

bool NguoiThue::find_customer(List<NguoiThue> &L)
{
    string customer_id, room_id, customer_name, customer_dateofbirth, check_in, customer_gender, customer_email, customer_address,
        customer_phone, customer_user_name, customer_password;
    ThoiGian time_customer_dateofbirth, time_check_in;
    cin.ignore();
    gotoXY(4, 5);
    cout << "Enter Customer ID: ";
    getline(cin, customer_id);
    gotoXY(4, 6);
    cout << "Enter Room ID: ";
    getline(cin, room_id);
    gotoXY(4, 7);
    cout << "Enter Customer Name: ";
    getline(cin, customer_name);
    gotoXY(4, 8);
    cout << "Enter Customer Date Of Birth(yy-mm-dd): ";
    getline(cin, customer_dateofbirth);
    gotoXY(4, 9);
    cout << "Enter Check_in_Date: ";
    getline(cin, check_in);
    gotoXY(4, 10);
    cout << "Enter Customer Gender: ";
    getline(cin, customer_gender);
    gotoXY(4, 11);
    cout << "Enter Customer Email: ";
    getline(cin, customer_email);
    gotoXY(4, 12);
    cout << "Enter Customer Address: ";
    getline(cin, customer_address);
    gotoXY(4, 13);
    cout << "Enter Customer Phone: ";
    getline(cin, customer_phone);
    ifstream inputFile;
    inputFile.open("NguoiThue.txt");
    string str, s, subs;
    int cnt = 0;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            NguoiThue obj = NguoiThue::Split(str);
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
                s = ChuyenDoi::Tolower(obj.get_room_id());
                subs = ChuyenDoi::Tolower(room_id);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (customer_name.size() != 0)
            {
                s = ChuyenDoi::Tolower(obj.get_customer_name());
                subs = ChuyenDoi::Tolower(customer_name);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (customer_dateofbirth.size() != 0)
            {
                if (ThoiGian::isValidDate(customer_dateofbirth))
                {
                    time_customer_dateofbirth = ThoiGian::Split(customer_dateofbirth);
                    if (time_customer_dateofbirth.get_years() != 0)
                    {

                        if (time_customer_dateofbirth.get_years() != obj.get_customer_dateofbirth().get_years())
                        {
                            continue;
                        }
                    }
                    if (time_customer_dateofbirth.get_months() != 0)
                    {

                        if (time_customer_dateofbirth.get_months() != obj.get_customer_dateofbirth().get_months())
                        {
                            continue;
                        }
                    }
                    if (time_customer_dateofbirth.get_days() != 0)
                    {

                        if (time_customer_dateofbirth.get_days() != obj.get_customer_dateofbirth().get_days())
                        {
                            continue;
                        }
                    }
                }
                else
                    continue;
            }
            if (check_in.size() != 0)
            {
                if (ThoiGian::isValidDate(check_in))
                {
                    time_check_in = ThoiGian::Split(check_in);
                    if (time_check_in.get_years() != 0)
                    {

                        if (time_check_in.get_years() != obj.get_check_in().get_years())
                        {
                            continue;
                        }
                    }
                    if (time_check_in.get_months() != 0)
                    {

                        if (time_check_in.get_months() != obj.get_check_in().get_months())
                        {
                            continue;
                        }
                    }
                    if (time_check_in.get_days() != 0)
                    {

                        if (time_check_in.get_days() != obj.get_check_in().get_days())
                        {
                            continue;
                        }
                    }
                }
                else
                    continue;
            }
            if (customer_gender.size() != 0)
            {
                s = ChuyenDoi::Tolower(obj.get_customer_gender());
                subs = ChuyenDoi::Tolower(customer_gender);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (customer_email.size() != 0)
            {
                s = ChuyenDoi::Tolower(obj.get_customer_email());
                subs = ChuyenDoi::Tolower(customer_email);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (customer_address.size() != 0)
            {
                s = ChuyenDoi::Tolower(obj.get_customer_address());
                subs = ChuyenDoi::Tolower(customer_address);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (customer_phone.size() != 0)
            {
                s = ChuyenDoi::Tolower(obj.get_customer_phone());
                subs = ChuyenDoi::Tolower(customer_phone);
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
            ++cnt;
            L.push_back(obj);
        }
    }
    inputFile.close();
    if (cnt == 0)
        return false;
    return true;
}
void NguoiThue::display(List<NguoiThue> &L)
{
    ifstream inputFile;
    inputFile.open("NguoiThue.txt");
    string str;
    NguoiThue obj;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            obj = NguoiThue::Split(str);
            L.push_back(obj);
        }
    }
    inputFile.close();
}
void NguoiThue::find_idcustomer(string customer_id, List<NguoiThue> &L)
{
    ifstream inputFile;
    inputFile.open("NguoiThue.txt");
    string str;
    NguoiThue obj;
    while (getline(inputFile, str))
    {
        obj = Split(str);
        if (customer_id == obj.customer_id)
        {
            L.push_back(obj);
        }
    }
    inputFile.close();
}
void NguoiThue::update_customer(NguoiThue &obj1, int pos)
{
    List<string> L;
    ifstream inputFile;
    inputFile.open("NguoiThue.txt");
    string str, customer_name, customer_dateofbirth, customer_gender, customer_email, customer_address,
        customer_phone;
    while (getline(inputFile, str))
    {
        if (str.size())
            L.push_back(str);
    }
    int size = L.getSize();
    NguoiThue obj;
    for (int i = 0; i < size; i++)
    {
        obj = Split(L[i]);
        if (obj.get_customer_id() == obj1.get_customer_id())
        {
            gotoXY(4, pos + 1);
            cout << "Enter Customer Name: ";
            getline(cin, customer_name);
            if (customer_name.size())
                obj1.set_customer_name(customer_name);
            gotoXY(4, pos + 2);
            cout << "Enter Customer Date Of Birth (yy-mm-dd): ";
            getline(cin, customer_dateofbirth);
            if (customer_dateofbirth.size())
            {
                obj1.set_customer_dateofbirth(ThoiGian::Split(customer_dateofbirth));
            }
            gotoXY(4, pos + 3);
            cout << "Enter Customer Gender: ";
            getline(cin, customer_gender);
            if (customer_gender.size())
                obj1.set_customer_gender(customer_gender);
            gotoXY(4, pos + 4);
            cout << "Enter Customer Email: ";
            getline(cin, customer_email);
            if (customer_email.size())
                obj1.set_customer_email(customer_email);
            gotoXY(4, pos + 5);
            cout << "Enter Customer Address: ";
            getline(cin, customer_address);
            if (customer_address.size())
                obj1.set_customer_address(customer_address);
            gotoXY(4, pos + 6);
            cout << "Enter Customer Phone: ";
            getline(cin, customer_phone);
            if (customer_phone.size())
                obj1.set_customer_phone(customer_phone);
            str = Union(obj1);
            L[i] = str;
        }
    }
    inputFile.close();
    write_File(L);
}
void NguoiThue::delete_customer(string customer_id)
{
    List<string> L;
    List<Phong> room;
    ifstream inputFile;
    inputFile.open("NguoiThue.txt");
    string str;
    string room_id;
    int cnt = 0;
    while (getline(inputFile, str))
    {
        NguoiThue obj = Split(str);
        if (obj.get_customer_id() != customer_id)
        {
            L.push_back(str);
        }
        else
        {
            room_id = obj.get_room_id();
        }
    }
    inputFile.close();
    write_File(L);
    int size = L.getSize();
    for (int i = 0; i < size; i++)
    {
        NguoiThue obj = Split(L[i]);
        if (obj.get_room_id() == room_id)
        {
            cnt++;
        }
    }
    if (cnt == 0)
    {
        Phong::find_idroom(room_id, room);
        room[0].setOccupied(false);
        Phong::delete_room(room_id,1);
        room[0].add_room(0);
    }
}
