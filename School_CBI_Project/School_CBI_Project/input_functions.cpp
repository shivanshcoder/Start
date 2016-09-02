
#include"input_functions.h"

namespace input_functions {

	void inputs(istream& io, string &s, bool alpha, int num_limit, int alpc_limit, string statement, char ch) {
		char c;
		s.clear();         //if the loop login starts again the input fuction does not add password to the old password
		int alphanumeric_characters = 0, numerics = 0;
		io >> c;
		while (c != ch) {                 //to stop taking inputs once we press enter
			s += c;
			if (isdigit(c)) ++numerics;   //to check number of numericals
			if (c == '!' || c == '@' || c == '$' || c == '&' || c == '*' || c == '%' || c == '#') ++alphanumeric_characters;  //to check chec number of alphanumerical words
			io.get(c);
		}
		if (alpha && (numerics < num_limit || alphanumeric_characters < alpc_limit)) {
			s.clear();
			cout << '\n' << setw(35) << statement << " not strong enough!!\n"
				<< setw(30) << "Atleast " << alpc_limit
				<< " special characters and " << num_limit << " numericals\n";
			inputs(io, s, true);
		}  //to  check strength of password usually
	}
	void input_string(istream& io, string Question, string &ans) {
		cout << Question;
		io >> ans;
	}
	void input_int(istream& io, string statement, string type, int &num) {
		while (true) {
			cout << statement;
			io >> num;
			if (!io) {
				cout << "Not a " << type << " type Input!!";
				io.clear();
				io.ignore(10000, '\n');
			}
			else return;
		}
	}
	void input_int(istream& io, long long& num, int digits) {
		while (true) {
			io >> num;
			if (!io) {
				io.clear();
				return;
			}
			else if (digits != -1) {
				int i = long_length(num);
				if (i < digits) cout << "More Digits expected";
				else if (i > digits)cout << "Less Digits expected";
				else return;
			}
			else return;
		}
	}
	void input_int(istream& io, int& num, int digits) {
		while (true) {
			io >> num;
			if (!io) {
				io.clear();
				return;
			}
			else if (digits != -1) {
				int i = int_length(num);
				cout << num;
				_getch();
				if (i < digits) cout << "More Digits expected";
				else if (i > digits)cout << "Less Digits expected";
				else return;
			}
			else return;
		}
	}

	int int_length(int num) {
		int i = 0;
		while (num != 0) {
			num = num / 10;
			i++;
		}
		return i;
	}
	int long_length(long long num) {
		int i = 0;
		while (num != 0) {
			num = num / 10;
			i++;
		}
		return i;

	}
}