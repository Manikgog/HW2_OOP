#pragma once
#include <vector>
#include "apartment.hpp"
#include "human.hpp"

class ApartmentBuilding {
private:
	std::vector<Apartment*> _bilding;


public:

	~ApartmentBuilding();

	void AddApartment(const Apartment& ap);

	void AddApartment(Human& human, unsigned int numApartment);

	void PrintApartmentBulding();

	void CheckNumOfApartment(Human& human, unsigned int numApartment);

};
