#ifndef _HUMAN_H_
#define _HUMAN_H_
#include <iostream>

#include "Component.hpp"

class Human : public Component {
private:
	
public:

	Human(std::string name);

	void Add(Component* component) override {

	}

	void Remove(Component* component) override {

	}

	void Print() {
		std::cout << name_ << std::endl;
	}
};
#endif