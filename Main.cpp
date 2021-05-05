#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include"UserHead.h"
#include"Chat.h"




using namespace std;

int chekChoose(int a, int b) // функция проверки верности выбора пункта меню
{
    int i; //счетчик цикла
    char* choose = new char; // вводимая строка
    do
    {
        i = 1;

        cout << "Сделайте свой выбор:" << endl;
        cin >> choose;
        if ((isdigit(*choose)) == false) // проверка на ввод символа
        {
            cout << "Неверный выбор. Попробуйте еще раз!" << endl;
            cout << "\n\n" << endl;
            i = 0;
        }
        else if (atoi(choose) < a || atoi(choose) > b) // проверка значений(1, 2 или 3), если int
        {
            cout << "Неверный выбор. Попробуйте еще раз!" << endl;
            cout << "\n\n" << endl;
            i = 0;
        }
    } while (i == 0);
    int ChooseSelect;
    return ChooseSelect = atoi(choose); // приведение char к int и возврат int
}

string LoginCheck(vector <User>& VtrUser, int size)//функция аутентификации пользователя
{
    int checkReg; // проверка корректности входа
    string OnRegLogin; // записываем Логин вошедшего пользователя
    do {
        checkReg = 1;
        cout << "\n" << endl;
        cout << "Введите свой логин:" << endl;
        string RegLogin; // ввод логина
        cin >> RegLogin;
        cout << "Введите свой пароль:" << endl;
        string RegPass;  // ввод пароля
        cin >> RegPass;


        for (size_t i = 0; i < size; ++i)
        {
            if (RegLogin == VtrUser[i].GetLoginUser() && RegPass == VtrUser[i].GetPassUser())
            {
                cout << "\n\n" << endl;
                cout << VtrUser[i].GetNameUser() << ", добрый день!!" << endl;
                checkReg = 0;
                return OnRegLogin = VtrUser[i].GetLoginUser();
            }
        }
        if (checkReg == 1)
        {
            cout << "\n\n" << endl;
            cout << "Неверный ввод логина и пароля." << endl;
            cout << "Если хотите попробовать еще раз, введите 1" << endl;
            cout << "Если хотите вернуться в Главное меню, введите 0" << endl;
        }
        checkReg = chekChoose(0, 1);
    } while (checkReg != 0);
    return "No";

}

void MainMenu() // Главное меню
{
    cout << "\n\n" << endl;
    cout << "Главное меню." << endl;
    cout << "\n" << endl;
    cout << "Войти в чат, если Вы уже зарегистрированы, выберите: 1" << endl;
    cout << "Регистрация нового пользователя, выберите: 2" << endl;
    cout << "Для завершения работы с программой, выберите: 3" << endl;
    cout << endl;
}

void ChatMenu() // Меню чата
{
    cout << "\n\n" << endl;
    cout << "Меню чата." << endl;
    cout << "\n" << endl;
    cout << "Для проверки новых сообщений, выберите: 1" << endl;
    cout << "Написать сообщение, выберите: 2" << endl;
    cout << "Чтобы выйти из аккаунта и перейти в главное меню, выберите: 3" << endl;
    cout << endl;
}

void MessageMenu() // Подменю чата: меню сообщений
{
    cout << "\n\n" << endl;
    cout << "Меню отправки сообщений." << endl;
    cout << "\n" << endl;
    cout << "Для отправки <Всем>, выберите: 1" << endl;
    cout << "Для отправки определенному пользователю, выберите: 2" << endl;
    cout << "Чтобы выйти из меню и перейти в меню чата, выберите: 3" << endl;
    cout << endl;
}

void PrintRegUsers(vector <User>& VtrUser) // вывод на экран всех зарегистрированных пользователей
{
    cout << "\n\n" << endl;
    cout << "Перечень зарегистрированных пользователей:" << endl;
    for (size_t i = 1; i < VtrUser.size(); ++i) // начинаем цикл с i = 1, т.к. 0 индекс у пользователя "All"
    {
        cout << "Пользователь с именем: " << VtrUser[i].GetNameUser() << ", логин " << VtrUser[i].GetLoginUser() << ";" << endl;
    }
}



int main()
{
    setlocale(LC_ALL, "");

    string OnRegLogin; // записываем Логин вошедшего пользователя
    string NewestName; // переменные для ввода новых данных пользователя
    string NewestLogin;
    string NewestPass;
    string NewestMessageText; // переменная для ввода текста нового сообщения
    string NewestMessageSender;
    string NewestMessageReceiver;

    User* All = new User("admin", "All", "admin");
    User* User1 = new User("Alex", "AlexTs", "123456");
    User* User2 = new User("Anna", "AIvanova", "Anna21");
    User* User3 = new User("Max", "Max1982", "Kx12Q");

    vector <User> VtrUser; // создаем вектор Пользователей
    VtrUser.reserve(100);
    VtrUser.insert(VtrUser.end(), *All);
    VtrUser.insert(VtrUser.end(), *User1);
    VtrUser.insert(VtrUser.end(), *User2);
    VtrUser.insert(VtrUser.end(), *User3);

    Message* AllMsgs = new Message("Hello!!", "All", "All");
    Message* Msgs1 = new Message("Hello, Alex!!", "AIvanova", "AlexTs");
    Message* Msgs2 = new Message("Hello, Anna!!", "Max1982", "AIvanova");
    Message* Msgs3 = new Message("Hello, Max!!", "AlexTs", "Max1982");

    vector <Message> VtrMessage; // создаем вектор Сообщений
    VtrMessage.reserve(1000);
    VtrMessage.insert(VtrMessage.end(), *AllMsgs);
    VtrMessage.insert(VtrMessage.end(), *Msgs1);
    VtrMessage.insert(VtrMessage.end(), *Msgs2);
    VtrMessage.insert(VtrMessage.end(), *Msgs3);

    int Y = 1; // счетчик цикла Главного меню
    cout << "Добро пожаловать в чат." << endl;
    do
    {
        PrintRegUsers(VtrUser);
        MainMenu(); // вывод главного меню

        int ChooseSelectMain = chekChoose(1, 3);; // обьявляем и инициализируем через функцию переменную выбора пункта меню

        switch (ChooseSelectMain)
        {
        case 1: // п.1 Главного меню: Войти в чат, если Вы уже зарегистрированы
        {
            int Z = 1; // счетчик цикла Главного меню

            int size = VtrUser.size();
            string ConfirmRegLogin;
            ConfirmRegLogin = LoginCheck(VtrUser, size); // вход и фиксация вошедшего!
            if (ConfirmRegLogin == "No") // если функция вернула "No" - возврат в головное меню!
            {
                continue;
            }
            do {
                ChatMenu(); // вывод меню чата
                int ChooseSelectChat = chekChoose(1, 3); // обьявляем и инициализируем через функцию переменную выбора пункта меню
                switch (ChooseSelectChat)
                {
                case 1: // п.1 Меню чата: проверка новых сообщений
                {
                    int checkMessage = 0;
                    for (size_t i = 0; i < VtrMessage.size(); ++i)
                    {
                        if ((VtrMessage[i].GetLoginReceiver() == ConfirmRegLogin) || (VtrMessage[i].GetLoginReceiver() == "All"))
                        {
                            cout << "\n\n" << endl;
                            cout << "У Вас новое сообщение!!" << endl;
                            cout << "Отправитель: " << VtrMessage[i].GetLoginSender() << "." << endl;
                            cout << "Сообщение: " << VtrMessage[i].GetTextMessage() << "." << endl;
                            checkMessage = 1;
                            cout << "\n" << endl;
                            cout << "Ответить на сообщение? (да: введите 1; нет: введите 0)" << endl;
                            int checkAnswer = chekChoose(0, 1);
                            if (checkAnswer == 0)
                            {
                                continue;
                            }
                            else if (checkAnswer = 1)
                            {
                                Message* NewestMessage = new Message("New", "New", "New");
                                cout << "Введите текст сообщения:" << endl;
                                cin >> NewestMessageText;
                                NewestMessage->NewMessage(NewestMessageText, ConfirmRegLogin, VtrMessage[i].GetLoginSender()); // присваиваем новому сообщению значения
                                VtrMessage.insert(VtrMessage.end(), *NewestMessage); // добавляем новое сообщение в вектор
                            }
                        }
                    }
                    break;
                }
                case 2: // п.2 Меню чата: Написать сообщение
                {
                    int X = 1; // счетчик цикла меню сообщений
                    do
                    {
                        PrintRegUsers(VtrUser);
                        MessageMenu();
                        int ChooseSelectMessage = chekChoose(1, 3); // обьявляем и инициализируем через функцию переменную выбора пункта меню
                        switch (ChooseSelectMessage)
                        {
                        case 1: // п.1 Меню сообщений: отправка <Всем>
                        {
                            Message* NewestMessage = new Message("New", "New", "New");
                            cout << "\n" << endl;
                            cout << "Введите текст сообщения:" << endl;
                            cin >> NewestMessageText;
                            NewestMessage->NewMessage(NewestMessageText, ConfirmRegLogin, "All"); // присваиваем новому сообщению значения
                            VtrMessage.insert(VtrMessage.end(), *NewestMessage); // добавляем новое сообщение в вектор
                            break;
                        }
                        case 2: // п.1 Меню сообщений: отправка определенному пользователю
                        {
                            Message* NewestMessage = new Message("New", "New", "New");
                            cout << "\n" << endl;
                            cout << "Введите текст сообщения:" << endl;
                            cin >> NewestMessageText;
                            cout << "Введите логин получателя сообщения:" << endl;
                            cin >> NewestMessageReceiver;
                            NewestMessage->NewMessage(NewestMessageText, ConfirmRegLogin, NewestMessageReceiver); // присваиваем новому сообщению значения
                            VtrMessage.insert(VtrMessage.end(), *NewestMessage); // добавляем новое сообщение в вектор'
                            break;
                        }
                        case 3: // п.1 Меню сообщений: выход в меню чата
                        {
                            X = 0;
                            break;
                        }
                        }

                    } while (X > 0);
                    break;
                }
                case 3: // п.3 Меню чата: Выход в главное меню
                {
                    Z = 0;
                    break;
                }
                }
            } while (Z > 0);
            break;
        }
        case 2: // п.2 Главного меню: Регистрация нового пользователя
        {
            cout << "При новой регистрации помните, что использовать логин All запрещено!!" << endl; // добавить регистрацию!!!
            User* NewestUser = new User("New", "New", "New"); // создаем нового пользователя со значениями по умолчанию
            int chekRegLog;
            do
            {
                chekRegLog = 0;
                cout << "Введите свое имя:" << endl;
                cin >> NewestName;
                cout << "Введите свой логин:" << endl;
                cin >> NewestLogin;
                cout << "Введите свой пароль:" << endl;
                cin >> NewestPass;
                for (size_t i = 0; i < VtrUser.size(); ++i) // проверка уникальности логина
                {
                    if (NewestLogin == VtrUser[i].GetLoginUser())
                    {
                        cout << "Этот логин занят!!" << endl;
                        chekRegLog = 1;
                    }
                }
            } while (chekRegLog > 0);
            NewestUser->NewUser(NewestName, NewestLogin, NewestPass); // присваиваем новому пользователю значения
            VtrUser.insert(VtrUser.end(), *NewestUser); // добавляем нового пользователя в вектор
        }
        break;
        case 3: // п.3 Главного меню : Выход из программы
        {
            Y = 0;
            break;
        }
        }

    } while (Y > 0);
    cout << "До свидания!" << endl;
    return 0;
}