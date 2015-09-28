typedef class FleaBay
{
	unsigned int numAccounts;
	ppAccount accounts;
public:
	FleaBay();				
	~FleaBay();
	bool Login();				
	bool AddNewAccount();
	bool Report();				
}* pFleaBay;
