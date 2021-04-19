#pragma once
#include <iostream>
#include <vector>
using namespace std;
class User//класс юзер,где будут содержаться значение имени,логина и пароля
{
public:
    User(string _NameUser, string _LoginUser, string _PassUser);//конструктор с 3 параметрами
    User()=default;//конструктор по умолчанию
    ~User() = default;// Деструктор

    void NewUser(string NameUser, string LoginUser, string PassUser);
    void SetNameUser(); // сеттер имени пользователя
    void SetLoginUser(); // сеттер логина пользователя
    void SetPassUser(); // сеттер пароля пользователя

    string GetNameUser() const; // геттер имени пользователя
    string GetLoginUser() const; // геттер логина пользователя
    string GetPassUser() const; // геттер пароля пользователя

    User& operator++(); // Перегрузка пре-инкремента
    User& operator--(); // Перегрузка пре-декремента

    User operator++(int); // Перегрузка пост-инкремента
    User operator--(int); // Перегрузка пост-декремента
    User vector(); // Перегрузка вектора
    User insert(User); // Перегрузка вставки в вектор
    User size(User); // Перегрузка размера вектора


private:
    string _NameUser;
    string _LoginUser;
    string _PassUser;
};