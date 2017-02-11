#include<iostream>
#include<string>
#include<conio.h>
using namespace std;


class link {
public:
	string value;
	link(const string& v,link* p = 0,link* s = 0)
		:value (v),prev(p),succ(s){}      

	link* insert(link *n);
	link* add(link* n);
	link* erase();
	link* find(link* p,const string& s);
//	const link* find(const string& s)const;

	link* advance(link* p,int n) const;

	link* next() const { return succ; }
	link* previous()const { return prev; }
private:
	link* prev;
	link* succ;
}; 
link* link::add(link*n) {           //insert after an element
	if (n == 0)return n;
	if (this == 0)return this;
	if (this->succ)this->succ->prev = n;
	this->succ = n;
	n->prev = this->succ;
	n->prev = this;
	return n;
}
link* link::insert(link*n) {
	if (n == 0)return n;
	if (this == 0)return this;
	n->succ = this;
	if (this->prev)this->prev->succ = n;
	this->prev = n->prev;
	this->prev = n;
	return n;
}
link* link::erase() {
	if (this == 0)return 0;
	if (this->succ)this->succ->prev = this->prev;
	if (this->prev)this->prev->succ = this->succ;
	return this->succ;
}
link* link::find(link* p,const string& s) {
	while (p) {
		if (p->value == s)return this;
		p = p->succ;
	}
	return 0;
}
link* link::advance(link*p, int n) const {
	if (this == 0)return 0;
	if (n > 0) {
		while (n--) {
			if (p->succ == 0) return 0;
			p = p->succ;
		}
	}
	if (n < 0) {
		while (n++) {
			if (p->prev == 0) return 0;
			p = p->prev;
		}
	}
	return p;
}
void print_all(link* p) {
	cout << '{';
	while (p) {
		cout << p->value;
		if (p = p->next())cout << ',';
	}
	cout << '}';
}
void main() {
	link* norse_gods = new link("Thor");
	norse_gods = norse_gods->insert(new link("Odin"));
	norse_gods = norse_gods->insert(new link("Zeus"));
	norse_gods = norse_gods->insert( new link("Freia"));

	link* greek_gods = new link("Hera");
	greek_gods = greek_gods->insert(new link("Athena")); 
	greek_gods = greek_gods->insert(new link("Mars"));
	greek_gods = greek_gods->insert(new link("Poseidon"));

	link* p = greek_gods->find(greek_gods,"Mars");
	if (p)p->value = "Ares";

	p = norse_gods->find(norse_gods,"Zeus");
	if (p) {
		if (p == norse_gods)norse_gods = p->next();
		p->erase();
		greek_gods = greek_gods->insert(p);
	}

	print_all(norse_gods);
	cout << endl;
	print_all(greek_gods);
	_getch();
}