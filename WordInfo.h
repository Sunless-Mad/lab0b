#ifndef WORDINFO
#define WORDINFO

#include <string>

class WordInfo {
private:
	int frequency;

public:
	WordInfo();
	~WordInfo();
	int get_frequency() const;
	void add_frequency();

};
#endif 
