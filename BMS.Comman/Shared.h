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
template<> string AskAndGetInput(string questionHeader)
{
	string userInp;
	cout << questionHeader << endl;
	getline(cin,userInp);
	return userInp;
}

void BuilApplicationHeader(string headerName)
{
	//<Header Automatic Centerlized>
	int HeaderLength = 0;
	char ToPrint = '_';
	for (int i = 0; i < 10; i++)
	{
		headerName.insert(0, 1, ' ');/// parmaters = (startingPoint, charToInsertLength, charToInsert)
	}
	for (int i = 0; i < 10; i++)
	{
		headerName.insert(headerName.length(), 1, ' ');/// parmaters = (startingPoint, charToInsertLength, charToInsert)
	}

	int headerWidth = headerName.length();
	for (int i = 0; i < headerWidth; i++)
	{
		cout << ToPrint;
	}
	cout << "\n\n";	
	cout << headerName;
	cout << "\n";
	for (int i = 0; i < headerWidth; i++)
	{
		cout << ToPrint;
	}
	cout << "\n\n";
}
bool AskToGoBack()
{
	auto SelectedChoice = AskAndGetInput<char>("DO YOU WANT TO GO BACK? (Y,N)");
	if (SelectedChoice =='Y'|| SelectedChoice == 'y')
	{
		return true;
	}
	return false;
}
bool AskToExitApplication()
{
	auto SelectedChoice = AskAndGetInput<char>("DO YOU WANT TO Exit Application? (Y,N)");
	if (SelectedChoice == 'Y' || SelectedChoice == 'y')
	{
		return true;
	}
	return false;
}
void ChangeApplicationColor() 
{

}
void StartUp();
