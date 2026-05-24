#pragma once
#define Formular_H
#include"ListNode.h"

struct Formular
{
	ListNode* head = NULL;
	ListNode* prev = NULL;
	ListNode* cur = NULL;

	void clear();
};