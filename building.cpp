#include "building.hpp"

ApartmentBuilding::~ApartmentBuilding() {
	for (auto it = _bilding.begin(); it != _bilding.end(); ++it) {
		if (*it != nullptr)
			delete* it;
	}
}

void ApartmentBuilding::AddApartment(const Apartment& ap) {
	Apartment* _ap = new Apartment;
	*_ap = ap;
	_bilding.push_back(_ap);
}

void ApartmentBuilding::AddApartment(Human& human, unsigned int numApartment) {
	Apartment* tmp = new Apartment(human, numApartment);
	_bilding.push_back(tmp);
}

void ApartmentBuilding::PrintApartmentBulding() {
	for (const auto& ap : _bilding) {
		std::cout << "---------------------------------------------\n";
		std::cout << " вартира - " << ap->GetNumApartment() << std::endl;
		ap->PrintApartment();

	}
	std::cout << "\n---------------------------------------------\n";
}

void ApartmentBuilding::CheckNumOfApartment(Human& human, unsigned int numApartment) {
	for (auto it = _bilding.begin(); it != _bilding.end(); ++it) {
		if ((*it)->GetNumApartment() == numApartment) {
			(*it)->AddHuman(human, numApartment);
			return;
		}
	}

	AddApartment(human, numApartment);
	return;
}
