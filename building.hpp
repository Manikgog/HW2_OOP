#ifndef _BUILDING_H_
#define _BUILDING_H_

#include "apartment.hpp"
#include "human.hpp"
#include <vector>


class Building : public Component
{
private:
	std::vector<Component*> apartments_;

public:
	Building(std::string name) : Component(name) {}
	void Add(Component* component) {
		apartments_.push_back(component);
	}

	void Remove(Component* component) {
		apartments_.erase(remove(apartments_.begin(), apartments_.end(), component), apartments_.end());
	}

	void Print() {
		std::cout << "Building address - " << name_ << std::endl;
		for (const auto apartment : apartments_) {
			apartment->Print();
		}
	}
};


#endif