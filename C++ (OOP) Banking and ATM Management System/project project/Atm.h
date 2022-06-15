#pragma once
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include <sstream>
using namespace std;

double balance1;//globally defined
	//****************************************************
	//					  Atm Class	   			        //
	//****************************************************
class atm  {   //Inherited from Base class
private:
	int password, pincode;
	double withdraw, deposit;

public:
	//****************************************************
	//			function for intro screen for ATM	    //
	//****************************************************
	void logo()
	{
		cout << "\t\t\t\t    -----------------------------------------";
		cout << "\n\t\t\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
		cout << "\n\t\t\t\t          # Welcome To OOP Final - Project #";
		cout << "\n\t\t\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
		cout << "\n\t\t\t\t    -----------------------------------------";
		cout << "\n\n\n\t\t   ***************************************************************************";
	}

	void logopw()
	{
		system("color 0b");
		cout << "\t\t\t\t**  Password for Aeraf Ali          IS 200954   ** \n";

		cout << "\n\n\n\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
		system("pause");
		system("cls");
	}

	//****************************************************
	//				void functions for ATM			    //
	//****************************************************

	void case1()  
	{
		cout << "\n-----B A L A N C E-----\n";
		cout << "\n Your current balance is RS " << balance1 << endl;
		system("pause");
		system("cls");
	}

	void case2()
	{
		cout << "\n-----W I T H D R A W A L-----\n";
		cout << "Enter amount in Rupees: ";
		cin >> withdraw;
		if (withdraw > balance1)
		{
			cout << "insufficient balance";
		}
		else
		{
			balance1 = balance1 - withdraw;
		}
		cout << "\nYou Withdrew RS: " << withdraw << endl;
		cout << "Your Remaining Balance is RS: " << balance1 << endl;
		system("pause");
		system("cls");
	}

	void case3()
	{
		cout << "\n-----D E P O S I T-----\n";
		cout << "Enter amount in RS: ";
		cin >> deposit;
		balance1 = balance1 + deposit;
		cout << "You Deposited RS: " << deposit << endl;
		cout << "Your New Balance is RS: " << balance1 << endl;
		system("pause");
		system("cls");
	}

	void case4()
	{
		system("cls");
		exit(0);
	}
	
	//*************************************************
	//			function for main menu for ATM		 //
	//*************************************************
	void menu()
	{
		system("color 0E");
		cout << "\n\n\n\t\t**********************\n";
		cout << "\t\t     !Main Screen!    \n";
		cout << "\t\t1. Show My Balance \n";
		cout << "\t\t2. Withdraw \n";
		cout << "\t\t3. Deposit \n";
		cout << "\t\t4. Quit \n";
		cout << "\n";
		cout << "\tEnter Option: ";
	}

	//*************************************************
	//		   Main function for Working of ATM		 //
	//*************************************************
	void Main_Function()
	{

		system("cls");
		logo();
		cout << "\n";
		logopw();

		
				cout << "\n\n\t\t\tWelcome To ATM Machine  \n\t\t\t  We are on Main Page \n\n";
			cout << "\n\tPLEASE ENTER THE PINCODE: ";
			cin >> pincode;
			system("cls");
			if (pincode == 200954)
			{
				cout << "\n\t Welcome Aeraf Ali ! \n";
				for (int i = 0; i < 3; i++)
				{
					cout << "\tEnter Your Password : ";
					cin >> password;
					system("cls");
					double balance = 52000;
					balance1 = balance;
					if (password == 200954)
					{
						for (int i = 1; i <= 10; i++)
						{
							withdraw, deposit;
							int option;
							cout << "\n";
							if (i == 1)
							{
								cout << "\t\t Welcome To Automated Teller Machine" << endl;

								cout << "\n\t\t\tChoose a Transcition! \n\n";
								cout << "\n";
							}
							menu();
							option = _getch();

							switch (option)
							{
							case '1':
								case1();
								continue;
							case '2':
								case2();
								continue;
							case '3':
								case3();
								continue;
							case '4':
								case4();
								break;
							default:
								cout << "\n\t You have Entered an Invalid Option, Please enter a valid option from above:  \n";
								system("pause");
								continue;
							}
							break;
						}
						break;
					}
					else if (i == 2)
					{
						cout << "\n\t The Card is Captured due to Wrong Password \n";
						system("pause");
					}
					else
						cout << "\n\n\n\t\tPlease Enter the Correct Password or Your card will be Captured \n";
				}
			}
			else {
			cout << "\n\n\n\t\t\t\tWorng Input: Please try again:\n";
			system("pause");
			cout << "\nPress any key to continue:";
}
		}
	
};


