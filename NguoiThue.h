#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "Phong.h"

class NguoiThue : public User
{
private:
    string customer_id;
    string room_id;
    string customer_name;
    ThoiGian customer_dateofbirth;
    ThoiGian check_in;
    string customer_gender;
    string customer_email;
    string customer_address;
    string customer_phone;

public:
    NguoiThue(string = "", string = " ", string = "", ThoiGian = ThoiGian(0, 0, 0), ThoiGian = ThoiGian(0, 0, 0), string = "", string = "", string = "", string = "", string = "", string = "");
    ~NguoiThue();

    string get_customer_id() const;
    void set_customer_id(string);

    string get_room_id() const;
    void set_room_id(string);

    string get_customer_name() const;
    void set_customer_name(string);

    ThoiGian get_customer_dateofbirth() const;
    void set_customer_dateofbirth(ThoiGian);

    ThoiGian get_check_in() const;
    void set_check_in(ThoiGian);

    string get_customer_gender() const;
    void set_customer_gender(string);

    string get_customer_email() const;
    void set_customer_email(string);

    string get_customer_address() const;
    void set_customer_address(string);

    string get_customer_phone() const;
    void set_customer_phone(string);

    friend istream &operator>>(istream &, NguoiThue &);

    static int NumOfCustomer();
    static NguoiThue Split(string);
    static string Union(NguoiThue &);
    static void write_File(List<string> &);

    static bool find_customer(List<NguoiThue> &);
    static void find_idcustomer(string, List<NguoiThue> &);
    static void find_idroom(string, List<NguoiThue> &);
    static bool find_user_name(string);

    static void update_customer(NguoiThue &, int);
    static void change_user_name(string);

    bool login();
    void add_customer();
    
    static void delete_customer(string);
    static void display(List<NguoiThue> &);
};
#endif
