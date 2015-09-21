/******************************************************************************
Filename:			ass0.c
Version:			1.0
Author:				Victor Fernandes
Student No.:		040772243
Course Name/Number:	CST8219 - C++ Programming / CST8233 - Numerical Computing
Lab Section:		302
Assignment #:		0
Assignment Name:	FleaBay
Due Date:			September 23, 2015
Submission Date:	
Professor:			Andrew Tyler
Purpose:			An Online Sales Management System (OSMS) that uses
					dynamic memory allocation for its data. It lets the user
					register with an ID and password, print a list of
					registered users, and quits the application releasing all
					dynamically allocated memory.
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {FALSE=0,TRUE}BOOL; 

typedef struct
{
	char* ID;
	char* PassWord;
}Account, *pAccount, **ppAccount;

typedef struct
{
	unsigned int numAccounts;
	ppAccount accounts;
}FleaBay,*pFleaBay;

void FleaBayInit(pFleaBay);				/* Initialise the FleaBay instance */
int FleaBayLogin(pFleaBay);				/* login to the FleaBay */
int FleaBayReport(pFleaBay);			/* Print all the Accounts */
void FleaBayCleanUp(pFleaBay);			/* Free all dynamically allocated memory */
void AddNewAccount(pFleaBay);			/* Add a new Account to the FleaBay */

int main(void)
{
	BOOL bRunning = TRUE;
	char i_response;
	FleaBay e;

	FleaBayInit(&e);

 	while(bRunning)
	{
		printf("\nPlease enter your choice\n");
		printf("1. FleaBay Login\n");
		printf("2. FleaBay Report\n");
		printf("3. Quit\n");
		fflush(stdin);
		scanf("%c",&i_response);
		switch(i_response)
		{
		case '1':
			if(!FleaBayLogin(&e))
				return 1;
			break;
		case '2':
			if(!FleaBayReport(&e))
				return 1;
			break;
		case '3':
			FleaBayCleanUp(&e);
			bRunning=FALSE;
			break;
		}
	}
	return 0;
}
/******************************************************************************
Function Name:		FleaBayInit
Purpose:			To instantiate the main FleaBay database
In Parameters:		pFleaBay
Out Parameters:		none
Version:			1.0
Author:				Victor Fernandes
******************************************************************************/
void FleaBayInit(pFleaBay e) {
	e->numAccounts = 0;
	e->accounts = NULL;
}

/******************************************************************************
Function Name:		AddNewAccount
Purpose:			Prompt user and add a new account to the FleaBay database
In Parameters:		pFleaBay
Out Parameters:		none
Version:			1.0
Author:				Victor Fernandes
******************************************************************************/
void AddNewAccount(pFleaBay e) {
	Account *newEntry;
	ppAccount newAccounts;
	char login_buffer[80] = {'\0'}; 
	char passwd_buffer[80] = {'\0'};
	unsigned int i; // Loop iterator
	BOOL check = TRUE;

	// ID prompt
	printf("\nPlease enter your account ID: ");
	fflush(stdin);
	fgets(login_buffer, 80, stdin);

	// Check if account already exists
	for(i = 0; i < e->numAccounts; i++) {
		if(!strcmp(e->accounts[i]->ID,login_buffer)) {
			printf("\nAccount already exists");
			check = FALSE;
			break;
		}
	}
	if (check) {
		// Password prompt
		printf("\nPlease enter your password: ");
		fflush(stdin);
		fgets(passwd_buffer, 80, stdin);

		//Create new account, then populate ID and password fields
		newEntry = (Account *) malloc(sizeof(Account));
		newEntry->ID = (char *)malloc((strlen(login_buffer)+1)*sizeof(char));
		newEntry->PassWord = (char *)malloc((strlen(passwd_buffer)+1)*sizeof(char));

		strcpy(newEntry->ID, login_buffer);
		strcpy(newEntry->PassWord, passwd_buffer);

		// Clone array into a newer and bigger array
		newAccounts = (ppAccount)malloc((sizeof(ppAccount))*(e->numAccounts+1));
		memcpy(newAccounts, e->accounts, (sizeof(ppAccount)*e->numAccounts));

		//Release old memory and assign the new array
		free(e->accounts);
		e->accounts = newAccounts;
		e->accounts[e->numAccounts++] = newEntry;
	}
}

/******************************************************************************
Function Name:		FleaBayLogin
Purpose:			To authenticate and give user access to their account
In Parameters:		pFleaBay
Out Parameters:		Exit status code (int)
Version:			1.0
Author:				Victor Fernandes
******************************************************************************/
int FleaBayLogin(pFleaBay e) {
	char user_select;
	char login_buffer[80] = {'\0'};
	char passwd_buffer[80] = {'\0'};
	unsigned int i;
	BOOL user_check = TRUE;
	BOOL found = FALSE;
	
	printf("\nPlease enter your choice\n");
	printf("1. Add a new Account\n");
	printf("2. Open an existing Account\n");
	printf("3. Return to Main Menu\n");
	fflush(stdin);
	user_select = getchar();

	switch(user_select) {
	case '1':					/** ADD A NEW ACCOUNT **/
		AddNewAccount(e);
		break;
	case '2':					/** OPEN EXISTING ACCOUNT **/
		// Username validation check
		if (e->numAccounts == 0){
			printf("\nThere are no accounts.");
			break;
		}

		printf("Please enter your account ID: ");
		fflush(stdin);
		fgets(login_buffer, 80, stdin);

		/* Search the specified account ID. If the ID is not found, 
		   the password prompt is not run and proper message is displayed. */
		for (i = 0; i < e->numAccounts && !found;) {
			if (strcmp(e->accounts[i]->ID, login_buffer) != 0) {
				if (i == e->numAccounts) { 
				} else {
					i++;
				}
			} else {
				found = TRUE;
			}
		}
		// Password prompt. (Given that ID check was successful)
		if (found) {
			printf("Please enter your password: ");
			fflush(stdin);
			fgets(passwd_buffer, 80, stdin);
			if (!strcmp(e->accounts[i]->PassWord, passwd_buffer)) {
				printf("Account is valid.\n");
				break;

			} else {
				printf("Password doesn't match this ID:");
				break;
			}
		} else {
			printf("%s is Invalid ID", login_buffer);
		}
		break;
	case '3':					/** RETURN TO PREVIOUS MENU **/
		break;
	}
	return 1;
}

/******************************************************************************
Function Name:		FleaBayReport
Purpose:			To display all accounts stored in the database
In Parameters:		pFleaBay
Out Parameters:		Exit status code (int)
Version:			1.0
Author:				Victor Fernandes
******************************************************************************/
int FleaBayReport(pFleaBay e) {
	unsigned int i;

	if (e->numAccounts != 0) {
		for (i = 0; i < e->numAccounts; i++) {
			printf("Account ID: %s\n", e->accounts[i]->ID);
		}
		return TRUE;
	}
	else {
		printf("**NO ACCOUNTS**");
		return TRUE;
	}
}

/******************************************************************************
Function Name:		FleaBayCleanup
Purpose:			To release all dynamically allocated memory
In Parameters:		pFleaBay
Out Parameters:		none
Version:			1.0
Author:				Victor Fernandes
******************************************************************************/
void FleaBayCleanUp(pFleaBay e) {
	unsigned int i; 
	for (i = 0; i < e->numAccounts; i++) {
		free(e->accounts[i]->ID);
		free(e->accounts[i]->PassWord);
		free(e->accounts[i]);
	}
	free(e->accounts);
}
