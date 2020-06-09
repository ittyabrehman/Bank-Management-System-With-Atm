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
	acount.set_DebitCardNumber(AskAndGetInput<string>("Enter Your Debit Card Number"));
	acount.set_DebitCardPin(AskAndGetInput<string>("Enter Your Debit Card Pin (4-Digits)"));
	acount.set_BusinessName(AskAndGetInput<string>("Enter Your Bussiness Name"));
	acount.set_MonthlyIncome(AskAndGetInput<double>("Enter Your Monthly Income"));
	acount.set_yearlyIncome(AskAndGetInput<double>("Enter Your Yearly Income"));
	acount.set_Status("A");
	auto dateOfReg = AskAndGetInput<string>("Enter Your Date of Registration");
	acount.set_DateofRegistration(dateOfReg);
	acount.CreateNewBankAccount();
	//initial transaction
	cout << "\n Enter Initial Transaction Details\n" << endl;
	cin.ignore();
	Transactions trans;
	trans.set_AccountNumber(acount.get_AccountNumber());
	trans.set_TransactionId("01");
	trans.set_ETransactionType(ETransactionType::Deposit);
	auto transInp = AskAndGetInput<double>("Enter Transaction Amount");
	while (!(transInp>1000))
	{
		transInp = AskAndGetInput<double>("Inital Amount Should be greater then 1,000. RE-Enter Transaction Amount");
	}
	trans.set_Amount(transInp);
	trans.set_Balance(transInp);
	cin.ignore();
	trans.set_TransactionDate(dateOfReg);
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
void ChangeAccountActitityStatus(EUserActivityType type) 
{
	cin.ignore();
	auto AccountToChangeStatus = AskAndGetInput<string>("Enter Account Number to Change Activity Status");
	Accounts account;
	switch (type)
	{
		case EUserActivityType::Active:
			account.ChangeAccountActivityStatus(AccountToChangeStatus,EUserActivityType::Active);
			break;
		case EUserActivityType::Deactive:
			account.ChangeAccountActivityStatus(AccountToChangeStatus, EUserActivityType::Deactive);
			break;
	default:
		throw runtime_error("ERROR INVALID");
		break;
	}
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
		trans.set_ETransactionType(ETransactionType::WithDraw);
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
		trans.set_ETransactionType(ETransactionType::Deposit);
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
	cin.ignore();
	User user;
	user.set_Name(AskAndGetInput<string>("Enter your Name"));
	user.set_FatherName(AskAndGetInput<string>("Enter your Father Name"));
	user.set_UserId(AskAndGetInput<string>("Enter User Id"));
	user.set_UserName(AskAndGetInput<string>("Enter User Name"));
	user.set_Email(AskAndGetInput<string>("Enter Email"));
	user.set_Password(AskAndGetInput<string>("Enter Password"));
	user.set_IsActive("A");
	user.CreateNewUserAccount();
}
void DeleteUserAccount()
{
	cin.ignore();
	User user;
	user.DeleteUserAccount(AskAndGetInput<string>("Enter User Id To Delete"));
}
void FindUserAccount()
{
	cin.ignore();
	User user;
	user.FindUserAccount(AskAndGetInput<string>("Enter User Id To Find"));
}
void UpdateUserAccount()
{
	cin.ignore();
	auto UserToFind = AskAndGetInput<string>("Enter User Id To Find");
	cout << "\nEnter Updated Record" << endl;
	User UpdatedRecord;
	UpdatedRecord.set_UserId(UserToFind);
	UpdatedRecord.set_Name(AskAndGetInput<string>("Enter your Name"));
	UpdatedRecord.set_FatherName(AskAndGetInput<string>("Enter your Father Name"));
	UpdatedRecord.set_UserName(AskAndGetInput<string>("Enter User Name"));
	UpdatedRecord.set_Email(AskAndGetInput<string>("Enter Email"));
	UpdatedRecord.set_Password(AskAndGetInput<string>("Enter Password"));
	UpdatedRecord.set_IsActive("A");
	User user;
	user.UpdateUserAccount(UserToFind,UpdatedRecord);
}
void DeactivateUserAccount()
{
	cin.ignore();
	auto UserToFind = AskAndGetInput<string>("Enter User Id To Deactivate User");
	User user;
	user.ChangeUserActivityStatus(UserToFind,EUserActivityType::Deactive);
}
void ReactivateUserAccount()
{
	cin.ignore();
	auto UserToFind = AskAndGetInput<string>("Enter User Id To Re-Activate User");
	User user;
	user.ChangeUserActivityStatus(UserToFind, EUserActivityType::Active);
}
//-----------------------------
//LOGIN MODULE
//-----------------------------
bool PerformLogin() 
{
	User user; 
	auto username = AskAndGetInput<string>("Enter UserName");
	auto password = AskAndGetInput<string>("Enter Password");
	auto response = user.PerformLogin(username, password);

	while (!response)//false = login successfull
	{
		 cout << "PRESS ENTER FROM YOUR KEYBOARD TO RE-ENTER USER NAME AND PASSWORD" << endl;
		 cin.ignore();
		 username = AskAndGetInput<string>("Re-Enter UserName");
		 password = AskAndGetInput<string>("Re-Enter Password");
		 response = user.PerformLogin(username, password);
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
				do 
				{
					switch (ShowNewBankAccountMenu())
					{
						case 1:
						{
							CreateLog(ELogType::SuccessFul, "CASE 1 REGISTER BANK IS SELECTED");
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
						case 5:
						{
							ChangeAccountActitityStatus(EUserActivityType::Active);
							break;
						}
						case 6:
						{
							ChangeAccountActitityStatus(EUserActivityType::Deactive);
							break;
						}
						default:
							throw runtime_error("ERROR PLEASE SELECT FROM ABOVE BANK MODULE LIST");
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
						throw runtime_error("ERROR PLEASE SELECT FROM ABOVE TRANSACTIONS LIST");
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
						case 6:
						{
							DeactivateUserAccount();
							break;
						}
						case 7:
						{
							ReactivateUserAccount();
							break;
						}
						default:
							throw runtime_error("ERROR PLEASE SELECT FROM ABOVE USER MANAGEMENT MODULE LIST");
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
			{
				throw runtime_error("Invalid Choice");
				StartUp();
				break; 
			}
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
	CreateLog(ELogType::SuccessFul,"======Application Started======");
	if (PerformLogin()) 
	{
		StartUp();
	}	
}