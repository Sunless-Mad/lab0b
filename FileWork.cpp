#include "FileWork.h"
#include <iostream>
#include <fstream>
#include <string>

FileWork::FileWork(std::ifstream& in, std::ofstream& out)
	: input(in), output(out), count_words(0.0) {}

FileWork::~FileWork() = default;
	
TableCSV FileWork::parse_words(){
	TableCSV table = TableCSV();
	char ch;
	std::string current;
	input.seekg(0);
	while (input.get(ch)) {
		if (std::isalnum(static_cast<unsigned char>(ch))) {
			current += ch;
		}
		else {
			if (!current.empty()) {
				table.add_word(current);
				count_words++;
				current.clear();
			}
		}
	}
	if (!current.empty()) {
		table.add_word(current); 
	}
	return table;
}
void FileWork::do_csvfile() {
	TableCSV table = parse_words();
	std::vector<std::pair<std::string, WordInfo>> frequency_words = table.sort_map();
	for (const auto& pair : frequency_words) {
		const std::string& word = pair.first;
		const WordInfo& info = pair.second;
		double persent = (info.get_frequency() / count_words) * 100.0;
		output << word << ";" << info.get_frequency() << ";" << persent << "%" << std::endl;
	}
}
