#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include"Chat.h"
#include"UserHead.h"




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

int main()

{
	setlocale(LC_ALL, "");
	char choice;
	vector <User> VtrUser;//создаем вектор для хранения пользовательских данных
	VtrUser.reserve(100);
	vector <Message> VtrMessage; // создаем вектор Сообщений
	VtrMessage.reserve(1000);
	while (true)
	{
		cout << "Добро пожаловать в чат.Вы зарегистрированы?y/n?" << endl;
		cin >> choice;
		if  (choice != 'y')
		{
			while (choice == 'n')
			{
				int size = VtrUser.size();
				User* NewUser = new User(); // создаем нового пользователя со значениями по умолчанию
				NewUser->SetNameUser();
				NewUser->SetLoginUser();
				NewUser->SetPassUser();
				VtrUser.insert(VtrUser.end(), *NewUser);
				cout << "Продолжить ввод пользователей  y/n?" << endl;
				cin >> choice;
					
				continue;
			}
			
			if (choice == 'y')
			{
				string ConfirmRegLogin;
				int size = VtrUser.size();
				ConfirmRegLogin = LoginCheck(VtrUser, size); // проверка пользователя
				if (ConfirmRegLogin == "No") 
				{
					continue;
				}

				cout << "Список зарегистрированных пользователей" << endl;
				for (size_t i = 0; i < VtrUser.size(); ++i) // начинаем цикл с i = 1, т.к. 0 индекс у пользователя "All"
				{
					cout << "Пользователь с именем: " << VtrUser[i].GetNameUser()<<'/t' << endl;
				}
				cout << "Написать сообщение в общий чат-1,написать личное сообщение-2" << endl;

			}
			

		}
		return 0;




	}
}