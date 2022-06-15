//Source.cpp

#include"Project.h"
void RSA::rsa()
{
	PrimeNumbers();
	cout << endl;
	cout << "\n\n\t\tEnter First Prime Number: ";
	cin >> Prime_1;
	flag = CheckPrime(Prime_1);
	if (flag == 0)
	{
		cout << "\nInvalid Input Press Enter to try Again\n";
		_getch();
		system("cls");
		rsa();
	}
	cout << "\n\t\tEnter Second Prime Number: ";
	cin >> Prime_2;
	flag = CheckPrime(Prime_2);
	if (flag == 0 || Prime_1 == Prime_2)
	{
		cout << "\nInvalid Input Press Enter to try Again\n";
		_getch();
		system("cls");
		rsa();
	}
	cout << "\n\t\tPlease Enter You Message: ";
	cin.ignore();
	cin.getline(msg, 100);
	for (i = 0; msg[i] != '\0'; i++)
		m[i] = msg[i];
	n = Prime_1 * Prime_2;
	totient = (Prime_1 - 1) * (Prime_2 - 1);
	ce();
	encrypt();
}
void RSA::PrimeNumbers()
{
	cout << "\n\t\tPrime Numbers between 1 and 100 are:\n";

	for (int i = 2; i <= 1000; i++)
	{
		bool flag = false;

		for (int j = 2; j <= sqrt(i); j++)

		{
			if (i % j == 0)

				flag = true;

		}

		if (flag == false) //checking and printing prime numbers

			cout << i << " ";

	}
}

int RSA::CheckPrime(long int p)
{
	int i;
	j = sqrt(p);
	for (i = 2; i <= j; i++)
	{
		if (p % i == 0)
			return 0;
	}
	return 1;
}
void RSA::ce()
{
	int k;
	k = 0;
	for (i = 2; i < totient; i++)
	{
		if (totient % i == 0)
			continue;
		flag = CheckPrime(i);
		if (flag == 1 && i != Prime_1 && i != Prime_2)
		{
			e[k] = i;
			flag = cd(e[k]);
			if (flag > 0)
			{
				d[k] = flag;
				k++;
			}
			if (k == 99)
				break;
		}
	}
}
long int RSA::cd(long int x)
{
	long int k = 1;
	while (1)
	{
		k = k + totient;
		if (k % x == 0)
			return (k / x);
	}
}
void RSA::encrypt()
{
	long int pt, ct, key = e[0], k, len;
	i = 0;
	len = strlen(msg);
	while (i != len)
	{
		pt = m[i];
		pt = pt - 96;
		k = 1;
		for (j = 0; j < key; j++)
		{
			k = k * pt;
			k = k % n;
		}
		temp[i] = k;
		ct = k + 96;
		en[i] = ct;
		i++;
	}
	en[i] = -1;
	cout << "\n\t\tThe Encrypted Message is:";
	for (i = 0; en[i] != -1; i++)
		cout << (char)en[i];
}
void RSA::decrypt()
{
	long int pt, ct, key = d[0], k;
	i = 0;
	while (en[i] != -1)
	{
		ct = temp[i];
		k = 1;
		for (j = 0; j < key; j++)
		{
			k = k * ct;
			k = k % n;
		}
		pt = k + 96;
		m[i] = pt;
		i++;
	}
	m[i] = -1;
	cout << "\n\n\t\tThe Decrypted Message is: ";
	for (i = 0; m[i] != -1; i++)
		cout << (char)m[i];
}
void Caesar_Rotation13::CesearEncryption(string PlainText, int Key) {
		for (int i = 0, j = PlainText.length(); i < j; i++) {
			if (isalpha(PlainText[i])) { //isalpha function will check that if the character is letter or numeric character
				//if letter
				int Ascii;
				if (isupper(PlainText[i])) {
					//If the character is Upper case letter, (A=65)
					Ascii = 65;
				}
				if (islower(PlainText[i])) {
					//If the character is Lower case letter, (a=97)
					Ascii = 97;
				}
				int CipherText = ((int(PlainText[i]) - Ascii + Key) % 26 + Ascii); //Formula
				cout << (char)CipherText;
			}
			else { //if numberic character
				cout << PlainText[i];
			}
		}
	}
	

//For Decryptionsss
void Caesar_Rotation13::CesearDecryption(string CipherText, int Key) {
	for (int i = 0, j = CipherText.length(); i < j; i++) {
		if (isalpha(CipherText[i])) { //isalpha function will check that if the character is letter or numeric character
			//if letter
			int Ascii;
			if (isupper(CipherText[i])) {
				//If the character is Upper case letter, (A=65)
				Ascii = 65;
			}
			if (islower(CipherText[i])) {
				//If the character is Lower case letter, (a=97)
				Ascii = 97;
			}
			int PlainText = ((int(CipherText[i]) - Ascii - Key + 26) % 26 + Ascii); //Formula
			cout << (char)PlainText;
		}
		else { //if numberic character
			cout << CipherText[i];
		}
	}
}
//--------------------------------------------------------------------------//
//								Rot13 Cipher
//--------------------------------------------------------------------------//
void Caesar_Rotation13::Rot13Encryption(string message) {
	int x;
	char ch;
	for (int i = 0, j = message.length(); i < j; i++) {
		if (isalpha(message[i])) {


			if (isupper(message[i])) {
				x = (int)message[i];
				x = x + 13;
				if (x > 90) {
					x = x - 90 + 64;
					ch = (char)x;
				}
				else {
					ch = x;

				}
			}
			else if (islower(message[i])) {
				x = (int)message[i];
				x = x + 13;
				if (x > 122) {
					x = x - 122 + 96;
					ch = (char)x;
				}
				else {
					ch = x;

				}
			}
		}
		else {
			cout << message[i];
		}
		cout << ch;
	}
}

void Caesar_Rotation13::Rot13Decryption(string message) {
	int x;
	char ch;
	for (int i = 0, j = message.length(); i < j; i++) {
		if (isalpha(message[i])) {

			if (isupper(message[i])) {
				x = (int)message[i];
				x = x - 13;
				if (x < 65) {
					x = 91 - (65 - x);
					ch = (char)x;
				}
				else {
					ch = x;

				}
			}
			else if (islower(message[i])) {
				x = (int)message[i];
				x = x - 13;
				if (x < 97) {
					x = 123 - (97 - x);
					ch = (char)x;
				}
				else {
					ch = x;

				}
			}
		}
		else {
			cout << message[i];
		}
		cout << ch;
	}
}
void MD5::MD51(vector<int>& A, vector<int>& binary, int i)
{
	int carry = 0;
	for (int j = A.size() - 1; j >= 0; j--)
	{
		if (A.at(j) == 0 && binary.at(i) == 0 && carry == 0)
		{
			A.at(j) = 0;
			carry = 0;
		}
		else if (A.at(j) == 0 && binary.at(i) == 0 && carry == 1)
		{
			A.at(j) = 1;
			carry = 0;
		}
		else if (A.at(j) == 0 && binary.at(i) == 1 && carry == 0)
		{
			A.at(j) = 1;
		}
		else if (A.at(j) == 0 && binary.at(i) == 1 && carry == 1)
		{
			A.at(j) = 0;
			carry = 1;
		}
		else if (A.at(j) == 1 && binary.at(i) == 0 && carry == 0)
		{
			A.at(j) = 1;
		}
		else if (A.at(j) == 1 && binary.at(i) == 0 && carry == 1)
		{
			A.at(j) = 0;
			carry = 1;
		}
		else if (A.at(j) == 1 && binary.at(i) == 1 && carry == 0)
		{
			A.at(j) = 0;
			carry = 1;
		}
		else if (A.at(j) == 1 && binary.at(i) == 1 && carry == 1)
		{
			A.at(j) = 1;
			carry = 1;
		}
		i--;
	}
}
void MD5::MD52() {
m:
	system("cls");
	cout << "\n\n\n\t\t\t\t\t\t\t\t      _______________";
	cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
	cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
	cout << "\n\t\t\t\t\t\t\t\t     |\t\t\tMD5 HASH\t\t |";
	cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
	cout << "\n\t\t\t\t\t\t\t\t     |\t\t\t\t\t\t |";
	cout << "\n\t\t\t\t\t\t\t\t     |_______________|";
	string a, b;
	char choice;
	vector<int>A;
	vector<int>B;
	vector<int>C;
	vector<int>D;
	vector<int>total;
	long long int deci = 0;
	int c, mode, size, add = 0;
	vector<int>binary;
	for (int i = 0; i < 32; i++)
	{
		A.push_back(0);
		B.push_back(0);
		C.push_back(0);
		D.push_back(0);
	}
	cout << "\n\n\t\tPlease Enter Your Message: ";
	cin.ignore();
	getline(cin, a);
	for (int i = 0; i < a.size(); i++)
	{
		c = int(a[i]);
		binary.push_back(0);
		while (c != 0)
		{
			binary.push_back(c % 2);
			c = c / 2;
		}
	}
	size = binary.size();
	while (size > 0)
	{
		mode = size % 512;
		if (mode < 512)
		{
			add = 512 - mode;
		}
		size = size - 512;
	}
	for (int i = 0; i < add; i++)
	{
		if (i == 0)
			binary.push_back(1);
		else
		{
			binary.push_back(0);
		}
	}
	/*cout << binary.size() << endl;
	cout << binary.size() / 512;*/
	int k;
	for (int i = 0; i < binary.size() / 512; i++)
	{
		k = 511 * i;
		MD51(A, binary, 31 + k);
		MD51(B, binary, 63 + k);
		MD51(C, binary, 95 + k);
		MD51(D, binary, 127 + k);

		MD51(A, B, 31);
		MD51(A, C, 31);
		MD51(A, D, 31);

		MD51(D, binary, 159 + k);
		MD51(A, binary, 191 + k);
		MD51(B, binary, 223 + k);
		MD51(C, binary, 255 + k);

		MD51(D, A, 31);
		MD51(D, B, 31);
		MD51(D, C, 31);

		MD51(C, binary, 287 + k);
		MD51(D, binary, 318 + k);
		MD51(A, binary, 351 + k);
		MD51(B, binary, 383 + k);

		MD51(C, D, 31);
		MD51(C, A, 31);
		MD51(C, B, 31);

		MD51(B, binary, 415 + k);
		MD51(C, binary, 447 + k);
		MD51(D, binary, 479 + k);
		MD51(A, binary, 511 + k);

		MD51(B, C, 31);
		MD51(B, D, 31);
		MD51(B, A, 31);
	}

	for (int i = 0; i < 32; i++)
	{
		total.push_back(A.at(i));
		total.push_back(B.at(i));
		total.push_back(C.at(i));
		total.push_back(D.at(i));
	}
	cout << endl;
	int hexaa = 0;
	vector<char>hexa;
	int j = 0;
	for (int i = 1; i <= total.size(); i++)
	{

		hexaa = hexaa + (total.at(i - 1) * pow(2, j));
		if (i % 4 == 0)
		{
			if (hexaa < 10)
				hexa.push_back(hexaa + 48);
			else
				hexa.push_back(hexaa + 55);
			j = -1;
			hexaa = 0;
		}
		j++;
	}
	cout << "\t\tHash for your Message is: ";
	for (int i = 0; i < hexa.size(); i++)
	{
		cout << hexa.at(i);
	}
	cout << "\n\n\t\t\t\t\t\t\t\t\t  Press Enter to go to the Main: ";
	_getch();
	system("cls");
	return;
}
string DES::Dec_To_Bin(int D) {		// Function to convert decimal to binary
	string binary;
	for (int i = D; i != 0; i /= 2) {
		if (i % 2 == 0)
			binary += "0";
		else
			binary += "1";

	}
	while (binary.length() != 4) {
		binary += "0";
	}
	return binary;
}

int DES::Bin_To_Dec(string B) {	// Function to convert binary to decimal
	int dec = 0, count = 0;

	for (int i = B.length() - 1; i >= 0; i--, count++)
		if (B[i] == '1')
			dec += pow(2, count);

	return dec;
}

string DES::shift(string Unshifted, int term) {	// Function to do a circular left shift by 1
	string shifted = "";

	if (term == 1) {
		for (int i = 1; i < 28; i++)
			shifted += Unshifted[i];

		shifted += Unshifted[0];

	}
	else {
		for (int i = 0; i < 2; i++) {

			for (int j = 1; j < 28; j++)
				shifted += Unshifted[j];

			shifted += Unshifted[0];
		}
	}
	return shifted;
}

// Function to compute xor between two strings
string DES::Xor(string a, string b) {
	string Xored = "";

	for (int i = 0; i < b.size(); i++) {
		if (a[i] != b[i])
			Xored += "1";
		else
			Xored += "0";
	}
	return Xored;
}

void DES::generate_keys(string key) {

	int pc1[56] = {		// The PC1 table
	57,49,41,33,25,17,9,
	1,58,50,42,34,26,18,
	10,2,59,51,43,35,27,
	19,11,3,60,52,44,36,
	63,55,47,39,31,23,15,
	7,62,54,46,38,30,22,
	14,6,61,53,45,37,29,
	21,13,5,28,20,12,4
	};

	int pc2[48] = {		// The PC2 table
	14,17,11,24,1,5,
	3,28,15,6,21,10,
	23,19,12,4,26,8,
	16,7,27,20,13,2,
	41,52,31,37,47,55,
	30,40,51,45,33,48,
	44,49,39,56,34,53,
	46,42,50,36,29,32
	};

	string perm_key = "";
	for (int i = 0; i < 56; i++)
		perm_key += key[pc1[i] - 1];

	string left = perm_key.substr(0, 28);
	string right = perm_key.substr(28, 28);
	for (int i = 0; i < 16; i++) {

		if (i == 0 || i == 1 || i == 8 || i == 15) {
			left = shift(left, 1);
			right = shift(right, 1);
		}

		else {
			left = shift(left, 2);
			right = shift(right, 2);
		}

		string combined_key = left + right;
		string round_key = "";

		for (int i = 0; i < 48; i++) {
			round_key += combined_key[pc2[i] - 1];
		}
		R_Keys[i] = round_key;
	}

}

string DES::des() {

	int I_perm[64] = {		// The initial permutation table 
	58,50,42,34,26,18,10,2,
	60,52,44,36,28,20,12,4,
	62,54,46,38,30,22,14,6,
	64,56,48,40,32,24,16,8,
	57,49,41,33,25,17,9,1,
	59,51,43,35,27,19,11,3,
	61,53,45,37,29,21,13,5,
	63,55,47,39,31,23,15,7
	};

	int exp_table[48] = {		// The expansion table
	32,1,2,3,4,5,4,5,
	6,7,8,9,8,9,10,11,
	12,13,12,13,14,15,16,17,
	16,17,18,19,20,21,20,21,
	22,23,24,25,24,25,26,27,
	28,29,28,29,30,31,32,1
	};

	int sub_boxes[8][4][16] =
	{ {
		14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
		0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
		4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
		15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
	},
	{
		15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
		3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
		0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
		13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
	},
	{
		10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
		13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
		13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
		1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
	},
	{
		7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
		13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
		10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
		3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
	},
	{
		2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
		14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
		4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
		11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
	},
	{
		12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
		10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
		9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
		4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
	},
	{
		4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
		13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
		1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
		6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
	},
	{
		13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
		1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
		7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
		2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
	} };

	int perm_table[32] = {		// The permutation table
	16,7,20,21,29,12,28,17,
	1,15,23,26,5,18,31,10,
	2,8,24,14,32,27,3,9,
	19,13,30,6,22,11,4,25
	};

	int inverse_perm[64] = {		// The inverse permutation table
	40,8,48,16,56,24,64,32,
	39,7,47,15,55,23,63,31,
	38,6,46,14,54,22,62,30,
	37,5,45,13,53,21,61,29,
	36,4,44,12,52,20,60,28,
	35,3,43,11,51,19,59,27,
	34,2,42,10,50,18,58,26,
	33,1,41,9,49,17,57,25
	};

	string perm = "";
	for (int i = 0; i < 64; i++) {
		perm += P_text[I_perm[i] - 1];
	}

	string left = perm.substr(0, 32);
	string right = perm.substr(32, 32);

	for (int i = 0; i < 16; i++) {
		string r_expand = "", xored, res = "", row1, col1;

		for (int i = 0; i < 48; i++) {
			r_expand += right[exp_table[i] - 1];
		}
		xored = Xor(R_Keys[i], r_expand);

		for (int i = 0; i < 8; i++) {
			int row, col, val;
			row1 = xored.substr(i * 6, 1) + xored.substr(i * 6 + 5, 1);
			row = Bin_To_Dec(row1);
			col1 = xored.substr(i * 6 + 1, 1) + xored.substr(i * 6 + 2, 1) + xored.substr(i * 6 + 3, 1) + xored.substr(i * 6 + 4, 1);;
			col = Bin_To_Dec(col1);
			val = sub_boxes[i][row][col];
			res += Dec_To_Bin(val);
		}

		string perm2 = "", temp;
		for (int i = 0; i < 32; i++) {
			perm2 += res[perm_table[i] - 1];
		}

		xored = Xor(perm2, left);
		left = xored;
		if (i < 15) {
			temp = right;
			right = xored;
			left = temp;
		}
	}

	string comb_text = left + right, cipher = "";

	for (int i = 0; i < 64; i++) {
		cipher += comb_text[inverse_perm[i] - 1];
	}
	return cipher;
}