#include "Shared.h"
#include "ApplicationMenus.h"
//-----------------------------
//TRANSACTION MODULE
//-----------------------------
void ShowTransactionHistoryModule()
{

}
void ShowWithDrawModule() 
{

}
//-----------------------------
//ACCOUNT MODULE
//-----------------------------
void ChangeDebitCardPinModule()
{

}

bool PerformLogin()
{
	return true;
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