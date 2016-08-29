#include"Helpers.h"
#include<stdlib.h>
namespace Helpers {
	
	void email::cls() {
		username.clear();
		domain.clear();
		id.clear();
	}
	bool email::check(char c, char termin, string s) {
		if (c == termin) {
			cls();
			cout << s << " Expected!!\n";
			return false;
		}
		return true;
	}
	void email::input() {
		cout << "Enter your Email-ID:";
		char c;
		cin >> c;
		while (c != '@') {
			username += c;
			cin.get(c);
			if (!check(c, '\n', "@")) return;
		}
		id += username;
		id += '@';
		cin >> c;
		while (c != '.') {
			domain += c;
			cin.get(c);
			if (!check(c, '\n', ".")) return;
		}
		domain += '.';
		string s;
		cin >> s;
		if (s != "com") {
			cls();
			cout << "'com' Expected!!\n";
		}
		domain += s;
		id += domain;
	}

	void Address::input() {
		cout << "\nEnter your House details\n";
		input_string("House num", house_num);
		input_int("Sector", "Sector", sector);
		input_string("City", city);
		input_string("State", state);
	}

	void car_num::input() {
		input_string("Enter car name", car_name);
		input_string("Enter Car Manufacturer", car_manf);
		cout << "\nEnter car number(As written on plate)";
		cin >> state[0] >> state[1];
		input_int(num_ini, 2);
		cin >> code[0] >> code[1];
		input_int(num_last, 4);
	}

	void person::input() {
		input_string("Enter your name:", name);
		input_int("Enter your Age", "Age", age);

		cout << "Enter Mobile Number:";
		input_int(mobile_num, 10);

	}
	void person::out_file(string name) {
		fstream fs;
		fs.open(name + ".txt");
		fs << name << endl
			<< age << endl;
	}

	void Agent::input() {
		string descrip;
		p.input();
		input_string("Post:", post);
		input_int("Enter Level:", "Level", level);
		cout << "\n\nDescription\n";
		while (cin) {
			cin >> descrip;
			description.push_back(descrip);
		}
	}

	void Criminal::input() {
		p.input();
		cout << "Enter the Criminal Code:";
		for (int i = 0; i < 10; ++i)cin >> code[0];
		input_int("Enter the level of Threat(0-9):","Threat level type",level_threat);
	}

	void inputs(string &s, bool alpha, int num_limit, int alpc_limit, string statement, char ch) {
		char c;
		s.clear();         //if the loop login starts again the input fuction does not add password to the old password
		int alphanumeric_characters = 0, numerics = 0;
		cin >> c;
		while (c != ch) {                 //to stop taking inputs once we press enter
			s += c;
			if (isdigit(c)) ++numerics;   //to check number of numericals
			if (c == '!' || c == '@' || c == '$' || c == '&' || c == '*' || c == '%') ++alphanumeric_characters;  //to check chec number of alphanumerical words
			cin.get(c);
		}
		if (alpha && (numerics < num_limit || alphanumeric_characters < alpc_limit)) {
			s.clear();
			cout << '\n' << setw(35) << statement << " not strong enough!!\n"
				<< setw(30) << "Atleast " << alpc_limit
				<< " special characters and " << num_limit << " numericals\n";
			inputs(s, true);
		}  //to  check strength of password usually
	}
	void input_string(string Question, string &ans) {
		cout << endl << Question;
		cin >> ans;
	}
	void input_int(string statement, string type, int &num) {
		while (true) {
			cout << endl << statement << ":";
			cin >> num;
			if (!cin) {
				cout << "Not a " << type << " type Input!!";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else return;
		}
	}
	void input_int(long long & num, int digits) {
		while (true) {
			cin >> num;
			if (!cin) {
				cout << "Not a int type Input!!";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else if (digits != -1) {
				int i = 0;
				while (num != 0) {
					num = num / 10;
					++i;
				}
				if (i < digits) cout << "More Digits expected";
				else if (i > digits)cout << "Less Digits expected";
				else return;
			}
			else return;
		}
	}
	void input_int(int & num, int digits) {
		while (true) {
			cin >> num;
			if (!cin) {
				cout << "Not a int type Input!!";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else if (digits != -1) {
				int i = 0;
				while (num != 0) {
					num = num / 10;
					++i;
				}
				if (i < digits) cout << "More Digits expected";
				else if (i > digits)cout << "Less Digits expected";
				else return;
			}
			else return;
		}
	}

	void create_LOG() {
		ifstream i("LOG.txt");
		if (i) return;
		ofstream ofs("LOG.txt");
		ofs << ".LOG";
	}
}