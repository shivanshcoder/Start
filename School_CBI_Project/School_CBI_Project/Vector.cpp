
#include"vector.h"

template<class T, class A>vector<T, A>& vector<T, A>::operator=(const vector&) {
	if (this == &a)return *this;

	if (a.sz <= space) {
		for (int i = 0; i < a.sz; ++i) elem[i] = a.elem[i];
		sz = a.sz;
		return *this;
	}


	T* p = new T(a.sz);
	for (int i = 0; i < a.sz; ++i) elem[i] = a.elem[i];
	delete[] elem;
	elem = p;
	space = sz = a.sz;
	return *this;
}

template<class T, class A>void vector<T, A>::reserve(int new_alloc) {
	if (new_alloc <= space) return;
	T* p = new T[new_alloc];
	for (int i = 0; i < sz; ++i) p[i] = elem[i];
	delete[] elem;
	elem = p;
	space = new_alloc;
}

template<class T, class A>void vector<T, A>::resize(int new_size) {
	reserve(new_size);
	for (int i = sz; i < new_size; ++i) elem[i] = 0;
	sz = new_size;
}

template<class T, class A>void vector<T, A>::push_back(T& d) {
	if (space == 0)reserve(8);
	else if (sz == space)reserve(space * 2);
	elem[sz] = d;
	++sz;
}

template<class T, class A>void vector<T, A>::clear() {
	T* p = new T[sz];
	delete[] elem;
	elem = p;
	for (int i = 0; i < sz; ++i) elem[i] = 0;
}
