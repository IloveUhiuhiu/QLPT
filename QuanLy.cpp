#include "QuanLy.h"

QuanLy::QuanLy(string admin_name, string admin_email, string user_name, string password)
    : admin_name(admin_name), admin_email(admin_email), User(user_name, password)
{
}
QuanLy::QuanLy(const QuanLy &obj)
{
    this->admin_name = obj.admin_name;
    this->admin_email = obj.admin_email;
    this->user_name = obj.user_name;
    this->password = obj.password;
}
QuanLy::~QuanLy()
{
}
string QuanLy::get_admin_name() const
{
    return this->admin_name;
}
void QuanLy::set_admin_name(string admin_name)
{
    this->admin_name = admin_name;
}
string QuanLy::get_admin_email() const
{
    return this->admin_email;
}
void QuanLy::set_admin_email(string admin_email)
{
    this->admin_email = admin_email;
}
ostream &operator<<(ostream &o, const QuanLy &obj)
{
    cout << "Admin Name: ";
    o << obj.admin_name << endl;
    cout << "Admin Email: ";
    o << obj.admin_email << endl;
    cout << "User Name: ";
    o << obj.user_name << endl;
    cout << "Password: ";
    o << obj.password << endl;
    return o;
}
bool QuanLy::login()
{
    List<QuanLy> L;
    string str, admin_name, admin_email, admin_password, admin_user_name;
    ifstream inputFile;
    inputFile.open("QuanLy.txt");
    if (inputFile.is_open())
    {
        while (getline(inputFile, str))
        {   
            if (str.size()) {
            str += ',';
            int id = 1;
            int begin = 0, end = 0;
            for (auto x : str)
            {
                if (x == ',')
                {
                    if (id == 1)
                        admin_name = str.substr(begin, end - begin);
                    else if (id == 2)
                        admin_email = str.substr(begin, end - begin);
                    else if (id == 3)
                        admin_user_name = str.substr(begin, end - begin);
                    else
                    {
                        admin_password = str.substr(begin, end - begin);
                    }
                    ++id;
                    begin = end + 1;
                }
                end++;
            }
            L.push_back(QuanLy(admin_name, admin_email, admin_user_name, admin_password));
            }
        }
        inputFile.close();
        int size = L.getSize();
        for (int i = 0; i < size; i++)
        {
            if (L[i].user_name == this->user_name && L[i].password == this->password)
            {
                *(this) = L[i];
                return true;
            }
        }
        
        return false;
    }
    else
    {
        cout << "Error Open File QuanLy.txt" << endl;
        return false;
    }
}