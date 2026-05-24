#include"Functions.h"
#include<fstream>

using namespace std;

/*
in file "word.txt" first line:word to insert
second line: word to search	
*/
int main() {
	fstream file("out.txt");
	Formular main_text = Formular();
	Formular words = Formular();//head-insert cur-search

	get_text(main_text);

	main_text.cur = main_text.head;
	while (main_text.cur) {
		file << *main_text.cur << endl;

		main_text.cur = main_text.cur->next;
	}
	file << endl;

	get_words(words);

	insert(main_text, words);

	main_text.cur = main_text.head;
	while (main_text.cur) {
		file << *main_text.cur << endl;

		main_text.cur = main_text.cur->next;
	}
	
	main_text.clear();
	delete words.head;
	delete words.cur;
}