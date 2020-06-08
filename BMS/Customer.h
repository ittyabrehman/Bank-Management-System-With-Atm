#pragma once
#include "Abstracts.h"
class Customer : public Person
{
	string BusinessName;
	double MonthlyIncome;
	double yearlyIncome;
	string DateOfBussinessEstablishing;
public:
	void set_DateOfBussinessEstablishing(string DateOfBussinessEstablishing_inp)
	{
		DateOfBussinessEstablishing = DateOfBussinessEstablishing_inp;
	}
	string get_DateOfBussinessEstablishing() const
	{
		return DateOfBussinessEstablishing;
	}
	void set_yearlyIncome(double yearlyIncome_inp)
	{
		yearlyIncome = yearlyIncome_inp;
	}
	double get_yearlyIncome() const
	{
		return yearlyIncome;
	}
	void set_MonthlyIncome(double MonthlyIncome_inp)
	{
		MonthlyIncome = MonthlyIncome_inp;
	}
	double get_MonthlyIncome() const
	{
		return MonthlyIncome;
	}
	void set_BusinessName(string BusinessName_inp)
	{
		BusinessName = BusinessName_inp;
	}
	string get_BusinessName() const
	{
		return BusinessName;
	}
	Customer()
	{
		BusinessName = DateOfBussinessEstablishing = "";
		MonthlyIncome = yearlyIncome = 0;
	}

};