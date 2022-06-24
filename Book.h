//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
//Nicolas Silva
//156929218
//nsilva18@myseneca.ca
//June 14, 2022
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>
#include"SpellChecker.h"
namespace sdds {
	class Book
	{
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_yearPub;
		double m_price;
		std::string m_description;
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book& obj);
		
		template<typename T>
		void fixSpelling(T& spellCheck) {
			spellCheck(this->m_description);
		};
	};
	void noSpaces(const std::string& in, std::string& out);//removes trailing and leading spaces from string

}

#endif //!SDDS_BOOK_H