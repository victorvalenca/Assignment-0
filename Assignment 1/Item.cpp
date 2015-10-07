#include "Item.h"
#include <iostream>
using namespace std;

Item::Item(){
	description = new char[160];
	price = 0.0;
}

void Item::Report(){
	
}

Item::~Item(){
	delete[] description;
}