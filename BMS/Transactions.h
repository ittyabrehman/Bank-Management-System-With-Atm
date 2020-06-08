#pragma once
#include "Abstracts.h"
class Transactions :public Accounts
{
	string TransactionType;
	double Amount;
	double Balance;
	string TransactionDate;
public:
	void set_TransactionDate(string TransactionDate_inp)
	{
		TransactionDate = TransactionDate_inp;
	}
	string get_TransactionDate() const
	{
		return TransactionDate;
	}
	void set_Balance(double Balance_inp)
	{
		Balance = Balance_inp;
	}
	double get_Balance() const
	{
		return Balance;
	}
	void set_Amount(double Amount_inp)
	{
		Amount = Amount_inp;
	}
	double get_Amount() const
	{
		return Amount;
	}
	void set_TransactionType(string TransactionType_inp)
	{
		TransactionType = TransactionType_inp;
	}
	string get_TransactionType() const
	{
		return TransactionType;
	}
	virtual void Display() override
	{

	}
	void write()
	{

	}
	Transactions()
	{
		TransactionType = TransactionDate = "";
		Amount = Balance = 0;
	}
};