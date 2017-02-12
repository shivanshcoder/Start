#pragma once

#include"input_functions.h"

using namespace std;
using namespace encryption;

namespace Helpers {

	void force_close();
	void login_session(int start);
	void add_LOG(string username);
	void see_log();
	struct names {
		string name;
	};
	struct ID {
		string username, password;
		int level;
		void cls() { username.clear(); password.clear(); level = 0; }
	};
	struct paragraph {
		vector<string>para;
	};
	struct email {
		string username, domain, id;
		void cls();
		bool check(char c, char termin, string s);
	};
	struct Address {
		string house_num, city, state,sector;
	};
	struct vehicle {
		string vehicle_name, vehicle_manf;
		string color;
		char state[2], code[2];
		char num_ini[2];
		int num_last;
	};
	struct person {
		names name;
		vector<Address>home;
		long long mobile_num;
		int age;
		email id;
	};
	struct Agent {
		vector<vehicle>car;
		person p;
		string post;
		ID id;
		paragraph description;
		bool filled;
	};
	struct Criminal {
		vector<vehicle>cars;
		paragraph last_seen;
		int number_of_cases;
		paragraph case_charged;
		string status;
		person p;
		vector<char>code;
		int level_threat;
	};
	struct Suspect {
		person p;
		vector<vehicle>cars;
		vector<string>cause;
	};
	istream& operator >> (istream& is, names& s);

	istream& operator >> (istream& is, paragraph& para);
	ostream& operator << (ostream& os, paragraph& para);
	ifstream& operator >> (ifstream& is, paragraph& para);
	ofstream& operator << (ofstream& os, paragraph& para);

	istream& operator >> (istream& is, email& e);
	ostream& operator << (ostream& os, email& e);
	ifstream& operator >> (ifstream& is, email& e);
	ofstream& operator << (ofstream& os, email& e);

	istream& operator >> (istream& is, Address& a);
	ostream& operator << (ostream& os, Address& a);
	ifstream& operator >> (ifstream& is, Address& a);
	ofstream& operator << (ofstream& os, Address& a);

	istream& operator >> (istream& is, vehicle& c);
	ostream& operator << (ostream& os, vehicle& c);
	ifstream& operator >> (ifstream& is, vehicle& c);
	ofstream& operator << (ofstream& os, vehicle& c);

	istream& operator >> (istream& is, person& p);
	ostream& operator << (ostream& os, person& p);
	ifstream& operator >> (ifstream& is, person& p);
	ofstream& operator << (ofstream& os, person& p);

	istream& operator >> (istream& is, Agent& a);
	ostream& operator << (ostream& os, Agent& a);
	ifstream& operator >> (ifstream& is, Agent& a);
	ofstream& operator << (ofstream& os, Agent& a);

	istream& operator >> (istream& is, Criminal& c);
	ostream& operator << (ostream& os, Criminal& c);
	ifstream& operator >> (ifstream& is, Criminal& c);
	ofstream& operator << (ofstream& os, Criminal& c);
}