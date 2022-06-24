//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
//Nicolas Silva
//156929218
//nsilva18@myseneca.ca
//June 14, 2022
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
#include <iostream>
#include "SpellChecker.h"
#include "Book.h"
namespace sdds {
	class Movie
	{
		std::string mov_title;
		int mov_year;
		std::string mov_description;
	public:
		Movie();
		Movie(const std::string& strMovie);
		const std::string& title() const;
		friend std::ostream& operator<<(std::ostream& os, const Movie& obj);


		template<typename T>
		void fixSpelling(T& spellCheck) {
			spellCheck(this->mov_title);
			spellCheck(this->mov_description);
		}
	
	};
}

#endif //!SDDS_MOVIE_H