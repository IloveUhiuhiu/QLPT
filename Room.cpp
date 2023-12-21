// Room.cpp
#include "Room.h"
#include "customer.h"

// Constructor with initialization
Room::Room(string room_id, string kind_of, int cost, bool occupied)
    : room_id(room_id), kind_of(kind_of), cost(cost), occupied(occupied) {}

// Destructor
Room::~Room() {}

// Getter and Setter
string Room::getRoomID() const {
    return room_id;
}

void Room::setRoomID(string room_id) {
    this->room_id = room_id;
}

string Room::getKindOf() const {
    return kind_of;
}

void Room::setKindOf(string kind_of) {
    this->kind_of = kind_of;
}

int Room::getCost() const {
    return cost;
}

void Room::setCost(int cost) {
    this->cost = cost;
}

bool Room::isOccupied() const {
    return occupied;
}

void Room::setOccupied(bool occupied) {
    this->occupied = occupied;
}


void Room::delete_room(string room_id,int k) 
{
    List<string> L;
    ifstream inputFile;
    inputFile.open("room.txt");
    string str;
    while (getline(inputFile, str))
    {   
        Room obj = Split(str);
        if (Convert::Tolower(obj.getRoomID()) != Convert::Tolower(room_id))
        {
            L.push_back(str);
        }
    }
    if ( k == 0) {
        dien_nuoc::delete_by_room(room_id);
        hoa_don::delete_by_room(room_id);
    }
    write_File(L);
}

Room Room::Split(string str)
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
                cost = Convert::str_to_int(str.substr(begin, end - begin));
            }
            else 
            {
                occupied = Convert::str_to_bool(str.substr(begin, end - begin));
            }
            
            ++id;
            begin = end + 1;
        }
        end++;
    }
    return Room(room_id,kind_of,cost,occupied);
}
string Room::Union(Room &obj)
{
    string str = obj.room_id + "," + obj.kind_of + "," + Convert::int_to_str(obj.cost) + "," + Convert::bool_to_str(obj.occupied);
    return str;
}

void Room::write_File(List<string> &L)
{
    ofstream inputFile;
    inputFile.open("room.txt", std::ios::out | std::ios::trunc);
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
        cout << "Error Opening File room.txt" << endl;
    }
}

void Room::add_room(int k) 
{
    ifstream inputFile;
    inputFile.open("room.txt");
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
        str = Room::Union(*this);
        L.push_back(str);
    }
    write_File(L);
    if (k == 1)
    {   
        Datetime dt;
        dien_nuoc dn;
        dn.set_room_id(this->room_id);
        dn.set_dien_nuoc_id(Convert::CreateID("dien_nuoc.txt"));
        dn.set_cost_water(dien_nuoc::getNewCostWater());
        dn.set_cost_electric(dien_nuoc::getNewCostElectric());
        dn.set_date(Datetime(dt.get_years(),dt.get_months(),0));
        dn.add_dien_nuoc();
    }

}
void Room::find_idroom(string room_id,List<Room>&L)
{
    ifstream inputFile;
    inputFile.open("room.txt");
    string str;
    Room obj;
    while (getline(inputFile, str))
    {   
        if (str.size()) {
            obj = Room::Split(str);
            if (Convert::Tolower(obj.getRoomID()) == Convert::Tolower(room_id))
            {
                L.push_back(obj);
            }
        }
    }
}
istream& operator>> (istream& i, Room& room)
{   
    List<Room> L;
    cin.ignore();
    do
    {   
        L.clear();
        xoa(4,5,40);
        xoa(4,6,40);
        gotoXY(4,5);cout << "Enter Room ID: ";
        getline(i, room.room_id);
        Room::find_idroom(room.room_id,L);
        
        if (L.getSize())
        {
            gotoXY(4,6);cout << "ID Already Exists.Try Again!" << endl;
            getch();
        }
    } while (L.getSize());
    do{ 
        xoa(4,6,40);
        xoa(4,7,40);
        gotoXY(4,6);cout << "Type (A, B, or C): ";
        i >> room.kind_of;
        if (room.kind_of != "A" && room.kind_of != "B" && room.kind_of != "C") {
            gotoXY(4,7); cout << "Incorrect Room Type.Try again.";
            getch();
        }
    } while (room.kind_of != "A" && room.kind_of != "B" && room.kind_of != "C");

    gotoXY(4,7);cout << "Cost: ";
    i >> room.cost;

    room.occupied = false;
    return i;
}

ostream& operator << (ostream& o,const Room& room)
{
    o << "RoomID: " << room.room_id << endl;
    o << "Kind of: " << room.kind_of << endl;
    o << "Cost: " << room.cost << endl;
    o << "Occupied: " << (room.occupied ? "Yes" : "No")  << endl;
    return o;
}

void Room::find_room(List<Room>&roomList)
{
    string searchRoomID, searchKindOf,costInput;
    gotoXY(4,5);cout << "Enter RoomID : ";
    getline(cin, searchRoomID);

    gotoXY(4,6);cout << "Enter Type (A, B, or C) : ";
    getline(cin, searchKindOf);

    gotoXY(4,7);cout << "Enter Cost: ";
    getline(cin, costInput);

    string s, subs;
    int cnt = 0;

    ifstream inputFile;
    inputFile.open("room.txt");
    string str;
    Room obj;
    while (getline(inputFile, str)) {
        if (str.size()) {
            obj = Room::Split(str);
            if (searchRoomID.size()) {
                subs = Convert::Tolower(obj.getRoomID());
                s = Convert::Tolower(searchRoomID);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (searchKindOf.size()) {
                subs = Convert::Tolower(obj.getKindOf());
                s = Convert::Tolower(searchKindOf);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            if (costInput.size()) {
                subs = Convert::Tolower(obj.getRoomID());
                s = Convert::Tolower(costInput);
                auto found = s.find(subs);
                if (found == std::string::npos)
                {
                    continue;
                }
            }
            roomList.push_back(obj);
        }
    }

    inputFile.close();

}

void Room::view_empty_room(List<Room>& L)
{
    ifstream inputFile;
    inputFile.open("room.txt");
    string str;
    Room obj;
    while (getline(inputFile, str))
    {   
        if (str.size()) {
            obj = Room::Split(str);
            if (!obj.isOccupied())
            {
                L.push_back(obj);
            }
        }
    }
    inputFile.close();
}
int Room::NumOfEmptyRoom()
{
    ifstream inputFile;
    inputFile.open("room.txt");
    string str;
    Room obj;
    int ans = 0;
    while (getline(inputFile, str))
    {   
        if (str.size()) {
            obj = Room::Split(str);
            if (!obj.isOccupied())
            {
                ans++;
            }
        }
    }
    inputFile.close();
    return ans;
}
void Room::view_rented_room(List<Room>& L)
{
    ifstream inputFile;
    inputFile.open("room.txt");
    string str;
    Room obj;
    while (getline(inputFile, str))
    {   
        if (str.size()) {
            obj = Room::Split(str);
            if (obj.isOccupied())
            {
                L.push_back(obj);
            }
        }
    }
    inputFile.close();
}

void Room::display(List<Room> &L)
{
    ifstream inputFile;
    inputFile.open("room.txt");
    string str;
    Room room;
    while (getline(inputFile, str))
    {   
        if (str.size()) {
            room = Room::Split(str);
            L.push_back(room);
        }
    }
    inputFile.close();
}
int Room::NumOfRoom()
{
    ifstream inputFile;
    inputFile.open("room.txt");
    string str;
    int ans = 0;
    while (getline(inputFile, str))
    {   
        if (str.size()) {
            ans++;
        }
    }
    inputFile.close();
    return ans;
}

void Room::update_room(Room &obj1,int vt)
{   
    List<string> L;
    ifstream inputFile;
    inputFile.open("room.txt");
    string str, room_id, kind_of, cost, occupied;
    while (getline(inputFile, str))
    {
        if (str.size())
            L.push_back(str);
    }
    int size = L.getSize();
    Room obj;
    for (int i = 0; i < size; i++)
    {
        obj = Split(L[i]);
        if (obj.getRoomID() == obj1.getRoomID())
        {   
            gotoXY(4,vt+1);cout << "Type Room: ";
            getline(cin, kind_of);
            if (kind_of.size())
                obj1.setKindOf(kind_of);
            gotoXY(4,vt+2);cout << "Cost Of Room: ";
            getline(cin, cost);
            if (cost.size())
                obj1.setCost(Convert::str_to_int(cost));
            gotoXY(4,vt+3);cout << "Status Of Room(Rent or Empty): ";
            getline(cin, occupied);
            if (occupied.size() && (occupied == "Rent" || occupied == "Empty"))
                obj1.setOccupied(("Rent")?true:false);
            str = Union(obj1);
            L[i] = str;
        }
    }
    write_File(L);
}


void Room::cancel_room(string room_id)
{
    List<string> L;
    ifstream inputFile;
    inputFile.open("room.txt");
    string str;
    while (getline(inputFile, str))
    {
        Room obj = Split(str);

        // Nếu phòng có trạng thái true và trùng với room_id, xóa thông tin người dùng và đặt trạng thái phòng về false
        if (obj.getRoomID() == room_id && obj.isOccupied())
        {
            obj.setOccupied(false);
        }

        L.push_back(Union(obj));
    }

    inputFile.close();

    // Ghi danh sách đã được cập nhật trở lại vào "room.txt"
    write_File(L);

      // Mở file "customer.txt" để xóa thông tin của người dùng
    List<string> customerList;
    ifstream customerFile;
    customerFile.open("customer.txt");
    string customerStr;
    while (getline(customerFile, customerStr))
    {   
        if (customerStr.size()) {
            customer obj = customer::Split(customerStr);

            // Nếu người dùng có room_id tương ứng, không thêm thông tin người dùng này vào danh sách (để xóa nó)
            if (obj.get_room_id() != room_id)
            {
                customerList.push_back(customerStr);
            }
        }
    }

    customerFile.close();

    // Ghi danh sách đã được cập nhật trở lại vào "customer.txt"
    customer::write_File(customerList);

}
bool Room::find_room_with_status_true(string room_id)
{
    ifstream inputFile;
    inputFile.open("room.txt");
    string str;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            Room obj = Room::Split(str);
            if (obj.getRoomID() == room_id && obj.isOccupied())
            {
                return true;
            }
        }
    }
    return false;
}


void Room::change_room()
{
    List<string> L;
    ifstream inputFile1,inputFile2,inputFile;
    inputFile.open("dien_nuoc.txt");
    Datetime dt;
    string str, num_electric_before, num_electric_after, num_water_before, num_water_after, status, ID_room_before, ID_room_after;
    while (getline(inputFile, str))
    {
        if (str.size())
            L.push_back(str);
    }
    cin.ignore();
    int size = L.getSize();
    dien_nuoc obj, dn, obj1;
    // nhap id phong truoc
    gotoXY(4,4);
    cout << "Enter ID Room Before: ";
    getline(cin, ID_room_before);
    if (ID_room_before.size() == 0) return;
    gotoXY(4,5);cout << "Enter ID Room After: ";
    getline(cin, ID_room_after);
    if (ID_room_after.size() == 0) return;
    for (int i = 0; i < size; i++)
    {
        obj = dien_nuoc::Split(L[i]);
        if (ID_room_before == obj.get_room_id())
        {   

            if (obj.get_num_electric_after() == 0 && obj.get_num_water_after() == 0)
            {   
                do
                {   xoa(4,6,40);
                    gotoXY(4,6);cout << "Num Electric After: ";
                    getline(cin, num_electric_after);
                } while (Convert::str_to_int(num_electric_after) <= obj.get_num_electric_before());
                obj.set_num_electric_after(Convert::str_to_int(num_electric_after));
                do
                {
                    xoa(4,7,40);
                    gotoXY(4,7);cout << "Num Water After: ";
                    getline(cin, num_water_after);
                } while (Convert::str_to_int(num_water_after) <= obj.get_num_water_before());
                obj.set_num_water_after(Convert::str_to_int(num_water_after));
                obj.set_status(true);
                obj.set_date(Datetime(dt.get_years(), dt.get_months(), dt.get_days()));
                // cout << obj << endl;
                dien_nuoc::delete_dien_nuoc(obj.get_dien_nuoc_id());
                obj.add_dien_nuoc();
                // L[i] = dien_nuoc::Union(obj);
                // // L[i] = str;
                // write_File(L);
                dn = dien_nuoc::Split(L[i]);
                dn.set_dien_nuoc_id(Convert::CreateID("dien_nuoc.txt"));
                (obj.get_date().get_months() == 12) ? (dn.set_date(Datetime(obj.get_date().get_years() + 1, (obj.get_date().get_months()) % 12 + 1, 0))) : (dn.set_date(Datetime(obj.get_date().get_years(), obj.get_date().get_months() + 1, 0)));
                dn.set_num_electric_before(obj.get_num_electric_after());
                dn.set_num_water_before(obj.get_num_water_after());
                dn.set_num_electric_after(0);
                dn.set_num_water_after(0);
                dn.set_status(false);
                dn.add_dien_nuoc();
                break;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        obj1 = dien_nuoc::Split(L[i]);
        if (ID_room_after == obj1.get_room_id())
        {
            if (obj1.get_num_electric_after() == 0 && obj1.get_num_water_after() == 0)
            {
                obj1.set_num_electric_before(obj1.get_num_electric_before() - (obj.get_num_electric_after() - obj.get_num_electric_before()));
                obj1.set_num_water_before(obj1.get_num_water_before() - (obj.get_num_water_after() - obj.get_num_water_before()));
                obj1.set_date(Datetime(dt.get_years(), dt.get_months(),0));
                dien_nuoc::delete_dien_nuoc(obj1.get_dien_nuoc_id());
                obj1.add_dien_nuoc();
                break;
            }
        }
    }
    inputFile.close();
    /// hoa don
    inputFile1.open("hoa_don.txt");
    L.clear();
    hoa_don hd1;
    int bonus;
    while (getline(inputFile1, str))
    {
        hd1 = hoa_don::Split(str);

        if (hd1.get_room_id() == ID_room_before)
        {
            if (hd1.get_date().get_days() == 0)
            {
                hd1.set_room_id(ID_room_after);
                hd1.set_date(Datetime(dt.get_years(), dt.get_months(), 0));
                if (dt.is_mid_month())
                {
                    bonus = 2 * hd1.get_total_cost();
                }
                else
                {
                    bonus = hd1.get_total_cost() + hd1.get_total_cost() / 2;
                }
                hd1.set_total_cost(bonus);
                str = hoa_don::Union(hd1);
            }
        }
        L.push_back(str);
    }
    inputFile1.close();
    hoa_don::write_File(L);

    // customer
    inputFile2.open("customer.txt");
    L.clear();
    customer cs;
    while (getline(inputFile2, str))
    {
        cs = customer::Split(str);

        if (cs.get_room_id() == ID_room_before)
        {
            cs.set_room_id(ID_room_after);
            str = customer::Union(cs);
        }
        L.push_back(str);
    }
    inputFile2.close();
    customer::write_File(L);
    // thay doi trang thai room
    inputFile.open("room.txt");
    Room room;
    L.clear();
    while (getline(inputFile, str))
    {
        room = Room::Split(str);
        if (room.room_id == ID_room_before)
        {
            room.setOccupied(false);
            str = Room::Union(room);
        } else if (room.room_id == ID_room_after) {
            room.setOccupied(true);
            str = Room::Union(room);
        }
        L.push_back(str);
    }
    inputFile.close();
    Room::write_File(L);

}