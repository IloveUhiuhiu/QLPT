#include "DienNuoc.h"
DienNuoc::DienNuoc(string dien_nuoc_id, string room_id, int num_electric_before, int num_electric_after, int num_water_before,
                     int num_water_after, int cost_water, int cost_electric, ThoiGian time, bool status)
    : dien_nuoc_id(dien_nuoc_id), room_id(room_id), num_electric_before(num_electric_before), num_electric_after(num_electric_after), num_water_before(num_water_before),
      num_water_after(num_water_after), cost_water(cost_water), cost_electric(cost_electric), date(time), status(status) {}

DienNuoc::~DienNuoc()
{
}
string DienNuoc::get_dien_nuoc_id() const
{
    return dien_nuoc_id;
}
string DienNuoc::get_room_id() const
{
    return room_id;
}
int DienNuoc::get_num_electric_before() const
{
    return num_electric_before;
}
int DienNuoc::get_num_electric_after() const
{
    return num_electric_after;
}
int DienNuoc::get_num_water_before() const
{
    return num_water_before;
}
int DienNuoc::get_num_water_after() const
{
    return num_water_after;
}
int DienNuoc::get_cost_water() const
{
    return cost_water;
}
int DienNuoc::get_cost_electric() const
{
    return cost_electric;
}
ThoiGian DienNuoc::get_date() const
{
    return this->date;
}
bool DienNuoc::get_status() const
{
    return status;
}

void DienNuoc::set_dien_nuoc_id(string dien_nuoc_id)
{
    this->dien_nuoc_id = dien_nuoc_id;
}
void DienNuoc::set_room_id(string room_id)
{
    this->room_id = room_id;
}
void DienNuoc::set_num_electric_before(int num_electric_before)
{
    this->num_electric_before = num_electric_before;
}
void DienNuoc::set_num_electric_after(int num_electric_after)
{
    this->num_electric_after = num_electric_after;
}
void DienNuoc::set_num_water_before(int num_water_before)
{
    this->num_water_before = num_water_before;
}
void DienNuoc::set_num_water_after(int num_water_after)
{
    this->num_water_after = num_water_after;
}
void DienNuoc::set_cost_water(int cost_water)
{
    this->cost_water = cost_water;
}
void DienNuoc::set_cost_electric(int cost_electric)
{
    this->cost_electric = cost_electric;
}
void DienNuoc::set_date(ThoiGian time)
{
    this->date = time;
}
void DienNuoc::set_status(bool status)
{
    this->status = status;
}
ostream &operator<<(ostream &o, const DienNuoc &obj)
{
    cout << "Dien_Nuoc_ID: ";
    o << obj.dien_nuoc_id << endl;
    cout << "Room_ID: ";
    o << obj.room_id << endl;
    cout << "Num Of Electric Before: ";
    o << obj.num_electric_before << endl;
    cout << "Num Of Electric After: ";
    o << obj.num_electric_after << endl;
    cout << "Num Of Water Before: ";
    o << obj.num_water_before << endl;
    cout << "Num Of Water After: ";
    o << obj.num_water_after << endl;
    cout << "Cost Of Ater: ";
    o << obj.cost_water << endl;
    cout << "Cost Of Electric : ";
    o << obj.cost_electric << endl;
    cout << "Date: ";
    o << obj.date << endl;
    cout << "Status: ";
    o << (obj.status ? "Yes" : "No") << endl;
    return o;
}

void DienNuoc::write_File(List<string> &L) // xuất dữ liệu ra file
{
    ofstream inputFile;
    inputFile.open("DienNuoc.txt", std::ios::out | std::ios::trunc);
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
        cout << "Error Openning File DienNuoc.txt" << endl;
    }
}
DienNuoc DienNuoc::Split(string str) // hàm tách chuổi
{
    string dien_nuoc_id, room_id, date;
    int num_electric_before, num_electric_after, num_water_before, num_water_after, cost_water, cost_electric;
    ThoiGian time;
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
                dien_nuoc_id = str.substr(begin, end - begin);
            }
            else if (id == 2)
            {
                room_id = str.substr(begin, end - begin);
            }
            else if (id == 3)
            {
                num_electric_before =ChuyenDoi::str_to_int(str.substr(begin, end - begin));
            }
            else if (id == 4)
            {
                num_electric_after =ChuyenDoi::str_to_int(str.substr(begin, end - begin));
            }
            else if (id == 5)
            {
                num_water_before =ChuyenDoi::str_to_int(str.substr(begin, end - begin));
            }
            else if (id == 6)
            {
                num_water_after =ChuyenDoi::str_to_int(str.substr(begin, end - begin));
            }
            else if (id == 7)
            {
                cost_water =ChuyenDoi::str_to_int(str.substr(begin, end - begin));
            }
            else if (id == 8)
            {
                cost_electric =ChuyenDoi::str_to_int(str.substr(begin, end - begin));
            }
            else if (id == 9)
            {
                date = str.substr(begin, end - begin);
                time = ThoiGian::Split(date);
            }
            else if (id == 10)
            {
                status =ChuyenDoi::str_to_bool(str.substr(begin, end - begin));
            }
            ++id;
            begin = end + 1;
        }
        end++;
    }
    return DienNuoc(dien_nuoc_id, room_id, num_electric_before, num_electric_after, num_water_before, num_water_after, cost_water, cost_electric, time, status);
}
string DienNuoc::Union(DienNuoc &obj) // hàm gộp chuổi
{
    string str = obj.dien_nuoc_id + "," + obj.room_id + "," +ChuyenDoi::int_to_str(obj.num_electric_before) + "," +ChuyenDoi::int_to_str(obj.num_electric_after) + "," +ChuyenDoi::int_to_str(obj.num_water_before) + "," +ChuyenDoi::int_to_str(obj.num_water_after) + "," +ChuyenDoi::int_to_str(obj.cost_water) + "," +ChuyenDoi::int_to_str(obj.cost_electric) + "," + ThoiGian::Union(obj.date) + "," +ChuyenDoi::bool_to_str(obj.status);
    return str;
}

int DienNuoc::getNewCostWater()
{
    ifstream inputFile;
    inputFile.open("TienNuoc.txt");
    int cost_water;
    inputFile >> cost_water;
    return cost_water;
}
int DienNuoc::getNewCostElectric()
{
    ifstream inputFile;
    inputFile.open("TienDien.txt");
    int cost_electric;
    inputFile >> cost_electric;
    return cost_electric;
}

void DienNuoc::updateCostElectric(int newCostElectric)
{
    ofstream outputFile;
    outputFile.open("costElectric.txt", std::ios::out | std::ios::trunc);
    outputFile << newCostElectric;
}
void DienNuoc::updateCostWater(int newCostWater)
{
    ofstream outputFile;
    outputFile.open("costWater.txt", std::ios::out | std::ios::trunc);
    outputFile << newCostWater;
}
void DienNuoc::add_dien_nuoc()
{
    List<string> L;
    string str, dien_nuoc_id, num_electric_before, num_electric_after, num_water_before, num_water_after, cost_water, cost_electric, date, status;
    ifstream inputFile;
    inputFile.open("DienNuoc.txt");
    bool add = true;
    while (getline(inputFile, str))
    {
        int end = 0;
        for (auto x : str)
        {
            if (x == ',')
            {
                dien_nuoc_id = str.substr(0, end);
                break;
            }
            end++;
        }
        if (dien_nuoc_id == this->dien_nuoc_id)
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

bool DienNuoc::find_room(string room_id)
{
    ifstream inputFile;
    inputFile.open("DienNuoc.txt");
    string str;
    int cnt = 0;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            DienNuoc obj = DienNuoc::Split(str);
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
DienNuoc DienNuoc::find_nearest_dien_nuoc(string room_id)
{
    ifstream inputFile;
    inputFile.open("DienNuoc.txt");
    string str;
    string max_id = "";
    DienNuoc ans;
    while (getline(inputFile, str))
    {
        DienNuoc obj = Split(str);
        if (obj.get_room_id() == room_id && obj.get_dien_nuoc_id() > max_id)
        {
            max_id = obj.get_dien_nuoc_id();
            ans = obj;
        }
    }
    return ans;
}

void DienNuoc::find_dien_nuoc_id(string dien_nuoc_id, List<DienNuoc> &L)
{
    ifstream inputFile;
    inputFile.open("DienNuoc.txt");
    string str;
    DienNuoc obj;
    while (getline(inputFile, str))
    {
        obj = Split(str);
        if (dien_nuoc_id == obj.dien_nuoc_id)
        {
            L.push_back(obj);
        }
    }
}
bool DienNuoc::find_dien_nuoc(List<DienNuoc> &L)
{
    string room_id, dien_nuoc_id, date, status;
    ThoiGian time;
    cin.ignore();
    gotoXY(4, 5);
    cout << "Enter Electric Water ID: ";
    getline(cin, dien_nuoc_id);
    gotoXY(4, 6);
    cout << "Enter Room ID: ";
    getline(cin, room_id);
    gotoXY(4, 7);
    cout << "Enter Payment Date(yy-mm-dd): ";
    getline(cin, date);
    gotoXY(4, 8);
    cout << "Enter Status: ";
    getline(cin, status);
    ifstream inputFile;
    inputFile.open("DienNuoc.txt");
    string str, s, subs;
    int cnt = 0;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            DienNuoc obj = DienNuoc::Split(str);
            if (dien_nuoc_id.size() != 0)
            {
                auto found = obj.get_dien_nuoc_id().find(dien_nuoc_id);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (room_id.size() != 0)
            {
                s =ChuyenDoi::Tolower(obj.get_room_id());
                subs =ChuyenDoi::Tolower(room_id);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (date.size() != 0)
            {
                if (ThoiGian::isValidDate(date))
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
                else
                    continue;
            }
            if (status.size())
            {
                s =ChuyenDoi::Tolower(ChuyenDoi::bool_to_str(obj.get_status()));
                subs =ChuyenDoi::Tolower(status);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
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
void DienNuoc::update_dien_nuoc(DienNuoc &obj1, int vt)
{
    List<string> L;
    ifstream inputFile;
    inputFile.open("DienNuoc.txt");
    string str, num_electric_before, num_electric_after, num_water_before, num_water_after, cost_water, cost_electric, date, status;
    while (getline(inputFile, str))
    {
        if (str.size())
            L.push_back(str);
    }
    int size = L.getSize();
    DienNuoc obj;
    for (int i = 0; i < size; i++)
    {
        obj = Split(L[i]);
        if (obj.get_dien_nuoc_id() == obj1.get_dien_nuoc_id())
        {
            gotoXY(4, vt + 1);
            cout << "Num Electric Before: ";
            getline(cin, num_electric_before);
            if (num_electric_before.size())
                obj1.set_num_electric_before(ChuyenDoi::str_to_int(num_electric_before));
            do
            {
                xoa(4, vt + 2, 40);
                xoa(4, vt + 3, 40);
                gotoXY(4, vt + 2);
                cout << "Num Electric After: ";
                getline(cin, num_electric_after);
                if (num_electric_after.size())
                {
                    if (ChuyenDoi::str_to_int(num_electric_after) < obj1.get_num_electric_before())
                    {
                        gotoXY(4, vt + 3);
                        cout << "Electric After is inValid. Try Again." << endl;
                        getch();
                    }
                    else
                    {
                        obj1.set_num_electric_after(ChuyenDoi::str_to_int(num_electric_after));
                    }
                }
                else
                {
                    break;
                }
            } while (ChuyenDoi::str_to_int(num_electric_after) < obj1.get_num_electric_before());
            gotoXY(4, vt + 3);
            cout << "Num Water Before: ";
            getline(cin, num_water_before);
            if (num_water_before.size())
                obj1.set_num_water_before(ChuyenDoi::str_to_int(num_water_before));
            do
            {
                xoa(4, vt + 4, 40);
                xoa(4, vt + 5, 40);
                gotoXY(4, vt + 4);
                cout << "Num Water After: ";
                getline(cin, num_water_after);
                if (num_water_after.size())
                {
                    if (ChuyenDoi::str_to_int(num_water_after) < obj1.get_num_water_before())
                    {
                        gotoXY(4, vt + 5);
                        cout << "Water After is inValid. Try Again." << endl;
                        getch();
                    }
                    else
                    {
                        obj1.set_num_water_after(ChuyenDoi::str_to_int(num_water_after));
                    }
                }
                else
                {
                    break;
                }
            } while (ChuyenDoi::str_to_int(num_water_after) < obj1.get_num_water_before());
            gotoXY(4, vt + 5);
            cout << "Payment Date(yy-mm-dd): ";
            getline(cin, date);
            if (date.size())
                obj1.set_date(ThoiGian::Split(date));
            str = Union(obj1);
            L[i] = str;
        }
    }

    write_File(L);
}
void DienNuoc::Pay_dien_nuoc(DienNuoc &obj1, int vt)
{
    bool ok = false;
    List<string> L;
    ifstream inputFile;
    inputFile.open("DienNuoc.txt");
    string str, num_electric_before, num_electric_after, num_water_before, num_water_after, status;
    while (getline(inputFile, str))
    {
        if (str.size())
            L.push_back(str);
    }
    int size = L.getSize();
    DienNuoc obj;
    ThoiGian dt;
    for (int i = 0; i < size; i++)
    {
        obj = Split(L[i]);
        if (obj.get_dien_nuoc_id() == obj1.get_dien_nuoc_id())
        {
            if (obj1.get_num_electric_after() == 0 && obj1.get_num_water_after() == 0)
            {
                do
                {
                    gotoXY(4, vt + 1);
                    cout << "Num Electric After: ";
                    getline(cin, num_electric_after);
                } while (ChuyenDoi::str_to_int(num_electric_after) <= obj1.get_num_electric_before() ||ChuyenDoi::str_to_int(num_electric_after) == 0);
                obj1.set_num_electric_after(ChuyenDoi::str_to_int(num_electric_after));
                do
                {
                    gotoXY(4, vt + 2);
                    cout << "Num Water After: ";
                    getline(cin, num_water_after);
                } while (ChuyenDoi::str_to_int(num_water_after) <= obj1.get_num_water_before() ||ChuyenDoi::str_to_int(num_water_after) == 0);
                obj1.set_num_water_after(ChuyenDoi::str_to_int(num_water_after));
                str = Union(obj1);
                L[i] = str;
                write_File(L);
            start:
                gotoXY(4, vt + 3);
                cout << "Electric Bill: " << (obj1.get_num_electric_after() - obj1.get_num_electric_before()) * obj1.get_cost_electric() << endl;
                gotoXY(4, vt + 4);
                cout << "Water Bill: " << (obj1.get_num_water_after() - obj1.get_num_water_before()) * obj1.get_cost_water() << endl;
                gotoXY(4, vt + 5);
                cout << "Total: " << (((obj1.get_num_electric_after() - obj1.get_num_electric_before()) * obj1.get_cost_electric()) + ((obj1.get_num_water_after() - obj1.get_num_water_before()) * obj1.get_cost_water())) << endl;
                gotoXY(4, vt + 6);
                cout << "Do you want to pay?(Yes/No): ";
                getline(cin, status);
                obj1.set_status(ChuyenDoi::str_to_bool(status));
                if (obj1.get_status())
                {
                    obj1.set_status(true);
                    obj1.set_date(ThoiGian(dt.get_years(), dt.get_months(), dt.get_days()));
                    L[i] = Union(obj1);
                    write_File(L);
                    DienNuoc dn = Split(L[i]);
                    dn.set_dien_nuoc_id(ChuyenDoi::CreateID("DienNuoc.txt"));
                    (obj1.get_date().get_months() == 12) ? (dn.set_date(ThoiGian(obj1.get_date().get_years() + 1, (obj1.get_date().get_months()) % 12 + 1, 0))) : (dn.set_date(ThoiGian(obj1.get_date().get_years(), obj1.get_date().get_months() + 1, 0)));
                    dn.set_num_electric_before(obj1.get_num_electric_after());
                    dn.set_num_water_before(obj1.get_num_water_after());
                    dn.set_num_electric_after(0);
                    dn.set_num_water_after(0);
                    dn.set_status(false);
                    dn.add_dien_nuoc();
                    xoa(4,vt+6,100);
                    gotoXY(4, vt + 6);
                    cout << "Payment success!!!" << endl;
                    getch();
                    break;
                }
            }
            else if (obj1.get_num_electric_after() != 0 && obj1.get_num_water_after() != 0)
                goto start;
        }
    }
}

void DienNuoc::delete_dien_nuoc(string dien_nuoc_id)
{
    List<string> L;
    ifstream inputFile;
    inputFile.open("DienNuoc.txt");
    string str;
    while (getline(inputFile, str))
    {
        L.push_back(str);
    }
    int size = L.getSize();

    for (int i = 0; i < size; i++)
    {
        DienNuoc obj = Split(L[i]);
        if (obj.get_dien_nuoc_id() == dien_nuoc_id)
        {
            continue;
        }
        L.push_back(str);
    }
    write_File(L);
}
void DienNuoc::display(List<DienNuoc> &L, int k)
{
    ifstream inputFile;
    inputFile.open("DienNuoc.txt");
    string str;
    DienNuoc obj;
    List<Phong> room;
    ThoiGian time;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            obj = Split(str);
            Phong::find_idroom(obj.get_room_id(), room);
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

void DienNuoc::delete_by_room(string room_id)
{
    ifstream inputFile;
    inputFile.open("DienNuoc.txt");
    string str;
    List<string> L;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            DienNuoc obj = DienNuoc::Split(str);
            if (ChuyenDoi::Tolower(obj.get_room_id()) !=ChuyenDoi::Tolower(room_id))
            {
                L.push_back(str);
            }
        }
    }
    write_File(L);
}
