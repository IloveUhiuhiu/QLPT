#include "HoaDon.h"

HoaDon::HoaDon(string bill_id, string room_id, ThoiGian time, int total_cost, bool status)
    : bill_id(bill_id), room_id(room_id), date(time), total_cost(total_cost), status(status) {}

HoaDon::~HoaDon() {}

string HoaDon::get_room_id() const
{
    return room_id;
}
string HoaDon::get_bill_id() const
{
    return bill_id;
}
ThoiGian HoaDon::get_date() const
{
    return this->date;
}
int HoaDon::get_total_cost() const
{
    return total_cost;
}
bool HoaDon::get_status() const
{
    return status;
}

void HoaDon::set_room_id(string room_id)
{
    this->room_id = room_id;
}
void HoaDon::set_bill_id(string bill_id)
{
    this->bill_id = bill_id;
}
void HoaDon::set_date(ThoiGian time)
{
    this->date = time;
}
void HoaDon::set_total_cost(int total_cost)
{
    this->total_cost = total_cost;
}
void HoaDon::set_status(bool status)
{
    this->status = status;
}
istream &operator>>(istream &i, HoaDon &obj)
{
    string date;
    List<Phong> room;
    cin.ignore();
    do
    {
        cout << "Enter RoomID: ";
        getline(i, obj.room_id);
        Phong::find_idroom(obj.room_id, room);
        if (room[0].getRoomID() != obj.room_id)
        {
            cout << "Room Not Found.Try Again!" << endl;
        }
    } while (room[0].getRoomID() != obj.room_id || obj.room_id.size() == 0);
    cout << "Date: ";
    getline(cin, date);
    obj.date = ThoiGian::Split(date);
    cout << "Total Cost: ";
    i >> obj.total_cost;
    cout << "Status: ";
    cin.ignore();
    string status;
    getline(cin, status);
    obj.status = ChuyenDoi::str_to_bool(status);
    return i;
}

ostream &operator<<(ostream &o, const HoaDon &obj)
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
    o << ((obj.status) ? ("Yes") : ("No")) << endl;
    return o;
}

HoaDon HoaDon::Split(string str)
{
    string room_id, bill_id, date;
    ThoiGian time;
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
                date = str.substr(begin, end - begin);
                time = ThoiGian::Split(date);
            }
            else if (id == 4)
            {
                total_cost = ChuyenDoi::str_to_int(str.substr(begin, end - begin));
            }
            else if (id == 5)
            {
                status = ChuyenDoi::str_to_bool(str.substr(begin, end - begin));
            }
            ++id;
            begin = end + 1;
        }
        end++;
    }
    return HoaDon(room_id, bill_id, time, total_cost, status);
}

void HoaDon::write_File(List<string> &L)
{
    ofstream inputFile;
    inputFile.open("HoaDon.txt", std::ios::out | std::ios::trunc);
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
        cout << "Error Opening File HoaDon.txt" << endl;
    }
}
string HoaDon::Union(HoaDon &obj)
{
    string str = obj.bill_id + "," + obj.room_id + "," + ThoiGian::Union(obj.date) + "," + ChuyenDoi::int_to_str(obj.total_cost) + "," + ChuyenDoi::bool_to_str(obj.status);
    return str;
}
void HoaDon::add_hoa_don()
{
    ifstream inputFile;
    inputFile.open("HoaDon.txt");
    string str, bill_id, room_id, date, total_cost, status;
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
        cout << "Warn: ID Already Exits!!!" << endl;
    }
}

void HoaDon::display(List<HoaDon> &L, int k)
{
    ifstream inputFile;
    inputFile.open("HoaDon.txt");
    string str;
    HoaDon obj;
    List<Phong> room;
    ThoiGian time;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            obj = Split(str);
            room.clear();
            Phong::find_idroom(obj.get_room_id(),room);
            if (k == 0)
            {
                L.push_back(obj);
            }
            else if (k == 1)
            {
                if (obj.get_status() && room[0].isOccupied())
                {
                    if (((obj.get_date().get_months() == time.get_months()) && (obj.get_date().get_years() == time.get_years())) || ((obj.get_date().get_months() == time.get_months() - 1) && (obj.get_date().get_years() == time.get_years())) || ((obj.get_date().get_months() % 12 + 1 == time.get_months()) && (obj.get_date().get_years() == time.get_years() - 1)))
                    {
                        L.push_back(obj);
                    }
                }
            }
            else
            {
                if (!obj.get_status() && room[0].isOccupied())
                {
                    if (((obj.get_date().get_months() <= time.get_months()) && (obj.get_date().get_years() == time.get_years())) || ((obj.get_date().get_months() > time.get_months()) && (obj.get_date().get_years() == time.get_years() - 1)))
                    {
                        L.push_back(obj);
                    }
                }
            }
        }
    }
}
bool HoaDon::find_hoa_don(List<HoaDon> &L)
{
    string room_id, bill_id, date, status;
    ThoiGian time;
    cin.ignore();
    gotoXY(4, 5);
    cout << "Enter BiLL ID: ";
    getline(cin, bill_id);
    gotoXY(4, 6);
    cout << "Enter Room ID: ";
    getline(cin, room_id);
    gotoXY(4, 7);
    cout << "Enter Date(yy-mm-dd): ";
    getline(cin, date);
    gotoXY(4, 8);
    cout << "Enter Status: ";
    getline(cin, status);
    ifstream inputFile;
    inputFile.open("HoaDon.txt");
    string str, s, subs;
    int cnt = 0;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            HoaDon obj = HoaDon::Split(str);
            if (bill_id.size() != 0)
            {
                auto found = obj.get_bill_id().find(bill_id);
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
            if (date.size() != 0)
            {
                time = ThoiGian::Split(date);
                if (time.get_years() != 0)
                {
                    if (time.get_years() != obj.get_date().get_years())
                    {
                        continue;
                    }
                }
                if (time.get_months() != 0)
                {
                    if (time.get_months() != obj.get_date().get_months())
                    {
                        continue;
                    }
                }
                if (time.get_days() != 0)
                {
                    if (time.get_days() != obj.get_date().get_days())
                    {
                        continue;
                    }
                }
            }
            if (status.size()) {
                if (status != ((obj.get_status())?"Yes":"No")) {
                    continue;
                }
            }
            ++cnt;
            L.push_back(obj);
        }
    }
    if (cnt == 0)
        return false;
    return true;
}
bool HoaDon::find_room(string room_id)
{
    ifstream inputFile;
    inputFile.open("HoaDon.txt");
    string str;
    int cnt = 0;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            HoaDon obj = HoaDon::Split(str);
            if (obj.get_room_id() == room_id)
            {
                ++cnt;
                cout << obj << endl;
            }
        }
    }
    if (cnt == 0)
        return false;
    return true;
}
void HoaDon::find_bill_id(string bill_id, List<HoaDon> &L)
{
    ifstream inputFile;
    inputFile.open("HoaDon.txt");
    string str;
    HoaDon obj;
    while (getline(inputFile, str))
    {
        obj = Split(str);
        if (bill_id == obj.bill_id)
        {
            L.push_back(obj);
        }
    }
}

HoaDon HoaDon::find_nearest_hoa_don(string room_id)
{
    ifstream inputFile;
    inputFile.open("HoaDon.txt");
    string str;
    string max_id = "";
    HoaDon ans;
    while (getline(inputFile, str))
    {
        HoaDon obj = Split(str);
        if (obj.get_room_id() == room_id && obj.get_bill_id() > max_id)
        {
            max_id = obj.get_bill_id();
            ans = obj;
        }
    }
    return ans;
}
void HoaDon::update_hoa_don(HoaDon &obj1, int vt)
{
    bool ok = false;
    List<string> L;
    ifstream inputFile;
    inputFile.open("HoaDon.txt");
    string str, date, total_cost, status;
    while (getline(inputFile, str))
    {
        if (str.size())
            L.push_back(str);
    }
    int size = L.getSize();
    HoaDon obj;
    for (int i = 0; i < size; i++)
    {
        obj = Split(L[i]);
        if (obj.get_bill_id() == obj1.get_bill_id())
        {
            gotoXY(4, vt + 1);
            cout << "Date(Year-Month-Day): ";
            getline(cin, date);
            if (date.size())
                obj1.set_date(ThoiGian::Split(date));
            gotoXY(4, vt + 2);
            cout << "Total Cost: ";
            getline(cin, total_cost);
            if (total_cost.size())
                obj1.set_total_cost(ChuyenDoi::str_to_int(total_cost));
            str = Union(obj1);
            L[i] = str;
        }
    }
    write_File(L);
}
void HoaDon::Pay_bill(HoaDon &obj1, int vt)
{
    List<string> L;
    DoanhThu DT;
    ifstream inputFile;
    inputFile.open("HoaDon.txt");
    string str, status;
    while (getline(inputFile, str))
    {
        if (str.size())
            L.push_back(str);
    }
    int size = L.getSize();
    HoaDon obj, hd;
    ThoiGian dt;
    for (int i = 0; i < size; i++)
    {
        obj = Split(L[i]);
        if (obj.get_bill_id() == obj1.get_bill_id())
        {
            gotoXY(4, vt + 1);
            cout << "Total Cost: " << obj1.get_total_cost() << endl;
            cin.ignore();
            gotoXY(4, vt + 2);
            cout << "Do you want to pay?(Yes/No): ";
            getline(cin, status);
            obj1.set_status(ChuyenDoi::str_to_bool(status));
            if (obj1.get_status())
            {
                obj1.set_status(true);
                obj1.set_date(ThoiGian(dt.get_years(), dt.get_months(), dt.get_days()));
                L[i] = Union(obj1);
                write_File(L);
                hd.set_room_id(obj.get_room_id());
                hd.set_bill_id(ChuyenDoi::CreateID("HoaDon.txt"));
                hd.set_total_cost(obj.get_total_cost());
                (obj1.get_date().get_months() == 12) ? (hd.set_date(ThoiGian(obj1.get_date().get_years() + 1, (obj1.get_date().get_months()) % 12 + 1, 0))) : (hd.set_date(ThoiGian(obj1.get_date().get_years(), obj1.get_date().get_months() + 1, 0)));
                hd.set_status(false);
                hd.add_hoa_don();
                gotoXY(4, vt + 3);
                cout << "Payment success!!!" << endl;
                getch();
                DT.set_date(dt);
                DT.setThuNhap(obj.get_total_cost());
                DT.addDoanhThu();
            }
        }
    }
}

void HoaDon::delete_by_room(string room_id)
{
    ifstream inputFile;
    inputFile.open("HoaDon.txt");
    string str;
    List<string> L;
    while (getline(inputFile, str))
    {
        HoaDon obj = Split(str);

        if (ChuyenDoi::Tolower(obj.get_room_id()) != ChuyenDoi::Tolower(room_id))
        {
            L.push_back(str);
        }
    }
    write_File(L);
}
