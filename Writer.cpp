#include "Writer.h"

Writer::Writer(std::ofstream& out, CounterWords& counter)
	:counter(counter), output(out) {}

Writer::~Writer() = default;

void Writer::create_csvfile() {
	auto word_map = counter.get_words();
	std::vector<std::pair<std::string, int>> frequency_words(word_map.begin(), word_map.end());
	std::sort(frequency_words.begin(), frequency_words.end(),
		[](const auto& a, const auto& b) {
			if (a.second != b.second){
				return a.second > b.second;
			}
			return a.first < b.first;
			
		});
	for (const auto& pair : frequency_words) {
		const std::string& word = pair.first;
		const int frequency = pair.second;
		double persent = (frequency / static_cast<double>(counter.get_count_words())) * 100.0;
		output << word << ";" << frequency << ";" << persent << "%" << std::endl;
	}
}