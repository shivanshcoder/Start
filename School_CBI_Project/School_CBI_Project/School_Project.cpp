#include"Helpers.h"
#include<fstream>
#include<conio.h>

using namespace std;
using namespace Helpers;

void start();
void assign(Agent &a, string username ,int lev);

void check_if_superuser();
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
	void confidentials();
	
	int disp(vector<string>list, string heading);
	bool eligibility;


};
class profiles : private credentials {
public:
	profiles(string username, int lev) :credentials(username, lev) {}
protected:
	void add_profile();
	void add_assets();
	void your_profile();
	void delete_profile();
	void edit_profile();
	void other_profile();
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
		if (credentials::granted()) {
			cout << "HELLO";
			main_disp();
		}
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
	if (A.username == "exit") exit(0);

	cout << endl << setw(35) << "Password:";
	inputs(cin,A.password, false, 0, 0);
	if (A.password == "exit") exit(0);

	ifstream ifs("confidentials.txt");
	if (!ifs) cout << "Error!!!";
	while (true) {
		input_str(ifs, id_real, 100);
		input_char(ifs, c, 100);
		input_str(ifs, id_passs, 100);
		input_num(ifs, leve, 100,1);
		if (!ifs) {
			eligibility = false;
			cout << setw(40) << "Wrong Password!";
			_getch();
			return;
		}

		if (A.username == id_real && A.password == id_passs) {
			eligibility = true;
			A.level = leve;
			system("cls");
			ifs.close();
			/*fstream f;
			system("start LOG.txt");
			system("taskill /F /IM notepad.exe");
			f.open("LOG.txt", ios::app);
			f << endl << A.username;
			f.close();*/
			return;
		}

	}
	_getch();
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
void credentials::confidentials() {
	ifstream input("confidentials.txt");
	vector<string>users;
	vector<string>pass;
	string u, p;
	int n;
	vector<int>power;
	char c;
	input >> p >> c >> p >> n;
	while (input) {
		users.push_back(u);
		pass.push_back(p);
		power.push_back(n);
		input >> p >> c >> p >> n;
	}
}
int credentials::disp(vector<string>list, string heading) {
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
		choice = credentials::disp({ "Manage Profiles","Criminals","Suspects","Log Out","Exit" }, "CBI");
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
		choice = credentials::disp({ "Your profile","Delete Profile","Add Profile","Edit Profile", "Back to Main Menu" }, "PROFILES");
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
		choice = credentials::disp({ "Search for Criminals","","Add Criminal Profile","Back to Main Menu" }, "CRIMINALS");
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
		choice = credentials::disp({ "" }, "");
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
		ofstream out(encrypt(A.username,100) + ".txt");
		out << A;
		ofstream ofs;
		ofs.open("confidentials.txt",ios::app);
		output_str(ofs, A.username, 100);
		output_char(ofs, '=', 100);
		output_str(ofs, A.password, 100);
		ofs << " ";
		output_num(ofs, A.level, 100, 1);
	}
void profiles::your_profile() {
	system("cls");
	cout << credentials::A.username<<encrypt(credentials::A.username, 100);
	_getch();
	ifstream input(encrypt(credentials::A.username,100) + ".txt");
	if (!input) {
		cout << "No File Present";
		_getch();
		return;
	}
	cout << setw(43) << "---Profile---\n";
	input >> A;
	cout << A;
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
	ifstream input(credentials::A.username + ".txt");
	input >> A;
	int choice = credentials::disp({"Change password","Edit Description","Add Assets"}, "Edit");
	switch (choice){
	case 1: {
		string s;
		for (int i = 0; i < 5; ++i) {
			//input_string(cin,"Enter Old Password:", s);
			//cout << credentials::A.password;
				add_pass(A.password);
				break;
		}
		break;
	//	_getch();
	//	Logout();
	//	exit(0);
	}
	case 2:
		while (cin) {
			string s;
			cin >> s;
			A.description.push_back(s);
		}
		cin.clear();
		break;
	case 3:
		add_assets();
			break;
	}
	ofstream output(encrypt(credentials::A.username,100) + ".txt");
	output << A;
}
void profiles::add_assets() {
	int choice = credentials::disp({ "Add House","Add Car" }, "Add Assets");
	switch (choice) {
	case 1: {
		Address a;
		cin >> a;
		A.p.home.push_back(a);
	}
	case 2: {
		car_num c;
		cin >> c;
		A.car.push_back(c);
	}
	}
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
void profiles::other_profile(){
	system("cls");
	if (leve() < 5) {
		cout << "You are not Authorised!";
		_getch();
		return;
	}
	cout << setw(44) << "Search Agents" << endl;

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
	//create_LOG();
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
void check_if_superuser() {
	vector<string>data;
	int i = search_from_file_edit(data, "confidentials.txt", "◊Ÿ‘…÷Ÿ◊…÷");
	if (i == -1) {
		ofstream os1("confidentials.txt", ios::app);
		os1 << "\n◊Ÿ‘…÷Ÿ◊…÷ °◊Ÿ‘…÷§Ÿ◊…÷ïñó  « ";
		ofstream os2("◊Ÿ‘…÷Ÿ◊…÷.txt");
		os2 << " ◊ÃÕ⁄≈“◊Ã ≈ø ¡æ≈∆¿øø¬æ« —≈ÿÃŸ÷◊ÃÕ⁄≈ùî≈§íÀ—≈Õ–«”— ø\n"
			<< "ïïúë™ õ¶ ßÃ≈“»ÕÀ≈÷Ã ßÃ≈“»ÕÀ≈÷Ã\n"
			<< "« ¨…≈» ø ª≈À”“∂ ±≈÷ŸÿÕ ∑Õ–⁄…÷ ß¨îï•∑≈√√≈"
			<< "∑¨≠∫•≤∑¨ ß∂©•∏≥∂ÖÖ";
		}
	else
		return;
}
void assign(Agent &a, string username, int lev) {
	a.username = username;
	a.level = lev;
	ifstream input(username+".txt");
	input >> a;
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

int main() {
	start();
	
	/*string username, password;
	int level;
	cin >> username >> password >> level;
	ofstream ofs("TRY.txt");
	output_str(ofs,username, 100);
	output_char(ofs, '=', 100);
	output_str(ofs, password, 100);
	ofs << " ";
	output_num(ofs, level, 100, 1);
	ofs.close();
	string id_real, id_passs;
	char c;
	int leve;
	ifstream ifs("TRY.txt");
	input_str(ifs, id_real, 100);
	input_char(ifs, c, 100);
	input_str(ifs, id_passs, 100);
	input_num(ifs, leve, 100, 1);
	cout << id_real << endl << id_passs << endl << leve;
	_getch();*/
}