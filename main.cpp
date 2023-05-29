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
#include "human.hpp"
#include "apartment.hpp"
#include "building.hpp"



int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	ApartmentBuilding ab1;
	bool is_first = true;
	char choice = 'e';
	do{
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
		delete[] c_fio;

		ab1.CheckNumOfApartment(tmp_h, numApartment);
		std::cout << "Хотите продолжить (y/n)? ";
		std::cin >> choice;
	}while (choice == 'y');
	
	ab1.PrintApartmentBulding();

	
	
	return 0;
}
