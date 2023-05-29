#ifndef _BUILDING_H_
#define _BUILDING_H_

#include "apartment.hpp"
#include "human.hpp"



#include <vector>


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

#endif