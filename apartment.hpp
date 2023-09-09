#ifndef _APARTMENT_H_
#define _APARTMENT_H_

#include "human.hpp"
#include <vector>


class Apartment : public Component {
private:
	std::vector<Component*> humans_;

public:
	
	Apartment(std::string name);

	void Add(Component* component)override;

	void Remove(Component* component)override;

	void Print()override;


};

#endif