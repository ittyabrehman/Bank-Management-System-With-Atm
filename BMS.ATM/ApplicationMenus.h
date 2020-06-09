#pragma once
#include "Shared.h"
int ShowMainMenu() 
{
	CreateLog(ELogType::SuccessFul, "LOADING MAIN MENU");
	system("cls");
	cout << "\t ****AUTOMATIC TRANSACTION MACHINE****" << endl;
	BuilApplicationHeader("MAIN MODULES");
	cout << "1.WITHDRAW MODULE" << endl;
	cout << "2.TRANSACTIONS HISTORY MODULE" << endl;
	cout << "3.CHANGE DEBIT CARD PIN" << endl;
	cout << "4.EXIT APPLICATION" << endl;
	CreateLog(ELogType::SuccessFul, "MAIN MENU LOADED COMPLETELY");
	int key; cin >> key;
	return key;
}
int ShowWithDrawModuleMenu() 
{
	CreateLog(ELogType::SuccessFul, "LOADING WITH-DRAW MODULE");
	system("cls");	
	BuilApplicationHeader("WITH-DRAW MODULE");
	cout << "1.WITH-DRAW 1,000"  << endl;
	cout << "2.WITH-DRAW 10,000" << endl;
	cout << "3.WITH-DRAW 25,000" << endl;
	cout << "4.WITH-DRAW 50,000" << endl;
	cout << "5.WITH-DRAW 75,000" << endl;	
	CreateLog(ELogType::SuccessFul, "WITH-DRAW MODULE MENU LOADED COMPLETELY");
	int key; cin >> key;
	return key;
}