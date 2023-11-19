#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "user.h"
#include "Room.h"

class customer : public user
{
private:
    string customer_id;
    string room_id;
    string customer_name;
    string customer_dateofbirth;
    string customer_gender;
    string customer_email;
    string customer_address;
    string customer_phone;

public:
    customer(string = "",string = " ",string = "", string = "", string = "", string = "", string = "", string = "", string = "", string = "");
    ~customer();

    string get_customer_id() const;
    void set_customer_id(string);

    string get_room_id() const;
    void set_room_id(string);

    string get_customer_name() const;
    void set_customer_name(string);

    string get_customer_dateofbirth() const;
    void set_customer_dateofbirth(string);

    string get_customer_gender() const;
    void set_customer_gender(string);

    string get_customer_email() const;
    void set_customer_email(string);

    string get_customer_address() const;
    void set_customer_address(string);

    string get_customer_phone() const;
    void set_customer_phone(string);

    friend istream &operator>>(istream &, customer &);
    friend ostream &operator<<(ostream &, const customer &);

    static customer Split(string);
    static string Union (customer&);
    static bool find_namecustomer(string);
    static customer find_idcustomer(string);
    static void update_customer(customer&);

    bool login();
    // static List<string> load_File(const string);
    static void write_File(List<string>&);
    void add_customer();
    // void update_customer(string);
    static void delete_customer(string);
    static void display();
};
#endif
