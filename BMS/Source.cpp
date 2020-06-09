#include "Abstracts.h"
//-----------------------------
//ACCOUNT MODULE
//-----------------------------
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
	acount.set_Status("Active");
	acount.CreateNewBankAccount();
	//intial transaction
	cout << "\n" << endl;
	cin.ignore();
	Transactions trans;
	trans.set_AccountNumber(acount.get_AccountNumber());
	trans.set_TransactionId("01");
	trans.set_TransactionType(TransactionType::Deposit);
	auto transInp = AskAndGetInput<double>("Enter Transaction Amount");
	while (!(transInp>1000))
	{
		transInp = AskAndGetInput<double>("Inital Amount Should be greater then 1,000. RE-Enter Transaction Amount");
	}
	trans.set_Amount(transInp);
	trans.set_Balance(transInp);
	cin.ignore();
	trans.set_TransactionDate(AskAndGetInput<string>("Enter Transaction Date"));
	trans.CreateNewTransction();

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
	UpdatedRecord.set_Status("Active");

	Accounts acnt;
	acnt.UpdateBankAccount(ToFind, UpdatedRecord);
}
//-----------------------------
//TRANSACTION MODULE
//-----------------------------
void WithDrawTransactionAmount() 
{
	cin.ignore();
	string accountNumber = AskAndGetInput<string>("Enter Account Number To WithDraw");
	Transactions checkBalance;
	auto currentbalace = checkBalance.CheckCurrentBalance(accountNumber);
	if (currentbalace > 1000)
	{
		Transactions trans;
		trans.set_AccountNumber(accountNumber);
		trans.set_TransactionId(AskAndGetInput<string>("Enter Transaction Id"));
		trans.set_TransactionType(TransactionType::WithDraw);
		trans.set_Amount(AskAndGetInput<double>("Enter Transaction Amount"));
		double newbalance = currentbalace - (trans.get_Amount());
		trans.set_Balance(newbalance);
		cin.ignore();
		trans.set_TransactionDate(AskAndGetInput<string>("Enter Transaction Date"));
		trans.CreateNewTransction();
	}
	else 
	{
		cout << "Current Balance is Less Then 1,000" << endl;
	}
	
}
void DepositTransactionAmount() 
{
	cin.ignore();
	string accountNumber = AskAndGetInput<string>("Enter Account Number To Deposit");
	Transactions checkBalance;
	auto currentbalace = checkBalance.CheckCurrentBalance(accountNumber);
	if (currentbalace!=0)
	{
		Transactions trans;
		trans.set_AccountNumber(accountNumber);
		trans.set_TransactionId(AskAndGetInput<string>("Enter Transaction Id"));
		trans.set_TransactionType(TransactionType::Deposit);
		trans.set_Amount(AskAndGetInput<double>("Enter Transaction Amount"));
		double newbalance = currentbalace + (trans.get_Amount());
		trans.set_Balance(newbalance);
		cin.ignore();
		trans.set_TransactionDate(AskAndGetInput<string>("Enter Transaction Date"));
		trans.CreateNewTransction();
	}
	else 
	{
		cout << "Invalid Accout Number" << endl;
	}
	
}
void TransactionHistory() 
{
	cin.ignore();
	string accountNumber = AskAndGetInput<string>("Enter Account Number To Deposit");
	Transactions tr;
	tr.FindTransactionHistoryByAccountNumber(accountNumber);
}
//-----------------------------
//USER MODULE
//-----------------------------
void RegisterUserAccount() 
{

}
void DeleteUserAccount()
{

}
void FindUserAccount()
{

}
void UpdateUserAccount()
{

}
void DeactivateUserAccount()
{

}
//-----------------------------
//CODE DRIVER
//-----------------------------
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
							StartUp();
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
				do
				{
					switch (ShowTranscationsModule())
					{
						case 1:
						{
							WithDrawTransactionAmount();
							break;
						}
						case 2:
						{
							DepositTransactionAmount();
							break;
						}
						case 3:
						{
							TransactionHistory();
							break;
						}					
					default:
						throw runtime_error("ERROR PLEASE SELECT FROM ABOVE LIST");
						StartUp();
						break;
					}
					SelectedCommand = AskToGoBack();
				} while (!SelectedCommand);
				{
					StartUp();
				}
				break;
			}
			case 3:
			{
				do
			    {
					switch (ShowUserManagementMenu())
					{
						case 1:
						{
							RegisterUserAccount();
							break;
						}
						case 2:
						{
							DeleteUserAccount();
							break;
						}
						case 3:
						{
							DeactivateUserAccount();
							break;
						}
						case 4:
						{
							UpdateUserAccount();
							break;
						}
						case 5:
						{
							FindUserAccount();
							break;
						}
						default:
							throw runtime_error("ERROR PLEASE SELECT FROM ABOVE LIST");
							StartUp();
							break;
					}
				  SelectedCommand = AskToGoBack();
			    }
		    while (!SelectedCommand);
			{
				StartUp();
			}
				break;
			}			
			default:
				throw runtime_error("Invalid Choice");				
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
//-----------------------------
//EXCEPTION HANDLER REGISTRATION
//-----------------------------
void StartUp() 
{
	try
	{
		StartMyApp();
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
		StartUp();
	}
}
//-----------------------------
//APP ENTRY POINT
//-----------------------------
int main()
{
	StartUp();
}