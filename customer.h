#include "user.h"

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

    customer Split(string);
    string Union (customer&);
    bool login();
    void write_File(List<string>&);
    void add_customer();
    void find_customer(string);
    void find_room(string);
    void update_customer(string);
    void delete_customer(string);
};
