//Charlie Ang
//May 27, 2016
//CSC 2431 Spring 2016
//Assignment 5 - petType class to store information for pets in a pet store.

#ifndef _PET_
#define _PET_

#include <string>

class petType
{
	//Overload stream insertion operator 
	friend ostream& operator<<(ostream&, const petType&);
public:
	//making print virtual will fix the compile-time binding
	// issue in the client print function, and allow us to pass
	// dogType as petType but have dogType::print() called.
	// Only works with pointers and reference parameters!
	//virtual void print(); 
	void print();

	petType(std::string n = "");

	//Overload relational operators 
	bool operator==(const petType&) const;
	bool operator!=(const petType&) const;
	bool operator<(const petType&) const;
	bool operator<=(const petType&) const;
	bool operator>(const petType&) const;
	bool operator>=(const petType&) const;

private:
	std::string name;
};

//Overload stream insertion operator 
ostream& operator <<(ostream& osObject, const petType& pet)
{
	osObject << pet.name << " ";
	return osObject;
}

petType::petType(std::string n)
{
	name = n;
}

//Overload the relational operators 
bool petType::operator==(const petType& right) const
{
	return(name == right.name);
}

bool petType::operator!=(const petType& right) const
{
	return(name != right.name);
}

bool petType::operator<(const petType& right) const
{
	return(name < right.name);
}

bool petType::operator<=(const petType& right) const
{
	return (name <= right.name);
}

bool petType::operator>(const petType& right) const
{
	return (name > right.name);
}

bool petType::operator>=(const petType& right) const
{
	return (name >= right.name);
}

#endif