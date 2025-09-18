
#include "WordInfo.h"
WordInfo::WordInfo() //конструктор
		: frequency(1) {}

WordInfo::~WordInfo() = default;

int WordInfo::get_frequency() const { 
	return frequency;
}

void WordInfo::add_frequency() {
	frequency++;
}
