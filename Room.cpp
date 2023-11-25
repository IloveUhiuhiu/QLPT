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


void Room::delete_room(string room_id) 
{
    List<string> L;
    ifstream inputFile;
    inputFile.open("room.txt");
    string str;
    while (getline(inputFile, str))
    {   
        Room obj = Split(str);
        if (obj.getRoomID() != room_id)
        {
            L.push_back(str);
        }
        
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
        dien_nuoc dn;
        dn.set_room_id(this->room_id);
        dn.set_dien_nuoc_id(Convert::CreateID("dien_nuoc.txt"));
        dn.set_cost_water(dien_nuoc::getNewCostWater());
        dn.set_cost_electric(dien_nuoc::getNewCostElectric());
        dn.add_dien_nuoc();
    }

}
istream& operator>> (istream& i, Room& room)
{   
    cout << "RoomID: ";
    i >> room.room_id;

    cout << "Kind of (A, B, or C): ";
    i >> room.kind_of;
    while (room.kind_of != "A" && room.kind_of != "B" && room.kind_of != "C")
    {
        cout << "Kind of (A, B, or C): ";
        i >> room.kind_of;
    }

    cout << "Cost: ";
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
Room Room::find_room(string search_term)
{
    ifstream inputFile;
    inputFile.open("room.txt");
    string str;
    Room obj;
    
    while (getline(inputFile, str))
    {
        obj = Room::Split(str);

        // Check if either room_id or kind_of matches the search term
        if (obj.getRoomID() == search_term || obj.getKindOf() == search_term)
        {
            return obj;
        }
    }

    // Return an empty Room object if no match is found
    return Room();
}

void Room::view_empty_room(List<Room>& L)
{
    ifstream inputFile;
    inputFile.open("room.txt");
    string str;
    while (getline(inputFile, str))
    {   
        if (str.size()) {
            Room obj = Room::Split(str);
            if (!obj.isOccupied())
            {
                L.push_back(obj);
            }
        }
    }
}
void Room::view_rented_room(List<Room>& L)
{
    ifstream inputFile;
    inputFile.open("room.txt");
    string str;
    while (getline(inputFile, str))
    {   
        if (str.size()) {
            Room obj = Room::Split(str);
            if (obj.isOccupied())
            {
                L.push_back(obj);
            }
        }
    }
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
}


void Room::edit_room() {
    string search_term;
    cout << "Enter the RoomID you want to edit: ";
    cin >> search_term;

    Room roomToEdit = find_room(search_term);

    if (roomToEdit.getRoomID().empty()) {
        cout << "Room not found." << endl;
    } else {
        cout << "Current Room Information:\n" << roomToEdit << endl;

        // Allow the user to edit the room information
        cout << "Enter new information:" << endl;

        // Check and update RoomID
        string newRoomID;
        cin.ignore(); 
        cout << "New RoomID (press Enter to keep current value): ";
        getline(cin, newRoomID);
        if (!newRoomID.empty()) {
            roomToEdit.setRoomID(newRoomID);
        }

        // Check and update KindOf
        string newKindOf;
        cout << "New KindOf (A, B, or C) (press Enter to keep current value): ";
        getline(cin, newKindOf);
        if (!newKindOf.empty() && (newKindOf == "A" || newKindOf == "B" || newKindOf == "C")) {
            roomToEdit.setKindOf(newKindOf);
        } else {
            cout << "Invalid KindOf. Keeping the current value." << endl;
        }

        // Check and update Cost
        string newCostStr;
        cout << "New Cost (press Enter to keep current value): ";
        getline(cin, newCostStr);
        if (!newCostStr.empty()) {
            int newCost = stoi(newCostStr);
            roomToEdit.setCost(newCost);
        }

        // Check and update Occupied
        string newOccupiedStr;
        cout << "New Occupied (press Enter to keep current value): ";
        getline(cin, newOccupiedStr);
        if (!newOccupiedStr.empty()) {
            bool newOccupied = Convert::str_to_bool(newOccupiedStr);
            roomToEdit.setOccupied(newOccupied);
        }

        // Delete the existing room entry
        delete_room(search_term);

        // Add the updated room information
        roomToEdit.add_room(0);

        cout << "Room information updated successfully." << endl;
    }
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
        customer obj = customer::Split(customerStr);

        // Nếu người dùng có room_id tương ứng, không thêm thông tin người dùng này vào danh sách (để xóa nó)
        if (obj.get_room_id() != room_id)
        {
            customerList.push_back(customer::Union(obj));
        }
    }

    customerFile.close();

    // Ghi danh sách đã được cập nhật trở lại vào "customer.txt"
    customer::write_File(customerList);

}


// Display room information method
// Function to load room data from file
// void Room::loadRoomListFromFile(List<Room>& roomList) {
//     std::ifstream inFile("room.txt");

//     // Check if the file is open
//     if (inFile.is_open()) {
//         int roomID;
//         std::string kindOf;
//         int cost;
//         bool occupied;

//         // Read room details from file
//         while (inFile >> roomID >> kindOf >> cost >> occupied) {
//             // Create a new room and add it to the list
//             Room newRoom(roomID, kindOf, cost, occupied);
//             roomList.push_back(newRoom);
//         }

//         // Close the file
//         inFile.close();
//     } else {
//         std::cerr << "Error opening file for reading: room.txt" << std::endl;
//     }
// }
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
