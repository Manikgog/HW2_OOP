#include "apartment.hpp"
#include "human.hpp"

Apartment::Apartment(std::string name) : Component(name){}

void Apartment::Add(Component* component) {
	humans_.push_back(component);
}

void Apartment::Remove(Component* component) {
	humans_.erase(remove(humans_.begin(), humans_.end(), component), humans_.end());
}

void Apartment::Print() {
	std::cout << "Apartment number - " << name_ << std::endl;
	for (const auto human : humans_) {
		human->Print();
	}
}