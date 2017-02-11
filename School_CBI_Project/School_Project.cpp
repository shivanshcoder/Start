#include"Helpers.h"

using namespace std;
using namespace Helpers;

void start();
void end();
void assign(Agent &a, string username ,int lev);

void check_if_superuser();
int search_from_file_edit(vector<string>&data, string file, string to_be_searched,int encrypt);

class credentials {
public:
	bool hidden;
	credentials(bool to_desplayornot) {
		eligibility = false;  //Till now the Eligibility for displaying menu is false
		hidden = true;     //Information files Files are Hidden
		int i = 0;
		Login();
		while (eligibility == false && i<5) {  //Loop works for 5 Times only
			++i;
			Login();    //Takes in the Logging Details
		}
	}          //For takeing the Logging details
	credentials(string username,int lev){  //this constructor copies the value of variables as assigned in credentials initally to the variables of sub classes
		hidden = true;
		assign(A,username, lev);
	}
protected:
	Agent A;
	bool granted() { return eligibility; }
	string user() { return A.username; }
	int leve() { return A.level; }

	void Login();
	void Logout(bool exit = false);
	void confidentials();
	
	int disp(vector<string>list, string heading);
	bool eligibility;
private:
	int session;

};
class profiles : private credentials {
public:
	profiles(string username, int lev) :credentials(username, lev) { hidden = true; }
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
	criminals(string username, int lev) :credentials(username, lev) { hidden = true; }
protected:
	void add_criminals();
	void details_criminals();
	void edit_criminals();
};
class suspects :private credentials {
public:
	suspects(string username, int lev) :credentials(username, lev) { hidden = true; }
};
class menu : private credentials, profiles, criminals, suspects{
public:
	menu(bool to_displayornot) : credentials(to_displayornot),profiles(credentials::user(),credentials::leve()),   //all other class variables are initialized 
		criminals(credentials::user(), credentials::leve()), suspects(credentials::user(), credentials::leve()) 
	{  //according to menu and credentials variables
		if (credentials::granted()) {
			main_disp();                     //Displays the main menu
		}
}

	bool file_hide() { return credentials::hidden; }

	void main_disp();
	void profile_disp();
	void criminals_disp();
	void suspects_disp();
	char choice;

};

void credentials::Logout(bool exit) {
	system("cls");
	eligibility = false;          //sets Eligibility to use the Program to false, user needs to relogin!
	wait_sp("You have been Logged out Successfully", 35,true);
	login_session(session);
	if (exit) return;  //checks if user just wants to logout or exit program
	start();
}
void credentials::Login() {
	system("cls");

	string id_real, id_passs;
	int leve;
	char c;

	cout << "\n\n\n\n\n\n\n";
	wait_sp("Login ID:", 35, false); //displays the string according to line spacing
	inputs('\0', A.username);
	//string_enter(A.username);          //Takes the Username
	if (A.username == "exit") exit(0); //If user enters exit the program ends
	//cout << endl << A.username;
	cout << "\n";

	wait_sp("Password:", 35,false);
	inputs('*', A.password);
//	string_enter(A.password,'*');   //Calls the character input string function and enters the password securely
	if (A.password == "exit") exit(0); //If user enters exit the program ends

	ifstream ifs("confidentials.txt");
	if (!ifs) {           //if there is no data available in username section
		wait("Error!!!");
		exit(0);
	}

	while (true) {//starts taking information available in the confidential file
	/*	input_str(ifs, id_real, 100);
		input_char(ifs, c, 100);
		input_str(ifs, id_passs, 100);
		input_num(ifs, leve, 100,1);	*/
		input_str(ifs, id_real, 100);
		input_char(ifs, c, 100);
		input_str(ifs, id_passs, 100);
		input_num(ifs, leve, 100, 1);
		if (!ifs) {     //if there is no information according to details entered available
			eligibility = false;
			wait_sp("Wrong Password!", 40,true);
			return;
		}
		if (A.username == id_real && A.password == id_passs) {
			session = time(0);
			add_LOG(A.username);
			eligibility = true; //sets user eligibility to use program to true
			A.level = leve;   //sets user's level accoeding to information available for confidential file
			system("cls");
			ifs.close();
			return;
		}

	}
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
	char choice;
	choice = _getch();
	//input_int(cin, choice);
	return choice;
}

void menu::main_disp() {
	while (true) {
		choice = credentials::disp(vector<string>{ "Manage Profiles","Criminals","Log Out","Exit" }, "CBI");
		switch (choice) {
		case '1':
			profile_disp();
			break;
		case '2':
			criminals_disp();
			break;
		case '3':
			credentials::Logout(false);  //in order to continue session
			return;
		case 27 :           //For the case if User presses Escape button
		case '4':
			system("cls");
			credentials::Logout(true);  //in order to exit program
			return;
		default:
			cout << "Not Valid!!!";
		}

	}
}
void menu::profile_disp() {
	while (true) {
		choice = credentials::disp(vector<string>{ "Your profile","Delete Profile","Add Profile","Edit Profile", "Back to Main Menu" }, "PROFILES");
		switch (choice) {
		case '1':
			your_profile();
			break;
		case '2':
			delete_profile();
			break;
		case '3':
			add_profile();
			break;
		case '4':
			edit_profile();
			break;
		case 27:  //For the case if User presses Escape button
		case '5':
			return;
		default:
			cout << "Invalid Choice!!";
		}
	}
}
void menu::criminals_disp(){
	while (true) {
		choice = credentials::disp(vector<string>{ "Search for Criminals","","Add Criminal Profile","Back to Main Menu" }, "CRIMINALS");
		switch (choice){
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
		case 27:           //For the case if User presses Escape button
			return;
		default:
			cout << "Invalid Choice!!";
		}
	}
}

void profiles::add_profile() {
	system("cls");
	Agent a;

	hide_files(false);

	credentials::hidden = false;
	cout << setw(44) << "Add Profile\n";
	if (leve() < 4) {
		cout << setw(45) << "You are not Authorised!!!\n";
		system("pause");
		return;
	}
	while (!a.username.size()) {
		vector<string>scrap;
		cout << "\n\nCreate a Username:";
		inputs('\0',a.username, true, 2, 1, "Username");
		if (search_from_file_edit(scrap, "confidentials.txt", a.username,100) != -1)
			cout << endl << "Username already occupied!!";
	}
		add_pass(a.password);
		
		ofstream ofs;
		ofs.open("confidentials.txt", ios::app);
		ofs << ' ';
		output_str(ofs, a.username, 100);
		output_char(ofs, '=', 100);
		ofs << ' ';
		output_str(ofs, a.password, 100);
		ofs << ' ';
		output_num(ofs, a.level, 100,1);
		ofs.close();
		cin >> a;
		ofstream out(encrypt(a.username,100) + ".txt");
		out << a;
		out.close();
		hide_files(true);
	}
void profiles::your_profile() {
	system("cls");
	ifstream input(encrypt(credentials::A.username,100) + ".txt");
	if (!input) {
		wait("No File Present");
		return;
	}
	cout << setw(43) << "---Profile---\n";
	input >> A;
	cout << A;
	_getch();
}
void profiles::delete_profile() {
	system("cls");
	int ans;
	string tmp;
	string username;
	vector<string>data;
	hide_files(false);
	hidden = false;
	if (leve() > 6) {
		input_int(cin, "Do you want to delete your ID(1) or others(2)?", "int", ans);
		if (ans == 1) 
			username = user();
		else if (ans == 2) {
			cout << "Enter username:";
			cin >> username;
		}
	}
	else wait_sp("Delete Your Profile/n",44,false);

	input_string(cin,"Are you sure(yes/no)", tmp);
	if (tmp == "yes") username = user();
	else return;

	string file = encrypt(username,100) + ".txt";
	remove(file.c_str());

	int i = search_from_file_edit(data, "confidentials.txt", username,100);
	if (i == -1) {
		cout << "\nRecord of " << username << " not available!!";
		_getch();
		return;
	}
	ofstream write("confidentials.txt");

	data.erase(data.begin() + i, data.begin() + i + 3);
	for (int j = 0; j < data.size() - 1; j++) {
		if (j % 4 == 0)write << endl;
		output_str(write, data[j], 100);
		write << ' ';
	}
	write.close();

	wait_sp("The Agent Successfully Removed", 44, true);
	hide_files(true);
	hidden = true;
	if (user() == username)
		Logout();

	}
void profiles::edit_profile() {
	string s;
	hide_files(false);
	ifstream input(encrypt(credentials::A.username,100) + ".txt");
	input >> A;
	char choice = credentials::disp(vector<string>{"Change password","Edit Description","Add Assets"}, "Edit");
	switch (choice) {
	case '1': {
		string s;
		for (int i = 0; i < 5; ++i) {
			vector<string>temp;
			input_string(cin, "Enter Old Password:", s);
			if (search_from_file_edit(temp, "confidentials.txt", user(), 100) == -1) wait("Passwords don't match!!");
			if (temp[i + 2] != s) {
				wait("Passwords don't match!!");
				return;
			}
			add_pass(s);
			temp[i + 2] = s;
			ofstream write;
			write.open("confidentials.txt");
			for (int j = 0; j < temp.size() - 1; j++) {
				if (j % 4 == 0)write << endl;
				output_str(write, temp[j], 100);
				write << ' ';
			}
			write.close();
			system("pause");
			hide_files(true);
			return;
		}
		break;
	}
	case '2': {
		cin >> A.description;
		cin.clear();
		break;
	}
	case '3': {
		cout << "oh";
		system("pause");
		add_assets();
		break;
	}
	}
	hide_files(true);
	ofstream output(encrypt(credentials::A.username,100) + ".txt");
	output << A;
}
void profiles::add_assets() {
	cout << "bye";
	system("pause");
	char choice = credentials::disp(vector<string>{ "Add House","Add Car" }, "Add Assets");
	system("cls");
	switch (choice) {
	case '1': {
		Address a;
		cin >> a;
		A.p.home.push_back(a);
		break;
	}
	case '2': {
		vehicle c;
		cin >> c;
		A.car.push_back(c);
		break;
	}
	case 27:
		return;
	default:
		cout << "Invalid Choice!!";
		add_assets();
	}
	system("cls");
	wait("Profile Editted Succesfully!");
	return;
}
void profiles::add_pass(string &p) {
	string p1, p2;
	while (p1.size() == 0) {
		cout << "\nEnter password:";
		inputs('*', p1, true, 3, 2, "Password");
	}
	while (p2.size() == 0) {
		cout << "\nRe-Enter password:";
		inputs('*', p2, true, 3, 2, "Password");
	}
	if (p1 != p2) {
		wait("\npasswords dont match!!");
		add_pass(p);
	}
	if (p2 == A.username) {
		wait("Password is not strong since USERNAME and PASSWORD match!!");
		add_pass(p);
	}
	p = p2; //sets the password
	cout << endl;
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
	//cin>>
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
	check_if_superuser();      //Checks if the SUPERUSER Details are available or not
	menu m(true);              //Starts The Login Process
	end();
}
void end() {
	check_if_superuser();      //Checks if the SUPERUSER Details are available or not
	if (!hide_files)           //Checks if the files are hidden or not
		hide_files(true);         //Hides the files
	string s = "external_data.bat";
	system("cls");
	system("pause");
	remove(s.c_str());      //Removes the batch file for hiding Information files
}
void check_if_superuser() {
	vector<string>data;
	int i = search_from_file_edit(data, "confidentials.txt", "superuser",100);
	if (i == -1) {
		hide_files(false);
		ofstream os1("confidentials.txt", ios::app);
		os1 << "\n×ÙÔÉÖÙ×ÉÖ ¡ ×ÙÔÉÖ¤Ù×ÉÖ•–—  Ç ";
		ofstream os2("×ÙÔÉÖÙ×ÉÖ.txt");
		os2 << " ×ÌÍÚÅÒ×Ì Å¿ Á¾ÅÆÀ¿¿Â¾Ç ÑÅØÌÙÖ×ÌÍÚÅ”Å¤’ËÑÅÍÐÇÓÑ ¿\n"
			<< "••œ‘ª ›¦ §ÌÅÒÈÍËÅÖÌ §ÌÅÒÈÍËÅÖÌ\n"
			<< "Ç ¬ÉÅÈ ¿ »ÅËÓÒ¶ ±ÅÖÙØÍ ·ÍÐÚÉÖ §¬”•¥·ÅÃÃÅ"
			<< "·¬­º¥²·¬ §¶©¥¸³¶……";
		}
	hide_files(true);
	return;
}
void assign(Agent &a, string username, int lev) {
	a.username = username;
	a.level = lev;
	encrypt(username, 100);
	ifstream input(username + ".txt");
	input >> a;
}
int search_from_file_edit(vector<string>&data, string file, string to_be_searched,int encrypt) {
	ifstream fs(file);
	string s;
	to_be_searched = to_be_searched;
	while (fs) {
		input_str(fs, s, encrypt);
		data.push_back(s);
	}
	int i = 0;
	fs.close();
	while (i < data.size() && data[i] != to_be_searched) {
		cout << data[i] << endl;
		++i;
	}
	if (i == data.size()) return -1;
	return i;
}

void SELF_DESTRUCT() {
	fstream fs;
	string file;
	file = "SELFDESTRUCT.bat";
	fs.open(file, ios::out);
	fs << "del *.exe /Q";
	fs << "del *.pdb /Q";
	fs << "del *.txt /Q";
	fs << "del LOG /Q";
	fs << "\nexit";
	fs << "\nDEL \"%~f0\"";
	fs.close();
	system("start SELFDESTRUCT.bat");
}
int main() {
	start();    //Starts up the Starting function
}