#include "dien_nuoc.h"
dien_nuoc::dien_nuoc(string dien_nuoc_id,string room_id, int num_electric_before, int num_electric_after, int num_water_before,
                     int num_water_after, int cost_water, int cost_electric, Datetime time, bool status)
    : dien_nuoc_id(dien_nuoc_id), room_id (room_id), num_electric_before(num_electric_before), num_electric_after(num_electric_after), num_water_before(num_water_before),
      num_water_after(num_water_after), cost_water(cost_water), cost_electric(cost_electric),date(time),status(status) {}

dien_nuoc::~dien_nuoc()
{
}
string dien_nuoc::get_dien_nuoc_id() const
{
    return dien_nuoc_id;
}
string dien_nuoc::get_room_id() const
{
    return room_id;
}
int dien_nuoc::get_num_electric_before() const
{
    return num_electric_before;
}
int dien_nuoc::get_num_electric_after() const
{
    return num_electric_after;
}
int dien_nuoc::get_num_water_before() const
{
    return num_water_before;
}
int dien_nuoc::get_num_water_after() const
{
    return num_water_after;
}
int dien_nuoc::get_cost_water() const
{
    return cost_water;
}
int dien_nuoc::get_cost_electric() const
{
    return cost_electric;
}
Datetime dien_nuoc::get_date() const
{
    return this->date;
}
bool dien_nuoc::get_status() const
{
    return status;
}

void dien_nuoc::set_dien_nuoc_id(string dien_nuoc_id)
{
    this->dien_nuoc_id = dien_nuoc_id;
}
void dien_nuoc::set_room_id(string room_id)
{
    this->room_id = room_id;
}
void dien_nuoc::set_num_electric_before(int num_electric_before)
{
    this->num_electric_before = num_electric_before;
}
void dien_nuoc::set_num_electric_after(int num_electric_after)
{
    this->num_electric_after = num_electric_after;
}
void dien_nuoc::set_num_water_before(int num_water_before)
{
    this->num_water_before = num_water_before;
}
void dien_nuoc::set_num_water_after(int num_water_after)
{
    this->num_water_after = num_water_after;
}
void dien_nuoc::set_cost_water(int cost_water)
{
    this->cost_water = cost_water;
}
void dien_nuoc::set_cost_electric(int cost_electric)
{
    this->cost_electric = cost_electric;
}
void dien_nuoc::set_date(Datetime time)
{
    this->date = time;
}
void dien_nuoc::set_status(bool status)
{
    this->status = status;
}
istream &operator>>(istream &i, dien_nuoc &obj)
{
    string date;
    // cout << "Dien_Nuoc_ID: ";
    // getline(i, obj.dien_nuoc_id);
    // cout << "Room_ID: ";
    // getline(i, obj.room_id);
    Room room;
    cin.ignore();
    do
    {
        cout << "Enter RoomID: ";
        getline(i, obj.room_id);
        room = Room::find_room(obj.room_id);
        if (room.getRoomID() != obj.room_id)
        {
            cout << "Room Not Found.Try Again!" << endl;
        }
    } while (room.getRoomID() != obj.room_id || obj.room_id.size() == 0);
    cout << "Num Of Electric Before: ";
    i >> obj.num_electric_before;
    cout << "Num Of Electric After: ";
    i >> obj.num_electric_after;
    cout << "Num Of Water Before: ";
    i >> obj.num_water_before;
    cout << "Num Of Water After: ";
    i >> obj.num_water_after;
    cout << "Cost Of Water: ";
    i >> obj.cost_water;
    cout << "Cost Of Electric: ";
    i >> obj.cost_electric;
    cin.ignore();
    cout << "Date(yy-mm-dd): ";
    getline(cin, date);
    obj.date = Datetime::Split(date);
    // cout << obj.date;
    cout << "Status: ";
    string status;
    i >> status;
    obj.status = Convert::str_to_bool(status);
    return i;
}
ostream &operator<<(ostream &o, const dien_nuoc &obj)
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
    o <<(obj.status ? "Yes" : "No") << endl;
    return o;
}

void dien_nuoc::write_File(List<string> &L) // xuất dữ liệu ra file
{
    ofstream inputFile;
    inputFile.open("dien_nuoc.txt", std::ios::out | std::ios::trunc);
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
        cout << "Error Openning File dien_nuoc.txt" << endl;
    }
}
dien_nuoc dien_nuoc::Split(string str) // hàm tách chuổi
{
    string dien_nuoc_id,room_id, date;
    int num_electric_before, num_electric_after, num_water_before, num_water_after, cost_water, cost_electric;
    Datetime time;
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
                dien_nuoc_id = str.substr(begin, end-begin);
            }
            else if (id == 2)
            {
                room_id = str.substr(begin, end - begin);
            }
            else if (id == 3)
            {
                num_electric_before = Convert::str_to_int(str.substr(begin, end - begin));
            }
            else if (id == 4)
            {
                num_electric_after = Convert::str_to_int(str.substr(begin, end - begin));
            }
            else if (id == 5)
            {
                num_water_before = Convert::str_to_int(str.substr(begin, end - begin));
            }
            else if (id == 6)
            {
                num_water_after = Convert::str_to_int(str.substr(begin, end - begin));
            }
            else if (id == 7)
            {
                cost_water = Convert::str_to_int(str.substr(begin, end - begin));
            }
            else if (id == 8)
            {
                cost_electric = Convert::str_to_int(str.substr(begin, end - begin));
            }
            else if (id == 9)
            {
                date = str.substr(begin, end - begin);
                time = Datetime::Split(date);
            }
            else if (id == 10)
            {
                status = Convert::str_to_bool(str.substr(begin, end - begin));
            }
            ++id;
            begin = end + 1;
        }
        end++;
    }
    return dien_nuoc(dien_nuoc_id,room_id, num_electric_before, num_electric_after, num_water_before, num_water_after, cost_water, cost_electric,time, status);
}
string dien_nuoc::Union(dien_nuoc &obj) // hàm gộp chuổi
{
    string str = obj.dien_nuoc_id + "," + obj.room_id + "," + Convert::int_to_str(obj.num_electric_before) + "," + Convert::int_to_str(obj.num_electric_after) + "," + Convert::int_to_str(obj.num_water_before) + "," + Convert::int_to_str(obj.num_water_after) + "," + Convert::int_to_str(obj.cost_water) + "," + Convert::int_to_str(obj.cost_electric) + "," + Datetime::Union(obj.date) + "," + Convert::bool_to_str(obj.status);
    return str;
}

int dien_nuoc::getNewCostWater()
{
    ifstream inputFile;
    inputFile.open("costWater.txt");
    int cost_water;
    inputFile >> cost_water;
    return cost_water;
}
int dien_nuoc::getNewCostElectric()
{
    ifstream inputFile;
    inputFile.open("costElectric.txt");
    int cost_electric;
    inputFile >> cost_electric;
    return cost_electric;
}

void dien_nuoc::updateCostElectric(int newCostElectric)
{
    ofstream outputFile;
    outputFile.open("costElectric.txt", std::ios::out | std::ios::trunc);
    outputFile << newCostElectric;
}
void dien_nuoc::updateCostWater(int newCostWater)
{
    ofstream outputFile;
    outputFile.open("costWater.txt", std::ios::out | std::ios::trunc);
    outputFile << newCostWater;
}
void dien_nuoc::add_dien_nuoc()
{   
    List<string> L;
    string str, dien_nuoc_id, num_electric_before, num_electric_after, num_water_before, num_water_after, cost_water, cost_electric, date, status;
    ifstream inputFile;
    inputFile.open("dien_nuoc.txt");
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

void dien_nuoc::display(List<dien_nuoc>&L)
{
    ifstream inputFile;
    inputFile.open("dien_nuoc.txt");
    string str;
    dien_nuoc dn;
    while (getline(inputFile, str))
    {      
        if (str.size()) {

            dn = Split(str);
            L.push_back(dn);
        }

        
    }
}
bool dien_nuoc::find_room(string room_id) 
{
    ifstream inputFile;
    inputFile.open("dien_nuoc.txt");
    string str;
    int cnt = 0;
    while (getline(inputFile, str))
    {
        if(str.size())
        {
            dien_nuoc obj = dien_nuoc::Split(str);
            if (obj.get_room_id() == room_id)
            {
                ++cnt;
                cout << obj << endl;
            }
        }
    }
    if (cnt == 0) return false;
        return true;
}
dien_nuoc dien_nuoc::find_nearest_dien_nuoc(string room_id)
{
    ifstream inputFile;
    inputFile.open("dien_nuoc.txt");
    string str;
    string max_id = "";
    dien_nuoc ans;
    while (getline(inputFile, str))
    {
        dien_nuoc obj = Split(str);
        if (obj.get_room_id() == room_id && obj.get_dien_nuoc_id() > max_id)
        {
            max_id = obj.get_dien_nuoc_id();
            ans = obj;
        }
    }
    return ans;
}
string dien_nuoc::find_max_dien_nuoc_id()
{
    ifstream inputFile;
    inputFile.open("dien_nuoc.txt");
    string str;
    string max_id = "";
    while (getline(inputFile, str))
    {
        dien_nuoc obj = Split(str);
        if (obj.get_dien_nuoc_id() > max_id)
        {
            max_id = obj.get_dien_nuoc_id();
        }
    }
    return max_id;
}
dien_nuoc dien_nuoc::find_dien_nuoc_id(string dien_nuoc_id)
{
    ifstream inputFile;
    inputFile.open("dien_nuoc.txt");
    string str;
    dien_nuoc obj;
    while (getline(inputFile, str))
    {
        obj = Split(str);
        if (dien_nuoc_id == obj.dien_nuoc_id)
        {
            return obj;
        }
    }
    return obj;
}
bool dien_nuoc::find_dien_nuoc(List<dien_nuoc>&L)
{
    string room_id,dien_nuoc_id,date;
    Datetime time;
    cin.ignore();
    cout << "Enter Room ID: ";
    getline(cin, room_id);
    cout << "Enter Electric Water ID: ";
    getline(cin, dien_nuoc_id);
    cout << "Enter Payment Date(yy-mm-dd): ";
    getline(cin, date);
    ifstream inputFile;
    inputFile.open("dien_nuoc.txt");
    string str, s, subs;
    int cnt = 0;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            dien_nuoc obj = dien_nuoc::Split(str);
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
                s = Convert::Tolower(obj.get_room_id());
                subs = Convert::Tolower(room_id);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (date.size() != 0)
            {
                time = Datetime::Split(date);
                if (time.get_years() != 0) {
                    if (time.get_years() != obj.get_date().get_years())
                    {
                        continue;
                    }
                }
                if (time.get_months() != 0) {
                    if (time.get_months() != obj.get_date().get_months())
                    {
                        continue;
                    }
                }
                if (time.get_days() != 0) {
                    if (time.get_days() != obj.get_date().get_days())
                    {
                        continue;
                    }
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
void dien_nuoc::update_dien_nuoc(dien_nuoc& obj1)
{
    bool ok = false;
    List<string> L;
    ifstream inputFile;
    inputFile.open("dien_nuoc.txt");
    string str, num_electric_before, num_electric_after, num_water_before, num_water_after, cost_water, cost_electric, date, status;
    while (getline(inputFile, str))
    {
        if (str.size()) L.push_back(str);
    }
    int size = L.getSize();
    dien_nuoc obj;
    for (int i = 0; i < size; i++)
    {
       obj = Split(L[i]);
        if (obj.get_dien_nuoc_id() == obj1.get_dien_nuoc_id())
        {
            cout << "num_electric_before: ";
            cin.ignore();
            getline(cin,num_electric_before);
            if (num_electric_before.size()) obj1.set_num_electric_before(Convert::str_to_int(num_electric_before));
            cout << "num_electric_after: ";
            getline(cin, num_electric_after);
            if(num_electric_after.size()) obj1.set_num_electric_after(Convert::str_to_int(num_electric_after));
            cout << "num_water_before: ";
            getline(cin, num_water_before);
            if(num_water_before.size()) obj1.set_num_water_before(Convert::str_to_int(num_water_before));
            cout << "num_water_after: ";
            getline(cin, num_water_after);
            if(num_water_after.size()) obj1.set_num_water_after(Convert::str_to_int(num_water_after));
            cout << "cost_water: ";
            getline(cin, cost_water);
            if(cost_water.size()) obj1.set_cost_water(Convert::str_to_int(cost_water));
            cout << "cost_electric: ";
            getline(cin, cost_electric);
            if(cost_electric.size()) obj1.set_cost_electric(Convert::str_to_int(cost_electric));
            cout << "date(yy-mm-dd): ";
            getline(cin, date);
            if(date.size()) obj1.set_date(Datetime::Split(date));
            cout << "status: ";
            getline(cin,status);
            if(status.size()) obj1.set_status(Convert::str_to_bool(status));
            str = Union(obj1);
            L[i] = str;
        }
    }
    write_File(L);
}
void dien_nuoc::Pay_dien_nuoc(dien_nuoc& obj1)
{
    bool ok = false;
    List<string> L;
    ifstream inputFile;
    inputFile.open("dien_nuoc.txt");
    string str, num_electric_before, num_electric_after, num_water_before, num_water_after, status;
    while (getline(inputFile, str))
    {
        if (str.size()) L.push_back(str);
    }
    int size = L.getSize();
    dien_nuoc obj;
    Datetime dt;
    for (int i = 0; i < size; i++)
    {
       obj = Split(L[i]);
        if (obj.get_dien_nuoc_id() == obj1.get_dien_nuoc_id())
        {
            // if(obj.get_num_electric_after() == 0 && obj.get_num_water_after() == 0){
            cout << "num_electric_after: ";
            cin.ignore();
            getline(cin,num_electric_after); obj1.set_num_electric_after(Convert::str_to_int(num_electric_after));
            cout << "num_water_after: ";
            getline(cin, num_water_after); obj1.set_num_water_after(Convert::str_to_int(num_water_after));
            str = Union(obj1);
            L[i] = str;
            write_File(L);
            // start:
            cout << "Electric Bill: " << (obj1.get_num_electric_after() - obj1.get_num_electric_before())*obj1.get_cost_electric() << endl;
            cout << "Water Bill: " << (obj1.get_num_water_after() - obj1.get_num_water_before())*obj1.get_cost_water() << endl;
            cout << "Do you want to pay?(Yes/No): ";
            getline(cin,status);
            obj1.set_status(Convert::str_to_bool(status));
            if(obj1.get_status())
            {
                obj1.set_status(true);
                obj1.set_date(Datetime(dt.get_years(), dt.get_months(), dt.get_days()));
                L[i] = Union(obj1);
                write_File(L);
                dien_nuoc dn = Split(L[i]);
                    dn.set_dien_nuoc_id(Convert::CreateID("dien_nuoc.txt"));
                    dn.set_date(Datetime(0,0,0));
                    dn.set_num_electric_before(obj1.get_num_electric_after());
                    dn.set_num_water_before(obj1.get_num_water_after());
                    dn.set_num_electric_after(0);
                    dn.set_num_water_after(0);
                    dn.set_status(false);
                    dn.add_dien_nuoc();
                cout << "Payment success!!!" << endl;
                // break;
            
            }
            // else if (obj.get_num_electric_after() != 0 && obj.get_num_water_after() != 0){
            //     goto start;
            // }
        }
    }  
}
void dien_nuoc::delete_dien_nuoc(string dien_nuoc_id)
{
    List<string> L;
    ifstream inputFile;
    inputFile.open("dien_nuoc.txt");
    string str;
    while (getline(inputFile, str))
    {
        L.push_back(str);
    }
    int size = L.getSize();

    for (int i = 0; i < size; i++)
    {
        dien_nuoc obj = Split(L[i]);
        if (obj.get_dien_nuoc_id() == dien_nuoc_id)
        {
            L.erase(i);
            i--;
        }
    }
    write_File(L);
}
void dien_nuoc::view_Paid_room(List<dien_nuoc>&L)
{
    
    ifstream inputFile;
    inputFile.open("dien_nuoc.txt");
    string str;
    while (getline(inputFile, str))
    {   
        if (str.size()) {
        dien_nuoc obj = dien_nuoc::Split(str);
        if (obj.get_status() && Room::find_room_with_status_true(obj.get_room_id()))
        {
            L.push_back(obj);
        }
        }
    }
}
void dien_nuoc::view_unpaid_room(List<dien_nuoc>&L)
{
    ifstream inputFile;
    inputFile.open("dien_nuoc.txt");
    string str;
    while (getline(inputFile, str))
    {   
        if (str.size()) {
        dien_nuoc obj = dien_nuoc::Split(str);
        if (!obj.get_status() && Room::find_room_with_status_true(obj.get_room_id()))
        {
            L.push_back(obj);
        }
        }
    }
}

