#include "Shared.h"
#include "ApplicationMenus.h"
string AccountNumber;
//-----------------------------
//TRANSACTION MODULE
//-----------------------------
void ShowTransactionHistoryModule()
{
	cin.ignore();
	const string accountNumber = AskAndGetInput<string>("Enter Account Number To Deposit");
	Transactions tr;
	tr.FindTransactionHistoryByAccountNumber(accountNumber);
}
void ShowWithDrawModule() 
{
	double amountToWithDraw ;
	switch (ShowWithDrawModuleMenu())
	{
		case 1: 
		{
			amountToWithDraw = 1000;
			break;
		}
		case 2:
		{
			amountToWithDraw = 10000;
			break;
		}
		case 3:
		{
			amountToWithDraw = 25000;
			break;
		}
		case 4:
		{
			amountToWithDraw = 50000;
			break;
		}
		case 5:
		{
			amountToWithDraw = 75000;
			break;
		}
		case 6:
		{
			amountToWithDraw = AskAndGetInput<double>("Enter Amount To WithDraw");
			break;
		}
		default:
			int amountToWithDraw = 0;
			break;
	}
	cin.ignore();

	Transactions checkBalance;
	const auto currentbalace = checkBalance.CheckCurrentBalance(AccountNumber);
	if (currentbalace > 1000)
	{
		Transactions trans;
		trans.set_AccountNumber(AccountNumber);
		trans.set_TransactionId(AskAndGetInput<string>("Enter Transaction Id"));
		trans.set_ETransactionType(ETransactionType::WithDraw);
		trans.set_Amount(AskAndGetInput<double>("Enter Transaction Amount"));
		const double newbalance = currentbalace - (trans.get_Amount());
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
//-----------------------------
//ACCOUNT MODULE
//-----------------------------
void ChangeDebitCardPinModule()
{
	Accounts account;
	auto ToChangeAccountNoDebitPin = AskAndGetInput<string>("Enter Account Number");
	auto NewDebitCardPin = AskAndGetInput<string>("Enter New Debit Card Pin");
	account.ChangeAccountDebitCardPin(ToChangeAccountNoDebitPin,NewDebitCardPin);
}

bool PerformLogin()
{
	Accounts account;
	auto accountNo = AskAndGetInput<string>("Enter Account Number");
	auto debitCardPin= AskAndGetInput<string>("Enter Debit Card Pin");
	auto response = account.PerformATMLogin(accountNo, debitCardPin);

	while (!response)
	{
		cout << "PRESS ENTER FROM YOUR KEYBOARD TO RE-ENTER USER NAME AND PASSWORD" << endl;
		cin.ignore();
		accountNo = AskAndGetInput<string>("Re-Enter Account Number");
		debitCardPin = AskAndGetInput<string>("Re-Enter Debit Card Pin");
		response = account.PerformATMLogin(accountNo, debitCardPin);
	}
	if (response)
		return true;
	else
		return false;
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
				ShowWithDrawModule();
				break;
			}
			case 2:
			{
				ShowTransactionHistoryModule();
				break;
			}
			case 3:
			{
				ChangeDebitCardPinModule();
				break;
			}
			case 4:
			{
				if (AskToExitApplication())
				{
					exit(0);
				}
				else
					StartUp();
				break;
			}
			default:
				throw runtime_error("Invalid Choice. PLEASE CHOOSE FROM ABOVE MAIN MENU");
				break;
		}


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
	CreateLog(ELogType::SuccessFul, "STARTUP TRIGGERED");
	try
	{
		StartMyApp();
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
		CreateLog(ELogType::Failed, ex.what());
		StartUp();
	}
}
//-----------------------------
//APP ENTRY POINT
//-----------------------------

int main()
{
	CreateLog(ELogType::SuccessFul, "======Application Started======");
	if (PerformLogin())
	{
		StartUp();
	}
}