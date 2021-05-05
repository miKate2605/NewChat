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

void Message::SetTextMessage(string TextMessage) // сеттер текста сообщения
{
    _TextMessage = TextMessage;
}

void Message::SetLoginSender(string LoginSender) // сеттер логина отправителя
{
    _LoginSender = LoginSender;
}

void Message::SetLoginReceiver(string LoginReceiver) // сеттер логина получателя
{
    _LoginReceiver = LoginReceiver;
}

string Message::GetTextMessage() const // геттер текста сообщения
{
    return _TextMessage;
}


string Message::GetLoginSender() const // геттер логина отправителя
{
    return _LoginSender;
}

string Message::GetLoginReceiver() const // геттер пароля получателя
{
    return _LoginReceiver;
}