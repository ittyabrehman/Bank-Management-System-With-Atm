#include "Shared.h"
#include "ApplicationMenus.h"

class Person //base class
{
	string Name;
	string FatherName;
	string ContactNumber;
	string Address;
	string CNIC;
public:
	void set_CNIC(string  CNIC_inp)
	{
		CNIC = CNIC_inp;
	}
	string  get_CNIC() const
	{
		return CNIC;
	}
	void set_Address(string Address_inp)
	{
		Address = Address_inp;
	}
	string get_Address() const
	{
		return Address;
	}
	void set_ContactNumber(string ContactNumber_inp)
	{
		ContactNumber = ContactNumber_inp;
	}
	string get_ContactNumber() const
	{
		return ContactNumber;
	}
	void set_FatherName(string FatherName_inp)
	{
		FatherName = FatherName_inp;
	}
	string get_FatherName() const
	{
		return FatherName;
	}
	void set_Name(string Name_inp)
	{
		Name = Name_inp;
	}
	string get_Name() const
	{
		return Name;
	}
	virtual void Display() = 0;
	Person()
	{
		Name = FatherName = ContactNumber = Address = CNIC="";
	}
};

class User : public Person 
{
	string UserName;
	string Password;
	string Email;
public:
	void set_Email(string Email_inp)
	{
		Email = Email_inp;
	}
	string get_Email() const
	{
		return Email;
	}
	void set_Password(string Password_inp)
	{
		Password = Password_inp;
	}
	string get_Password() const
	{
		return Password;
	}
	void set_UserName(string UserName_inp)
	{
		UserName = UserName_inp;
	}
	string get_UserName() const
	{
		return UserName;
	}
	virtual void Display() override
	{
		
	}
	void write() 
	{

	}
	void PerformLogin() 
	{

	}
	User()
	{
		UserName = Password = Email = "";
	}
	
};

class Customer : public Person 
{
	string BusinessName;
	double MonthlyIncome;
	double yearlyIncome;
	string DateOfBussinessEstablishing;
public:
	void set_DateOfBussinessEstablishing(string DateOfBussinessEstablishing_inp)
	{
		DateOfBussinessEstablishing = DateOfBussinessEstablishing_inp;
	}
	string get_DateOfBussinessEstablishing() const
	{
		return DateOfBussinessEstablishing;
	}
	void set_yearlyIncome(double yearlyIncome_inp)
	{
		yearlyIncome = yearlyIncome_inp;
	}
	double get_yearlyIncome() const
	{
		return yearlyIncome;
	}
	void set_MonthlyIncome(double MonthlyIncome_inp)
	{
		MonthlyIncome = MonthlyIncome_inp;
	}
	double get_MonthlyIncome() const
	{
		return MonthlyIncome;
	}
	void set_BusinessName(string BusinessName_inp)
	{
		BusinessName = BusinessName_inp;
	}
	string get_BusinessName() const
	{
		return BusinessName;
	}
	Customer()
	{
		BusinessName = DateOfBussinessEstablishing = "";
		MonthlyIncome = yearlyIncome = 0;
	}

};

class Accounts :public Customer
{
	string AccountTitle;
	string AccountNumber;
	string DebitCardNumber;
	string AtmCardNumber;
	string Status;
	string DateofRegistration;
public:
	void set_DateofRegistration(string DateofRegistration_inp)
	{
		DateofRegistration = DateofRegistration_inp;
	}
	string get_DateofRegistration() const
	{
		return DateofRegistration;
	}
	void set_Status(string Status_inp)
	{
		Status = Status_inp;
	}
	string get_Status() const
	{
		return Status;
	}
	void set_AtmCardNumber(string AtmCardNumber_inp)
	{
		AtmCardNumber = AtmCardNumber_inp;
	}
	string get_AtmCardNumber() const
	{
		return AtmCardNumber;
	}
	void set_DebitCardNumber(string DebitCardNumber_inp)
	{
		DebitCardNumber = DebitCardNumber_inp;
	}
	string get_DebitCardNumber() const
	{
		return DebitCardNumber;
	}
	void set_AccountNumber(string AccountNumber_inp)
	{
		AccountNumber = AccountNumber_inp;
	}
	string get_AccountNumber() const
	{
		return AccountNumber;
	}
	void set_AccountTitle(string AccountTitle_inp)
	{
		AccountTitle = AccountTitle_inp;
	}
	string get_AccountTitle() const
	{
		return AccountTitle;
	}
	virtual void Display() override
	{		
		cout << get_Name() << " details" << endl;
	}
	void CreateNewBankAccount()
	{
		string ModelString = get_Name() + "," + get_FatherName() + "," + get_ContactNumber() +
			"," + get_CNIC() + "," + get_Address() + "," + get_AccountNumber() + "," +
			get_AccountTitle() + "," + get_AtmCardNumber() + "," + get_DateofRegistration() + "," +
			get_DebitCardNumber() + "," + get_BusinessName() + "," + to_string(get_MonthlyIncome()) + "," +
			to_string(get_yearlyIncome()) + "," + get_DateOfBussinessEstablishing() + "," + get_Status()+",";
		if (SaveToFile("Data\\account.dat", ModelString)) 
		{
			cout<< "Saved SuccessFully" << endl;
		}
		else 
		{
			cout << "Saving Failed" << endl;
		}
	}

	void ReadBankAccountData() 
	{
		ifstream reader;
		reader.open("Data\\account.dat");
		if (reader.is_open())
		{
			string Data, MyAttribute;
			int Attribute = 0,index=0;
			while (getline(reader,Data))
			{
				Accounts CurrentAccountLoaded;
				for (int i = 0; i < Data.length(); i++)
				{
					if (Data[i] != ',')
					{
						MyAttribute.insert(index, 1, Data[i]);
						index++;
																					
					}
					else
					{
						Attribute++;
						
						if (Attribute == 1)
						{
							CurrentAccountLoaded.set_Name(MyAttribute);
							MyAttribute.clear();
							index = 0;
						}
						if (Attribute == 2)
						{
							CurrentAccountLoaded.set_FatherName(MyAttribute);
							MyAttribute.clear();
							index = 0;
						}
						if (Attribute == 3)
						{
							CurrentAccountLoaded.set_ContactNumber(MyAttribute);
							MyAttribute.clear();
							index = 0;
						}
						if (Attribute == 4)
						{
							CurrentAccountLoaded.set_CNIC(MyAttribute);
							MyAttribute.clear();
							index = 0;
						}
						if (Attribute == 5)
						{
							CurrentAccountLoaded.set_Address(MyAttribute);
							MyAttribute.clear();
							index = 0;
						}
						if (Attribute == 6)
						{
							CurrentAccountLoaded.set_AccountNumber(MyAttribute);
							MyAttribute.clear();
							index = 0;
						}
						if (Attribute == 7)
						{
							CurrentAccountLoaded.set_AccountTitle(MyAttribute);
							MyAttribute.clear();
							index = 0;
						}
						if (Attribute == 8)
						{
							CurrentAccountLoaded.set_AtmCardNumber(MyAttribute);
							MyAttribute.clear();
							index = 0;
						}
						if (Attribute == 9)
						{
							CurrentAccountLoaded.set_DateofRegistration(MyAttribute);
							MyAttribute.clear();
							index = 0;
						}
						if (Attribute == 10)
						{
							CurrentAccountLoaded.set_DebitCardNumber(MyAttribute);
							MyAttribute.clear();
							index = 0;
						}
						if (Attribute == 11)
						{
							CurrentAccountLoaded.set_BusinessName(MyAttribute);
							MyAttribute.clear();
							index = 0;
						}
						if (Attribute == 12)
						{
							CurrentAccountLoaded.set_MonthlyIncome(stod(MyAttribute));
							MyAttribute.clear();
							index = 0;
						}
						if (Attribute == 13)
						{
							CurrentAccountLoaded.set_yearlyIncome(stod(MyAttribute));
							MyAttribute.clear();
							index = 0;
						}
						if (Attribute == 14)
						{
							CurrentAccountLoaded.set_DateOfBussinessEstablishing((MyAttribute));
							MyAttribute.clear();
							index = 0;
						}
						if (Attribute == 15)
						{
							CurrentAccountLoaded.set_Status((MyAttribute));
							MyAttribute.clear();
							index = 0;
						}
						
					}	
					if (Data[i] == '$')///object completed
					{
						//this delete first char in 					
						if (CurrentAccountLoaded.get_Name()[0]=='$')
						{							
							CurrentAccountLoaded.set_Name(CurrentAccountLoaded.get_Name().erase(0, 1));
						}
						CurrentAccountLoaded.Display();
						Data.clear();
						Attribute = 0;
					}
				}				
				
			}
		}
	}

	Accounts()
	{
		AccountTitle = AccountNumber = DebitCardNumber = AtmCardNumber = Status = DateofRegistration = "";
	}
};

class Transactions :public Accounts
{
	string TransactionType;
	double Amount;
	double Balance;
	string TransactionDate;
public:
	void set_TransactionDate(string TransactionDate_inp)
	{
		TransactionDate = TransactionDate_inp;
	}
	string get_TransactionDate() const
	{
		return TransactionDate;
	}
	void set_Balance(double Balance_inp)
	{
		Balance = Balance_inp;
	}
	double get_Balance() const
	{
		return Balance;
	}
	void set_Amount(int Amount_inp)
	{
		Amount = Amount_inp;
	}
	int get_Amount() const
	{
		return Amount;
	}
	void set_TransactionType(string TransactionType_inp)
	{
		TransactionType = TransactionType_inp;
	}
	string get_TransactionType() const
	{
		return TransactionType;
	}
	virtual void Display() override
	{

	}
	void write()
	{

	}
	Transactions()
	{
		TransactionType = TransactionDate = "";
		Amount = Balance = 0;
	}
};

void RegisterNewBankAccount() 
{
	Accounts acount;
	cin.ignore();
	acount.set_Name(AskAndGetInput<string>("Enter Your Name"));
	acount.set_FatherName(AskAndGetInput<string>("Enter Your Father Name"));
	acount.set_ContactNumber(AskAndGetInput<string>("Enter Your Contact Number"));
	acount.set_CNIC(AskAndGetInput<string>("Enter Your CNIC"));
	acount.set_Address(AskAndGetInput<string>("Enter Your Address"));
	acount.set_AccountNumber(AskAndGetInput<string>("Enter Your Account Number"));
	acount.set_AccountTitle(AskAndGetInput<string>("Enter Your Account Title"));
	acount.set_AtmCardNumber(AskAndGetInput<string>("Enter Your Atm Card Number"));
	acount.set_DateofRegistration(AskAndGetInput<string>("Enter Your Date of Registration"));
	acount.set_DebitCardNumber(AskAndGetInput<string>("Enter Your Debit Card Number"));
	acount.set_BusinessName(AskAndGetInput<string>("Enter Your Bussiness Name"));
	acount.set_MonthlyIncome(AskAndGetInput<double>("Enter Your Monthly Income"));
	acount.set_yearlyIncome(AskAndGetInput<double>("Enter Your Yearly Income"));
	acount.set_Status("A");
	acount.CreateNewBankAccount();	
}
void DeleteBankAccount() 
{

}
void FindBankAccount() 
{
	Accounts ac;
	ac.ReadBankAccountData();
}
void UpdateBankAccount() 
{

}
void StartMyApp() 
{
	bool SelectedCommand = true;
	do
	{
		switch (ShowMainMenu())
		{
			case 1:
			{
				do 
				{
					switch (ShowNewBankAccountMenu())
					{
						case 1:
						{
							RegisterNewBankAccount();
							break;
						}
						case 2:
						{
							DeleteBankAccount();
							break;
						}
						case 3:
						{
							FindBankAccount();
							break;
						}
						case 4:
						{
							UpdateBankAccount();
							break;
						}
						default:
							throw runtime_error("ERROR PLEASE SELECT FROM ABOVE LIST");
							break;
					}
					SelectedCommand = AskToGoBack();
				} while (!SelectedCommand);
				{
					StartUp();
				}
				break;
			}
			case 2:
			{
				break;
			}
			case 3:
			{
				break;
			}
			case 4:
			{
				break;
			}
			default:
				StartUp();
				break;
		}
		if (AskToExitApplication())
		{
			exit(0);
		}
		else
			StartUp();
	} while (!SelectedCommand);
	{
		StartUp();
	}
}
void StartUp() 
{
	try
	{
		StartMyApp();
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
}
int main()
{
	StartUp();
}