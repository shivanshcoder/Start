#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<fstream>
#include<istream>
#include<conio.h>

using namespace std;

void inchar(istream& in, char& c);
void inchar_enter(char& c);
void inchar_enter(char& c, vector<int>splchars);

int splchar(char c);

int int_length(int num);
int long_length(long long num);

void hide_files(bool hide);
bool cinclear(istream& is);


	void input_int(istream& io,string statement, string type, int &num);
	void input_int(istream& io,long long& num, int digits);
	void input_int(istream& io,int& num, int digits);
	void input_int(istream& io, int& num);
	void input_int(istream& io, long long& num);

	void input_string(istream& io,string Question, string &ans);
	void inputs(istream& io,string &s, bool alpha = false, int num_limit = 1, int alpc_limit = 1, string statement = "", char ch = '\n');
	void inputs(char charac, string &s, bool alpha = false, int num_limit = 1, int alpc_limit = 1, string statement = "");
	void string_enter(string& s, char charac = '\0');
	void wait(string s);
	void wait_sp(string s, int z,bool k);
	
	namespace encryption {

		void input_num(ifstream& is, int& n, int z,int digit);
		void output_num(ofstream& os, int n, int z,int digit);
		void input_num(ifstream& is, long long& n, int z,int digit);
		void output_num(ofstream& os, long long n, int z,int digit);

		void input_char(ifstream& is, char& s, int z);
		void output_char(ofstream& os, char s, int z);

		void input_str(ifstream& is, string& s, int z);
		void output_str(ofstream& os, string s, int z);

		void input_line(ifstream& is, vector<string>&s, int z);
		void output_line(ofstream& os, vector<string> s, int z);

		string encrypt(string s,int z);
		string decrypt(string s, int z);
		void decrypt(char& c, int z);
		void encrypt(char& c, int z);
}