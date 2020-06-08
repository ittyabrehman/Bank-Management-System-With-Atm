#pragma once
#include "Abstracts.h"
class User : public Person
{
	string UserName;
	string Password;
	string Email;
public:
	void set_Email(string Email_inp)
	{
		Email = Email_inp;
	}
	string get_Email() const
	{
		return Email;
	}
	void set_Password(string Password_inp)
	{
		Password = Password_inp;
	}
	string get_Password() const
	{
		return Password;
	}
	void set_UserName(string UserName_inp)
	{
		UserName = UserName_inp;
	}
	string get_UserName() const
	{
		return UserName;
	}
	virtual void Display() override
	{

	}
	void write()
	{

	}
	void PerformLogin()
	{

	}
	User()
	{
		UserName = Password = Email = "";
	}

};