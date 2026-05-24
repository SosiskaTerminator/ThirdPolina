#pragma once
#define String_H
#include<iostream>

struct String {
	unsigned short count = 0;
	char* pA;

	String();
	void remove();
	void push_back(char);
	friend std::ostream& operator<<(std::ostream&, String&);
	String& operator=(const String&);
private:
	unsigned short cap = 0;
	void alloc(unsigned);
};