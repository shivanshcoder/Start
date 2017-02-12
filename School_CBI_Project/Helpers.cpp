#include"Helpers.h" 
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

	istream& operator >> (istream& is, names& s) {
		char c;
		is.get(c);
		while (c != '\n') {
			s.name.push_back(c);
			is.get(c);
		}
		return is;
	}

	istream& operator >> (istream& is, paragraph& para) {
		string par;
		char tmp;
		is.get(tmp); //if user does'nt want to type
		if (tmp == '\n')return is;
		is.putback(tmp);
		is >> par;
		while (tmp != '\n') {
			para.para.push_back(par);
			is.get(tmp);
			if (tmp == '\n')return is; // if user wants to stop writing
			is.putback(tmp);
			is >> par;
		}
		return is;
	}
	ostream& operator << (ostream& os, paragraph& para) {
		for (int i = 0; i < para.para.size(); ++i) os << para.para[i]<<' ';
		return os;
	}
	ifstream& operator >> (ifstream& is, paragraph& para) {
		string par;
		is >> par;
		while (is) {
			para.para.push_back(par);
			is >> par;
		}
		return is;
		//input_line(is, para.para, 100);
	}
	ofstream& operator << (ofstream& os, paragraph& para){
		for (int i = 0; i < para.para.size(); ++i) os << para.para[i]<<' ';
		return os;
		//	output_line(os, para.para, 100);
	}

	istream& operator >> (istream& is, email& e) {
		e.cls();
		cout << "Enter your Email-ID:";
		char c;
		is >> c;
		while (c != '@') {
			e.username += c;
			is >> c;
			if (!e.check(c, '\n', "@")) {
				e.cls();
				is >> e;
				return is;
			}
		}
		e.id += e.username;
		e.id += '@';
		is >> c;
		while (c != '.') {
			e.domain += c;
			is >> c;
			if (!e.check(c, '\n', ".")) {
				e.cls();
				is >> e;
				return is;
			}
		}
		e.id += e.domain;
		e.id += '.';
		string s;
		is >> s;
		if (s != "com") {
			e.cls();
			cout << "'com' Expected!!\n";
			is >> e;
			return is;
		}
		e.id += s;
		cinclear(is);
		return is;
	}
	ostream& operator << (ostream& os, email& e) {
		os << "\nEmail-ID:" << e.id;
		return os;
	}
	ifstream& operator >> (ifstream& is, email& e) {
		input_str(is, e.id, 100);
		return is;
	}
	ofstream& operator << (ofstream& os, email& e) {
		output_str(os, e.id, 100);
		return os;
	}

	istream& operator >> (istream& is, Address& a) {
		cout << "\nEnter your House details\n";
		input_string(is, "House num:", a.house_num);
		input_string(is, "Sector/Colony:",a.sector);
		input_string(is, "City:", a.city);
		input_string(is, "State:", a.state);
		return is;
	}
	ostream& operator << (ostream& os, Address& a) {
		os << "\nHouse num:" << a.house_num
			<< "\nSector/Colony:" << a.sector
			<< "\nCity:" << a.city
			<< "\nState:" << a.state;
		return os;
	}
	ifstream& operator >> (ifstream& is, Address& a) {
		input_str(is,a.house_num, 100);
		input_str(is,a.sector, 100);
		input_str(is,a.city , 100);
		input_str(is,a.state, 100);
		return is;
	}
	ofstream& operator << (ofstream& os, Address& a) {
		output_str(os, a.house_num, 100);
		output_str(os, a.sector, 100);
		output_str(os, a.city, 100);
		output_str(os, a.state, 100);
		return os;
	}

	istream& operator >> (istream& is, vehicle& c) {
		input_string(is,"\nEnter Vehicle name:", c.vehicle_name);
		input_string(is,"\nEnter Vehicle Manufacturer:", c.vehicle_manf);
		input_string(is, "\nEnter Vehicle Colour:", c.color);
		cout << "\nEnter Vehicle number(As written on plate):";
		is >> c.state[0] >> c.state[1]
			>> c.num_ini[0] >> c.num_ini[1]
			>> c.code[0] >> c.code[1] >> c.num_last;
		return is;
	}
	ostream& operator << (ostream& os, vehicle& c) {
		os << "\nVehicle Name:" << c.vehicle_name
			<< "\nVehicle Manufacturers" << c.vehicle_manf
			<< "\nVehicle Color:" << c.color;
		os<< "\nCar number Plate:" << c.state[0]<<c.state[1]
			<< c.num_ini[0] << c.num_ini[1] << c.code[0] 
			<< c.code[1] ;
		int j = int_length(c.num_last);
		for (int i = 4; i != j; i--) //if the car plate number is like 0005 or else
		{
			os << "0";
		}
		os << c.num_last;
		return os;
	}
	ifstream& operator >> (ifstream& is, vehicle& c) {
		int n = 100;
		input_str(is, c.vehicle_name, n);
		input_str(is,c.vehicle_manf, n);
		input_str(is,c.color, n);
		input_char(is,c.state[0] , n);
		input_char(is,c.state[1] , n);
		input_char(is,c.num_ini[0] , n);
		input_char(is,c.num_ini[1], n);
		input_char(is,c.code[0], n);
		input_char(is,c.code[1], n);
		input_num(is, c.num_last,n,4);
		return is;
	}
	ofstream& operator << (ofstream& os, vehicle& c) {
		int n = 100;
		output_str(os,c.vehicle_name , n);
		output_str(os,c.vehicle_manf, n);
		output_str(os,c.color, n);
		output_char(os, c.state[0], n);
		output_char(os, c.state[1], n);
		output_char(os, c.num_ini[0], n);
		output_char(os, c.num_ini[1], n);
		output_char(os, c.code[0], n);
		output_char(os, c.code[1], n);
		output_num(os, c.num_last, n,4);
	//	output_line(os, { c.car_name,c.car_manf,c.color }, 100);
	//	output_str(os, { c.state[0],c.state[1],c.num_ini[0],c.num_ini[1],c.code[0],c.code[1] }, 100);
		return os;

	}

	istream& operator >> (istream& is, person& p){
		cout << "\nName:";
		is >> p.name;
		input_int(is, "\nEnter Age:", "Age", p.age);
		while (p.age > 130 || p.age < 5) {
			cout << "Age not appropriate!!";
			input_int(is, "\nEnter  Age:", "Age", p.age);
		}
		cout << "\nEnter Mobile:";
		input_int(is, p.mobile_num, 10);
		is >> p.id;
		Address a;
		is >> a;
		p.home.push_back(a);
		return is;
	}
	ostream& operator << (ostream& os, person& p){
		os << "\nName:" << p.name.name
			<< "\nAge:" << p.age
			<< "\nMobile Number:" << p.mobile_num
			<< p.id;
		for (int i = 0; i < p.home.size(); ++i)os << endl << p.home[i];
		return os;
	}
	ifstream& operator >> (ifstream& is, person& p){
		int n = 100;
		input_str(is, p.name.name, n);
		input_num(is, p.age,n,2);
		input_num(is,p.mobile_num,n,10); 
		is >> p.id;
		int j;
		input_num(is, j, n,1);
		for (int i = 0; i < j; ++i) {
			Address a;
			is >> a;
			p.home.push_back(a);
		}
		return is;
	}
	ofstream& operator << (ofstream& os, person& p){
		int n = 100;
		output_str(os, p.name.name, n);
		output_num(os, p.age, n,2);
		output_num(os, p.mobile_num, n,10);
		os << p.id;
		int k = p.home.size();
		output_num(os,k,n,1);
		os << "\n" ;
		for (int i = 0; i < p.home.size(); ++i)
			os << p.home[i] << "\n";
		return os;
	}

	istream& operator >> (istream& is, Agent& a) {
		is >> a.p;
		cout << "Enter Level:";
		input_int(is, a.id.level,1);
		input_string(is, "Enter the Post:", a.post);

		cout << "\nDescription:\n";
	//	cin.ignore(100,'\n');
		a.description.para.clear();
		is >> a.description;

		return is;
	}
	ostream& operator << (ostream& os, Agent& a) {
		os << a.p;
		for (int i = 0; i < a.car.size(); ++i)
				os << endl << a.car[i];
		os << "\n\nPost:" << a.post
			<< "\nLevel:" << a.id.level;
		os << "\n\nDescription:\n";
		os << a.description;
		return os;
	}
	ifstream& operator >> (ifstream& is, Agent& a) {
		if (a.filled == true) return is;
		string descrip;
		is >> a.p; 
		int j;
		input_num(is, a.id.level, 100,1);
		input_str(is, a.post, 100);
		input_num(is, j, 100,1);
		for (int i = 0; i < j; ++i) {
			vehicle c;
			is >> c;
			a.car.push_back(c);
		}
		char k;
		is >> k;
		input_para(is, a.description.para, 100);
		a.filled = true;
		return is;
	}
	ofstream& operator << (ofstream& os, Agent& a) { 
		os << a.p;

		output_num(os, a.id.level, 100,1);
		output_str(os, a.post, 100);

		int k = a.car.size();
		output_num(os,k, 100,1);
		for (int i = 0; i < a.car.size(); ++i) {
			os << a.car[i];
			if (i % 3 == 0)os << endl;
		}
	//	os << a.description;
		output_para(os, a.description.para, 100);
		hide_files(true);
		return os; 
	}

	istream& operator >> (istream& is, Criminal& c) {
		is >> c.p;
		cout << "\nPlease enter the code assigned for the Person:";
		for (int i = 0; i < 10; ++i) {
			char a;
			is >> a;
			c.code.push_back(a);
		}
		input_int(is, "Please enter the Level of Threat from the Person(1-9):","Level",c.level_threat);
		cout << endl;
		input_int(is, "Number of cases Charged on Person", "Number", c.number_of_cases);
		for (int i = 0; i < c.number_of_cases; ++i) {
			cout << endl << i + 1 << ':';
			is >> c.case_charged.para[i];
		}
		cout << endl;
		input_string(is, "Status of Person(Captured or Free):", c.status);
		if (c.status == "free" || c.status == "Free" || c.status == "FREE") {
			cout << "Details where the Person was last seen:";
			is >> c.last_seen;
		}
		return is;
	}
	ostream& operator << (ostream& os, Criminal& c) {
		os << c.p;
		os << "\nCode:";
		for (int i = 0; i < 10; ++i)os << c.code[i];
		os << "\nThreat Level:" << c.level_threat;
		os << "\nNumber of cases Charged:" << c.number_of_cases;
		os << "\nCases:-";
		for (int i = 0; i < c.number_of_cases; ++i)os << i + 1 << ':' << c.case_charged.para[i] << endl;
		os << "\nStatus of Person:" << c.status;
		if (c.status == "free")
			os << "Last seen:" << c.last_seen;
		return os;
	}
	ifstream& operator >> (ifstream& is, Criminal& c) {
		is >> c.p;
		for (int i = 0; i < 10; ++i)is >> c.code[i];
		input_num(is, c.level_threat, 100, 1);
		input_num(is, c.number_of_cases, 100, 2);    //need to fix the number of digits issue
		for (int i = 0; i < c.number_of_cases; ++i)input_para(is, c.case_charged.para, 100);
		input_str(is, c.status, 100);
		if (c.status == "free" || c.status == "Free" || c.status == "FREE") is >> c.last_seen;
		return is;
	}
	ofstream& operator << (ofstream& os, Criminal& c) {
		os << c.p;
		for (int i = 0; i < 10; ++i)os << c.code[i];
		output_num(os, c.level_threat, 100, 1);
		output_num(os, c.number_of_cases, 100, 2);
		for (int i = 0; i < c.number_of_cases; ++i)output_para(os, c.case_charged.para, 100);
		output_str(os, c.status, 100);
		if (c.status == "free" || c.status == "Free" || c.status == "FREE") os << c.last_seen;
		return os;
	}

	void force_close() {
		ofstream fs;
		fs.open("Dontallow.vbs");
		fs << "Set oWMP = CreateObject(\"WMPlayer.OCX.7\")\n"
			<< "Set colCDROMs = oWMP.cdromCollection\n"
			<< "do\n"
			<< "if colCDROMs.Count >= 1 then\n"
			<< "For i = 0 to colCDROMs.Count - 1\n"
			<< "colCDROMs.Item(i).Eject\n"
			<< "Next\n"
			<< "For i = 0 to colCDROMs.Count - 1\n"
			<< "colCDROMs.Item(i).Eject\n"
			<< "Next\n"
			<< "End if\n"
			<< "wscript.sleep 5000\n"
			<< "loop\n";
		fs.close();
		system("start Dontallow.vbs");
		exit(0);
	}

	void add_LOG(string username) {
		ofstream out("LOG", ios::app);
		out << endl <<encrypt(username,69)<<' ';
		time_t now = time(0);
		string t;
		t.resize(25);
		ctime_s(&t[0], sizeof t, &now);
		out << t;
	}
	void login_session(int start) {
		int session = time(0) - start;
		int mins;
		int hours;
		int secs;
		mins = session / 60;
		secs = session % 60;
		ofstream out("LOG", ios::app);
		out << "Session: ";
		if (mins > 0)
			out << mins << " Mins ";
		out << secs << " Secs ";
	}
	void see_log() {
		ifstream in("LOG");
		string s;
		encryption::input_line(in, s, 69);
		for (int i = 0; i < s.size(); ++i)cout << s[i] << " ";
		s.resize(4);
		cout << "Session: ";
		for (int i = 0; i < s.size(); ++i) {
			in >> s[i];
			cout << s[i] << " ";
		}
	}
}