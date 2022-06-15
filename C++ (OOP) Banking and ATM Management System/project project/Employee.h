#pragma once

#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include <sstream>
using namespace std;


//***********************************************
//				   Employee Class	   			//
//***********************************************
class Employee  {  

	int amount, acc, pin, amount1;
	string name;
	char ch;
	long long int ph;
public:

	//*****************************************************************
	//    	function to create account & write data into the file	 //
	//*****************************************************************
	void write_account()
	{
		ofstream file;
		file.open("newaccount.txt", ios::app);

		//account ac;
		cout << "\n\tEnter The Name of The Account Holder: ";
		cin >> name;
		cout << "\n\n\tEnter The New Account Number Of User : ";
		cin >> acc;
		cout << "\n\tEnter The Type of Account (C/S): ";
		cin >> ch;
		cout << "\n\tEnter Phone Number Of User: ";
		cin >> ph;
		cout << "\n\tEnter The Initial amount Into The User Account: ";
		cin >> amount;
		
		cout << "\n\nAccount Created!";
		file << acc << " " << name << " " << ch << " " << amount << " " << ph << endl;
		file.close();

	}

	//*****************************************************************
	//       	function to open file and modify customer record	 //
	//*****************************************************************
	void modify()
	{
		
		int numLines = 0;
		ifstream in("newaccount.txt");
		string liine;
		while (getline(in, liine)) {
			++numLines;
		}


		string line, * nametemp = new string[numLines+1];
		char* chtemp = new char[numLines + 1];
		int* acctemp = new int[numLines + 1];
		int* acctemp1 = new int[numLines + 1];
		int* amounttemp = new int[numLines + 1];
		int* phoneNumber = new int[numLines + 1];
		int i = 0;
		ifstream inputFile("newaccount.txt");
		while (getline(inputFile, line))
		{
			istringstream obj(line);
			obj >> acctemp[i] >> nametemp[i] >> chtemp[i] >> amounttemp[i] >> phoneNumber[i];
			i++;

		}
		i = 0;
		int a, b;

		cout << "\n\n\tEnter Account Number:";
		cin >> a;
	h:
		if (a == acctemp[i])
		{
			cout << "\n\n\tEnter The  New Account Number: ";
			cin >> acctemp[i];
			cout << "\n\tEnter The New Name of The Account Holder: ";
			cin >> nametemp[i];
			cout << "\n\tEnter The New Type of Account (C/S): ";
			cin >> chtemp[i];
			cout << "\n\tEnter The New Initial amount : ";
			cin >> amounttemp[i];
			cout << "Enter New Phone Number: ";
			cin >> ph;
			cout << "\n\n\tAccount Modified!";
			ofstream file;
			file.open("newaccount.txt", ios::out);
			for (int i = 0; i < numLines; i++)
			{
				file << acctemp[i] << " " << nametemp[i] << " " << chtemp[i] << " " << amounttemp[i] << phoneNumber[i] << endl;
			}
			file.close();
			return;
		}
		else if (i == numLines)
		{
			cout << "\nRECORD NOT FOUND.\n";
		}
		else
		{
			i++;
			goto h;
		}

	}

	//*****************************************************************
	//				function to Display all customer records		 //
	//*****************************************************************
	void display_all()
	{
		ifstream inputFile("newaccount.txt");
		string line;
		int i = 0;


		while (getline(inputFile, line))
		{
			i++;
			istringstream obj(line);
			obj >> acc >> name >> ch >> amount;

			cout << "\t_____________________________________________" << endl;
			cout << "\n\t\tThe Account Number: " << acc << endl;
			cout << "\n\t\tThe Name of The Account Holder:" << name << endl;
			cout << "\n\t\tThe Type of Account (C/S): " << ch << endl;
			cout << "\n\t\tThe Initial amount : " << amount << endl;
			cout << "\t_____________________________________________" << endl;
		}
	}

	void Search_Customer()
	{
		
		int numLines = 0;
		ifstream in("newaccount.txt");
		string unused;
		while (getline(in, unused))
			++numLines;


		string line, * nametemp = new string[numLines + 1];
		char* chtemp = new char[numLines + 1];
		int* acctemp = new int[numLines + 1];
		int* amounttemp = new int[numLines + 1];
		int i = 0;
		ifstream inputFile("newaccount.txt");
		while (getline(inputFile, line))
		{
			istringstream obj(line);
			obj >> acctemp[i] >> nametemp[i] >> chtemp[i] >> amounttemp[i];
			i++;

		}
		i = 0;
		int a;

		cout << "\n\tEnter Account Number:";
		cin >> a;
	h:
		if (a == acctemp[i])
		{
			cout << "_____________________________________________" << endl;
			cout << "\n\tThe Account Number: " << acctemp[i] << endl;
			cout << "\n\tThe Name of The Account Holder:" << nametemp[i] << endl;
			cout << "\n\tThe Type of Account (C/S): " << chtemp[i] << endl;
			cout << "\n\tThe Initial amount : " << amounttemp[i] << endl;
			cout << "_____________________________________________" << endl;
			return;
		}
		else if (i == numLines)
		{
			cout << "\nRECORD NOT FOUND.\n";
		}
		else
		{
			i++;
			goto h;
		}


	}


	//********************************************************************
	//    Main function for the Employee & every function calling		//
	//********************************************************************
	void Employee_Main_Function()
	{
		char b;
		do{
			system("color 0C");
			l:
			system("cls");
			cout << "\n\n\n\t\tMAIN MENU";
			cout << "\n\n\t01. Add New Customer Account";
			cout << "\n\n\t02. Modify Customer Account";
			cout << "\n\n\t03. Display all Customers Accounts";
			cout << "\n\n\t04. Search Customer";
			cout << "\n\n\t05. EXIT";
			cout << "\n\n\tSelect Your Option (1-4): ";
			cin >> b;
			system("cls");
			switch (b)
			{
			case '1':
				write_account();
				system("pause");
				break;

			case '2':
				modify();
				system("pause");
				break;
			case '3':
				display_all();
				system("pause");
				break;
			case '4':
				Search_Customer();
				system("pause");
				break;
			case '5':

				cout << "\n\n\tThanks for using Bank Management System\n";
				system("pause");
				exit(1);
			default:
				cout << "\n\t\t\t\t Invalid Choice ";
				cout << "Press Enter to continue:"; _getch();
				goto l;

			}
		} while (b >= 1 || b <= 5);

	}
};
