#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<fstream>
#include<istream>
#include<conio.h>
#include"input_functions.h"

using namespace std;
using namespace input_functions;

namespace Helpers {

	void force_close();

	void create_LOG();

	struct email {
		string username, domain, id;
		void cls();
		bool check(char c, char termin, string s);
	};
	struct Address {
		string house_num, city, state;
		int sector;
	};
	struct car_num {
		string car_name, car_manf;
		char state[2], code[2];
		char num_ini[2];
		int num_last;
		void input();
	};
	struct person {
		string name;
		long long mobile_num;
		int age;
		email id;
		Address home;
		car_num cars;
		void input();
		void out_file(string name);
		void in_file();
	};
	struct Agent {
		person p;
		string post, username, password;
		int level;
		vector<string>description;
		//void input();
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

	istream& operator >> (istream& is, email& e);
	ostream& operator << (ostream& os, email& e);
	ifstream& operator >> (ifstream& is, email& e);
	ofstream& operator << (ofstream& os, email& e);

	istream& operator >> (istream& is, Address& a);
	ostream& operator << (ostream& os, Address& a);
	ifstream& operator >> (ifstream& is, Address& a);
	ofstream& operator << (ofstream& os, Address& a);

	istream& operator >> (istream& is, car_num& c);
	ostream& operator << (ostream& os, car_num& c);
	ifstream& operator >> (ifstream& is, car_num& c);
	ofstream& operator << (ofstream& os, car_num& c);

	istream& operator >> (istream& is, person& p);
	ostream& operator << (ostream& os, person& p);
	ifstream& operator >> (ifstream& is, person& p);
	ofstream& operator << (ofstream& os, person& p);

	istream& operator >> (istream& is, Agent& a);
	ostream& operator << (ostream& os, Agent& a);
	ifstream& operator >> (ifstream& is, Agent& a);
	ofstream& operator << (ofstream& os, Agent& a);
}