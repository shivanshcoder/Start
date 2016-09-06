
#include"input_functions.h"


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

	void input_int(istream& io, int& num) {
		io >> num;
		if (!io) {
			io.clear();
			io.ignore(1000, '\n');
		}
	}
	void input_int(istream& io, long long& num) {
		io >> num;
		if (!io) {
			io.clear();
			io.ignore(1000, '\n');
		}
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

	void hide_files(bool hide) {
		fstream fs;
		string file_name = "external_data.bat";
		fs.open(file_name, ios::out);
		if (hide)
			fs << "attrib +r +a +s +h \"*.txt\" /s /d\n"
			<< "exit";
		else
			fs << "attrib -r -a -s -h \"*.txt\" /s /d\n"
			<< "exit";
		fs.close();
		system("start external_data.bat");

	}

	namespace encryption {

		void input_num(ifstream& is, int& n, int z,int digit) {
			char c;
			int a, h;
			n = 0;
			z += 90;
			for (int i = 0; i < digit; ++i) {
				is >> c;
				a = c;
				a -= z;
				char r = a;
				h = r;
				n = n + pow(10, i)*h;
			}
		}     //to be tested
		void output_num(ofstream& os, int n, int z,int digit) {
			if (int_length(n) < digit) {
				char c = 190;
				os << c;
			}
			for (int i = digit; i >0; --i) {
				int m = n % 10;
				n /= 10;
				m = m + z + 90;
				char c = m;
				os << c;
			}
			os << ' ';
		}

		void input_num(ifstream& is, long long& n, int z, int digit) {
			char c;
			int a, h;
			n = 0;
			z += 90;
			for (int i = 0; i < digit; ++i) {
				is >> c;
				a = c;
				a -= z;
				char r = a;
				h = r;
				n = n + pow(10, i)*h;
			}


		}     //to be tested
		void output_num(ofstream& os, long long n, int z, int digit) {
			for (int i = digit; i >0; --i) {
				int m = n % 10;
				n /= 10;
				m = m + z + 90;
				char c = m;
				os << c;
			}
			os << ' ';
		}    //to be tested

		void output_char(ofstream& os, char s, int z) {
			if (s == 0)os << '0';
			int a = s;
			a += z;
			s = a;
			os << s;
		}
		void input_char(ifstream& is, char& s, int z) {
			is >> s;
			if (s == 0) s = '0';
			int a = s;
			a = a - z;
			s = a;
		}

		void output_str(ofstream& os, string s, int z) {
			for (int i = 0; i < s.size(); ++i) {
				output_char(os, s[i], z);
			}
			os << " ";
		}
		void input_str(ifstream& is, string& s, int z) {
			is >> s;
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] == 0)s[i] = '0';
				int n = s[i];
				n -= z;
				s[i] = n;
			}
		}

		void output_line(ofstream& os, vector<string>s, int z) {
			for (int i = 0; i < s.size(); ++i) {
				output_str(os, s[i], z);
			}
		}
		void input_line(ifstream& is, vector<string>&s, int z) {    //need to tackle with vector pointer
			string c;
			input_str(is, c, z);
			while (is) {
				s.push_back(c);
				input_str(is, c, z);

			}
		}

		string encrypt(string s, int z) {
			for (int i = 0; i < s.size(); ++i) {
				int a = s[i];
				a += z;
				s[i] = a;
			}
			return s;
		}

	}