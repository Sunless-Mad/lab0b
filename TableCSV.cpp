#include <map>
#include <string>
#include "TableCSV.h"
#include "WordInfo.h"

TableCSV::TableCSV() :words(){}
TableCSV::~TableCSV() = default;

void TableCSV::add_word(std::string word) {
	auto key_word = words.find(word);
	if (key_word != words.end()) {
		key_word->second.add_frequency(); 
	}
	else {
		WordInfo word_info = WordInfo(); // если в мапе слова нет, то создаем объект с частотой 1
		words[word] = word_info;
	}
}
std::vector<std::pair<std::string, WordInfo>> TableCSV::sort_map() {
	std::vector<std::pair<std::string, WordInfo>> vecMap(words.begin(), words.end()); //копируем мапу в вектор
	std::sort(vecMap.begin(), vecMap.end(),
		[](const auto& a, const auto& b) {
			return a.second.get_frequency() > b.second.get_frequency(); //сортировка по частоте объектов WordInfo
		});
	return vecMap;
}
