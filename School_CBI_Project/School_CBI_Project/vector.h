#pragma once
#include<conio.h>
#include<string>
#include<iostream>
using namespace std;

template<class T, class A = allocator<T>> class vector {
	A alloc;
	int sz;
	T* elem;
	int space;
public:
	int size() { return sz; }
	int capacity() const { return space; }

	vector& operator=(const vector &a);
	vector() :sz{ 0 }, elem{ 0 }, space{ 0 } {}
	vector(int s)
		:sz{ s }, elem{ new T[s] } {
		for (int i = 0; i < sz; ++i) elem[i] = T() ;
	}
	vector(vector& arg)
		:sz{ arg.sz }, elem{ new T[arg.sz] } {
		for (int i = 0; i < sz; ++i)elem[i] = arg[i];
	}
	vector(initializer_list<T> arg)
		:sz{ arg.size() },elem { new T[arg.size()] } {
		copy(arg.begin(), arg.end(), elem);
	}

	T& operator[](int n) { return elem[n]; }
	const T& operator[](int n)const { return elem[n]; }

	void reserve(int new_alloc);
	void resize(int new_size, T val = T());
	void push_back(const T &val);

	void clear();

	~vector() { delete[] elem; }
};

template<class T,class A>vector<T,A>& vector<T, A>::operator=(const vector &a) {
	if (this == &a)return *this;

	if (a.sz <= space) {
		for (int i = 0; i < a.sz; ++i) elem[i] = a.elem[i];
		sz = a.sz;
		return *this;
	}
	T* p = alloc.allocate(a.sz);
	for (int i = 0; i < a.sz; ++i)alloc.construct(&p[i], a.elem[i]);
	for (int i = 0; i < a.sz; ++i) alloc.destroy(&elem[i]);
	elem = p;
	space = sz;
	sz = a.sz;
	return *this;
}

template<class T, class A>void vector<T, A>::reserve(int new_alloc) {
	if (new_alloc <= space) return;
	T* p = alloc.allocate(new_alloc);
	for (int i = 0; i < sz; ++i) alloc.construct(&p[i], elem[i]);
	for (int i = 0; i < sz; ++i) alloc.destroy(&elem[i]);
	alloc.deallocate(elem, space);
	elem = p;
	space = new_alloc;
}

template<class T, class A>void vector<T, A>::resize(int new_size, T val = T()) {
	reserve(new_size);
	for (int i = sz; i < new_size; ++i) alloc.construct(&elem[i], val);
	for (int i = new_size; i < sz; ++i) alloc.destroy(&elem[i]);
	sz = new_size;
}

template<class T, class A>void vector<T, A>::push_back(const T &val) {
	if (space == 0)reserve(8);
	else if (sz == space)reserve(space * 2);
	alloc.construct(&elem[sz], val);
	++sz;
}

template<class T, class A>void vector<T, A>::clear() {
	T* p = new T[sz];
	delete[] elem;
	elem = p;
	for (int i = 0; i < sz; ++i) elem[i] = T();
}


template<class T>istream& operator >> (istream& is, vector<T>v) {
	T a;
	is >> a;
	if (!is) return;
	v.push_back(a);
	return is;
}