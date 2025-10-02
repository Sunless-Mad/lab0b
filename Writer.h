#ifndef WRITER
#define WRITER

#include <fstream> 
#include <iostream>
#include "CounterWords.h"

class Writer {
private:
	std::ofstream& output;
	CounterWords& counter;
public:
	Writer(std::ofstream&, CounterWords&);
	~Writer();
	void create_csvfile();
};


#endif