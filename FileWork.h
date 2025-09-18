#ifndef FILEWORK
#define FILEWORK

#include <iostream>
#include <fstream>
#include <string>
#include "TableCSV.h"

class FileWork {
private:
	std::ifstream& input; 
	std::ofstream& output;
	double count_words;
	TableCSV parse_words();
public:
	~FileWork();
	FileWork(std::ifstream& in, std::ofstream& out);
	void do_csvfile();
};




#endif

