#pragma once
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include <sstream>
#include"Admin.h"
#include"Employee.h"
using namespace std;
//*******************************************************************
//    						Customer Class						   //
//*******************************************************************
class Customer :public Employee { //Inherited From Employee Class
private:
	int amount, acc, pin, amount1;
	string name;
	char ch, chh;

public:
//************************************************************************
//    Main function for the Customer & every function calling			//
//************************************************************************


	void Main_Function()
	{
		char b;


		
		do {

			system("color 0C");
		l:
			system("cls");

			cout << "\n\n\n\t    MAIN MENU";

			cout << "\n\n\t01. DEPOSIT AMOUNT";
			cout << "\n\n\t02. WITHDRAW AMOUNT";
			cout << "\n\n\t03. BALANCE ENQUIRY";
			cout << "\n\n\t04. Go To The Employee:";
			cout << "\n\n\t05. EXIT";
			cout << "\n\n\tSelect Your Option (1-4) ";
			cin >> b;
			system("cls");

			switch (b)
			{
			case '1':
				deposit();
				system("pause");
				break;
			case '2':
				withdraw();
				system("pause");
				break;
			case '3':
				Balance_Inquiry();
				system("pause");
				break;
			case '4':

				Employee* Emp;
				Emp=new Employee();
				Emp->Employee_Main_Function();

			case '5':
				exit(0);
			default:
				cout << "\n\t\t\t\t Invalid Choice ";
				cout << "Press Enter to continue:"; _getch();
				goto l;
			}
		} while (b >= 1 || b <= 5);
		}
	
	//*****************************************************************
	//    	function to Do Balance Inquiry of a certain Account		 //
	//*****************************************************************
	void Balance_Inquiry()
	{
		ifstream inputFile("newaccount.txt");
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
		while (getline(inputFile, line))
		{
			istringstream obj(line);
			obj >> acctemp[i] >> nametemp[i] >> chtemp[i] >> amounttemp[i];
			i++;

		}
		i = 0;
		int a, b;

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
	//*****************************************************************
	//    		function to deposit money into the account			 //
	//*****************************************************************
	void deposit()
	{
		ifstream inputFile("newaccount.txt");
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
		while (getline(inputFile, line))
		{
			istringstream obj(line);
			obj >> acctemp[i] >> nametemp[i] >> chtemp[i] >> amounttemp[i];
			i++;
		}
		i = 0;
		int a, b;

		cout << "\n\tEnter Account Number:";
		cin >> a;
	h:
		if (a == acctemp[i])
		{
			cout << "\n\tEnter Amount to Deposit:";
			cin >> b;
			amounttemp[i] = amounttemp[i] + b;
			cout << "\nRecord Updated!";
			ofstream file;
			file.open("newaccount.txt", ios::out);
			for (int i = 0; i < numLines; i++)
			{
				file << acctemp[i] << " " << nametemp[i] << " " << chtemp[i] << " " << amounttemp[i] << endl;
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
	//    		function to withdraw money from the account			 //
	//*****************************************************************

	void withdraw()
	{
		ifstream inputFile("newaccount.txt");
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
		while (getline(inputFile, line))
		{
			istringstream obj(line);
			obj >> acctemp[i] >> nametemp[i] >> chtemp[i] >> amounttemp[i];
			i++;
		}
		i = 0;
		int a, b;

		cout << "\n\tEnter Account Number:";
		cin >> a;
	h:
		if (a == acctemp[i])
		{
			cout << "\n\tEnter Amount to Withdraw:";
			cin >> b;
			amounttemp[i] = amounttemp[i] - b;
			cout << "\nRecord Updated!";
			ofstream file;
			file.open("newaccount.txt", ios::out);
			for (int i = 0; i < numLines; i++)
			{
				file << acctemp[i] << " " << nametemp[i] << " " << chtemp[i] << " " << amounttemp[i] << endl;
			}

			file.close();
			return;
		}
		else if (i == numLines)
		{
			cout << "\n\tRECORD NOT FOUND.\n";
		}
		else
		{
			i++;
			goto h;
		}
	}


};