#include "Abstracts.h"

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
	cin.ignore();
	Accounts ac;
	ac.DeleteBankAccount(AskAndGetInput<string>("Enter Account No To Delete"));
}
void FindBankAccount() 
{
	cin.ignore();
	Accounts ac;
	ac.FindBankAccount(AskAndGetInput<string>("Enter Account No To Find"));
}
void UpdateBankAccount() 
{
	cin.ignore();
	auto ToFind = AskAndGetInput<string>("Enter Your Account No To Find");
	Accounts UpdatedRecord;
	UpdatedRecord.FindBankAccount(ToFind);
	cout << "\n\nPlease Enter New Details For Your Account\n\n";
	UpdatedRecord.set_Name(AskAndGetInput<string>("Enter Your Name"));
	UpdatedRecord.set_FatherName(AskAndGetInput<string>("Enter Your Father Name"));
	UpdatedRecord.set_ContactNumber(AskAndGetInput<string>("Enter Your Contact Number"));
	UpdatedRecord.set_CNIC(AskAndGetInput<string>("Enter Your CNIC"));
	UpdatedRecord.set_Address(AskAndGetInput<string>("Enter Your Address"));
	UpdatedRecord.set_AccountNumber(AskAndGetInput<string>("Enter Your Account Number"));
	UpdatedRecord.set_AccountTitle(AskAndGetInput<string>("Enter Your Account Title"));
	UpdatedRecord.set_AtmCardNumber(AskAndGetInput<string>("Enter Your Atm Card Number"));
	UpdatedRecord.set_DateofRegistration(AskAndGetInput<string>("Enter Your Date of Registration"));
	UpdatedRecord.set_DebitCardNumber(AskAndGetInput<string>("Enter Your Debit Card Number"));
	UpdatedRecord.set_BusinessName(AskAndGetInput<string>("Enter Your Bussiness Name"));
	UpdatedRecord.set_MonthlyIncome(AskAndGetInput<double>("Enter Your Monthly Income"));
	UpdatedRecord.set_yearlyIncome(AskAndGetInput<double>("Enter Your Yearly Income"));
	UpdatedRecord.set_Status("A");

	Accounts acnt;
	acnt.UpdateBankAccount(ToFind, UpdatedRecord);
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