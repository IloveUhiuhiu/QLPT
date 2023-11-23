// Room.cpp
#include "Room.h"
#include "hoa_don.h"
#include <string.h>

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
        cout << dn.get_dien_nuoc_id() << endl;
        dn.set_cost_water(dien_nuoc::getNewCostWater());
        dn.set_cost_electric(dien_nuoc::getNewCostElectric());
        dn.add_dien_nuoc();
    }

}
istream& operator>> (istream& i, Room& room)
{   
    cout << "RoomID: ";
    i >> room.room_id;

    cout << "Kind of (Single or Double): ";
    i >> room.kind_of;
    while (room.kind_of != "Single" && room.kind_of != "Double")
    {
        cout << "Kind of (Single or Double): ";
        i >> room.kind_of;
    }
    cout << "Cost: ";
    i >> room.cost;
    cout << "Occupied (Yes or No): ";
    string ok; i >> ok;
    while (ok != "Yes" && ok != "No")
    {
        cout << "Occupied (Yes or No): ";
        i >> ok;
    }
    room.occupied = Convert::str_to_bool(ok);
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

Room Room:: find_room(string room_id)
{
    ifstream inputFile;
    inputFile.open("room.txt");
    string str;
    Room obj;
    while (getline(inputFile, str))
    {
        obj = Room::Split(str);
        if (obj.getRoomID() == room_id)
        {
            return obj;
        }
    }
    return obj;
}

void Room::view_empty_room()
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
            cout << obj << endl;
        }
        }
    }
}
void Room::view_rented_room()
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
            cout << obj << endl;
        }
        }
    }
}

void Room::display()
{
    ifstream inputFile;
    inputFile.open("room.txt");
    string str;
    Room room;
    while (getline(inputFile, str))
    {   
        if (str.size()) {
        room = Room::Split(str);
        cout << room << endl;
        }
    }
}


void Room::edit_room() {
    // Display the list of rooms
    display();

    // Ask for the room ID to edit
    std::string roomToEditID;
    std::cout << "Enter the Room ID to edit: ";
    std::cin >> roomToEditID;

    // Retrieve existing details of the selected room
    Room roomToEdit = find_room(roomToEditID);

    if (roomToEdit.getRoomID().empty()) {
        std::cout << "Room not found. Please enter a valid Room ID." << std::endl;
        return;
    }

    // Allow the user to update the details
    std::cout << "Enter new details for the room (or press Enter to keep existing values):" << std::endl;

    std::cout << "New Room ID [" << roomToEdit.getRoomID() << "]: ";
    std::string newRoomID;
    std::getline(std::cin >> std::ws, newRoomID);
    if (!newRoomID.empty()) {
        roomToEdit.setRoomID(newRoomID);
    }

    std::cout << "New Kind of [" << roomToEdit.getKindOf() << "]: ";
    std::string newKindOf;
    std::getline(std::cin >> std::ws, newKindOf);
    if (!newKindOf.empty()) {
        roomToEdit.setKindOf(newKindOf);
    }

    std::cout << "New Cost [" << roomToEdit.getCost() << "]: ";
    std::string newCostStr;
    std::getline(std::cin >> std::ws, newCostStr);
    if (!newCostStr.empty()) {
        int newCost = Convert::str_to_int(newCostStr);
        roomToEdit.setCost(newCost);
    }

    std::cout << "Is the room occupied? (Yes/No) [" << (roomToEdit.isOccupied() ? "Yes" : "No") << "]: ";
    std::string newOccupiedStr;
    std::getline(std::cin >> std::ws, newOccupiedStr);
    if (!newOccupiedStr.empty()) {
        bool newOccupied = Convert::str_to_bool(newOccupiedStr);
        roomToEdit.setOccupied(newOccupied);
    }

    // Save the updated details back to the file
    List<std::string> roomsList;
    std::ifstream inputFile("room.txt");
    std::string line;
    while (std::getline(inputFile, line)) {
        Room room = Split(line);
        if (room.getRoomID() == roomToEditID) {
            // Replace the line with updated details
            roomsList.push_back(Union(roomToEdit));
        } else {
            roomsList.push_back(line);
        }
    }
    inputFile.close();

    // Write the updated list back to the file
    write_File(roomsList);

    std::cout << "Room details updated successfully." << std::endl;
}


void Room::add_payment_room() {
    display();
    // Ask for the room ID to which the payment will be added
    std::string roomID;
    std::cout << "Enter the Room ID to add payment: ";
    std::cin >> roomID;

    // Retrieve existing details of the selected room
    Room room = find_room(roomID);

    if (room.getRoomID().empty()) {
        std::cout << "Room not found. Please enter a valid Room ID." << std::endl;
        return;
    }

    // Allow the user to input payment details
    hoa_don newPayment;

    std::cout << "Enter Payment ID: ";
    string bill_id ;
    std::cin >> bill_id;
    newPayment.set_bill_id(bill_id); // Assuming set_bill_id is a setter method

    // Assuming Datetime is a class with proper input method
    int year, month, day;
    std::cout << "Enter Payment Date:" << std::endl;
    std::cout << "Year: "; std::cin >> year;
    std::cout << "Month: "; std::cin >> month;
    std::cout << "Day: "; std::cin >> day;
    newPayment.set_date(year, month, day);

    std::cout << "Enter Payment Amount: ";
    int amount;
    std::cin >> amount;
    newPayment.set_total_cost(amount);

    // Assuming status is a boolean field
    newPayment.set_status(true);  // You can set it based on your logic

    newPayment.set_room_id(room.getRoomID());

    // Update the payment information for the room
    std::ofstream outputFile("hoa_don.txt", std::ios::app); // Open file in append mode

     if (outputFile.is_open()) {
        // Format the payment record and write it to the file
        std::string paymentRecord = newPayment.get_bill_id() + "," + newPayment.get_room_id() + ","
                                    + Convert::int_to_str(newPayment.get_date().get_years()) + "-"
                                    + Convert::int_to_str(newPayment.get_date().get_months()) + "-"
                                    + Convert::int_to_str(newPayment.get_date().get_days()) + ","
                                    + Convert::int_to_str(newPayment.get_total_cost()) + ","
                                    + Convert::bool_to_str(newPayment.get_status()) + "\n";
        outputFile << paymentRecord;
        outputFile.close();

        std::cout << "Payment added successfully for Room ID " << room.getRoomID() << std::endl;
    } else {
        std::cerr << "Error opening file hoa_don.txt for writing." << std::endl;
    }
}



void Room::delete_payment_room() {
    // Implement the logic to delete payment details for a room
    // For example, ask for the room ID, find the payment record, and then delete it.
}

void Room::edit_payment_room() {
    // Implement the logic to edit payment details for a room
    // For example, ask for the room ID, find the payment record, and then edit the details.
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