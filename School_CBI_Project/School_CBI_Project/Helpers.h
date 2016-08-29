#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

namespace Helpers {

	void input_int(string statement, string type, int &num);
	void input_int(long long & num, int digits);
	void input_int(int& num, int digits);
	void input_string(string Question, string &ans);
	void inputs(string &s, bool alpha = false, int num_limit = 1, int alpc_limit = 1, string statement = "", char ch = '\n');

	void create_LOG();

	struct email {
		string username, domain, id;
		void cls();
		bool check(char c, char termin, string s);
		void input();
	};
	struct Address {
		string house_num, city, state;
		int sector;
		void input();
	};
	struct car_num {
		string car_name, car_manf;
		char state[2], code[2];
		int num_ini, num_last;
		void input();
	};
	struct person {
		string name;
		long long mobile_num;
		int age;
		email id;
		Address home;
		vector<car_num>cars;
		void input();
		void out_file(string name);
		void in_file();
	};
	struct Agent {
		person p;
		string post, username, password;
		int level;
		vector<string>description;
		void input();
	};
	struct Criminal {
		person p;
		char code[10];
		int level_threat;
		void input();
	};
	struct Suspect {
		person p;
		vector<string>cause;
		void input();
	};

}