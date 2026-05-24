#include<iostream>
#include "String.h"

String::String() {
	cap = 1;
	count = 0;
	pA = new char[cap];
}

void String::remove() {
	if (pA != nullptr) {
		delete[] pA;
		pA = nullptr;
	}
	cap = 0;
	count = 0;
}

std::ostream& operator<<(std::ostream& os, String& s) {
	for (int i = 0; i < s.count; i++) {
		os << *(s.pA + i);
	}
	return os;
}

String& String::operator=(const String& other) {
	if (this != &other) {
		delete[] pA;
		count = other.count;
		cap = other.cap;
		pA = new char[cap];
		for (int i = 0; i < count; i++) pA[i] = other.pA[i];
	}
	return *this;
}

void String::push_back(char c) {
	alloc(1);
	pA[count++] = c;
}

void String::alloc(unsigned n) {
	if (cap >= count + n) return;

	while (cap < count + n) {
		cap *= 2;
	}

	char* tmp = new char[cap];
	for (int i = 0; i < count; i++) {
		*(tmp + i) = *(pA + i);
	}

	delete[] pA;
	pA = tmp;
}