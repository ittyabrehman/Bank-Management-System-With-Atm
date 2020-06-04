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


