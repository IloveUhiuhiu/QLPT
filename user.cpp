#include "user.h"

user::user(string user_name, string password) : user_name(user_name), password(password)
{
}
user::~user()
{
}
string user::get_user_name() const
{
    return this->user_name;
}
void user::set_user_name(string user_name)
{
    this->user_name = user_name;
}
string user::get_password() const
{
    return this->password;
}
void user::set_password(string password)
{
    this->password = password;
}

