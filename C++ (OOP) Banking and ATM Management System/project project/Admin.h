#pragma once
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include <sstream>
#include"Employee.h"
using namespace std;
//**************************************************************
//							Admin Class						  //	
//**************************************************************

class Admin:public Employee{   
	int amount, acc, pin, amount1, salary, age, id;
	string name, Email;
	char ch;
	long long int ph;
public:
	bool admin_password() {
		string ID,Pass;
		bool temp_v = true;


		


		do {
			string pass = "";
			char ch;
			cout << "\t\tEnter password:\n";
			ch = _getch();
			while (ch != 13) {
				pass.push_back(ch);
				cout << '*';
				ch = _getch();
			}
			if (pass == "aeraf200954") {
				cout << "\nAccess granted :P\n";
				cout << "\t\t\t\t\tPassword is Valid: " << endl << endl;
				cout << "\t\t\t\t\tPress Enter To Continue:"; _getch();
				temp_v = true;
			}
			else {
				cout << "\nAccess aborted...\n";
				cout << "\t\t\t\t\tInvalid Input:" << endl << endl;
				temp_v = false;
			}
			
			 
		} while (temp_v == false);
		return temp_v;
	}
	//********************************************************************
	//      Main function for the Admin & every function calling		//
	//********************************************************************
	void Main_Function()
	{
		char b;
		do{


			system("color 0C");
			l:
			system("cls");
			cout << "\n\n\n\tMAIN MENU";
			cout << "\n\n\t01. Add New Employee:";
			cout << "\n\n\t02. Add New Customer:";
			cout << "\n\n\t03. MODIFY Customer ACCOUNT";
			cout << "\n\n\t04. DISPLAY  ALL Employee ACCOUNTS";
			cout << "\n\n\t05. DISPLAY  ALL Customer ACCOUNTS";
			cout << "\n\n\t06. Search Customer";
			cout << "\n\n\t07. Search Employee";
			cout << "\n\n\t08. EXIT";
			cout << "\n\n\tSelect Your Option (1-8) ";
			cin >> b;
			system("cls");
			
			
				switch (b)
				{
				case '1':
					write_account();
					system("pause");
					break;
				case '2':
					write_account_customer();
					system("pause");
					break;
				case '3':
					modify_customer();
					system("pause");
					break;
				case '4':
					display_all_Employee();
					system("pause");
					break;
				case '5':
					display_all_customers();
					system("pause");
					break;
				case'6':
					Search_Customer();
					system("pause");
					break;
				case'7':
					Search_Employee();
					system("pause");
					break;
				case'8':
					cout << "\n\n\tThanks for using Bank Management System\n";
					system("pause");
					exit(1);
				default:
					
					
						cout << "\n\t\t\t\t Invalid Choice ";
						cout << "Press Enter to continue:"; _getch();
						goto l;
					
					

				}
			
	} while (b >= 1 || b <= 8);



	}
	//*****************************************************************
	//    	function to create account & write data into the file	 //
	//*****************************************************************
	void write_account()
	{
		ofstream file;
		file.open("Employee_accounts.txt", ios::app);

		//account ac;
		cout << "\n\tEnter The Name of New Employee: ";
		cin >> name;
		cout << "\n\tEnter The ID of New Employee:";
		cin >> id;
		cout << "\n\tEnter Phone Number Of Employee: ";
		cin >> ph;
		cout << "\n\tEnter Email of Employee:";
		cin >> Email;
		cout << "\n\tStarting Salary of Employee:";
		cin >> salary;
		cout << "\n\nAccount Created!";
	
		file << name << " " <<" " <<id <<" "<< ph << " " << Email << " " << salary << endl;
		file.close();

	}

	//*****************************************************************
	//    	function to create account & write data into the file	 //
	//*****************************************************************
	void write_account_customer()
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
	void modify_customer()
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
			obj >> acctemp[i] >> nametemp[i] >> chtemp[i] >> amounttemp[i] ;
			i++;
		}
		i = 0;
		int a;

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
			
			cout << "\n\n\tAccount Modified!";
			ofstream file;
			file.open("newaccount.txt", ios::out);
			for (int i = 0; i < numLines; i++)
			{
				file << acctemp[i] << " " << nametemp[i] << " " << chtemp[i] << " " << amounttemp[i]<< endl;
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
	void display_all_customers()
	{
		ifstream inputFile("newaccount.txt");
		string line;
		
		

		while (getline(inputFile, line))
		{
			istringstream ss(line);
			ss >> acc >> name >> ch >> salary;
			cout << "____" << endl;
			cout << "\nThe Account Number: " << name << endl;
			cout << "\nThe Name of The Account Holder:" << acc << endl;
			cout << "\nThe Type of Account (C/S): " << ch << endl;
			cout << "\nThe Initial amount : " << salary << endl;
			cout << "____" << endl;

		}




	}
	//*****************************************************************
	//				function to Display all Employee records		 //
	//*****************************************************************
	void display_all_Employee()
	{
		ifstream inputFile("Employee_accounts.txt", ios::app);
		string line;
		
		while (getline(inputFile, line))
		{

			istringstream obj(line);
			obj >> name >> id >> ph >> Email >> salary;


			cout << "\t_____________________________________________" << endl;
			cout << "\n\tName of  Employee: " << name << endl;
			cout << "\n\tID of Employee:" << id << endl;
			cout << "\n\tPhone Number of Employee: " << ph << endl;
			cout << "\n\tEmail of Employee : " << Email << endl;
			cout << "\n\tSalary of Employee : " << salary<<endl;
			cout << "\t_____________________________________________" << endl;
		}
	}

	void Search_Customer()
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


	void Search_Employee()
	{
		ifstream inputFile("Employee_accounts.txt");
		int numLines = 0;
		ifstream in("Employee_accounts.txt");
		std::string unused;
		while (std::getline(in, unused))
			++numLines;



		string line, * nametemp = new string[numLines + 1];
		int* idtemp = new int[numLines + 1];
		int* phtemp = new int[numLines + 1];
		int* acctemp = new int[numLines + 1];
		int* Emailtemp1 = new int[numLines + 1];
		int* salarytemp = new int[numLines + 1];
		int i = 0;
		while (getline(inputFile, line))
		{
			istringstream obj(line);
			obj >> nametemp[i] >> idtemp[i] >> phtemp[i] >> Emailtemp1[i] >> salarytemp[i];
			i++;
		}

		i = 0;
		int a;

		cout << "\n\n\tEnter The ID of Employee:";
		cin >> a;
	h:
		if (a == idtemp[i])
		{
			cout << "\t_____________________________________________" << endl;
			cout << "\n\tName of  Employee: " << name << endl;
			cout << "\n\tID of Employee:" << id << endl;
			cout << "\n\tPhone Number of Employee: " << ph << endl;
			cout << "\n\tEmail of Employee : " << Email << endl;
			cout << "\n\tSalary of Employee : " << salary << endl;
			cout << "\t_____________________________________________" << endl;
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
};
