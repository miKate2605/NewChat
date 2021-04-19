#pragma once
#include <iostream>
#include <vector>
using namespace std;
class User//����� ����,��� ����� ����������� �������� �����,������ � ������
{
public:
    User(string _NameUser, string _LoginUser, string _PassUser);//����������� � 3 �����������
    User()=default;//����������� �� ���������
    ~User() = default;// ����������

    void NewUser(string NameUser, string LoginUser, string PassUser);
    void SetNameUser(); // ������ ����� ������������
    void SetLoginUser(); // ������ ������ ������������
    void SetPassUser(); // ������ ������ ������������

    string GetNameUser() const; // ������ ����� ������������
    string GetLoginUser() const; // ������ ������ ������������
    string GetPassUser() const; // ������ ������ ������������

    User& operator++(); // ���������� ���-����������
    User& operator--(); // ���������� ���-����������

    User operator++(int); // ���������� ����-����������
    User operator--(int); // ���������� ����-����������
    User vector(); // ���������� �������
    User insert(User); // ���������� ������� � ������
    User size(User); // ���������� ������� �������


private:
    string _NameUser;
    string _LoginUser;
    string _PassUser;
};