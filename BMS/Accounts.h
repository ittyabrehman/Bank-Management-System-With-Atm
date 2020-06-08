#pragma once
#include "Abstracts.h"
class Accounts :public Customer
{
	string AccountTitle;
	string AccountNumber;
	string DebitCardNumber;
	string AtmCardNumber;
	string Status;
	string DateofRegistration;
public:
	void set_DateofRegistration(string DateofRegistration_inp)
	{
		DateofRegistration = DateofRegistration_inp;
	}
	string get_DateofRegistration() const
	{
		return DateofRegistration;
	}
	void set_Status(string Status_inp)
	{
		Status = Status_inp;
	}
	string get_Status() const
	{
		return Status;
	}
	void set_AtmCardNumber(string AtmCardNumber_inp)
	{
		AtmCardNumber = AtmCardNumber_inp;
	}
	string get_AtmCardNumber() const
	{
		return AtmCardNumber;
	}
	void set_DebitCardNumber(string DebitCardNumber_inp)
	{
		DebitCardNumber = DebitCardNumber_inp;
	}
	string get_DebitCardNumber() const
	{
		return DebitCardNumber;
	}
	void set_AccountNumber(string AccountNumber_inp)
	{
		AccountNumber = AccountNumber_inp;
	}
	string get_AccountNumber() const
	{
		return AccountNumber;
	}
	void set_AccountTitle(string AccountTitle_inp)
	{
		AccountTitle = AccountTitle_inp;
	}
	string get_AccountTitle() const
	{
		return AccountTitle;
	}
	virtual void Display() override
	{
		cout << get_Name() << " details" << endl;
	}
	string ModelToString()
	{
		string ModelString = get_Name() + "," + get_FatherName() + "," + get_ContactNumber() +
			"," + get_CNIC() + "," + get_Address() + "," + get_AccountNumber() + "," +
			get_AccountTitle() + "," + get_AtmCardNumber() + "," + get_DateofRegistration() + "," +
			get_DebitCardNumber() + "," + get_BusinessName() + "," + to_string(get_MonthlyIncome()) + "," +
			to_string(get_yearlyIncome()) + "," + get_DateOfBussinessEstablishing() + "," + get_Status() + ",";
		return ModelString;
	}
	void DisplayAllBankAccountData()
	{
		ifstream reader;
		reader.open("Data\\account.dat");
		if (reader.is_open())
		{
			string Data, MyAttribute;
			int Attribute = 0, index = 0;
			while (getline(reader, Data))
			{
				Accounts CurrentAccountLoaded;
				int datalength = Data.length();
				for (int i = 0; i < datalength; i++)
				{
					if (Data[i] != ',')
					{
						MyAttribute.insert(index, 1, Data[i]);
						index++;

					}
					else
					{
						Attribute++;

						if (Attribute == 1)
						{
							CurrentAccountLoaded.set_Name(MyAttribute);
						}
						if (Attribute == 2)
						{
							CurrentAccountLoaded.set_FatherName(MyAttribute);
						}
						if (Attribute == 3)
						{
							CurrentAccountLoaded.set_ContactNumber(MyAttribute);
						}
						if (Attribute == 4)
						{
							CurrentAccountLoaded.set_CNIC(MyAttribute);
						}
						if (Attribute == 5)
						{
							CurrentAccountLoaded.set_Address(MyAttribute);
						}
						if (Attribute == 6)
						{
							CurrentAccountLoaded.set_AccountNumber(MyAttribute);
						}
						if (Attribute == 7)
						{
							CurrentAccountLoaded.set_AccountTitle(MyAttribute);
						}
						if (Attribute == 8)
						{
							CurrentAccountLoaded.set_AtmCardNumber(MyAttribute);
						}
						if (Attribute == 9)
						{
							CurrentAccountLoaded.set_DateofRegistration(MyAttribute);
						}
						if (Attribute == 10)
						{
							CurrentAccountLoaded.set_DebitCardNumber(MyAttribute);
						}
						if (Attribute == 11)
						{
							CurrentAccountLoaded.set_BusinessName(MyAttribute);
						}
						if (Attribute == 12)
						{
							CurrentAccountLoaded.set_MonthlyIncome(stod(MyAttribute));
						}
						if (Attribute == 13)
						{
							CurrentAccountLoaded.set_yearlyIncome(stod(MyAttribute));
						}
						if (Attribute == 14)
						{
							CurrentAccountLoaded.set_DateOfBussinessEstablishing((MyAttribute));
						}
						if (Attribute == 15)
						{
							CurrentAccountLoaded.set_Status((MyAttribute));
						}
						MyAttribute.clear();
						index = 0;
					}

					if (Data[i] == '$')///object completed
					{
						MyAttribute.clear();
						index = 0;

						CurrentAccountLoaded.Display();

						Data.clear();
						Attribute = 0;
					}
				}

			}
		}
	}
	void CreateNewBankAccount()
	{

		if (SaveToFile("Data\\account.dat", ModelToString()))
		{
			cout << "Saved SuccessFully" << endl;
		}
		else
		{
			cout << "Saving Failed" << endl;
		}
	}
	void FindBankAccount(string ToFindParameter)
	{
		bool is_found = false;
		ifstream reader;
		reader.open("Data\\account.dat");
		if (reader.is_open())
		{
			string Data, MyAttribute;
			int Attribute = 0, index = 0;
			while (getline(reader, Data))
			{
				Accounts CurrentAccountLoaded;
				int datalength = Data.length();
				for (int i = 0; i < datalength; i++)
				{
					if (Data[i] != ',')
					{
						MyAttribute.insert(index, 1, Data[i]);
						index++;

					}
					else
					{
						Attribute++;

						if (Attribute == 1)
						{
							CurrentAccountLoaded.set_Name(MyAttribute);
						}
						if (Attribute == 2)
						{
							CurrentAccountLoaded.set_FatherName(MyAttribute);
						}
						if (Attribute == 3)
						{
							CurrentAccountLoaded.set_ContactNumber(MyAttribute);
						}
						if (Attribute == 4)
						{
							CurrentAccountLoaded.set_CNIC(MyAttribute);
						}
						if (Attribute == 5)
						{
							CurrentAccountLoaded.set_Address(MyAttribute);
						}
						if (Attribute == 6)
						{
							CurrentAccountLoaded.set_AccountNumber(MyAttribute);
						}
						if (Attribute == 7)
						{
							CurrentAccountLoaded.set_AccountTitle(MyAttribute);
						}
						if (Attribute == 8)
						{
							CurrentAccountLoaded.set_AtmCardNumber(MyAttribute);
						}
						if (Attribute == 9)
						{
							CurrentAccountLoaded.set_DateofRegistration(MyAttribute);
						}
						if (Attribute == 10)
						{
							CurrentAccountLoaded.set_DebitCardNumber(MyAttribute);
						}
						if (Attribute == 11)
						{
							CurrentAccountLoaded.set_BusinessName(MyAttribute);
						}
						if (Attribute == 12)
						{
							CurrentAccountLoaded.set_MonthlyIncome(stod(MyAttribute));
						}
						if (Attribute == 13)
						{
							CurrentAccountLoaded.set_yearlyIncome(stod(MyAttribute));
						}
						if (Attribute == 14)
						{
							CurrentAccountLoaded.set_DateOfBussinessEstablishing((MyAttribute));
						}
						if (Attribute == 15)
						{
							CurrentAccountLoaded.set_Status((MyAttribute));
						}

					}

					if (Data[i] == '$')///object completed
					{
						MyAttribute.clear();
						index = 0;
						//compare with Parameter
						if (CurrentAccountLoaded.get_AccountNumber() == ToFindParameter)
						{
							is_found = true;
							CurrentAccountLoaded.Display();
						}
						Data.clear();
						Attribute = 0;
					}
				}
			}
			if (!is_found)
			{
				cout << "NO RECORD FOUND" << endl;
			}
		}
	}
	void DeleteBankAccount(string ToFindParameter)
	{
		bool is_found = false;
		ifstream reader("Data\\account.dat");
		if (reader.is_open())
		{
			string Data, MyAttribute;
			int Attribute = 0, index = 0;
			while (getline(reader, Data))
			{
				Accounts CurrentAccountLoaded;
				int datalength = Data.length();
				for (int i = 0; i < datalength; i++)
				{
					if (Data[i] != ',')
					{
						MyAttribute.insert(index, 1, Data[i]);
						index++;

					}
					else
					{
						Attribute++;

						if (Attribute == 1)
						{
							CurrentAccountLoaded.set_Name(MyAttribute);
						}
						if (Attribute == 2)
						{
							CurrentAccountLoaded.set_FatherName(MyAttribute);

						}
						if (Attribute == 3)
						{
							CurrentAccountLoaded.set_ContactNumber(MyAttribute);
						}
						if (Attribute == 4)
						{
							CurrentAccountLoaded.set_CNIC(MyAttribute);
						}
						if (Attribute == 5)
						{
							CurrentAccountLoaded.set_Address(MyAttribute);
						}
						if (Attribute == 6)
						{
							CurrentAccountLoaded.set_AccountNumber(MyAttribute);
						}
						if (Attribute == 7)
						{
							CurrentAccountLoaded.set_AccountTitle(MyAttribute);
						}
						if (Attribute == 8)
						{
							CurrentAccountLoaded.set_AtmCardNumber(MyAttribute);
						}
						if (Attribute == 9)
						{
							CurrentAccountLoaded.set_DateofRegistration(MyAttribute);
						}
						if (Attribute == 10)
						{
							CurrentAccountLoaded.set_DebitCardNumber(MyAttribute);
						}
						if (Attribute == 11)
						{
							CurrentAccountLoaded.set_BusinessName(MyAttribute);
						}
						if (Attribute == 12)
						{
							CurrentAccountLoaded.set_MonthlyIncome(stod(MyAttribute));
						}
						if (Attribute == 13)
						{
							CurrentAccountLoaded.set_yearlyIncome(stod(MyAttribute));
						}
						if (Attribute == 14)
						{
							CurrentAccountLoaded.set_DateOfBussinessEstablishing((MyAttribute));
						}
						if (Attribute == 15)
						{
							CurrentAccountLoaded.set_Status((MyAttribute));
						}
						MyAttribute.clear();
						index = 0;
					}

					if (Data[i] == '$')///object completed
					{
						MyAttribute.clear();
						index = 0;
						//<After finding specific account to delete>
						//<we create a new file temp.bin in which we transfer all record (except which is requested to delete) and then rename this file to account.dat>

						if (CurrentAccountLoaded.get_AccountNumber() == ToFindParameter)
						{
							is_found = true;
						}
						if (!is_found)
						{
							SaveToFile("Data\\temp.dat", CurrentAccountLoaded.ModelToString());
						}
						Data.clear();
						Attribute = 0;
					}
				}
			}
			if (!is_found)
			{
				cout << "NO RECORD FOUND" << endl;
			}
			else
			{
				cout << "DELETED SUCESSFULLY" << endl;
			}
			reader.close();

			auto isRemoved = remove("Data\\account.dat"); //file containing old record
			auto isRenamed = rename("Data\\temp.dat", "Data\\account.dat"); //file containing new record
		}
	}
	void UpdateBankAccount(string ToFindParameter, Accounts UpdatedRecord)
	{
		bool is_found = false;
		ifstream reader("Data\\account.dat");
		if (reader.is_open())
		{
			string Data, MyAttribute;
			int Attribute = 0, index = 0;
			while (getline(reader, Data))//read a line 
			{
				Accounts CurrentAccountLoaded;
				int datalength = Data.length();
				for (int i = 0; i < datalength; i++)
				{
					if (Data[i] != ',')
					{
						MyAttribute.insert(index, 1, Data[i]);
						index++;

					}
					else
					{
						Attribute++;

						if (Attribute == 1)
						{
							CurrentAccountLoaded.set_Name(MyAttribute);
						}
						if (Attribute == 2)
						{
							CurrentAccountLoaded.set_FatherName(MyAttribute);

						}
						if (Attribute == 3)
						{
							CurrentAccountLoaded.set_ContactNumber(MyAttribute);
						}
						if (Attribute == 4)
						{
							CurrentAccountLoaded.set_CNIC(MyAttribute);
						}
						if (Attribute == 5)
						{
							CurrentAccountLoaded.set_Address(MyAttribute);
						}
						if (Attribute == 6)
						{
							CurrentAccountLoaded.set_AccountNumber(MyAttribute);
						}
						if (Attribute == 7)
						{
							CurrentAccountLoaded.set_AccountTitle(MyAttribute);
						}
						if (Attribute == 8)
						{
							CurrentAccountLoaded.set_AtmCardNumber(MyAttribute);
						}
						if (Attribute == 9)
						{
							CurrentAccountLoaded.set_DateofRegistration(MyAttribute);
						}
						if (Attribute == 10)
						{
							CurrentAccountLoaded.set_DebitCardNumber(MyAttribute);
						}
						if (Attribute == 11)
						{
							CurrentAccountLoaded.set_BusinessName(MyAttribute);
						}
						if (Attribute == 12)
						{
							CurrentAccountLoaded.set_MonthlyIncome(stod(MyAttribute));
						}
						if (Attribute == 13)
						{
							CurrentAccountLoaded.set_yearlyIncome(stod(MyAttribute));
						}
						if (Attribute == 14)
						{
							CurrentAccountLoaded.set_DateOfBussinessEstablishing((MyAttribute));
						}
						if (Attribute == 15)
						{
							CurrentAccountLoaded.set_Status((MyAttribute));
						}
						MyAttribute.clear();
						index = 0;
					}

					if (Data[i] == '$')///object completed
					{
						MyAttribute.clear();
						index = 0;
						//<After finding specific account to delete>
						//<we create a new file temp.dat in which we transfer all record and then rename this file to account.dat>

						if (CurrentAccountLoaded.get_AccountNumber() == ToFindParameter)
						{
							is_found = true;
							CurrentAccountLoaded = UpdatedRecord;
						}
						SaveToFile("Data\\temp.dat", CurrentAccountLoaded.ModelToString());
						Data.clear();
						Attribute = 0;
					}
				}
			}
			if (!is_found)
			{
				cout << "NO RECORD FOUND" << endl;
			}
			else
			{
				cout << "DELETED SUCESSFULLY" << endl;
			}
			reader.close();
			auto resul = remove("Data\\account.dat"); //file containing old record
			auto result = rename("Data\\temp.dat", "Data\\account.dat"); //file containing new record
		}
	}
	Accounts()
	{
		AccountTitle = AccountNumber = DebitCardNumber = AtmCardNumber = Status = DateofRegistration = "";
	}
};