#include<iostream>
#include<string>
#include<conio.h>
using namespace std;


struct link {
	string value;
	link* prev;
	link* succ;
	link(const string& v,link* p = 0,link* s = 0)
		:value (v),prev(p),succ(s){}        
}; 
link* insert_after(link*p, link*n) {           //insert after an element
	if (n == 0)return n;
	if (p == 0)return p;
	if (p->succ)p->succ->prev = n;
	p->succ = n;
	n->prev = p->succ;
	n->prev = p;
	return n;
}
link* insert_before(link*p, link*n) {
	if (n == 0)return n;
	if (p == 0)return p;
	n->succ = p;
	if (p->prev)p->prev->succ = n;
	p->prev = n->prev;
	p->prev = n;
	return n;
}
link* erase(link* p) {
	if (p == 0)return 0;
	if (p->succ)p->succ->prev = p->prev;
	if (p->prev)p->prev->succ = p->succ;
	return p->succ;
}
link* find(link* p, const string& s) {
	while (p) {
		if (p->value == s)return p;
		p = p->succ;
	}
	return 0;
}
link* advance(link*p, int n) {
	if (p == 0)return 0;
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
void main() {
	link* norse_gods = new link("Thor");
	norse_gods = insert_before(norse_gods, new link("Odin"));
	norse_gods = insert_before(norse_gods, new link("Zeus"));
	norse_gods = insert_before(norse_gods, new link("Freia"));

	link* greek_gods = new link("Hera");
	greek_gods = insert_before(greek_gods, new link("Athena")); 
	greek_gods = insert_before(greek_gods, new link("Mars"));
	greek_gods = insert_before(greek_gods, new link("Poseidon"));

	link* p = find(greek_gods, "Mars");
	if (p)p->value = "Ares";

	p = find(norse_gods, "Zeus");
	if (p) {
		if (p == norse_gods)norse_gods = p->succ;
		erase(p);
		greek_gods = insert_before(greek_gods, p);
	}
	cout << greek_gods->value << " " << greek_gods->succ->value << " " << greek_gods->succ->succ->value
		<< " " << greek_gods->succ->succ->prev->value << endl;
	_getch();
}