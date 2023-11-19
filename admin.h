#include "user.h"
using namespace std;
class admin : public user
{
private:
    string admin_name;
    string admin_email;

public:
    admin(string = "", string = "", string = "", string = "");
    admin(const admin&);
    ~admin();
    string get_admin_name() const;
    void set_admin_name(string);

    string get_admin_email() const;
    void set_admin_email(string);

    friend ostream& operator << (ostream&, const admin&);
    bool login();
};