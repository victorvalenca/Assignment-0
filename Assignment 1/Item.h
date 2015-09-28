typedef struct Item
{
	char* description;
	double price;
	Item();
	~Item();
	void Report();
}*pItem,**ppItem;