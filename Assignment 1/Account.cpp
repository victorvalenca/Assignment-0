#include "Item.h"
#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(){
	numItems = 0;
	ID = nullptr;
	PassWord = nullptr;
	items = new pItem();
}

void Account::AddItem(){
	
}

void Account::Report(){
	//TODO: List Account name and items
	if (!numItems){
		cout << "No items in your account" << endl;
	} 
	else {
		cout << "Account ID: " << ID << endl;
		for (unsigned int i = 0; i < numItems; i++){
			cout << "Item " << numItems << ": " << items[i]->description;
			cout << "| Cost: $" << items[i]->price << endl;
		}
	}

	cout << "Would you like to add another item? (Y/N)" << endl;
	//TODO: Write item entry logic
	
}

Account::~Account(){
	cout << "Inside Account Destructor" << endl;
	delete[] ID;
	delete[] PassWord;
	delete[] items;
}