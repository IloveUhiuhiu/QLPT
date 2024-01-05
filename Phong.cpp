// Room.cpp
#include "Phong.h"
#include "NguoiThue.h"

// Constructor with initialization
Phong::Phong(string room_id, string kind_of, int cost, bool occupied)
    : room_id(room_id), kind_of(kind_of), cost(cost), occupied(occupied) {}

// Destructor
Phong::~Phong() {}

// Getter and Setter
string Phong::getRoomID() const
{
    return room_id;
}

void Phong::setRoomID(string room_id)
{
    this->room_id = room_id;
}

string Phong::getKindOf() const
{
    return kind_of;
}

void Phong::setKindOf(string kind_of)
{
    this->kind_of = kind_of;
}

int Phong::getCost() const
{
    return cost;
}

void Phong::setCost(int cost)
{
    this->cost = cost;
}

bool Phong::isOccupied() const
{
    return occupied;
}

void Phong::setOccupied(bool occupied)
{
    this->occupied = occupied;
}

void Phong::delete_room(string room_id, int k)
{
    List<string> L;
    ifstream inputFile;
    inputFile.open("Phong.txt");
    string str;
    while (getline(inputFile, str))
    {
        Phong obj = Split(str);
        if (ChuyenDoi::Tolower(obj.getRoomID()) != ChuyenDoi::Tolower(room_id))
        {
            L.push_back(str);
        }
    }
    if (k == 0)
    {
        DienNuoc::delete_by_room(room_id);
        HoaDon::delete_by_room(room_id);
    }
    write_File(L);
}

Phong Phong::Split(string str)
{
    string room_id, kind_of;
    int cost;
    bool occupied;
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
                kind_of = str.substr(begin, end - begin);
            }
            else if (id == 3)
            {
                cost = ChuyenDoi::str_to_int(str.substr(begin, end - begin));
            }
            else
            {
                occupied = ChuyenDoi::str_to_bool(str.substr(begin, end - begin));
            }

            ++id;
            begin = end + 1;
        }
        end++;
    }
    return Phong(room_id, kind_of, cost, occupied);
}
string Phong::Union(Phong &obj)
{
    string str = obj.room_id + "," + obj.kind_of + "," + ChuyenDoi::int_to_str(obj.cost) + "," + ChuyenDoi::bool_to_str(obj.occupied);
    return str;
}

void Phong::write_File(List<string> &L)
{
    ofstream inputFile;
    inputFile.open("Phong.txt", std::ios::out | std::ios::trunc);
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
        cout << "Error Opening File Phong.txt" << endl;
    }
}

void Phong::add_room(int k)
{
    ifstream inputFile;
    inputFile.open("Phong.txt");
    string str, room_id;
    List<string> L;
    bool add = true;
    while (getline(inputFile, str))
    {
        int end = 0;
        for (auto x : str)
        {
            if (x == ',')
            {
                room_id = str.substr(0, end);
                break;
            }
            end++;
        }
        if (room_id == this->room_id)
        {
            add = false;
        }
        L.push_back(str);
    }
    if (add)
    {
        str = Phong::Union(*this);
        L.push_back(str);
    }
    write_File(L);
    if (k == 1)
    {
        ThoiGian dt;
        DienNuoc dn;
        dn.set_room_id(this->room_id);
        dn.set_dien_nuoc_id(ChuyenDoi::CreateID("DienNuoc.txt"));
        dn.set_cost_water(DienNuoc::getNewCostWater());
        dn.set_cost_electric(DienNuoc::getNewCostElectric());
        dn.set_date(ThoiGian(dt.get_years(), dt.get_months(), 0));
        dn.add_dien_nuoc();
    }
}
void Phong::find_idroom(string room_id, List<Phong> &L)
{
    ifstream inputFile;
    inputFile.open("Phong.txt");
    string str;
    Phong obj;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            obj = Phong::Split(str);
            if (ChuyenDoi::Tolower(obj.getRoomID()) == ChuyenDoi::Tolower(room_id))
            {
                L.push_back(obj);
            }
        }
    }
}
istream &operator>>(istream &i, Phong &room)
{
    List<Phong> L;
    cin.ignore();
    do
    {
        L.clear();
        xoa(4, 5, 40);
        xoa(4, 6, 40);
        gotoXY(4, 5);
        cout << "Enter Room ID: ";
        getline(i, room.room_id);
        Phong::find_idroom(room.room_id, L);

        if (L.getSize())
        {
            gotoXY(4, 6);
            cout << "ID Already Exists.Try Again!" << endl;
            getch();
        }
    } while (L.getSize());
    do
    {
        xoa(4, 6, 40);
        xoa(4, 7, 40);
        gotoXY(4, 6);
        cout << "Type (A, B, or C): ";
        i >> room.kind_of;
        if (room.kind_of != "A" && room.kind_of != "B" && room.kind_of != "C")
        {
            gotoXY(4, 7);
            cout << "Incorrect Room Type.Try again.";
            getch();
        }
    } while (room.kind_of != "A" && room.kind_of != "B" && room.kind_of != "C");

    gotoXY(4, 7);
    cout << "Cost: ";
    i >> room.cost;

    room.occupied = false;
    return i;
}

ostream &operator<<(ostream &o, const Phong &room)
{
    o << "RoomID: " << room.room_id << endl;
    o << "Kind of: " << room.kind_of << endl;
    o << "Cost: " << room.cost << endl;
    o << "Occupied: " << (room.occupied ? "Yes" : "No") << endl;
    return o;
}

void Phong::find_room(List<Phong> &roomList)
{
    string searchRoomID, searchKindOf, costInput, status;
    gotoXY(4, 5);
    cout << "Enter RoomID : ";
    getline(cin, searchRoomID);

    gotoXY(4, 6);
    cout << "Enter Type (A, B, or C) : ";
    getline(cin, searchKindOf);

    gotoXY(4, 7);
    cout << "Enter Cost: ";
    getline(cin, costInput);

    gotoXY(4, 8);
    cout << "Enter Status: ";
    getline(cin, status);
    string s, subs;
    int cnt = 0;

    ifstream inputFile;
    inputFile.open("Phong.txt");
    string str;
    Phong obj;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            obj = Phong::Split(str);
            if (searchRoomID.size())
            {
                subs = ChuyenDoi::Tolower(obj.getRoomID());
                s = ChuyenDoi::Tolower(searchRoomID);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (searchKindOf.size())
            {
                subs = ChuyenDoi::Tolower(obj.getKindOf());
                s = ChuyenDoi::Tolower(searchKindOf);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (costInput.size())
            {
                bool ok = true;
                for (auto x : costInput)
                    if (x < '0' || x > '9')
                        ok = false;
                if (!ok)
                    continue;

                int cost = ChuyenDoi::str_to_int(costInput);
                if (cost < obj.getCost())
                {
                    continue;
                }
            }
            if (status.size())
            {
                s = ChuyenDoi::Tolower(status);
                subs = (obj.isOccupied() ? "rent" : "empty");
                if (s != subs)
                    continue;
            }
            roomList.push_back(obj);
        }
    }

    inputFile.close();
}
int Phong::NumOfEmptyRoom()
{
    ifstream inputFile;
    inputFile.open("Phong.txt");
    string str;
    Phong obj;
    int ans = 0;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            obj = Phong::Split(str);
            if (!obj.isOccupied())
            {
                ans++;
            }
        }
    }
    inputFile.close();
    return ans;
}

void Phong::display(List<Phong> &L, int k)
{
    ifstream inputFile;
    inputFile.open("Phong.txt");
    string str;
    Phong room;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            room = Phong::Split(str);
            if (k == 0)
            {
                L.push_back(room);
            }
            else if (k == 1)
            {
                if (room.isOccupied())
                {
                    L.push_back(room);
                }
            }
            else
            {
                if (!room.isOccupied())
                {
                    L.push_back(room);
                }
            }
        }
    }
    inputFile.close();
}
int Phong::NumOfRoom()
{
    ifstream inputFile;
    inputFile.open("Phong.txt");
    string str;
    int ans = 0;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            ans++;
        }
    }
    inputFile.close();
    return ans;
}

void Phong::update_room(Phong &obj1, int vt)
{
    List<string> L;
    ifstream inputFile;
    inputFile.open("Phong.txt");
    string str, room_id, kind_of, cost, occupied;
    while (getline(inputFile, str))
    {
        if (str.size())
            L.push_back(str);
    }
    int size = L.getSize();
    Phong obj;
    for (int i = 0; i < size; i++)
    {
        obj = Split(L[i]);
        if (obj.getRoomID() == obj1.getRoomID())
        {
            gotoXY(4, vt + 1);
            cout << "Type Room: ";
            getline(cin, kind_of);
            if (kind_of.size())
                obj1.setKindOf(kind_of);
            gotoXY(4, vt + 2);
            cout << "Cost Of Room: ";
            getline(cin, cost);
            if (cost.size())
                obj1.setCost(ChuyenDoi::str_to_int(cost));
            str = Union(obj1);
            L[i] = str;
        }
    }
    write_File(L);
}

void Phong::cancel_room(string room_id)
{
    List<string> L;
    ifstream inputFile;
    inputFile.open("Phong.txt");
    string str;
    while (getline(inputFile, str))
    {
        Phong obj = Split(str);

        // Nếu phòng có trạng thái true và trùng với room_id, xóa thông tin người dùng và đặt trạng thái phòng về false
        if (obj.getRoomID() == room_id && obj.isOccupied())
        {
            obj.setOccupied(false);
        }

        L.push_back(Union(obj));
    }

    inputFile.close();

    // Ghi danh sách đã được cập nhật trở lại vào "Phong.txt"
    write_File(L);

    // Mở file "customer.txt" để xóa thông tin của người dùng
    List<string> customerList;
    ifstream customerFile;
    customerFile.open("NguoiThue.txt");
    string customerStr;
    while (getline(customerFile, customerStr))
    {
        if (customerStr.size())
        {
            NguoiThue obj = NguoiThue::Split(customerStr);

            // Nếu người dùng có room_id tương ứng, không thêm thông tin người dùng này vào danh sách (để xóa nó)
            if (obj.get_room_id() != room_id)
            {
                customerList.push_back(customerStr);
            }
        }
    }

    customerFile.close();

    // Ghi danh sách đã được cập nhật trở lại vào "customer.txt"
    NguoiThue::write_File(customerList);
}

void Phong::change_room(Phong roomBefore, Phong roomAfter)
{
    List<string> L;
    Phong room;
    List<Phong> roomList;
    DienNuoc dnBefore, dnAfter, obj;
    List<DienNuoc> dnList;
    List<HoaDon> hdList;
    HoaDon hdBefore, hdAfter, obj1;
    ThoiGian dt;
    string str, num_electric_before, num_electric_after, num_water_before, num_water_after, status, ID_room_before, ID_room_after;
    int size, bonus, cnt = 0;

    ID_room_before = roomBefore.getRoomID();
    ID_room_after = roomAfter.getRoomID();
    L.clear();
    // ĐIện Nước
    ifstream inputFile;
    inputFile.open("DienNuoc.txt");

    while (getline(inputFile, str))
    {
        if (str.size())
            L.push_back(str);
    }

    size = L.getSize();
    // láy thông tin điện nước trước và sau
    for (int i = 0; i < size; i++)
    {
        obj = DienNuoc::Split(L[i]);
        if (ID_room_before == obj.get_room_id())
        {

            if (obj.get_num_electric_after() == 0 && obj.get_num_water_after() == 0)
            {
                dnBefore = obj;
            }
        }
        if (ID_room_after == obj.get_room_id())
        {
            if (obj.get_num_electric_after() == 0 && obj.get_num_water_after() == 0)
            {
                dnAfter = obj;
            }
        }
    }
    // nhập số nước số didenj sau và kiểm tra
    do
    {
        xoa(4, 20, 100);
        xoa(4, 21, 100);
        gotoXY(4, 20);
        cout << "Num Electric After: ";
        getline(cin, num_electric_after);
        if (ChuyenDoi::str_to_int(num_electric_after) < dnBefore.get_num_electric_before())
        {
            gotoXY(4, 21);
            cout << "Electric After is inValid. Try Again." << endl;
        }
    } while (ChuyenDoi::str_to_int(num_electric_after) < dnBefore.get_num_electric_before());
    dnBefore.set_num_electric_after(ChuyenDoi::str_to_int(num_electric_after));

    do
    {
        xoa(4, 21, 100);
        xoa(4, 22, 100);
        gotoXY(4, 21);
        cout << "Num Water After : ";
        getline(cin, num_water_after);
        if (ChuyenDoi::str_to_int(num_water_after) < dnBefore.get_num_water_before())
        {
            gotoXY(4, 22);
            cout << "Water After is inValid. Try Again." << endl;
        }
    } while (ChuyenDoi::str_to_int(num_water_after) < dnBefore.get_num_water_before());
    // thay dổi điện nước trước
    dnBefore.set_num_water_after(ChuyenDoi::str_to_int(num_water_after));
    dnBefore.set_status(true);
    dnBefore.set_date(dt);
    dnBefore.add_dien_nuoc();

    // thay đổi điện nước sau
    // (dnAfter.get_date().get_months() == 12) ? (dnAfter.set_date(ThoiGian(dnAfter.get_date().get_years() + 1, (dnAfter.get_date().get_months()) % 12 + 1, 0))) : (dnAfter.set_date(ThoiGian(dnAfter.get_date().get_years(), dnAfter.get_date().get_months() + 1, 0)));
    dnAfter.set_num_electric_before(dnAfter.get_num_electric_before() - (dnBefore.get_num_electric_after() - dnBefore.get_num_electric_before()));
    dnAfter.set_num_water_before(dnAfter.get_num_water_before() - (dnBefore.get_num_water_after() - dnBefore.get_num_water_before()));
    dnAfter.add_dien_nuoc();

    // add ddienj nước mới
    dnBefore.set_dien_nuoc_id(ChuyenDoi::CreateID("DienNuoc.txt"));
    dnBefore.set_num_electric_before(ChuyenDoi::str_to_int(num_electric_after));
    dnBefore.set_num_water_before(ChuyenDoi::str_to_int(num_water_after));
    dnBefore.set_num_electric_after(0);
    dnBefore.set_num_water_after(0);
    dnBefore.set_status(false);
    (dnBefore.get_date().get_months() == 12) ? (dnBefore.set_date(ThoiGian(dnBefore.get_date().get_years() + 1, (dnBefore.get_date().get_months()) % 12 + 1, 0))) : (dnBefore.set_date(ThoiGian(dnBefore.get_date().get_years(), dnBefore.get_date().get_months() + 1, 0)));
    dnBefore.add_dien_nuoc();
    inputFile.close();

    /// Hóa Đơn

    inputFile.open("HoaDon.txt");
    L.clear();
    // láy thông tin Hóa dđơn trước và sau
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            obj1 = HoaDon::Split(str);
            if (obj1.get_room_id() == ID_room_before && obj1.get_date().get_days() == 0)
            {
                hdBefore = obj1;
                continue;
            }
            L.push_back(str);
        }
    }
    size = L.getSize();

    hdAfter.set_bill_id(ChuyenDoi::CreateID("HoaDon.txt"));
    hdAfter.set_room_id(ID_room_after);
    hdAfter.set_date(ThoiGian(dt.get_years(), dt.get_months(), 0));
    if (dt.is_mid_month())
    {
        bonus = hdBefore.get_total_cost();
    }
    else
    {
        bonus = hdBefore.get_total_cost() / 2;
    }
    hdAfter.set_total_cost(roomAfter.getCost() + bonus);
    L.push_back(HoaDon::Union(hdAfter));

    HoaDon::write_File(L);

    inputFile.close();

    // Người Thuê
    inputFile.open("NguoiThue.txt");
    L.clear();
    NguoiThue cs;
    while (getline(inputFile, str))
    {
        cs = NguoiThue::Split(str);

        if (cs.get_room_id() == ID_room_before)
        {
            cs.set_room_id(ID_room_after);
            str = NguoiThue::Union(cs);
        }
        L.push_back(str);
    }
    NguoiThue::write_File(L);
    inputFile.close();

    // Thay đổi trạng thái của phòng
    inputFile.open("Phong.txt");
    L.clear();
    while (getline(inputFile, str))
    {
        room = Phong::Split(str);
        if (room.room_id == ID_room_before)
        {
            room.setOccupied(false);
            str = Phong::Union(room);
        }
        else if (room.room_id == ID_room_after)
        {
            room.setOccupied(true);
            str = Phong::Union(room);
        }
        L.push_back(str);
    }
    Phong::write_File(L);
    inputFile.close();
}