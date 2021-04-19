#include "UserHead.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

User::User(string NameUser, string LoginUser, string PassUser):
    _NameUser(NameUser),_LoginUser(LoginUser),_PassUser(PassUser)
{
}


void User::NewUser(string NameUser, string LoginUser, string PassUser) // вставка значений нового пользователя
{
    _NameUser = NameUser;
    _LoginUser = LoginUser;
    _PassUser = PassUser;
}

void User::SetNameUser() // сеттер имени пользователя
{
    cout << "Введите Имя :/n" << endl;
    cin >> _NameUser;
   // _NameUser = NameUser;
}
void User::SetLoginUser() // сеттер логина пользователя
{
    cout << "Введите логин :/n" << endl;
    cin >> _LoginUser;
    //_LoginUser = LoginUser;
}
void User::SetPassUser() // сеттер пароля пользователя
{
    cout << "Введите пароль :/n" << endl;
    cin >> _PassUser;
    //_PassUser = PassUser;
}

string User::GetNameUser() const // геттер имени пользователя
{
    return _NameUser;
}
string User::GetLoginUser() const // геттер логина пользователя
{
    return _LoginUser;
}
string User::GetPassUser() const // геттер пароля пользователя
{
    return _PassUser;
}



