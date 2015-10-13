#include "Item.h"
#include <iostream>
using namespace std;

Item::Item(){
	description = nullptr;
	price = 0.0;
}

void Item::Report(){
	
}

Item::~Item(){
	cout << "Inside Item Destructor" << endl;
	delete description;
}