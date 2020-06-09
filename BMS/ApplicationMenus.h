#pragma once
#include "Shared.h"
int ShowMainMenu()
{
	CreateLog(ELogType::SuccessFul, "LOADING MAIN MENU");
	system("cls");
	cout << "\t ****BANK MANAGEMENT SYSTEM ****" << endl;
	BuilApplicationHeader("MAIN MODULES");
	cout << "1.ACCOUNT MODULE" << endl;
	cout << "2.TRANSACTIONS MODULE" << endl;
	cout << "3.USER MODULE" << endl;
	cout << "4.EXIT APPLICATION" << endl;
	int key; cin >> key;
	CreateLog(ELogType::SuccessFul, "MAIN MENU LOADED COMPLETELY");
	return key;
}
int ShowTranscationsModule() 
{
	CreateLog(ELogType::SuccessFul, "LOADING TRANSACTION MODULE MENU");
	system("cls");
	BuilApplicationHeader("ACCOUNT MANAGEMENT MODULE");
	cout << "1.WITH-DRAW AMOUNT" << endl;
	cout << "2.DEPOSIT AMOUNT" << endl;
	cout << "3.TRANSACTIONS HISTORY" << endl;	
	int key; cin >> key;
	CreateLog(ELogType::SuccessFul, "TRANSACTION MODULE LOADED COMPLETELY");
	return key;
}
int ShowNewBankAccountMenu()
{
	CreateLog(ELogType::SuccessFul, "LOADING NEW BANK ACCOUNT MENU");
	system("cls");
	BuilApplicationHeader("ACCOUNT MANAGEMENT MODULE");
	cout << "1.REGISTER NEW ACCOUNT" << endl;
	cout << "2.DELETE ACCOUNT" << endl;
	cout << "3.FIND ACCOUNT" << endl;
	cout << "4.UPDATE ACCOUNT" << endl;
	cout << "5.RE-ACTIVE ACCOUNT" << endl;
	cout << "6.DEACTIVE ACCOUNT" << endl;
	int key; cin >> key;
	CreateLog(ELogType::SuccessFul, "BANK ACCOUNT MENU LOADED COMPLETELY");
	return key;
}
int ShowUserManagementMenu()
{
	CreateLog(ELogType::SuccessFul, "LOADING USER MANAGEMENT MODULE");
	system("cls");
	BuilApplicationHeader("USER MANAGEMENT MODULE");
	cout << "1.REGISTER NEW USER" << endl;
	cout << "2.DELETE USER" << endl;
	cout << "3.DEACTIVATE USER" << endl;
	cout << "4.UPDATE USER" << endl;
	cout << "5.FIND USER" << endl;
	cout << "6.DEACTIVE USER" << endl;
	cout << "7.REACTIVE USER" << endl;
	CreateLog(ELogType::SuccessFul, "USER MANAGEMENT MODULE LOADED COMPLETELY");
	int key; cin >> key;
	return key;
}
