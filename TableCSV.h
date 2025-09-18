#ifndef TABLE
#define TABLE

#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "WordInfo.h"

class TableCSV {
private:
	std::map<std::string, WordInfo> words;
public:
	TableCSV();
	~TableCSV();
	void add_word(std::string word);
	std::vector<std::pair<std::string, WordInfo>> sort_map();
};
#endif
//PR