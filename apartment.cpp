#include "apartment.hpp"
#include "human.hpp"

Apartment::Apartment(Human& human, unsigned int numApartment)
{
	Human* tmp = new Human(human);
	_apartment.push_back(tmp);
	_numApartment = numApartment;
}

Apartment::~Apartment() {
	for (std::vector<Human*>::iterator it = _apartment.begin(); it != _apartment.end(); ++it) {
		if (*it != nullptr)
			delete* it;
	}
}

void Apartment::AddHuman(const Human& h, unsigned int numApartment) {
	if (numApartment == _numApartment) {
		Human* _h = new Human;
		*_h = h;
		_apartment.push_back(_h);
		return;
	}
	return;
}

Apartment& Apartment::operator=(Apartment const& ap) {
	if (this != &ap) {
		_apartment = ap._apartment;
	}
	return *this;
}

void Apartment::PrintApartment() {

	for (const auto& h : _apartment) {
		h->PrintHuman();
	}
}