#include "Item.h"
#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(){
	numItems = 0;
	ID = new char[81];
	PassWord = new char[81];
	items = ppItem();
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
	delete[] Account::items;
	delete[] Account::ID;
	delete[] Account::PassWord;
}