#include "Item.h"
#include <iostream>
using namespace std;

Item::Item(){
	description = nullptr;
	price = 0.0;
}

void Item::Report(){
	cout << description;
	cout << " , Cost: $" << price << endl;
}

Item::~Item(){
	delete description;
}