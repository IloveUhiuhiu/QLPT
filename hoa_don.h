#ifndef HOA_DON_H
#define HOA_DON_H
#include "Datetime.h"
#include "Room.h"
class hoa_don
{
private:
    string bill_id;
    string room_id;
    Datetime date;
    int total_cost;
    bool status;

public:
    hoa_don(string = "", string = "",Datetime = Datetime(0,0,0), int = 0, bool = false);
    ~hoa_don();
    string get_room_id() const;
    string get_bill_id() const;
    Datetime get_date() const;
    int get_total_cost() const;
    bool get_status() const;

    void set_room_id(string);
    void set_bill_id(string);
    void set_date(Datetime);
    void set_total_cost(int);
    void set_status(bool);

    friend istream &operator>>(istream &, hoa_don &);
    friend ostream &operator<<(ostream &, const hoa_don &);

    static void write_File(List<string> &);
    static hoa_don Split(string);
    static string Union(hoa_don &);
    void add_hoa_don();

    static void display();
    static void view_payment_room();
    static void view_unpayment_room();
    static bool find_hoa_don();
    static bool find_room(string);
    static hoa_don find_bill_id(string);
    static bool find_bill_id_check(string);
    string find_max_bill_id();
    static void update_hoa_don(hoa_don&);
    static void Pay_bill(hoa_don&);
};
#endif
