#include "UserHead.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

User::User(string NameUser, string LoginUser, string PassUser):
    _NameUser(NameUser),_LoginUser(LoginUser),_PassUser(PassUser)
{
}


void User::NewUser(string NameUser, string LoginUser, string PassUser) // ������� �������� ������ ������������
{
    _NameUser = NameUser;
    _LoginUser = LoginUser;
    _PassUser = PassUser;
}

void User::SetNameUser() // ������ ����� ������������
{
    cout << "������� ��� :/n" << endl;
    cin >> _NameUser;
   // _NameUser = NameUser;
}
void User::SetLoginUser() // ������ ������ ������������
{
    cout << "������� ����� :/n" << endl;
    cin >> _LoginUser;
    //_LoginUser = LoginUser;
}
void User::SetPassUser() // ������ ������ ������������
{
    cout << "������� ������ :/n" << endl;
    cin >> _PassUser;
    //_PassUser = PassUser;
}

string User::GetNameUser() const // ������ ����� ������������
{
    return _NameUser;
}
string User::GetLoginUser() const // ������ ������ ������������
{
    return _LoginUser;
}
string User::GetPassUser() const // ������ ������ ������������
{
    return _PassUser;
}



