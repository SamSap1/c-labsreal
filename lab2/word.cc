#include <string>
#include <vector>
#include "word.h"

using std::vector;
using std::string;

Word::Word(const string& w, const vector<string>& t) {
	word = w;
	trigrams = t;

}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	unsigned int matchCount = 0;
	size_t i = 0;
	size_t j = 0;

	while (i < trigrams.size() && j < t.size()){
		if (trigrams[i] == t[j]){
			matchCount++;
			i++;
			j++;
		}else if (trigrams[i] < t[j]){
			i++;
		} else {
			j++;


		}



	}

	return matchCount;
}
