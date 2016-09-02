#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<fstream>
#include<istream>
#include<conio.h>
using namespace std;

namespace input_functions{

	int int_length(int num);
	int long_length(long long num);

	void hide_files(bool hide);

	void input_int(istream& io,string statement, string type, int &num);
	void input_int(istream& io,long long& num, int digits);
	void input_int(istream& io,int& num, int digits);
	void input_string(istream& io,string Question, string &ans);
	void inputs(istream& io,string &s, bool alpha = false, int num_limit = 1, int alpc_limit = 1, string statement = "", char ch = '\n');


}