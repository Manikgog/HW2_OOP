#ifndef _HUMAN_H_
#define _HUMAN_H_


#include <iostream>

class Human {
private:
	char* _FIO;
	size_t _size;


public:
	Human() : _FIO(nullptr), _size(0)
	{}

	Human(char* FIO, size_t size);

	Human(Human& human);

	Human& operator=(Human const& human);

	~Human() {
		//std::cout << "Деструктор Human\nАдрес -> " << this << _FIO << ". Адрес -> " << &_FIO << std::endl;
		if (_FIO != nullptr)
			delete[] _FIO;
	}
	void PrintHuman() {
		std::cout << _FIO << std::endl;
	}
};
#endif