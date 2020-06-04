#pragma once
#include <iostream>
#include <string>
using namespace std;
template<typename T>T AskAndGetInput(string questionHeader)
{	
	T userInp;
	cout << questionHeader << endl;
	cin >> userInp;
	return userInp;
}
template<>string AskAndGetInput(string questionHeader)
{
	string userInp;
	cout << questionHeader << endl;
	getline(cin,userInp);
	return userInp;
}
enum AppMenuType
{
	MainMenu = 0, SubMenu = 1, SubMenuChild = 2
};
void BuilApplicationHeader(string headerName, AppMenuType menuType)
{
	int headerWidth = 0;
	char ToPrint = '_';
	switch (menuType)
	{
		case AppMenuType::MainMenu: 
		{
			headerWidth = (50);
			break;
		}
		case AppMenuType::SubMenu:
		{
			headerWidth = 25;
			break;
		}
		case AppMenuType::SubMenuChild:
		{
			headerWidth = 20;
			break;
		}
	 default:
		throw runtime_error("ERROR In Building Application Header Failed");
		break;
	}
	for (int i = 0; i < headerWidth; i++)
	{
		cout << ToPrint;
	}
	cout << "\n";
	cout << "\n";
	switch (menuType)
	{
		case AppMenuType::MainMenu:
		{			
			cout << "\t\t\t";
			break;
		}
		case AppMenuType::SubMenu:
		{			
			cout << "\t";
			break;
		}
		case AppMenuType::SubMenuChild:
		{			
			cout << "   ";
			break;
		}	
		default:
			throw runtime_error("ERROR In Building Application Header Failed");
		break;
	}
	cout << headerName;
	cout << "\n";
	for (int i = 0; i < headerWidth; i++)
	{
		cout << ToPrint;
	}
}

