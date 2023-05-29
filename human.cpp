#include "human.hpp"

Human::Human(char* FIO, size_t size)
{

	if (_FIO != nullptr)
		delete[] _FIO;
	_FIO = new char[size] {};
	for (size_t i = 0; i < size; ++i) {
		_FIO[i] = FIO[i];
	}
	_size = size;
	//std::cout << "Конструктор копирования Human\n" << "Адрес -> " << this << std::endl << _FIO 
		//<< ". Адрес -> " << &_FIO << std::endl;
}

Human::Human(Human& human)
{
	if (_FIO != nullptr)
		delete[] _FIO;
	_FIO = new char[human._size] {};
	for (size_t i = 0; i < human._size; ++i) {
		_FIO[i] = human._FIO[i];
	}
	_size = human._size;
	//std::cout << "Конструктор копирования Human\n" << "Адрес -> " << this << std::endl << _FIO
		//<< ". Адрес -> " << &_FIO << std::endl;
}

Human& Human::operator=(Human const& human) {
	if (this != &human) {
		if (_FIO != nullptr)
			delete[] _FIO;
		_size = human._size;
		_FIO = new char[_size] {};
		for (size_t i = 0; i != _size; ++i) {
			_FIO[i] = human._FIO[i];
		}
	}
	//std::cout << "Оператор присваивания Human:\nАдрес -> " << this << std::endl << _FIO
		//<< ". Адрес -> " << &_FIO << std::endl;
	return *this;
}
