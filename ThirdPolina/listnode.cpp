#include<iostream>
#include"String.h"
#include"ListNode.h"

ListNode::ListNode() {
	next = NULL;
}

ListNode::ListNode(String& str) {
	next = NULL;
	val = str;
}

ListNode::ListNode(String& str, ListNode* nxt) {
	next = nxt;
	val = str;
}

ListNode::~ListNode() {
	val.remove();
}

std::ostream& operator<<(std::ostream& os, ListNode& el) {
	os << el.val << "\n |\n\\/";
	if (el.next == NULL) os << "\nNULL";
	return os;
}