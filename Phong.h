#ifndef ROOM_H
#define ROOM_H

#include "DienNuoc.h"
#include "HoaDon.h"
class Phong {
public:
    Phong(string  = "", string  = "" , int  = 0, bool  = false);  // Constructor with initialization

    // Destructor
    ~Phong();

    // Getter and Setter
    string getRoomID() const;
    void setRoomID(string room_id);

    string getKindOf() const;
    void setKindOf(string kind_of);

    int getCost() const;
    void setCost(int cost);

    bool isOccupied() const;
    void setOccupied(bool occupied);

    static Phong Split(string);
    static string Union (Phong&);

    static int NumOfRoom();
    static int NumOfEmptyRoom();
    
    static void display(List<Phong>&,int = 0); // 0 bình thường, 1 rent, 2 empty 

    static void write_File(List<string>&); 
    static void delete_room(string room_id,int k = 0);// xóa phòng k = 0 thì xóa cả điện nước và hóa đơn

    void add_room(int);
    friend istream& operator>>(istream&, Phong&);
    friend ostream& operator<<(ostream&, const Phong&);

    static void find_idroom(string,List<Phong>&);
    static void find_room(List<Phong>&);

    static void update_room(Phong&,int);
    static void cancel_room(string room_id);
    static void change_room(Phong , Phong);

private:
    string room_id;
    string kind_of;
    int cost;
    bool occupied;
};

#endif // ROOM_H