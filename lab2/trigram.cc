#include "trigram.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>


std::vector<std::string> trigramFind (const std::string& word){
std::vector<std::string> results;

if (word.size() < 3){
return results;

}

for (size_t i = 0; i <= word.size() -3; ++i){
	std::string trigram = word.substr(i,3);
	if(std::find(results.begin(), results.end(), trigram) == results.end()){
		results.push_back(trigram);
	}


}

std::sort(results.begin(), results.end());

return results;
}

void readDict (){

std::ifstream inFile("dict.txt");
std::ofstream outFile ("words.txt");

std::string word;
while(std::getline(inFile, word)){
if (word.empty()){
	continue;
}


std::vector<std::string> trigramList = trigramFind(word);


}