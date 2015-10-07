#include "Item.h"
#include "Account.h"
#include "FleaBay.h"
#include <iostream>
using namespace std;

FleaBay::FleaBay(){
	numAccounts = 0;
	accounts = new ppAccount(); // TODO: FIX THIS MEMORY ALLOCATION
}

bool FleaBay::Login(){
	char user_select;
	char login_buffer[80] = {'\0'};
	char passwd_buffer[80] = {'\0'};

	bool user_check = true;
	bool found = false;

	cout << "1. Add a new Account" << endl;
	cout << "2. Open an existing Account" << endl;
	cout << "3. Return to main menu" << endl;
	fflush(stdin);
	cin >> user_select;

	switch(user_select) {
	case '1': //TODO: Add New Account
		if (!AddNewAccount()){}
		break;
	case '2': //TODO: Account Management
		break;
	case '3': // Return to menu
		break;
	default:
		cout << "Invalid selection. Returning to main menu..." << endl;
		break;
	}

	return true;
}

bool FleaBay::AddNewAccount(){
	Account *newEntry;
	//ppAccount newAccounts;
	char login_buffer[80] = {'\0'};
	char passwd_buffer[80] = {'\0'};
	bool check = true;

	//TODO: ID Prompt
	cout << "Please enter your account ID: " << endl;
	fflush(stdin);
	cin >> login_buffer;
	for (unsigned int i = 0; i < FleaBay::numAccounts; i++){
		if (!strcmp(FleaBay::accounts[i]->ID, login_buffer)){
			cout << "Account already exists" << endl;
			check = false;
			break;
		}
	}

	if (check){
		//TODO: Password Prompt
		cout << "Please enter your password: " << endl;
		fflush(stdin);
		cin >> passwd_buffer;

		newEntry = new Account();

		strcpy_s(newEntry->ID, strlen(login_buffer) + 1, login_buffer);
		strcpy_s(newEntry->ID, strlen(passwd_buffer) + 1, passwd_buffer);

		FleaBay::accounts[numAccounts++] = newEntry;

		return true;
	}

	return true;
}

bool FleaBay::Report(){
	if (numAccounts != 0){
		for (unsigned int i = 0; i < numAccounts; i++){
			cout << "Account ID: " << accounts[i]->ID << endl;
		}
		return true;
	} 
	else {
		cout << "** NO ACCOUNTS **" << endl;
		return true;
	}
}

FleaBay::~FleaBay(){
	delete[] FleaBay::accounts;
}