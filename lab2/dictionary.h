#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

constexpr int maxlen = 25;

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
	void add_trigram_suggestions(const std::string& word, std::vector<std::string>& suggestions) const;

	void rank_suggestions(const std::string& word, std::vector<std::string>& suggestions) const;
	void trim_suggestions(std::vector<std::string>& suggestions) const;


private:
	std::vector<Word> words[maxlen];

	std::vector<std::string> gen_trigrams(const std::string& word) const;

};

#endif
