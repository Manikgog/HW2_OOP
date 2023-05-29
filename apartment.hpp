#ifndef _APARTMENT_H_
#define _APARTMENT_H_

#include "human.hpp"


#include <vector>


class Apartment {
private:
	std::vector<Human*> _apartment;
	unsigned int _numApartment;

public:
	Apartment() : _numApartment(0)
	{}

	Apartment(Human& human, unsigned int numApartment);


	~Apartment();

	void AddHuman(const Human& h, unsigned int numApartment);

	Apartment& operator=(Apartment const& ap);

	unsigned int GetNumApartment() {
		return _numApartment;
	}

	void PrintApartment();


};

#endif