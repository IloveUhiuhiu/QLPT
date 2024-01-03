#include "User.h"
using namespace std;
class QuanLy : public User
{
private:
    string admin_name;
    string admin_email;
public:
    QuanLy(string = "", string = "", string = "", string = "");
    QuanLy(const QuanLy&);
    ~QuanLy();
    string get_admin_name() const;
    void set_admin_name(string);

    string get_admin_email() const;
    void set_admin_email(string);

    friend ostream& operator << (ostream&, const QuanLy&);
    bool login();
};