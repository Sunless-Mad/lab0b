#include <map>
#include <string>
#include "CounterWords.h"


CounterWords::CounterWords() : count_words(0) {};
CounterWords::~CounterWords() = default;

std::map<std::string, int> CounterWords::get_words() { 
	return words; 
}

int CounterWords::get_count_words() {
	return count_words;
}

void CounterWords::add_word(std::string word) {
	auto key_word = words.find(word);
	if (key_word != words.end()) {
		words[word] += 1;
	}
	else {
		words[word] = 1;
	}
	count_words++;
}

