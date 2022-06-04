#include <iostream>

#include <Windows.h>

using namespace std;

class String {


	private:

		int size;

		char* str;

	public:

		String() {

			size = 0;

			str = nullptr;

		}

		String(const char* str) {

			size = strlen(str);

			this->str = new char[size];

			for (int i = 0; i < size; i++) this->str[i] = str[i];

		}

		String(const String& other) {
		
			this->size = other.size;

			this->str = new char[size];

			for (int i = 0; i < size; i++) this->str[i] = other.str[i];


		}

		String (String && other) noexcept {

			this->size = other.size;

			this->str = other.str;

			other.str = nullptr;

		}

		String& operator = (String && other) {

			this->size = other.size;

			this->str = other.str;

			other.str = nullptr;

			return *this;
		}

		String operator + (const String& other) {

			String temp;

			temp.size = this->size + other.size;

			temp.str = new char[temp.size];

			for (int i = 0; i < this->size; i++) temp.str[i] = this->str[i];

			for (int i = this->size, j = 0; i < temp.size; i++, j++) temp.str[i] = other.str[j];
			
			return temp;

		}

		String & operator = (const String & other) {

			delete[] this->str;

			this->str = new char[other.size];

			this->size = other.size;

			for (int i = 0; i < other.size; i++) this->str[i] = other.str[i];

			return *this;

		}

		char& operator[] (const int index) {

			return this->str[index];

		}

		void show() {

			for (int i = 0; i < this->size; i++) cout << str[i];

		}

		int getSize() {

			return this->size;
		}

		bool operator == (const String other) {

			if (this->size != other.size) return false;

			for (int i = 0; i < this->size; i++) {

				if (this->str[i] != other.str[i]) return false;

			}
			return true;
		}
		bool operator != (const String other) {

			if (this->size != other.size) return true;

			for (int i = 0; i < this->size; i++) {

				if (this->str[i] != other.str[i]) return true;

			}
			return false;
		}
		~String() {

			delete [] str;

			str = nullptr;

		}

};

int main() {
	
	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);
 
	
	system("pause");

 }