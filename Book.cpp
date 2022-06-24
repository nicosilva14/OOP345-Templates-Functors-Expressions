//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
//Nicolas Silva
//156929218
//nsilva18@myseneca.ca
//June 14, 2022
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <list>
#include "Book.h"
namespace sdds {
	Book::Book() {
		m_author="";
		m_title="";
		m_country="";
		m_yearPub=0;
		m_price=0;
		m_description="";
	}
	const std::string& Book::title() const{
		return this->m_title;
	}
	const std::string& Book::country() const{
		return this->m_country;
	}
	const size_t& Book::year() const{
		return this->m_yearPub;
	}
	double& Book::price(){
		return this->m_price;
	}
	Book::Book(const std::string& strBook){
		m_author = "";
		m_title = "";
		m_country = "";
		m_yearPub = 0;
		m_price = 0;
		m_description = "";
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
		int end = strBook.find(comma);
		while (cnt >= 0) {
			//for description instead of finding a comma we find newline; set end to newline
			if (cnt == 5) {
				end = strBook.find(newline);
			}
			temp = strBook.substr(start, end - start);
			//removes leading and trailing spaces
			noSpaces(temp, tempNo);
			if (cnt==0)	{
				m_author = tempNo;
			}
			if (cnt == 1){
				m_title = tempNo;
			}
			if (cnt == 2){
				m_country = tempNo;
			}
			if (cnt == 3){
				m_price = stod(tempNo);
			}
			if (cnt == 4){
				m_yearPub = stoi(tempNo);
			}
			if (cnt == 5){
				m_description = tempNo;
				//set cnt to -2 to exit while loop
				cnt = -2;
			}
			cnt++;
			start = end + comma.size();
			end = strBook.find(comma, start);
		}
		
	}
	std::ostream& operator<<(std::ostream& os, const Book& obj) {
		os << std::setw(20) << obj.m_author << " | ";
		os << std::setw(22) << obj.m_title << " | ";
		os << std::setw(5) << obj.m_country << " | ";
		os << std::setw(4) << obj.m_yearPub << " | ";
		os << std::fixed << std::setw(6) << std::setprecision(2) << obj.m_price << " | ";
		os << obj.m_description << std::endl;
		return os;
	}
	
	void noSpaces(const std::string& in, std::string& out) {
		std::string::const_iterator start = in.begin(), fin = in.end();
		while (isspace(*start)) {
			++start;
		}
		if (start != fin) {
			while (isspace(*(fin - 1))) {
				--fin;
			}
		}
		out.assign(start, fin);
	}
}