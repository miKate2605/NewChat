#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Message
{
public:
    Message(string TextMessage, string LoginSender, string LoginReceiver);
    Message();
    ~Message() = default;// ����������

    Message& operator++(); // ���������� ���-����������
    Message& operator--(); // ���������� ���-����������

    Message operator++(int); // ���������� ����-����������
    Message operator--(int); // ���������� ����-����������

    Message vector(); // ���������� �������
    Message insert(Message); // ���������� ������� � ������
    Message size(Message); // ���������� ������� �������


    void NewMessage(string TextMessage, string LoginSender, string LoginReceiver);
    void SetTextMessage(string TextMessage); // ������ ������ ���������
    void SetLoginSender(string LoginSender); // ������ ������ �����������
    void SetLoginReceiver(string LoginReceiver); // ������ ������ ����������
    string GetTextMessage() const; // ������ ������ ���������
    string GetLoginSender() const; // ������ ������ �����������
    string GetLoginReceiver() const; // ������ ������ ����������



private:
    string _TextMessage;
    string _LoginSender;
    string _LoginReceiver;

};