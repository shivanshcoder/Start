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
		input_string(is, "Sector:",a.sector);
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
		input_str(is,a.house_num, 100);
		input_str(is,a.sector, 100);
		input_str(is,a.city , 100);
		input_str(is,a.state, 100);
	//	input_line(is, { a.house_num,a.sector,a.city,a.state }, 100);
		return is;
	}
	ofstream& operator << (ofstream& os, Address& a) {
		output_str(os, a.house_num, 100);
		output_str(os, a.sector, 100);
		output_str(os, a.city, 100);
		output_str(os, a.state, 100);
	//	output_line(os, { a.house_num,a.sector,a.city,a.state }, 100);
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
		input_str(is, c.car_name, 100);
		input_str(is,c.car_manf, 100);
		input_str(is,c.color, 100);
		input_char(is,c.state[0] , 100);
		input_char(is,c.state[1] , 100);
		input_char(is,c.num_ini[0] , 100);
		input_char(is,c.num_ini[1], 100);
		input_char(is,c.code[0], 100);
		input_char(is,c.code[1], 100);
		input_num(is, c.num_last,100,4);
		return is;
	}
	ofstream& operator << (ofstream& os, car_num& c) {
		output_str(os,c.car_name , 100);
		output_str(os,c.car_manf, 100);
		output_str(os,c.color, 100);
		output_char(os, c.state[0], 100);
		output_char(os, c.state[1], 100);
		output_char(os, c.num_ini[0], 100);
		output_char(os, c.num_ini[1], 100);
		output_char(os, c.code[0], 100);
		output_char(os, c.code[1], 100);
		output_num(os, c.num_last, 100,4);
	//	output_line(os, { c.car_name,c.car_manf,c.color }, 100);
	//	output_str(os, { c.state[0],c.state[1],c.num_ini[0],c.num_ini[1],c.code[0],c.code[1] }, 100);
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
		input_str(is, p.name, 100);
		input_num(is, p.age,100,2);
		input_num(is,p.mobile_num,100,10); 
		is >> p.id;
		int j;
		input_num(is, j, 100,1);
		for (int i = 0; i < j; ++i) {
			Address a;
			is >> a;
			p.home.push_back(a);
		}
		return is;
	}
	ofstream& operator << (ofstream& os, person& p){
		output_str(os, p.name, 100);
		output_num(os, p.age, 100,2);
		output_num(os, p.mobile_num, 100,10);
		os << p.id;
		int k = p.home.size();
		output_num(os,k,100,1);
		os << "\n" ;
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
		for (int i = 0; i < a.description.size(); ++i) os << a.description[i] << " ";
		return os;
	}
	ifstream& operator >> (ifstream& is, Agent& a) {
		string descrip;
		is >> a.p;
		int j;
		input_num(is, a.level, 100,1);
		input_str(is, a.post, 100);
		input_num(is, j, 100,1);
		for (int i = 0; i < j; ++i) {
			car_num c;
			is >> c;
			a.car.push_back(c);
		}
		input_line(is, a.description, 100);
		return is;
	}
	ofstream& operator << (ofstream& os, Agent& a) { 
		hide_files(false);
		os << a.p;
		output_num(os, a.level, 100,1);
		output_str(os, a.post, 100);
		int k = a.car.size();
		output_num(os,k, 100,1);
		for (int i = 0; i < a.car.size(); ++i) {
			os << a.car[i];
			if (i % 3 == 0)os << endl;
		}
		output_line(os, a.description, 100);
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