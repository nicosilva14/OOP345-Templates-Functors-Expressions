//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
//Nicolas Silva
//156929218
//nsilva18@myseneca.ca
//June 14, 2022
#include <string>
#include <iomanip>
#include "Movie.h"
namespace sdds {
	Movie::Movie()	{
		mov_title = "";
		mov_description = "";
		mov_year = 0;
	}
	Movie::Movie(const std::string& strMovie) {
		mov_title = "";
		mov_description = "";
		mov_year = 0;
		//counter to keep track of which variable we are assigning
		int cnt = 0;
		int start = 0;
		//string to hold delimiter ","
		std::string comma = ",";
		//string to hold delimiter "\n"
		std::string newline = "\n";
		//temp strings to hold variables with and without spaces
		std::string temp;
		std::string tempNo;
		int end = strMovie.find(comma);
		while (cnt >= 0) {
			//for description instead of finding a comma we find newline; set end to newline
			if (cnt == 2) {
				end = strMovie.find(newline);
			}
			temp = strMovie.substr(start, end - start);
			//removes leading and trailing spaces
			noSpaces(temp, tempNo);
			if (cnt == 0) {
				mov_title = tempNo;
			}
			if (cnt == 1) {
				mov_year = stoi(tempNo);
			}
			if (cnt == 2) {
				mov_description = tempNo;
				cnt = -2;
			}
			cnt++;
			start = end + comma.size();
			end = strMovie.find(comma, start);
		}
	}
	const std::string& Movie::title() const{
			return this->mov_title;
	}
	std::ostream& operator<<(std::ostream& os, const Movie& obj){
		os << std::setw(40) << obj.mov_title << " | " 
			<< std::setw(4) << obj.mov_year <<" | " 
			<< obj.mov_description << std::endl;
		return os;
	}
}