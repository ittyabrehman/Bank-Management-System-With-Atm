#include "Shared.h"
#include "ApplicationMenus.h"

void RegisterNewBankAccount() 
{

}
void DeleteBankAccount() 
{

}
void FindBankAccount() 
{

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