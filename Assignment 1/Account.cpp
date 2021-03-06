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

	if (numItems){
		cout << "These are your items for sale:" << endl;
		Report();
	} else{
		cout << "No items in your account." << endl;
	}
	char user_select;
	cout << "Would you like to add another item? (y/N)" << endl;

	fflush(stdin);
	cin >> user_select;
	if (toupper(user_select) == 'Y'){
		char desc_buffer[100] = {'\0'};
		double price_buffer;
		cout << "Enter the new Item description: ";
		fflush(stdin);
		cin.getline(desc_buffer, 100);

		// Set up condition checks
		bool price_ok = false;
		bool cancelled = false;
		
		// Will continue to run until user gives up or enters a proper value for price
		while (!price_ok || cancelled){
			cout << "\nEnter the Item Price (or -1.0 to cancel): ";
			fflush(stdin);
			cin >> price_buffer;

			if (!cin.good()){
				cin.clear();
				cin.ignore(128,'\n');
				cout << endl << "Incorrect value. Try again with a proper number";
				continue;
			}
			
			if (price_buffer == -1.0){
				cancelled = true;
				break; // Break out of loop and cancel
			}

			price_ok = true;

		}

		if (cancelled){
			return; //Check if user cancelled item entry and exit if so
		} 

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

}

void Account::Report(){
	for (unsigned int i = 0; i < numItems; i++){
		cout << " Item " << i+1 << ":\t";
		items[i]->Report();
	}
}

Account::~Account(){
	if (numItems > 0) {
		for (unsigned int i = 0; i < numItems; i++){
			delete items[i];
		}
	}
	delete[] items;
	delete ID;
	delete PassWord;
}