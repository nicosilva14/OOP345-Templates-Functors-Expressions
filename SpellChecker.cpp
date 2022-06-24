//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
//Nicolas Silva
//156929218
//nsilva18@myseneca.ca
//June 18, 2022
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include "SpellChecker.h"
#include "Book.h"

namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file) {
			throw std::invalid_argument("Bad file name!");
		}
		std::string words;
		int index = 0;
		do {
			//index to add word to
			std::getline(file, words);
			if (file) {
				//counter to keep track of which variable we are assigning
				int cnt = 0;
				int start = 0;
				//string to hold delimiter ","
				std::string del = " ";
				//string to hold delimiter "\n"
				std::string newline = "\n";
				//temp strings to hold variables with and without spaces
				std::string temp;
				std::string tempNo;
				int end = words.find(del);
				while (cnt >= 0) {
					//for description instead of finding a comma we find newline; set end to newline
					if (cnt == 1) {
						end = words.find(newline);
					}
					temp = words.substr(start, end - start);
					//removes leading and trailing spaces
					noSpaces(temp, tempNo);
					if (cnt==0){
						m_badWords[index]= tempNo;
					}
					else {
						m_goodWords[index]= tempNo;
						cnt = -2;
					}
					cnt++;
					start = end;
				}
				index++;
			}
		} while (file);
	}
	void SpellChecker::operator()(std::string& text){
		int word;
		for (auto i = 0; i < 6; i++){
			word = 0;
			while (word != -1)
			{
				word = text.find(m_badWords[i]);
				if (word !=-1)
				{
					text.replace(word, m_badWords[i].length(), m_goodWords[i]);
					rep[i]++;
				}
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& os)	{
		os << "Spellchecker Statistics\n";
		for (auto i = 0; i < 6; i++){
			os << std::setw(15) <<this->m_badWords[i]<< ": " << this->rep[i] << " replacements"<<std::endl;
		}
	}
}