#include "Item.h"
#include "Account.h"
#include "FleaBay.h"
#include <iostream>
using namespace std;

int main(void)
{
	bool bRunning = true;
	char response;
	FleaBay e;

	while(bRunning)
	{
		cout<<"\nPlease enter your choice"<<endl;
		cout<<"1. FleaBay Login"<<endl;
		cout<<"2. FleaBay Report"<<endl;
		cout<<"3. Quit"<<endl;

		cin>>response;
		switch(response)
		{
		case '1':
			if(!e.Login())
				return 1;
			break;
		case '2':
			if(!e.Report())
				return 1;
			break;
		case '3':
			bRunning=false;
			break;
		default:
			cout<<"invalid choice";
		}
	}
	return 0;
}
