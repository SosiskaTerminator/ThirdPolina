#pragma once
#define ListNode_H
#include"String.h"

struct ListNode {
	ListNode* next;
	String val;

	ListNode();
	ListNode(String&);
	ListNode(String&, ListNode*);
	~ListNode();
	friend std::ostream& operator<<(std::ostream&, ListNode&);
};