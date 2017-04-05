//Charlie Ang
//May 27, 2016
//CSC 2431 Spring 2016
//Assignment 5 - petInventoryTree client to test petInventoryTree class

#include <iostream>
#include <string>
#include "petInventoryTree.h"
#include "binarySearchTree.h"
#include "petType.h"

using namespace std;

//Function to display the menu for user with options to choose from 
void displayMenu()
{
	cout << "1. Add pet to inventory" << endl;
	cout << "2. Remove pet from inventory" << endl;
	cout << "3. Search for pet in inventory" << endl;
	cout << "4. Print list of pets" << endl;
	cout << "5. Quit" << endl;
}

int main()
{
	petInventoryTree myPet; //make petInventoryTree object 
	int choice;				//user input for menu choice number 

	displayMenu();			//call display menu function 
	cout << "Enter menu choice: ";
	cin >> choice;			//retrieve user input for choice number 
		
	string name;			//name user inputs 
	while (choice != 5)	//while choice does not equal quit 
	{
		switch (choice)
		{
		case 1:
			cout << "Enter pet name to be added: ";
			cin >> name;
			cout << endl;
			myPet.addPet(name);
			break;

		case 2:
			cout << "Enter pet name to be removed: ";
			cin >> name;
			cout << endl;
			myPet.removePet(name);
			break;

		case 3:
			cout << "Enter pet name to search for: ";
			cin >> name;
			if (myPet.findPet(name))
			{
				cout << name << " is in our database!" << endl;
			}
			else
			{
				cout << name << " is not in our database!" << endl;
			}
			cout << endl;
			break;

		case 4:
			cout << "Here is a list of the " << myPet.petCount() << " pet(s) in the database: ";
			myPet.printPets();
			cout << endl;
			cout << endl;
			break;

		default: cout << "Invalid selection." << endl;

		}//end switch

		displayMenu();
		cout << "Enter menu choice: ";
		cin >> choice;
	}//end while 
	cout << "Goodbye!" << endl;

	return 0;
}

/* MY TEST
petInventoryTree myPet;
myPet.addPet("Sam");
myPet.addPet("zeek");
myPet.addPet("chester");
myPet.addPet("chester");

myPet.printPets();
if (myPet.findPet("chester") == true)
{
cout << "Pet was found." << endl;
}
else
{
cout << "Pet not found." << endl;
}

myPet.removePet("heidi");
myPet.printPets();
*/
