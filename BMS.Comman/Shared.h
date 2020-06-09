#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>     // setw()
#include <stdio.h>     //for File remove( ) and rename( )
using namespace std;
//-------------
//ENUMS
//-------------
enum class ELogType { SuccessFul = 0, Failed = 1, Warning = 2};
//-------------
//TEMPLATES
//-------------
template<typename T>T AskAndGetInput(string questionHeader)
{	
	T userInp;
	cout << questionHeader << endl;
	cin >> userInp;
	if (userInp==0)
	{
		throw runtime_error("GOING BACK TO MAIN MENU MODULE");
	}
	return userInp;
}
template<> string AskAndGetInput(string questionHeader)
{
	string userInp;
	cout << questionHeader << endl;
	getline(cin,userInp);
	if (userInp == to_string(0))
	{
		throw runtime_error("GOING BACK TO MAIN MENU MODULE");
	}
	return userInp;
}
//-------------
//BASE FUNCTIONS
//-------------
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
void CreateLog(ELogType type, string Message);
bool AskToExitApplication()
{
	auto SelectedChoice = AskAndGetInput<char>("DO YOU WANT TO Exit Application? (Y,N)");
	if (SelectedChoice == 'Y' || SelectedChoice == 'y')
	{
		CreateLog(ELogType::SuccessFul,"==========APPLICATION CLOSED==========");
		return true;
	}
	return false;
}
bool SaveToFile(string FileName,string DataString) 
{
	ofstream writer;
	writer.open(FileName, ios::app);
	if (writer.is_open()) 
	{
		writer << DataString << "$"<<endl;
		return true;
	}
	else
	{
		return false;
	}
	writer.close();
}
void StartUp();
bool PerformLogin();
//-------------
//LOGGER
//-------------
void CreateLog(ELogType type,string Message) 
{
	ofstream writer;
	writer.open("Logs\\log.txt", ios::app);
	if (writer.is_open())
	{
		string ActionStatus;
		switch (type)
		{
			case ELogType::SuccessFul:
			{
				ActionStatus = "SUCCESSFULL";
				break;
			}				
			case ELogType::Failed:
			{
				ActionStatus = "FAILED";
				break;
			}
			case ELogType::Warning:
			{
				ActionStatus = "WARNING";
				break;
			}
		default:
			throw runtime_error("Invalid Logger Type");
			StartUp();
			break;
		}
		writer <<"\n=> "<<ActionStatus <<": \n"<<"MESSAGE: "<< Message << "\nAction Completed" << endl;
		writer.close();
	}
	else
	{
		throw runtime_error("ERROR IN OPENING LOG FILE");
	}
	
}
