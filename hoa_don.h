// #include <iostream>
// #include <string>
// #include "List.cpp"
// #include <fstream>
#include "Datetime.h"

// #include "dien_nuoc.h"
// using namespace std;
class hoa_don
{
private:
    string bill_id;
    string room_id;
    Datetime date;
    int total_cost;
    bool status;

public:
    hoa_don(string = "", string = "",int = 0,int =0,int = 0, int = 0, bool = false);
    ~hoa_don();
    string get_room_id() const;
    string get_bill_id() const;
    Datetime get_date() const;
    int get_total_cost() const;
    bool get_status() const;

    void set_room_id(string);
    void set_bill_id(string);
    void set_date(int,int,int);
    void set_total_cost(int);
    void set_status(bool);

    friend istream &operator>>(istream &, hoa_don &);
    friend ostream &operator<<(ostream &, const hoa_don &);

    void write_File(List<string> &);
    static hoa_don Split(string);
    static string Union(hoa_don &);
    void add_hoa_don();

    static void display();
    static void view_payment_room();
    // void find_room(string);
    // void update_hoa_don(string);
    //     void deletehoa_don();
};
