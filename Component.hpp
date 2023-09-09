#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>
#include <vector>


class Component
{
protected:
	std::string name_;

public:
	Component(std::string name) : name_(name) {	}
	virtual void Add(Component* component) = 0;
	virtual void Remove(Component* component) = 0;
	virtual void Print() = 0;
};



#endif // !_COMPONENT_HPP_
