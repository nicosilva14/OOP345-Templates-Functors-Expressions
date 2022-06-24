//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
//Nicolas Silva
//156929218
//nsilva18@myseneca.ca
//June 18, 2022
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <fstream>
#define MAX_SIZE 6
namespace sdds {
	class SpellChecker
	{
		std::string m_badWords[MAX_SIZE]{};
		std::string m_goodWords[MAX_SIZE]{};
		int rep[6]{};//badwords replacement counter

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& os);
	};


}

#endif //!SDDS_SPELLCHECKER_H