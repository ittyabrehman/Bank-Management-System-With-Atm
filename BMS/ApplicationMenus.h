#pragma once
#include "Shared.h"
int ShowMainMenu()
{
	system("cls");
	cout << "\t ****BANK MANAGEMENT SYSTEM ****" << endl;
	BuilApplicationHeader("MAIN MENU");
	cout << "1.NEW BANK ACCOUNT" << endl;
	cout << "2.DEPOSIT AMOUNT" << endl;
	cout << "3.TRANSACTION HISTORY" << endl;
	cout << "4.USER MANAGEMENT" << endl;
	int key; cin >> key;
	return key;
}
int ShowNewBankAccountMenu()
{
	system("cls");
	BuilApplicationHeader("ACCOUNT MANAGEMENT MODULE");
	cout << "1.REGISTER NEW ACCOUNT" << endl;
	cout << "2.DELETE ACCOUNT" << endl;
	cout << "3.FIND ACCOUNT" << endl;
	cout << "4.UPDATE ACCOUNT" << endl;
	int key; cin >> key;
	return key;
}
int ShowUserManagementMenu()
{
	cout << "1.REGISTER NEW USER" << endl;
	cout << "2.DELETE USER" << endl;
	cout << "3.DEACTIVATE USER" << endl;
	cout << "4.UPDATE USER" << endl;
	cout << "5.FIND USER" << endl;
	int key; cin >> key;
	return key;
}
