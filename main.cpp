#include <iostream>
#include <fstream>
#include "FileWork.h"
#include <filesystem>
int main(int argc, char* argv[])
{
	std::ifstream infile(argv[1]);
	std::ofstream outfile(argv[2]);
	if (!infile.is_open() || !outfile.is_open()) {
		return 1;
	}
	
	FileWork files = FileWork(infile, outfile);
	files.do_csvfile();
	infile.close();
	outfile.close();
}
