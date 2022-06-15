#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<cstring>
#include <sstream>
#include"Customer.h"
#include"Atm.h"
#include"Admin.h"
#include"Employee.h"
using namespace std;

//Main Function
int main()
{
	int ch;

	system("color 0b");
	cout << "\t\t\t\t\t\t WELCOME TO" << endl;
	cout << "\t\t\t\t\t\t------------" << endl;
	cout << "\n\n\t\t\t\tB A N K    M A N A G E M E N T\tS Y S T E M  ";
	cout << "\n\n\t\t\t\t\t\t      &";
	cout << "\n\n\t\t\t     A U T O M A T E D   T E L L E R    M A C H I N E " << endl << endl;;

	cout << "\nPress Enter to continue:";
	cin.get();
	system("cls");
	for (int i = 0; i < 5; i++)
	{

	l:
		system("color 0A");
		system("cls");
		cout << "\n\n\t  -------------------------------------------------------------------------------------------------------" << endl;
		cout << "\t  |\t\t\t\t\t\tBANK OF PAKISTAN\t\t\t\t\t|" << endl;
		cout << "\t  |\t\t\t\t\t  ATM & BANK MANAGENMENT SYSTEM\t\t\t\t\t|" << endl;
		cout << "\t  -------------------------------------------------------------------------------------------------------" << endl;
		cout << "\t  |\t\t\t\t\t\t\t\t\t\t\t\t\t|";
		cout << "\n\t  |\t\t\t\t\tPress 1 To Enter BANK\t\t\t|\t\t\t|" << endl;
		cout << "\t  |\t\t\t\t\t\t\t\t\t\t|\tATM MACHINE\t|" << endl;
		cout << "\t  |\t\t\t\t\t\t\t\t\t\t|    Press 2 to Enter\t|" << endl;
		cout << "\t  |_____________________________________________________________________________________________________|" << endl;
		cout << "\n\t Press 1 or 2: ";
		ch = _getch();

		switch (ch)
		{
		case '1':
			system("cls");
			int i;
		z:
			cout << "\n\n\t  -------------------------------------------------------------------------------------------------------" << endl;
			cout << "\t  |\t\t\t\t\t\tBANK OF PAKISTAN\t\t\t\t\t|" << endl;
			cout << "\t  |\t\t\t\t\t  ATM & BANK MANAGENMENT SYSTEM\t\t\t\t\t|" << endl;
			cout << "\t  -------------------------------------------------------------------------------------------------------" << endl;
			cout << "\t  |\t\t\t\t\t\t\t\t\t\t\t\t\t|";
			cout << "\t\t\t  |_____________________________________________________________________________________________________|" << endl;
			cout << "\n\n\t\t\t\t\t 1:Enter as a Admin:" << endl;
			cout << "\t\t\t\t\t 2:Enter as a Employee:" << endl;
			cout << "\t\t\t\t\t 3:Enter as a Customer:" << endl;
			cout << "\t\t\t\t\t 4:Go Back:" << endl;

			cout << "\n\t\t\t\t Enter Your Choice...: ";
			cin >> i;
			if (i == 1)
			{
				Admin p;
				p.admin_password();
				p.Main_Function();
				break;

			}
			else if (i == 2)
			{
				Employee p;
				p.Employee_Main_Function();
				break;
			}
			else if (i == 3)
			{
				Customer p;
				p.Main_Function();
				break;
			}
			else if (i == 4)
			{
				goto l;
			}


			else {
				cout << "\n\t\t\t\t\tInvalid Choice:";
				cout << "\n\n\t\t\t\t\t\tPress any key to continue:"; _getch();
				system("cls");
				goto z;

			}

		case '2':
			try {
				atm At;
				At.Main_Function();
			}
			catch (...)
			{
				cout << "Wrong Input:";
				system("pause");
				_getch();
			}
		
		}
	}
		
	
	return 0;
}