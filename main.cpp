/*
Создайте программу, имитирующую многоквартирный
дом. Необходимо иметь классы “Человек”, “Квартира”,
“Дом”. Класс “Квартира” содержит динамический массив
объектов класса “Человек”. Класс “Дом” содержит массив
объектов класса “Квартира”.
Каждый из классов содержит переменные-члены и функции-члены, которые необходимы для предметной области
класса. Обращаем ваше внимание, что память под строковые значения выделяется динамически. Например, для
ФИО в классе “Человек”. Не забывайте обеспечить классы
различными конструкторами (конструктор копирования
обязателен), деструкторами. В main протестировать работу полученного набора классов.
*/


#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <string>

class Human {
private:
	char* _FIO;
	size_t _size;
	

public:
	Human() : _FIO(nullptr), _size(0)
	{}

	Human(char* FIO, size_t size)
	{
		_FIO = new char[size] {};
		for (size_t i = 0; i < size; ++i) {
			_FIO[i] = FIO[i];
		}
		_size = size;
	}
	
	Human& operator=(Human const & human) {
		if (this != &human) {
			if(_FIO != nullptr)
				delete[] _FIO;
			_size = human._size;
			_FIO = new char[_size] {};
			for (size_t i = 0; i != _size; ++i) {
				_FIO[i] = human._FIO[i];
			}
		}
		return *this;
	}

	~Human() {
		if(_FIO != nullptr)
			delete[] _FIO;
	}
	void PrintHuman() {
		std::cout << _FIO << std::endl;
	}

	

};


class Apartment {
private:
	std::vector<Human*> _apartment;
	unsigned int _numApartment;

public:
	Apartment() {}

	Apartment(Human& human, unsigned int numApartment)
	{
		Human* h = new Human(human);
		_apartment.push_back(h);
		_numApartment = numApartment;
	}

	~Apartment() {
		for (auto it = _apartment.begin(); it != _apartment.end(); ++it) {
			if (*it != nullptr)
				delete* it;
		}
	}

	void AddHuman(const Human& h, unsigned int numApartment) {
		if (numApartment == _numApartment) {
			Human* _h = new Human;
			*_h = h;
			_apartment.push_back(_h);
			return;
		}
		return;
	}

	Apartment& operator=(Apartment const& ap) {
		if (this != &ap) {
			_apartment = ap._apartment;
		}
		return *this;
	}

	unsigned int GetNumApartment() {
		return _numApartment;
	}
	
	void PrintApartment() {
		std::cout << "---------------------------------------------\n";
		for (const auto& h : _apartment) {
			h->PrintHuman();
		}
	}

	
};


class ApartmentBuilding {
private:
	std::vector<Apartment*> _bilding;


public:

	~ApartmentBuilding() {
		for (auto it = _bilding.begin(); it != _bilding.end(); ++it) {
			if(*it != nullptr)
				delete *it;
		}
	}

	void AddApartment(const Apartment& ap) {
		Apartment* _ap = new Apartment;
		*_ap = ap;
		_bilding.push_back(_ap);
	}

	void AddApartment(Human& human, unsigned int numApartment) {
		Apartment* _ap = new Apartment;
		Apartment tmp(human, numApartment);
		_ap = &tmp;
		_bilding.push_back(_ap);
	}

	void PrintApartmentBulding() {
		for (const auto& ap : _bilding) {
			ap->PrintApartment();
		}
	}

	void CheckNumOfApartment(Human& human, unsigned int numApartment) {
		for (auto it = _bilding.begin(); it != _bilding.end(); ++it) {
			if ((*it)->GetNumApartment() == numApartment) {
				(*it)->AddHuman(human, numApartment);
			}
			return;
		}

		AddApartment(human, numApartment);
		return;
	}

};


int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	Human h1;
	ApartmentBuilding ab1;
	bool is_first = true;
	for (int i = 0; i < 2; ++i) {
		std::cout << "Введите ФИО -> ";
		std::string fio;
		if(!is_first)
			std::cin.ignore();
		is_first = false;
		std::getline(std::cin, fio);
		std::cout << "Введите номер квартиры -> ";
		unsigned int numApartment;
		std::cin >> numApartment;
		char* c_fio = new char[fio.size() + 1] {};
		for (size_t i = 0; i < fio.size(); i++) {
			c_fio[i] = fio[i];
		}
		Human tmp_h(c_fio, fio.size() + 1);
		h1 = tmp_h;
		delete[] c_fio;

		ab1.CheckNumOfApartment(h1, numApartment);
				
	}
	
	ab1.PrintApartmentBulding();
	
	return 0;
}
