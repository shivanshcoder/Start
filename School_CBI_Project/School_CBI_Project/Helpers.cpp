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

	istream& operator >> (istream& is, email& e) {
		cout << "Enter your Email-ID:";
		char c;
		is >> c;
		while (c != '@') {
			e.username += c;
			is.get(c);
		
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
			is.get(c);
			if (!e.check(c, '\n', ".")) {
				e.cls();
				is >> e;
				return is;
			}
		}
		e.id += '.';
		string s;
		is >> s;
		if (s != "com") {
			e.cls();
			cout << "'com' Expected!!\n";
			is >> e;
			return is;
		}
		e.domain += s;
		e.id += e.domain;
		return is;
	}
	ostream& operator << (ostream& os, email& e) {
		os << "\nEmail-ID:" << e.id;
		return os;
	}
	ifstream& operator >> (ifstream& is, email& e) {
		is >> e.id;
		return is;
	}
	ofstream& operator << (ofstream& os, email& e) {
		os << e.id;
		return os;
	}

	istream& operator >> (istream& is, Address& a) {
		cout << "\nEnter your House details\n";
		input_string(is, "House num:", a.house_num);
		input_int(is, "Sector:", "Sector",a. sector);
		input_string(is, "City:", a.city);
		input_string(is, "State:", a.state);
		return is;
	}
	ostream& operator << (ostream& os, Address& a) {
		os << "\nHouse num:" << a.house_num
			<< "\nSector:" << a.sector
			<< "\nCity:" << a.city
			<< "\nState:" << a.state;
		return os;
	}
	ifstream& operator >> (ifstream& is, Address& a) {
		is >> a.house_num;
		input_int(is, a.sector);
		is >> a.city >> a.state;
		return is;
	}
	ofstream& operator << (ofstream& os, Address& a) {
		os << a.house_num << " "
			<< a.sector << " "
			<< a.city << " "
			<< a.state;
		return os;
	}

	istream& operator >> (istream& is, car_num& c) {
		input_string(is,"\nEnter Car name:", c.car_name);
		input_string(is,"\nEnter Car Manufacturer:", c.car_manf);
		input_string(is, "\nEnter Car Colour:", c.color);
		cout << "\nEnter car number(As written on plate):";
		is >> c.state[0] >> c.state[1]
			>> c.num_ini[0] >> c.num_ini[1]
			>> c.code[0] >> c.code[1] >> c.num_last;
		return is;
	}
	ostream& operator << (ostream& os, car_num& c) {
		os << "\nCar Name:" << c.car_name
			<< "\nCar Manufacturers" << c.car_manf
			<< "\nCar Color:" << c.color;
		os<< "\nCar number Plate:" << c.state[0]<<c.state[1]
			<< c.num_ini[0] << c.num_ini[1] << c.code[0] 
			<< c.code[1] ;
		int j = int_length(c.num_last);
		for (int i = 4; i != j; i--)
		{
			os << "0";
		}
		os << c.num_last;
		return os;
	}
	ifstream& operator >> (ifstream& is, car_num& c) {
		is>>c.car_name>>c.car_manf>>c.color;
		is >> c.state[0] >> c.state[1]
			>> c.num_ini[0] >> c.num_ini[1];
		is >> c.code[0] >> c.code[1];
		input_int(is, c.num_last);
		return is;
	}
	ofstream& operator << (ofstream& os, car_num& c) {
		os << c.car_name << " "
			<< c.car_manf << " "
			<< c.color << " ";
		os<< " " << c.state[0]<<c.state[1]
			<< " " << c.num_ini[0] << c.num_ini[1] 
			<< " " << c.code[0] << c.code[1] << " " << c.num_last;
		return os;

	}

	istream& operator >> (istream& is, person& p){
		input_string(is, "Enter Name:", p.name);
		input_int(is, "\nEnter Age:", "Age", p.age);
		while (p.age > 130 || p.age < 1) {
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
		os << "\nName:" << p.name
			<< "\nAge:" << p.age
			<< "\nMobile Number:" << p.mobile_num
			<< p.id;
		for (int i = 0; i < p.home.size(); ++i)os << p.home[i];
		return os;
	}
	ifstream& operator >> (ifstream& is, person& p){
		is>>p.name;
		input_int(is, p.age);
		input_int(is,p.mobile_num);
		is >> p.id;
		int j;
		is >> j;
		for (int i = 0; i < j; ++i) {
			Address a;
			is >> a;
			p.home.push_back(a);
		}
		return is;
	}
	ofstream& operator << (ofstream& os, person& p){
		os << p.name << "\n" << p.age << "\n" << p.mobile_num << "\n";
		os << p.id << "\n";
		os << p.home.size()<< "\n" ;
		for (int i = 0; i < p.home.size(); ++i)
			os << p.home[i] << "\n";
		return os;
	}

	istream& operator >> (istream& is, Agent& a) {
		string descrip;
		is >> a.p;
		input_int(is,"Enter Level:", "Level", a.level);
		input_string(is, "Enter the Post:", a.post);
		car_num c;
		is >> c;
		a.car.push_back(c);
		cout << "\nDescription:\n";
		is >> descrip;
		a.description.clear();
		while (is) {
			a.description.push_back(descrip);
			is >> descrip;
		}
		is.clear();
		return is;
	}
	ostream& operator << (ostream& os, Agent& a) {
		os << a.p;
		os << "\nPost:" << a.post
			<< "\nLevel:" << a.level;
		for (int i = 0; i<a.car.size(); ++i)
				os << endl << a.car[i];
		os << "\nDescription:\n";
		for (int i = 0; i < a.description.size(); ++i) cout << a.description[i] << " ";
		return os;
	}
	ifstream& operator >> (ifstream& is, Agent& a) {
		string descrip;
		is >> a.p;
		int j;
		is >> j;
		for(int i =0;i<j;++i)
		is >> a.car[i];
		input_int(is,a.level);
		is >> a.post;
		is >> descrip;
		a.description.clear();
		while (is) {
			a.description.push_back(descrip);
			is >> descrip;
		}
		return is;
	}
	ofstream& operator << (ofstream& os, Agent& a) { 
		hide_files(false);
		os << a.p;
		os << "\n" << a.level << "\n" << a.post << "\n";
		os << a.car.size() << endl;
		for (int i = 0; i < a.car.size(); ++i) os << a.car[i] << endl;
		for (int i = 0; i < a.description.size(); ++i) {
			os << a.description[i] << " ";
		}
		hide_files(true);
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

	void create_LOG() {
		ifstream i("LOG.txt");
		if (i) return;
		ofstream ofs("LOG.txt");
		ofs << ".LOG";

		//system("start LOG.txt");
	}
}