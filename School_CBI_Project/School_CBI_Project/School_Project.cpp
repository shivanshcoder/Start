#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<conio.h>
using namespace std;

struct email {
	string username, domain, id;
	void cls() {
		username.clear();
		domain.clear();
		id.clear();
	}
	bool check(char c, char termin, string s) {
		if (c == termin) {
			cls();
			cout << s << " Expected!!\n";
			return false;
		}
		return true;
	}
};
struct Address {
	string house_num, city, state;
	int sector;
};
struct car_num {
	char state[2], code[2];
	int num_ini, num_last;
};
struct person {
	string name, mobile_num;
	int age;
	email id;
	Address home;
	vector<car_num>cars;

};
struct Agent {
	string name, post, username, password,mobile_num;
	int age, level;
	email id;
	vector<string>description;
};
struct Criminal {
	string name;
	int age, level_threat;
};
struct suspect {
	string name;
	int age;

};
void start();
void assign(Agent &a, string username ,int lev);
void email_input(email &e);
void inputs(string &s, bool alpha = false, int num_limit = 1, int alpc_limit = 1, string statement = "", char ch = '\n');
void input_file(Agent &A, string username);
void output_file(Agent &A);
void check_if_superuser();
void input_choice(string Question, string &ans);
void hide_files(bool hide);
void input_int(string statement, string type, int &num);
int search_from_file_edit(vector<string>&data, string file, string to_be_searched);

class credentials {
public:
	credentials(bool to_desplayornot) {
		eligibility = false;
		int i = 0;
		Login();
		while (eligibility == false && i<5) {
			++i;
			Login();
		}
	}
	credentials(string username,int lev){
		assign(A,username, lev);
	}
protected:
	Agent A;
	bool granted() { return eligibility; }
	string user() { return A.username; }
	int leve() { return A.level; }
	void Login();
	void Logout();
	bool eligibility;


};
class profiles : private credentials {
public:
	profiles(string username, int lev) :credentials(username, lev) {}
protected:
	void add_profile();
	void your_profile();
	void delete_profile();
	void edit_profile();
	void add_pass(string &p);
	Agent A;
};
class criminals : private credentials {
public:
	criminals(string username, int lev) :credentials(username, lev) {}
protected:
	void add_criminals();
	void details_criminals();
	void edit_criminals();
};
class suspects :private credentials {
public:
	suspects(string username, int lev):credentials(username,lev){}
};
class menu : private credentials, profiles, criminals, suspects{
public:
	menu(bool to_displayornot) : credentials(to_displayornot),profiles(credentials::user(),credentials::leve()),
		criminals(credentials::user(), credentials::leve()), suspects(credentials::user(), credentials::leve()) {
	if (credentials::granted())
			main_disp();
}
	void main_disp();
	void profile_disp();
	void criminals_disp();
	void suspects_disp();
	int choice;

};

void credentials::Login() {
	system("cls");

	string id_real, id_passs;
	int leve;
	char c;

	cout << "\n\n\n\n\n\n\n"
		<< setw(35) << "Login ID:";
	cin >> A.username;
	cout << endl << setw(35) << "Password:";

	inputs(A.password, false, 0, 0);
	ifstream ifs("confidentials.txt");
	if (!ifs) cout << "Error!!!";
	while (true) {
		ifs >> id_real >> c >> id_passs >> leve;

		if (!ifs) {
			eligibility = false;
			return;
		}

		if (A.username == id_real && A.password == id_passs) {
			eligibility = true;
			A.level = leve;
			system("cls");
			ifs.close();
			return;
		}

	}
}
void credentials::Logout() {
	system("cls");
	eligibility = false;
	cout << '\n' << setw(35) << "You have been Loged out Successfully";
	_getch();
	start();
	return;
}

void menu::main_disp() {
	while (true) {
		system("cls");
		cout << setw(44) << "CBI\n"
			<< "\n\n 1. Manage Profiles"
			<< "\n\n 2. Criminals"
			<< "\n\n 3. Suspects"
			<< "\n\n 4. Log Out"
			<< "\n\n 5. Exit";
		cin >> choice;
		switch (choice) {
		case 1:
			profile_disp();
			break;
		case 2:
			criminals_disp();
			break;
		case 3:
			suspects_disp();
			break;
		case 4:
			credentials::Logout();
			return;
		case 5:
			return;
		default:
			cout << "Not Valid!!!";
		}

	}
}
void menu::profile_disp() {
	while (true) {
		system("cls");
		cout << setw(44) << "PROFILES\n"
			<< "\n\n 1. Your Profile"
			<< "\n\n 2. Delete Profile"
			<< "\n\n 3. Add Profile"
			<< "\n\n 4. Back to Main Menu";
		cin >> choice;
		switch (choice) {
		case 1:
			your_profile();
			break;
		case 2:
			delete_profile();
			break;
		case 3:
			add_profile();
			break;
		case 4:
			return;
		default:
			cout << "Invalid Choice!!";
		}
	}
}
void menu::criminals_disp(){
	while (true) {
		system("cls");
		cout << setw(44) << "Criminals\n"
			<< "\n\n 1. Search for Criminals"
			<< "\n\n 2. "
			<< "\n\n 3. Add Profile"
			<< "\n\n 4. Back to Main Menu";
		cin >> choice;
		switch (choice) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			return;
		default:
			cout << "Invalid Choice!!";
		}
	}
}
void menu::suspects_disp(){
	while (true) {
		system("cls");
		cout << setw(44) << "Suspects\n"
			<< "\n\n 1. Your Profile"
			<< "\n\n 2. Delete Profile"
			<< "\n\n 3. Add Profile"
			<< "\n\n 4. Back to Main Menu";
		cin >> choice;
		switch (choice) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			return;
		default:
			cout << "Invalid Choice!!";
		}
	}
}

void profiles::add_profile() {
	system("cls");
	cout << setw(44) << "Add Profile\n";
	string descrip;
	if (leve() < 4) {
		cout << setw(45) << "You are not Authorised\n";
		system("pause");
		//	disp();
		return;
	}
	int age, level;
	cout << "Enter Name:";
	cin >> A.name;

	input_int("\n\nEnter Age:", "Age", A.age);
	input_int("\n\nEnter Level:","Level",A.level);

	cout << "\n\nEnter Post:";
	cin >> A.post;
	cout << "\n\nEnter Email-ID:";
	email_input(A.id);
	cout << "\n\nEnter Mobile Number:";
	cin >> A.mobile_num;

	while (true) {
		vector<string>scrap;
		cout << "\n\nCreate a Username:";
		inputs(A.username, true, 2, 1, "Username"); if (search_from_file_edit(scrap, "confidentials.txt", A.username) == -1) break;
		cout << endl << "Username already occupied!!";
	}
		add_pass(A.password);
		cout << "\n\nDescription\n";
		while (cin) {
			cin >> descrip;
			A.description.push_back(descrip);
		}
		cin.clear();
		output_file(A);
	}
void profiles::your_profile() {
	input_file(A, user());
	cout << setw(43) << "---Profile---\n";
	cout << "Name:" << A.name << endl
		<< "Age:" << A.age << endl
		<< "Level:" << A.level << endl
		<< "Post:" << A.post << endl
		<< "Email ID:" << A.id.id << endl
		<< "Mobile Number:" << A.mobile_num << endl
		<< "Description:\n";

	for (int i = 0; i < A.description.size() - 2; ++i) {
		cout << A.description[i] << " ";
	}
	_getch();
}
void profiles::delete_profile() {
	system("cls");
	string ans,username;

	if (leve() > 6) {
		input_choice("Do you want to delete you ID or others(your/other)?", ans);
		if (ans == "your"||ans == "mine") {
			input_choice("Are you sure(yes/no)",ans);
			if (ans == "yes")
				username = user();
			else
				return;
		}
		else if (ans == "other") {
			cout << "Enter username:";
			cin >> username;
		}
		else {
			cout << "invalid answer";
			return;
		}
	}
	else {
		input_choice("Are you sure(yes/no)", ans);
		if (ans == "yes")
			username = user();
		else
			return;
	}

	string file = username + ".txt";
	remove(file.c_str());
	vector<string>data;

	int i = search_from_file_edit(data, "confidentials.txt", username);

	if (i == -1) {
		cout << "\nRecord of" << username << " not available!!";
		_getch();
		return;
	}

	data.erase(data.begin() + i, data.begin() + (i + 4));

	ofstream write("confidentials.txt");
	for (int j = 0; j < data.size()-1; j+=4) {
		write << data[j] << " " << data[j + 1] << " " << data[j + 2] << " " << data[j + 3] << endl;
		}
	if (user() == username)
		Logout();
	}
void profiles::edit_profile() {
	string s;
	input_file(A, user());
	system("cls");
	cout << setw(44) << "Edit\n"
		<< "\n\n 1. Change username"
		<< "\n\n 2. Change password"
		<< "\n\n 3. Edit Description";
	int choice;
	cin >> choice;
	switch (choice){
	case 1:
		while (true) {
			vector<string>scrap;
			cout << "\n\nCreate a Username:";
			inputs(A.username, true, 2, 1, "Username"); if (search_from_file_edit(scrap, "confidentials.txt", A.username) == -1) break;
			cout << endl << "Username already occupied!!";
		}
		break;
	case 2:
		add_pass(A.password);
		break;
	case 3:
		while (cin) {
			string s;
			cin >> s;
			A.description.push_back(s);
		}
	}
	output_file(A);
}
void profiles::add_pass(string &p) {
	string p1, p2;
	cout << "\nEnter password:";
	inputs(p1, true, 3, 2, "Password");
	cout << "\nRe-Enter password:";
	inputs(p2, true, 3, 2, "Password");
	if (p1 != p2) {
		cout << "\npasswords dont match!!";
		_getch();
		add_pass(p);
	}
	if (p2 == A.username) {
		cout << "Password is not strong since USERNAME and PASSWORD matches!!";
		_getch();
		add_pass(p);
	}
	p = p2;
}

void criminals::add_criminals(){
	system("cls");
}     
void criminals::edit_criminals(){

}
void criminals::details_criminals() {
	system("cls");
	string name;
	cout << setw(44) << "Criminals Search";
	cout << "Name of the Criminal:";
	cin >> name;

}

void start() {
	check_if_superuser();
	hide_files(false);
	menu m(true);
	check_if_superuser();
	hide_files(true);
	string s = "external_data.bat";
	system("cls");
	remove(s.c_str());
}

void email_input(email& e) {
	char c;
	cin >> c;
	while (c != '@') {
		e.username += c;
		cin.get(c);
		if (!e.check(c, '\n', "@")) return;
	}
	e.id += e.username;
	e.id += '@';
	cin >> c;
	while (c != '.') {
		e.domain += c;
		cin.get(c);
		if (!e.check(c, '\n', ".")) return;
	}
	e.domain += '.';
	string s;
	cin >> s;
	if (s != "com") {
		e.cls();
		cout << "'com' Expected!!\n";
	}
	e.domain += s;
	e.id += e.domain;
}
void car_num_input(car_num &c) {
	while (true) {
		cout << "\nEnter car Number";
		cin >> c.state[0] >> c.state[1];

		cin >> c.code[0] >> c.code[1];
		if (c.num_ini % 100 != 0 || c.num_last % 100 != 0) {
			cout << "\nnumber not vaild";
			_getch();
		}
	}
}
void inputs(string &s, bool alpha, int num_limit, int alpc_limit, string statement, char ch) {
	char c;
	s.clear();         //if the loop login starts again the input fuction does not add password to the old password
	int alphanumeric_characters = 0, numerics = 0;
	cin >> c;
	while (c != ch) {                 //to stop taking inputs once we press enter
		s += c;
		if (isdigit(c)) ++numerics;   //to check number of numericals
		if (c == '!'||c =='@'||c=='$'||c=='&'||c=='*'||c=='%') ++alphanumeric_characters;  //to check chec number of alphanumerical words
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
void input_file(Agent &A,string username){
	string descrip;
	system("cls");
	ifstream input(username+".txt");
	if (!input) {
		cout << "No File Present";
		_getch();
		return;
	}
	input >> A.name >> A.age >> A.level
		>> A.post >> A.id.id >> A.mobile_num;

	while (input) {
		input >> descrip;
		A.description.push_back(descrip);
	}
}
void output_file(Agent &A) {
	ofstream output(A.username + ".txt");
	if (!output) {
		cout << "No File Present";
		_getch();
		return;
	}
	output << A.name << '\n' << A.age
		<< '\n' << A.level << '\n'
		<< A.post << '\n' << A.id.id << '\n'
		<< A.mobile_num << '\n';
	for (int i = 0; i < A.description.size(); ++i) {
		output << A.description[i] << " ";
	}

	ofstream add_list("confidentials.txt", ios::app);
	output << "\n" << A.username << ' ' << '='
		<< ' ' << A.password << ' ' << A.level;
}
void input_choice(string Question, string &ans) {
	cout << endl <<Question;
	cin >> ans;
}
void input_int(string statement ,string type ,int &num) {
	while (true) {
		cout << endl << statement << ":";
		cin >> num;
		if(!cin){
			cout << "Not a " << type << " type Input!!";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else return;
	}
}
void input_int(long long & num,int digits) {
	while (true) {
		cin >> num;
		if (!cin) {
			cout << "Not a int type Input!!";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else if( digits != -1){
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
/*void check_input_and_take(string statement,auto data) {
	while (true) {
		cout << statement;
	}
}*/
void check_if_superuser() {
	vector<string>data;
	int i = search_from_file_edit(data, "confidentials.txt", "superuser");
	if (i == -1) {
		ofstream os1("confidentials.txt", ios::app);
		os1 << "\nsuperuser = super@user123 10";
		ofstream os2("superuser.txt");
		os2 << "superuser\n"
			<< "17\n" << "10\n"
			<< "creator\n" << "mathurshiva90a@gmail.com\n"
			<< "+919041128703\n"
			<< "I Created this Program";
	}
	else
		return;
}
void assign(Agent &a, string username, int lev) {
	a.username = username;
	a.level = lev;
	ifstream input(username);
	input >> a.name >> a.age >> a.level >> a.post;
}
int search_from_file_edit(vector<string>&data, string file, string to_be_searched) {
	ifstream fs(file);
	string s;
	while (fs) {
		fs >> s;
		data.push_back(s);
	}
	int i = 0;
	fs.close();
	while (i < data.size() && data[i] != to_be_searched)++i;
	if (i == data.size()) return -1;
	return i;
}

void hide_files(bool hide) {
	fstream fs;
	string file_name = "external_data.bat";
	fs.open(file_name, ios::out);
	if(hide)
	fs << "attrib +r +a +s +h \"*.txt\" /s /d\n"
		<< "exit";
	else
		fs << "attrib -r -a -s -h \"*.txt\" /s /d\n"
		    << "exit";
	fs.close();
	system("start external_data.bat");

}
int main() {
	start();
	_getch();
}