#include"Functions.h"
#include<fstream>

using namespace std;

void print(Formular& frm, fstream& file) {
	frm.cur = frm.head;
	while (frm.cur) {
		file << *frm.cur << endl;

		frm.cur = frm.cur->next;
	}
	file << endl;
}

/*
in file "word.txt" first line:word to insert
second line: word to search	
*/
int main() {
	fstream file("out.txt");
	Formular main_text = Formular();
	Formular words = Formular();//head-insert cur-search

	get_text(main_text);

	print(main_text, file);

	get_words(words);

	insert(main_text, words);

	print(main_text, file);
	
	main_text.clear();
	delete words.head;
	delete words.cur;
}