#include "Chat.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Message::Message(string TextMessage, string LoginSender, string LoginReceiver)
{
    _TextMessage = TextMessage;
    _LoginSender = LoginSender;
    _LoginReceiver = LoginReceiver;
}
void Message::NewMessage(string TextMessage, string LoginSender, string LoginReceiver)
{
    _TextMessage = TextMessage;
    _LoginSender = LoginSender;
    _LoginReceiver = LoginReceiver;
}

void Message::SetTextMessage(string TextMessage) // ������ ������ ���������
{
    _TextMessage = TextMessage;
}

void Message::SetLoginSender(string LoginSender) // ������ ������ �����������
{
    _LoginSender = LoginSender;
}

void Message::SetLoginReceiver(string LoginReceiver) // ������ ������ ����������
{
    _LoginReceiver = LoginReceiver;
}

string Message::GetTextMessage() const // ������ ������ ���������
{
    return _TextMessage;
}


string Message::GetLoginSender() const // ������ ������ �����������
{
    return _LoginSender;
}

string Message::GetLoginReceiver() const // ������ ������ ����������
{
    return _LoginReceiver;
}