#ifndef ROOM_H
#define ROOM_H

#include "dien_nuoc.h"
#include "hoa_don.h"
class Room {
public:
    // Constructors
  // Default constructor
    Room(string  = "", string  = "" , int  = 0, bool  = false);  // Constructor with initialization

    // Destructor
    ~Room();

    // Getter and Setter
    string getRoomID() const;
    void setRoomID(string room_id);

    string getKindOf() const;
    void setKindOf(string kind_of);

    int getCost() const;
    void setCost(int cost);

    bool isOccupied() const;
    void setOccupied(bool occupied);

    static Room Split(string);
    static string Union (Room&);
    static void display(List<Room>&);
    static void view_empty_room(List<Room>&);
    static void view_rented_room(List<Room>&);
    // static List<string> load_File(const string);
    static void write_File(List<string>&); 
    static void delete_room(string room_id,int k = 0);

    void add_room(int);
    friend istream& operator>>(istream&, Room&);
    friend ostream& operator<<(ostream&, const Room&);

    static void find_idroom(string,List<Room>&);
    static void find_room(List<Room>&);
    static bool find_room_with_status_true(string);
    // Display room information method
    // void display() const;
      // Function to load room data from file
    // static void loadRoomListFromFile(List<Room>& roomList);
    static void update_room(Room&,int);
     
    static void cancel_room(string room_id);
    static void change_room();

private:
    string room_id;
    string kind_of;
    int cost;
    bool occupied;
};

#endif // ROOM_H