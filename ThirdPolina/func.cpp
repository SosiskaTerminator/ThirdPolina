#include"Functions.h"
#include<fstream>

using namespace std;

bool compare(String& first, String& second) {
	if (first.count != second.count) return false;

	int i = 0, j = 0;
	while (i != first.count) {
		if (first.pA[i] != second.pA[j]) return false;

		i++;
		j++;
	}

	return true;
}

void get_string(String& str, fstream& file) {
	char cur = '\0';

	while (true) {
		file >> cur;

		if (cur == '\n' || file.eof()) break;

		str.push_back(cur);
	}
}

void get_text(Formular& form) {
	ListNode* head = new ListNode(), * cur; form.head = head;
	cur = head;

	fstream file("input.txt", ios::in);
	if (!file.is_open()) { cout << "Ошибка открытия файла" << endl; return; }
	file.unsetf(ios::skipws);

	while (!file.eof()) {
		ListNode* temp = new ListNode();
		String str;

		get_string(str, file);

		temp->val = str;
		cur->next = temp;
		cur = cur->next;

		str = String{};
	}

	form.head = form.head->next;
}

void get_words(Formular& frm) {
	fstream file("word.txt", ios::in);
	if (!file.is_open()) { cout << "Ошибка открытия файла" << endl; return; }
	file.unsetf(ios::skipws);

	ListNode *wrd1 = new ListNode(), *wrd2 = new ListNode();

	for (int i = 0; i < 2; i++) {
		if (!i) {
			String str;
			get_string(str, file);

			wrd1->val = str;
		}
		else {
			String str;
			get_string(str, file);

			wrd2->val = str;
		}
	}

	frm.head = wrd1;
	frm.cur = wrd2;
}

void insert(Formular& main, Formular& words) {
	main.prev = NULL;
	main.cur = main.head;

	while (main.cur) {
		if (compare(main.cur->val, words.cur->val)) {
			ListNode* new_node = new ListNode(words.head->val);
			if (main.prev) {
				main.prev->next = new_node;
				new_node->next = main.cur;
				main.cur = main.cur->next;
				main.prev = new_node;
			}
			else {
				new_node->next = main.head;
				main.head = new_node;
				main.cur = main.head->next->next;
				main.prev = main.head->next;
			}
		}
		else {
			main.prev = main.cur;
			main.cur = main.cur->next;
		}
	}
}