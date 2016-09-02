#include"Helpers.h"
#include<fstream>
#include<conio.h>

using namespace std;
using namespace Helpers;

void start();
void assign(Agent &a, string username ,int lev);

void input_file(Agent &A, string username);
void output_file(Agent &A);
void check_if_superuser();
void hide_files(bool hide);
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
	int disp(vector<string>list, string heading);
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
	if (A.username == "exit") exit(0);

	cout << endl << setw(35) << "Password:";
	inputs(cin,A.password, false, 0, 0);
	if (A.password == "exit") exit(0);

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
			fstream f;
			f.open("LOG.txt",ios::app);
			f << endl << A.username;
			f.close();
			return;
		}

	}
}
void credentials::Logout() {
	system("cls");
	eligibility = false;
	cout << '\n' << setw(35) << "You have been Loged out Successfully";
	fstream fs;
	fs.open("help.bat");
	fs << "start ";
	_getch();
	start();
	return;
}

int menu::disp(vector<string>list,string heading) {
	system("cls");
	cout << setw(44) << heading << endl;
	for (int i = 0; i < list.size(); ++i) {
		cout << "\n\n" << i + 1 << ' ' << list[i];
	}
	cout << endl;
	int choice;
	cin >> choice;
	return choice;
}
void menu::main_disp() {
	while (true) {
		choice = disp({ "Manage Profiles","Criminals","Suspects","Log Out","Exit" }, "CBI");
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
		choice = disp({ "Your profile","Delete Profile","Add Profile","Edit Profile", "Back to Main Menu" }, "PROFILES");
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
			edit_profile();
			break;
		case 5:
			return;
		default:
			cout << "Invalid Choice!!";
		}
	}
}
void menu::criminals_disp(){
	while (true) {
		choice = disp({ "Search for Criminals","","Add Criminal Profile","Back to Main Menu" }, "CRIMINALS");
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
		choice = disp({ "" }, "");
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
	if (leve() < 4) {
		cout << setw(45) << "You are not Authorised!!!\n";
		system("pause");
		return;
	}
	while (true) {
		vector<string>scrap;
		cout << "\n\nCreate a Username:";
		inputs(cin,A.username, true, 2, 1, "Username"); if (search_from_file_edit(scrap, "confidentials.txt", A.username) == -1) break;
		cout << endl << "Username already occupied!!";
	}
		add_pass(A.password);
		cin.clear();
		cin >> A;
		output_file(A);
	}
void profiles::your_profile() {
	input_file(A, user());
	cout << setw(43) << "---Profile---\n";
	cout << "Name:" << A.p.name << endl
		<< "Age:" << A.p.age << endl
		<< "Level:" << A.level << endl
		<< "Post:" << A.post << endl
		<< "Email ID:" << A.p.id.id << endl
		<< "Mobile Number:" << A.p.mobile_num << endl
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
		input_string(cin,"Do you want to delete you ID or others(your/other)?", ans);
		if (ans == "your"||ans == "mine") {
			input_string(cin,"Are you sure(yes/no)",ans);
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
		input_string(cin,"Are you sure(yes/no)", ans);
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
			cout << "\n\nNew Username:";
			inputs(cin,A.username, true, 2, 1, "Username"); if (search_from_file_edit(scrap, "confidentials.txt", A.username) == -1) break;
			cout << endl << "Username already occupied!!";
		}
		break;
	case 2: {
		string s;
		for (int i = 0; i < 5; ++i) {
			input_string(cin,"Enter Old Password:", s);
			cout << credentials::A.password;
			if (s == A.password) {
				add_pass(A.password);
				output_file(A);
				return;
			}
			cout << "Password not correct\n";
		}
		_getch();
		Logout();
		exit(0);
	}
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
	inputs(cin,p1, true, 3, 2, "Password");
	cout << "\nRe-Enter password:";
	inputs(cin,p2, true, 3, 2, "Password");
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
	create_LOG();
	check_if_superuser();
	hide_files(false);
	menu m(true);
	check_if_superuser();
	hide_files(true);
	string s = "external_data.bat";
	system("cls");
	system("pause");
	remove(s.c_str());
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
	input >> A.p.name >> A.p.age >> A.level
		>> A.post >> A.p.id.id >> A.p.mobile_num;

	while (input) {
		input >> descrip;
		A.description.push_back(descrip);
	}
}
//void input_file(Criminal &C, string name);
//void input_file(Suspect &S, string name);
void output_file(Agent &A) {
	ofstream output(A.username + ".txt");
	if (!output) {
		cout << "No File Present";
		_getch();
		return;
	}
	output << A.p.name << '\n' << A.p.age
		<< '\n' << A.level << '\n'
		<< A.post << '\n' << A.p.id.id << '\n'
		<< A.p.mobile_num << '\n';
	for (int i = 0; i < A.description.size(); ++i) {
		output << A.description[i] << " ";
	}

	ofstream add_list("confidentials.txt", ios::app);
	output << "\n" << A.username << ' ' << '='
		<< ' ' << A.password << ' ' << A.level;
}
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
	input >> a.p.name >> a.p.age >> a.level >> a.post;
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
	//start();
	Agent a,b;
	ifstream fs;
	fs.open("Hell.txt");
	fs >> a;
	_getch();
	fs.close();
	ifstream ifs;
	ifs.open("Hell.txt");
	ifs >> b;
	_getch();
	cout << b;
	_getch();

}