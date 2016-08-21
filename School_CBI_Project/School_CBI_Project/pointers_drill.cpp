#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

void print(ostream& os, int* a,int n) {
	for (int i = 0; i < n; ++i) {
		cout << a[i] << endl;
	}
}

void main() {
	int n = 11;
	int* a = new int[n];
	for (int i = 0; i < n; ++i) {
		a[i] = i+100;
	}
	print(cout, a,n);
	delete a;
	_getch();
}