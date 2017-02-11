#pragma once
#include<conio.h>
#include<string>
using namespace std;

template<class T, class A = allocator<T>>class vector {
	int sz;
	T* elem;
	int space;
public:
	int size() { return sz; }
	int capacity() const { return space; }

	vector& operator=(const vector&);
	vector() :sz(0), elem(0), space(0) {}
	vector(int s)
		:sz(s), elem(new T[s]) {
		for (int i = 0; i < sz; ++i) elem[i] = 0;
	}
	vector(const vector<T>& arg)
		:sz(arg.sz), elem(new T[arg.sz]) {
		for (int i = 0; i < arg.sz; ++i) elem[i] = arg.elem[i];
	}
	vector(initializer_list<T>arg)
		:sz(arg.size()), elem(new T[arg.size()]) {
		const T* p = arg.begin();
		int i = 0;
		while (p != arg.end()) {
			elem[i] = *p;
			cout << elem[i] << endl;
			++p;
			++i;
		}
	}

	T& operator[](int n) { return elem[n]; }
	const T& operator[](int n)const { return elem[n]; }

	void reserve(int new_alloc);
	void resize(int new_size);
	void push_back(T& d);

	void clear();

	~vector() { delete[] elem; }
};
