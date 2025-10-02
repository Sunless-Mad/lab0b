#include "Reader.h"
#include <iostream>
#include "CounterWords.h"

Reader::Reader(std::ifstream& in)
	:input(in){}

Reader::~Reader() = default;

CounterWords Reader::parse_words() {
	CounterWords counter = CounterWords();
	char ch;
	std::string current;
	input.seekg(0);
	while (input.get(ch)) {
		if (std::isalnum(static_cast<unsigned char>(ch))) {
			current += ch;
		}
		else {
			if (!current.empty()) {
				counter.add_word(current);	
				current.clear();
			}
		}
	}
	if (!current.empty()) {
		counter.add_word(current);
	}
	return counter;
}