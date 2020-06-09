#pragma once
/// <summary>
/// BASE CLASS
/// </summary>
#include "Shared.h"
class Person
{
	string Name;
	string FatherName;
	string ContactNumber;
	string Address;
	string CNIC;
public:
	void set_CNIC(string  CNIC_inp)
	{
		CNIC = CNIC_inp;
	}
	string  get_CNIC() const
	{
		return CNIC;
	}
	void set_Address(string Address_inp)
	{
		Address = Address_inp;
	}
	string get_Address() const
	{
		return Address;
	}
	void set_ContactNumber(string ContactNumber_inp)
	{
		ContactNumber = ContactNumber_inp;
	}
	string get_ContactNumber() const
	{
		return ContactNumber;
	}
	void set_FatherName(string FatherName_inp)
	{
		FatherName = FatherName_inp;
	}
	string get_FatherName() const
	{
		return FatherName;
	}
	void set_Name(string Name_inp)
	{
		Name = Name_inp;
	}
	string get_Name() const
	{
		return Name;
	}
	virtual void Display() = 0;
	Person()
	{
		Name = FatherName = ContactNumber = Address = CNIC = "";
	}
};