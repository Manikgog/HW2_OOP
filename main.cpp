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
#include "Component.hpp"



int main() {

	Component* MonicaBing = new Human("Monica Bing");
	Component* ChendlerBing = new Human("Monica Bing");
	Component* JoeTribiany = new Human("Joe Tribiany");
	Component* RachelGreen = new Human("Rachel Green");

	Component* apartment_1 = new Apartment("1");
	Component* apartment_2 = new Apartment("2");
	
	apartment_1->Add(MonicaBing);
	apartment_1->Add(ChendlerBing);
	apartment_2->Add(JoeTribiany);
	apartment_2->Add(RachelGreen);

	Component* building = new Building("Engelsa 38");
	
	building->Add(apartment_1);
	building->Add(apartment_2);
	
	
	building->Print();

	
	
	return 0;
}
