//Project.h

#include<iostream>
#include<iostream>
#include<string.h>
#include<string>
#include<conio.h>
#include<vector>
#include<math.h>
using namespace std;
class RSA
{
public:
	long int Prime_1, Prime_2, e[100], d[100], temp[100], j, m[100], n, totient, flag, en[100], i;
	char msg[1000];
	void rsa();
	int CheckPrime(long int);
	void ce();
	long int cd(long int);
	void encrypt();
	void decrypt();
	void PrimeNumbers();
};
class Caesar_Rotation13
{
public:
	void CesearEncryption(string, int);
	void CesearDecryption(string, int);
	void Rot13Encryption(string);
	void Rot13Decryption(string);
};
class MD5
{
public:
	void MD51(vector<int>& A, vector<int>& binary, int i);
	void MD52();
};
class DES
{
public:
	string R_Keys[16];
	string P_text;
	string Dec_To_Bin(int D);
	int Bin_To_Dec(string B);
	string shift(string Unshifted, int term);
	string Xor(string a, string b);
	void generate_keys(string key);
	string des();
};