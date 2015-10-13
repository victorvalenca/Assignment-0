#include "Item.h"
#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(){
	numItems = 0;
	ID = nullptr;
	PassWord = nullptr;
	items = nullptr;
}

void Account::AddItem(){
	char desc_buffer[100] = {'\0'};
	double price_buffer;
	cout << "Enter the new Item description: ";
	fflush(stdin);
	cin >> desc_buffer;
	cout << "\nEnter the Item Price: ";
	fflush(stdin);
	cin >> price_buffer;

	//TODO: Input validation
	
	Item *newItem = new Item();
	newItem->description = new char[strlen(desc_buffer)+1];
	newItem->price = price_buffer;
	strcpy(newItem->description, desc_buffer);

	ppItem newItems = new pItem[numItems+1];

	if (items == nullptr){
		items = newItems;
	} else {
		for (unsigned int i = 0; i < numItems; i++) {
				newItems[i] = items[i];
			}
		delete[] items;
		items = newItems;
	}
	items[numItems++] = newItem;
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

	char user_select;
	cout << "Would you like to add another item? (y/N)" << endl;
	//TODO: Write item entry logic
	fflush(stdin);
	cin >> user_select ;
	switch (user_select){
	case 'y':
	case 'Y':
		AddItem();
		break;
	default:
		break;
	}
	
}

Account::~Account(){
	cout << "Inside Account Destructor" << endl;
	if (numItems > 0) {
		for (unsigned int i = 0; i < numItems; i++){
			delete items[i];
		}
	}
	delete[] items;
	delete ID;
	delete PassWord;
}