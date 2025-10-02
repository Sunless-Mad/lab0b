#ifndef READER
#define READER
#include <fstream> 
#include <iostream>
#include "CounterWords.h"

class Reader {
private:
	std::ifstream& input;
public:
	Reader(std::ifstream&);
	~Reader();
	CounterWords parse_words();
};
#endif