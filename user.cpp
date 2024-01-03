#include "User.h"

User::User(string user_name, string password) : user_name(user_name), password(password)
{
}
User::~User()
{
}
string User::get_user_name() const
{
    return this->user_name;
}
void User::set_user_name(string user_name)
{
    this->user_name = user_name;
}
string User::get_password() const
{
    return this->password;
}
void User::set_password(string password)
{
    this->password = password;
}

