#ifndef COUNTER_WORDS
#define COUNTER_WORDS

#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "CounterWords.h"

class CounterWords {
private:
	int count_words;
	std::map<std::string, int> words;
public:
	CounterWords();
	~CounterWords();
	std::map<std::string, int> get_words();
	int get_count_words();
	void add_word(std::string);	
};
#endif