#include <iostream>
#include <fstream>
#include <filesystem>
#include "CounterWords.h"
#include "Reader.h"
#include "Writer.h"

int main(int argc, char* argv[])
{
	std::ifstream infile(argv[1]);
	if (!infile.is_open()) {
		std::cerr << "couldn't open the file " << argv[1];
	}
	Reader reader = Reader(infile);
	CounterWords counter = reader.parse_words();
	infile.close();
	std::ofstream outfile(argv[2]);
	if (!outfile.is_open()) {
		std::cerr << "couldn't open the file " << argv[2];
	}
	Writer writer = Writer(outfile, counter);
	writer.create_csvfile();
	outfile.close();
}