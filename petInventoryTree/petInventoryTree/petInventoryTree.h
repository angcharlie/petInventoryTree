//Charlie Ang
//May 27, 2016
//CSC 2431 Spring 2016
//Assignment 5 - petInventoryTree class to store information for pets in a pet store.


#ifndef H_petInventoryTree
#define H_petInventoryTree

#include <iostream>
#include <string>
#include "binarySearchTree.h"
#include "petType.h"

class petInventoryTree : private bSearchTreeType<petType>
{
public:
	//Default constructor 
	petInventoryTree();

	//Accessor to keep track of number of pets in inventory 
	int petCount();

	//Prints all pets in the inventory, and number of pets.
	//Wrapper for bSearchTreeType inorderTraversal
	void printPets();

	//Finds a pet in the inventory by name
	//Returns true if pet is in the inventory, false otherwise
	//Wrapper for bSearchTree search
	bool findPet(string name);

	//Add a pet to the inventory (if not present) by name
	//Wrapper for bSearchTree insert
	void addPet(string name);

	//Remove a pet from the inventory (if present) by name
	//Wrapper for bSearchTree deleteNode
	void removePet(string name);


private:
	unsigned int numberPets;	//keeping track of number of pets in inventory 
};

//*******************************************implementation*******************************************

//Default constructor 
petInventoryTree::petInventoryTree()
{
	numberPets = 0;
}

//Acessor for number of pets in inventory
int petInventoryTree::petCount()
{
	return numberPets;
}

//Print pets
void petInventoryTree::printPets()
{
	bSearchTreeType::inorderTraversal();
}

//Find pet 
bool petInventoryTree::findPet(string name)
{
	//petType(name);
	return bSearchTreeType::search(name);
}

//Add pet 
void petInventoryTree::addPet(string name)
{
	//petType(name);
	if (findPet(name) == true)
	{
		cout << "Pet is already in the inventory!" << endl;
	}
	else //pet is not already in the inventory 
	{
		bSearchTreeType::insert(name);
		numberPets++;	//only if added name doesn't already exist 
	}
}

//Remove pet
void petInventoryTree::removePet(string name)
{
	//nodeType<petType>
	if (findPet(name) == true )
	{
		bSearchTreeType::deleteNode(name);
		numberPets--; //if removed since name was in inventory 
	}
	else
	{
		cout << "Pet does not exist in the inventory." << endl;
	}

}
#endif