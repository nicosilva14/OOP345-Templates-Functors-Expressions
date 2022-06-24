//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
//Nicolas Silva
//156929218
//nsilva18@myseneca.ca
//June 18, 2022
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>
#include <stdexcept>
#include "Book.h"
#include "Movie.h"
#include "SpellChecker.h"
namespace sdds {
	template <class T>
	class Collection
	{
		std::string colName;
		T* t;
		size_t arrSize;
		void (*foo)(const Collection<T>&, const T&);
	public:
		Collection(const std::string& name) {
			colName = name;
			t = nullptr;
			arrSize = 0;
			foo = nullptr;
		};
		~Collection() {
			delete[]t;
		};
		const std::string& name() const {
			return this->colName;
		}
		size_t size() const {
			return this->arrSize;
		}
		void setObserver(void(*observer)(const Collection<T>&, const T&)) {
			this->foo = observer;
		};
		
		Collection<T>& operator+=(const T& item) {
			T* temp = nullptr;
			int check=0;
			for (auto i = 0u; i < arrSize; i++)
			{
				if (this->t[i].title() == item.title()) {
					check++;
				}
			}
			if (check == 0) {
				temp = new T[arrSize + 1];
				for (auto i = 0u; i < arrSize; i++)
				{
					temp[i] = this->t[i];
				}
				temp[arrSize] = item;
				delete[]this->t;
				arrSize++;
				this->t = new T[arrSize];
				for (auto i = 0u; i < arrSize; i++)
				{
					this->t[i] = temp[i];
				}
				delete[]temp;
				if (foo!=nullptr){
					foo(*this, item);
				}
			}
			return *this;
		}

		T& operator[](size_t idx)const {
			int check = -1;
			for (auto i = 0u; i < arrSize; i++){
				if (i == idx) {
					check++;
				}
			}
			if (check>=0){

				return this->t[idx];
			}
			else
			{
				std::string idxstr = std::to_string(idx);
				std::string arrstr = std::to_string(arrSize);
				throw std::out_of_range(("Bad index [" + idxstr + "]. Collection has [" + arrstr+ "] items."));
			}
		}
		T* operator[](const std::string& title)const {
			int check = -1;
			for (auto i = 0u; i < arrSize; i++)
			{
				if (this->t[i].title() == title) {
					check = i;
				}
			}
			if (check>=0){
				return &this->t[check];
			}
			else {
				return nullptr;
			}
		}
	
	};
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T> & obj) {
		
		for (auto i = 0u; i < obj.size(); i++) {
			os << obj[i];
		}
		return os;
	}
}
#endif //!SDDS_COLLECTION_H