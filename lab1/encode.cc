#include "coding.h"
#include <iostream>
#include <fstream>
#include <string>

int main(){

std::string filename;

std::cout <<"Enter filename: ";
std::cin >> filename;

std::ifstream infile(filename);
std::ofstream outfile (filename + ".enc");

char ch;
while(infile.get(ch)){
	outfile.put(encode(static_cast<unsigned char>(ch)));



}
}