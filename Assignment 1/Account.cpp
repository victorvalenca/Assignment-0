#include "Item.h"
#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(){
	numItems = 0;
	ID = nullptr;
	PassWord = nullptr;
	items = new pItem[0];
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

	ppItem newItems = new pItem[numItems];
	//copy(items[0], items[numItems], newItems[0]);
	for (unsigned int i = 0; i < numItems; i++) {
			newItems[i] = items[i];
		}
	items = newItems;
	items[numItems] = newItem;
	numItems++;
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
	if (!numItems) {
		for (unsigned int i = 0; i < numItems; i++){
			delete[] items[i];
		}
	}
	delete items;
	delete ID;
	delete PassWord;
}