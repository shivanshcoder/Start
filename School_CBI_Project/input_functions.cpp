
#include"input_functions.h"

void inputs(istream& io, string &s, bool alpha, int num_limit, int alpc_limit, string statement, char ch) {
	char c;
	s.clear();         //if the loop login starts again the input fuction does not add password to the old password
	int alphanumeric_characters = 0, numerics = 0;
	io.get(c);
	while (c != ch) {                 //to stop taking inputs once we press enter
		s += c;
		io.get(c);
	}
	cinclear(io);  //checks if the stream is in good state
	if (alpha&&check_constraint(s, alphanumeric_characters, numerics) && (numerics < num_limit || alphanumeric_characters < alpc_limit)) {
		s.clear();
		cout << '\n' << setw(35) << statement << " not strong enough!!\n"
			<< setw(30) << "Atleast " << alpc_limit
			<< " special characters and " << num_limit << " numericals\n";
		inputs(io, s, true, num_limit, alpc_limit, statement);
	}  //to check the constraints of the string
}
void inputs(char charac, string &s, bool alpha, int num_limit, int alpc_limit, string statement) {
	int alphanumeric_characters = 0, numerics = 0;
	string c; //max characters should me 20
	c.resize(20);
	s.clear();
	inchar_enter(c[0]);
	
	for (int i = 1; c[i] != 13; ++i) {
		if (charac) //checks if a character is provided
			cout << charac;
		else
			cout << c[i-1];
		inchar_enter(c[i], { 13,8 });
	//	if (isdigit(c[i])) ++numerics;   //to check number of numericals
		//alphanumeric_characters += splchar(c[i]);  //to check chec number of alphanumerical words

		if (c[i] == 13) {  //checks if enter is pressed
			c[i] = '\0';
			break;
		}
		while (c[i] == 8 && i > 0) {  //when backspace is pressed
			cout << '\b'; //gets cursor back
			cout << " ";  //replaces the old value as space
			cout << '\b'; //gets again the cursor on the space given in last step
			c[i] = '\0';
			--i; //decrease string length by 1
			inchar_enter(c[i], { 8,13 }); 
			while (i == 0 && c[i] == 8) { 
				c[i] = _getch();
			}
		}
		
	}
	check_constraint(c, alphanumeric_characters, numerics);
	if (alpha && (numerics < num_limit || alphanumeric_characters < alpc_limit)) {
		s.clear();
		cout << '\n' << setw(35) << statement << " not strong enough!!\n"
			<< setw(30) << "Atleast " << alpc_limit
			<< " special characters and " << num_limit << " numericals\n";
		return;
	}  //to  check if the constraints are fulfilled
	for (int i = 0; c[i] != '\0'; ++i) { //fills the string to be returned
		s += " "; //since originally the size of string is zero at starting of program
		s[i] = c[i];
	}
}

	void input_string(istream& io, string Question, string &ans) {
		cout << Question;
		io >> ans;
		cinclear(io);
	}
	void input_line(istream& io, string& s) {
		char c;
		io.get(c);
		while (c != '\n') {
			s += c;
			io.get(c);
		}
		cinclear(io);
	}
	void input_line(ifstream& io, string& s) {
		char c;
		io.get(c);
		while (c != '\n') {
			s += c;
			io.get(c);
		}
		cinclear(io);
	}

	void input_int(istream& io, int& num) {
		io >> num;
		cinclear(io);
	}
	void input_int(istream& io, long long& num) {
		io >> num;
		cinclear(io);
	}
	void input_int(istream& io, string statement, string type, int &num) {
		while (true) {
			cout << statement;
			io >> num;
			cinclear(io);
			if (!io) {
				cout << "Not a " << type << " type Input!!";
				cinclear(io);
			}
			else return;
		}
	}
	void input_int(istream& io, long long& num, int digits) {
		while (true) {
			io >> num;
			cinclear(io);
			if (!io) {
				cinclear(io);
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
	void input_int(istream& io, int& num, int digits)  {
		while (true) {
			io >> num;
			cinclear(io);
			if (!io) {
				cinclear(io);
				return;
			}
			else if (digits != -1) {
				int i = int_length(num);
			//	cout << num;
				//_getch();
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

	bool cinclear(istream& io) {  //checks the state of input stream and corrects it 
		cin.ignore(INT_MAX,'\n');
		if (!io) {
			if (io.bad()) {  //if the input stream gets badly corrected
				system("cls");
				wait("Stream Got corrupted!!");
				exit(0);   //the only chance is to exit program
			}
			else if (io.fail()) {  //if the state is flagged than clear stream and continue
				io.clear();
				io.ignore(1000, '\n');
				return false;
			}
		}
		else return true;  //if everything is fine
	}

	void hide_files(bool hide) {
		fstream fs;
		string file_name = "external_data.bat";
		fs.open(file_name, ios::out);
		if (hide)            //if the hide is true then hide files
			fs << "attrib +r +a +s +h \"*.txt\" /s /d\n"
			<< "exit";
		else                 //if hte hide is false then unhide files
			fs << "attrib -r -a -s -h \"*.txt\" /s /d\n"
			<< "exit";
		fs.close();
		system("start external_data.bat");

	}

	void wait(string s) {
		cout << endl << s;
		_getch();
	}
	void wait_sp(string s,int z,bool k){
		cout << endl << setw(z) << s;
		if(k)
		_getch();
	}

	bool check_constraint(string s, int& alphachar, int& numericals) {
		for (int i = 0; i < s.size(); ++i) {
			alphachar += splchar(s[i]);
			if (isdigit(s[i]))numericals++;
		}
		return true;
	}
	int splchar(char c) {  //checks if the character is a special character and returns true
		switch (c) {
		case '~': case '`': case '!': case '@': case '#': case '$': case '%': case '^': case '&': case '*': case '(': case ')':
		case '-': case '_': case '+': case '=': case '\'': case '|': case ']': case '[': case '{': case '}': case ';': case ':':
		//case ''': 
		case '"': case '/': case '<': case '>':  case '?':  case '.': case',':
			return 1;
		default:
			return 0;
		}
	}
		
	void inchar_enter(char& c) {
		c = _getch();
		while (c < 0 || c>255) { //because such values are commonly combination of two characters
			c = _getch();
			c = _getch();
		}
		if (isalpha(c)|| isdigit(c) || splchar(c))return;
		inchar_enter(c);//if it is not a desired value call the function recursively
	}
	void inchar_enter(char& c, vector<int>splchars) {
		c = _getch();
		while (c < 0 || c>255) {  //because such values are commonly combination of two characters
			c = _getch();
			c = _getch();
		}
		if (isalpha(c) || isdigit(c) || splchar(c))return;
		for (int i = 0; i < splchars.size(); ++i) { // checks if it is a specified ascii character
			if (splchars[i] == c)return;
		}
		inchar_enter(c,splchars); //if it is not a desired value call the function recursively
	} 

	namespace encryption {

		void input_num(ifstream& is, int& n, int z,int digit) {
			char c;
			int a, h;
			n = 0;
			z += 90;
			for (int i = 0; i < digit; ++i) {
				is >> c;
				if (c == '\n')return;
				a = c;
				a -= z;
				char r = a;
				h = r;
				n = n + pow(10, i)*h;
			}
		}     //to be tested
		void output_num(ofstream& os, int n, int z,int digit ) {
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
				if (c == '\n')return;
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
			encrypt(s,z);
			os << s;
		}
		void input_char(ifstream& is, char& s, int z) {
			is >> s;
			decrypt(s, z);
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
				decrypt(s[i],z);
			}
		}

		void input_line(ifstream& is, string s, int z) {    
			char c;
			input_char(is, c, z);
			while (is&&c!='\n') {
				s += c;
				input_char(is, c, z);
			}
		}

		void output_para(ofstream& os, vector<string>s, int z) {
			for (int i = 0; i < s.size(); ++i) {
				output_str(os, s[i], z);
			}
		}
		void input_para(ifstream& is, vector<string>&s, int z) {
			string c;
			input_str(is, c, z);
			while (is) {
				s.push_back(c);
				input_str(is, c, z);
			}
		}

		string encrypt(string s, int z) {
			for (int i = 0; i < s.size(); ++i) {
				encrypt(s[i], z);
			}
			return s;
		}
		string decrypt(string s, int z) {
			for (int i = 0; i < s.size(); ++i) decrypt(s[i], z);
			return s;
		}
		void decrypt(char& c, int z) {
			if (c == 0)c = '0';
			int a = c;
			a -= z;
			c = a;
		}
		void encrypt(char& c, int z) {
			if (c == 0)c = '0';
			int a = c;
			a += z;
			c = a;
		}
	}