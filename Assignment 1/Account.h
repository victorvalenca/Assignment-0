typedef class Account
{
public:
	char* ID;
	char* PassWord;
	unsigned int numItems;
	ppItem items;
	Account();
	~Account();
	void AddItem();	
	void Report();	
}*pAccount,**ppAccount;
