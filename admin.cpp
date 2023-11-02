#include "admin.h"

admin::admin(string admin_name, string admin_email, string user_name, string password)
    : admin_name(admin_name), admin_email(admin_email), user(user_name, password)
{
}
admin::admin(const admin &obj)
{
    this->admin_name = obj.admin_name;
    this->admin_email = obj.admin_email;
    this->user_name = obj.user_name;
    this->password = obj.password;
}
admin::~admin()
{
}
string admin::get_admin_name() const
{
    return this->admin_name;
}
void admin::set_admin_name(string admin_name)
{
    this->admin_name = admin_name;
}
string admin::get_admin_email() const
{
    return this->admin_email;
}
void admin::set_admin_email(string admin_email)
{
    this->admin_email = admin_email;
}
ostream &operator<<(ostream &o, const admin &obj)
{
    cout << "admin_name: ";
    o << obj.admin_name << endl;
    cout << "admin_email: ";
    o << obj.admin_email << endl;
    cout << "user_name: ";
    o << obj.user_name << endl;
    cout << "password: ";
    o << obj.password << endl;
    return o;
}
bool admin::login()
{
    List<admin> L;
    string str, admin_name, admin_email, admin_password, admin_user_name;
    ifstream inputFile;
    inputFile.open("admin.txt");
    if (inputFile.is_open())
    {
        while (getline(inputFile, str))
        {
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
            L.push_back(admin(admin_name, admin_email, admin_user_name, admin_password));
        }
        inputFile.close();
        int size = L.getSize();
        for (int i = 0; i < size; i++)
        {
            if (L[i].user_name == this->user_name && L[i].password == this->password)
            {

                for (int j = 0; j <= 100; j = j + 25)
                {
                    cout << "Dang kiem tra thong tin... " << j << "%" << endl;
                    sleep(1);
                    system("cls");
                }
                cout << "Dang Nhap Thanh Cong!" << endl;
                *(this) = L[i];
                return true;
            }
        }
        cout << "Ten Dang Nhap hoac Mat Khau khong dung. Vui long thu lai!!!" << endl;
        return false;
    }
    else
    {
        cout << "Loi Trong Qua Trinh Mo File" << endl;
        return false;
    }
}