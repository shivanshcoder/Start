#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
using namespace std;

void main() {
	int n = 7;
	int *p1 = &n;
	cout << p1 << endl;
	int a[7]{ 1,2,4,8,16,32,64 };
	int* p2 = a;
	for (int i = 0; i < 7; ++i) {
		cout << p2 << endl;
		p2++;
	}
	int* p3 = p2;
	cout << p3 << endl;
	_getch();
}