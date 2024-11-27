#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include "trigram.h"
#include <sstream>
#include "edit_distance.h"

using std::string;
using std::vector;


Dictionary::Dictionary() {
std::ifstream inFile("words.txt");
    std::string line;

    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string word;
        int trigramCount;

        ss >> word >> trigramCount;

        std::vector<std::string> trigrams;
        std::string trigram;
        for (int i = 0; i < trigramCount; ++i) {
            ss >> trigram;
            trigrams.push_back(trigram);
        }

        if (word.size() <= maxlen) {
            words[word.size() - 1].push_back(Word(word, trigrams));
        }
    }

    inFile.close();
}


bool Dictionary::contains(const string& word) const {
	   for (const Word& dictionaryWord : words[word.size() - 1]) {
        if (dictionaryWord.get_word() == word) {
            return true;
        }
    }
	return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(word, suggestions);
	rank_suggestions(word, suggestions);
	trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(const std::string& word, std::vector<std::string>& suggestions) const {
    if (word.size() > maxlen) {
        return;
    }
    
    std::vector<std::string> trigrams = gen_trigrams(word);
    size_t wordLength = word.size();

    for (int lengthDiff = -1; lengthDiff <= 1; ++lengthDiff) {
        size_t targetLength = wordLength + lengthDiff;

        if (targetLength > 0 && targetLength <= maxlen) {
            for (const Word& candidate : words[targetLength - 1]) {
                unsigned int matches = candidate.get_matches(trigrams);

                if (matches >= 1) {
                    suggestions.push_back(candidate.get_word());
                }
            }
        }
    }
}

void Dictionary::rank_suggestions(const std::string& word, std::vector<std::string>& suggestions) const{
	std::sort(suggestions.begin(), suggestions.end(), [&word] (const std::string& a, const std::string& b){
			return edit_distance(word, a) < edit_distance(word, b);
	});


}

void Dictionary::trim_suggestions(std::vector<std::string>& suggestions) const{
	if (suggestions.size() > 5){
		suggestions.resize(5);

	}

}


std::vector<std::string> Dictionary::gen_trigrams(const std::string& word) const{
 std::vector<std::string> results;

    if (word.size() < 3) {
        return results;
    }

    std::string alphOnly;
    for (char c : word) {
        if (std::isalpha(c)) {
            alphOnly.push_back(tolower(c));
        }
    }

    for (size_t i = 0; i + 2 < alphOnly.size(); ++i) {
        std::string trigram = alphOnly.substr(i, 3);
        if (std::find(results.begin(), results.end(), trigram) == results.end()) {
            results.push_back(trigram);
        }
    }

    std::sort(results.begin(), results.end());

    return results;

}