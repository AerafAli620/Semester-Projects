//main.cpp
/*********************************************************************
************** Data Structure Project*********************
************** ***SUBMITTED BY GROUP MEMBERS *************************
******************ALI HAIDER    200982********************************
******************Aeraf ********************************
******************Alyan Malik 200996********************************
**********************************************************************/
#include"Project.h"
int main() {
	RSA R1;
	Caesar_Rotation13 C1;
	MD5 m1;
	DES d1;
a:
	cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t  Data Structures And Algorithums";
	cout << "\n\t\t\t\t\t\t\t ______________________________________________________________";
	cout << "\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|" << endl;
	cout << "\n\t\t\t\t\t\t\t|\t\t\t   Cyptography \t\t\t\t|" << endl;
	cout << "\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|" << endl;
	cout << "\n\t\t\t\t\t\t\t|\t\t\t     Made By:\t\t\t\t|" << endl;
	cout << "\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|" << endl;
	cout << "\n\t\t\t\t\t\t\t|\t\t\t\tAeraf Ali\t\t\t|" << endl;
	cout << "\n\t\t\t\t\t\t\t|______________________________________________________________|\n\n" << endl;
	int choice;
	char choice1;
	int Key;
	string PlainText, CipherText;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t1) Ceaser Cipher.\n";
	cout << "\t\t\t\t\t\t\t\t\t\t2) ROT 13 Cipher.\n";
	cout << "\t\t\t\t\t\t\t\t\t\t3) MD5 HASH.\n";
	cout << "\t\t\t\t\t\t\t\t\t\t4: RSA Encryption.\n";
	cout << "\t\t\t\t\t\t\t\t\t\t5: Data Encryption Standard(DES).\n";
	cout << "\t\t\t\t\t\t\t\t\t\tEnter Your Choice: ";
	cin >> choice;
	if (choice == 1) {
		system("cls");
		cout << "\n\n\n\t\t\t\t\t\t\t\t      ___________________________________________";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t      Caeser Cipher\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |___________________________________________|";

		cout << "\n\n\t\tEnter Any Message In PlainText: ";
		cin.ignore();
		getline(cin, PlainText);
b:
		cout << "\t\tEnter The key: ";
		cin >> Key;
		if (Key >= 1 && Key <= 26)
		{
			cout << "\n\n\t\tCeaserCipher: ";
			C1.CesearEncryption(PlainText, Key);
		}
		if (Key >= -26 || Key <= -1)
		{
			Key = Key * -1;
			cout << "\n\n\t\tCeaserCipher: ";
			C1.CesearEncryption(PlainText, Key);
		}

		cout << endl << endl;
		cout << "\n\n\t\t\t\t\t\t\t\t\tDo you want to Decrypt This(Y OR N): ";
		cin >> choice1;
		if (choice1 == 'Y' || choice1 == 'y') {
			cin.ignore();
			cout << "\t\tEnter Any Message In CipherText: ";
			getline(cin, CipherText);
c:
			cout << "\t\tEnter The key: ";
			cin >> Key;
			if (Key >= 1 && Key <= 26)
			{
				cout << "\n\n\t\tPlainText: ";
				C1.CesearDecryption(CipherText, Key);
			}
			else if (Key >= -26 || Key <= -1)
			{
				Key = Key * -1;
				cout << "\n\n\t\tPlainText: ";
				C1.CesearDecryption(CipherText, Key);
			}
			
			cout << "\n\n\t\t\t\t\t\t\t\t\t  Press Enter to go to the Main: ";
			_getch();
			system("cls");
			goto a;
		}
		else {
			cout << "\n\n\t\t\t\t\t\t\t\t\t  Press Enter to go to the Main: ";
			_getch();
			system("cls");
			goto a;
		}
	}
	else if (choice == 2) {
		system("cls");
		cout << "\n\n\n\t\t\t\t\t\t\t\t      ___________________________________________";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t      ROT13 Encryption\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |___________________________________________|";
		string PlainText, CipherText;
		char choice1;
		cout << "\n\n\t\tEnter Any PlainText: ";
		cin.ignore();
		getline(cin, PlainText);
		cout << "\n\n\t\tROT 13 Cipher: ";
		C1.Rot13Encryption(PlainText);
		cout << "\n\n\t\t\t\t\t\t\t\t\tDo you want to Decrypt This(Y OR N): ";
		cin >> choice1;
		if (choice1 == 'Y' || choice1 == 'y') {
			cin.ignore();
			cout << "\n\n\t\tEnter Any CipherText: ";
			getline(cin, CipherText);
			cout << "\n\n\t\tPlain Text: ";
			C1.Rot13Decryption(CipherText);
			cout << "\n\n\t\t\t\t\t\t\t\t\t  Press Enter to go to the Main: ";
			_getch();
			system("cls");
			goto a;
		}
		else {
			cout << "\n\n\t\t\t\t\t\t\t\t\t  Press Enter to go to the Main: ";
			_getch();
			system("cls");
			goto a;
		}

	}
	else if (choice == 3) {
		m1.MD52();
		goto a;
	}
	else if (choice == 4)
	{
		system("cls");
		cout << "\n\n\n\t\t\t\t\t\t\t\t      ___________________________________________";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t      RSA Encryption\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |___________________________________________|";
		R1.rsa();
		char ch = 'n';
		int p1, p2;
		cout << "\n\t\tDo You Want to Decrypt it(Y or N): ";
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "\n\t\tPlease Enter Prime Numbers That used for encryption: ";
			cin >> p1 >> p2;
			if (p1 == R1.Prime_1 && p2 == R1.Prime_2)
			{
				R1.decrypt();
			}
			else
				cout << "\n\t\tSorry Your Entered Prime Numbers Is Invalid" << endl;
		}
		else
		{
			cout << "\n\n\t\t\t\t\t\t\t\t\t  Press Enter to go to the Main: ";
			_getch();
			system("cls");
			goto a;
		}

	}
	else if (choice == 5) {
		system("cls");
		cout << "\n\n\n\t\t\t\t\t\t\t\t      ___________________________________________";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t      DES Encryption\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t\t     |___________________________________________|";
		string key, apt, temp, ct, decrypted;

		cout << "\n\t\tPlease Enter Text: ";
		cin.ignore();
		getline(cin, d1.P_text);
		cout << "\n\t\tPlease Enter Key: ";
		cin.ignore();
		getline(cin, key);
		apt = d1.P_text;
		d1.generate_keys(key);
		cout << "\n\n\t\tPlain text: " << d1.P_text << endl;
		ct = d1.des();
		cout << "\n\t\tCiphertext: " << ct << endl << endl;
		int i = 15;
		int j = 0;
		while (i > j) {
			temp = d1.R_Keys[i];
			d1.R_Keys[i] = d1.R_Keys[j];
			d1.R_Keys[j] = temp;
			i--;
			j++;
		}
		d1.P_text = ct;
		decrypted = d1.des();
		char ch;
		string Key;
		cout << "\n\t\tDo You Want to Decrypt it(Y or N): ";
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "\n\t\tPlease Enter Key Which is  used for encryption: ";
			cin.ignore();
			getline(cin, Key);
			if (Key == key)
			{
				cout << "\t\tDecrypted text: " << decrypted << endl << endl;
			}
			else
				cout << "\n\t\tSorry Your Entered Key Is Invalid" << endl;
		}
		else
		{
			cout << "\n\n\t\t\t\t\t\t\t\t\t  Press Enter to go to the Main: ";
			_getch();
			system("cls");
			goto a;
		}
	}
	return 0;
}
