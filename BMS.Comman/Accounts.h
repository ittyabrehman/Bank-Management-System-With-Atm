#pragma once
#include "Shared.h"

class Accounts :public Customer
{
	string AccountTitle;
	string AccountNumber;
	string DebitCardNumber;
	string AtmCardNumber;
	string Status;
	string DateofRegistration;
	string DebitCardPin;
	string IsActive;
public:

	void set_DebitCardPin(string DebitCardPin_inp)
	{
		DebitCardPin = DebitCardPin_inp;
	}
	string get_DebitCardPin() const
	{
		return DebitCardPin;
	}
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
		CreateLog(ELogType::SuccessFul, AccountNumber+" IS REQUESTED TO DISPALY");
		cout << " Name                 :	" << get_Name() << endl;
		cout << " Father Name          :	" << get_FatherName() << endl;
		cout << " Contact Number       :	" << get_ContactNumber() << endl;
		cout << " Address              :	" << get_Address() << endl;
		cout << " CNIC                 :	" << get_CNIC() << endl;
		cout << " Business Name        :	" << get_BusinessName() << endl;
		cout << " Monthly Income       :	" << get_MonthlyIncome() << endl;
		cout << " Yearly Income        :	" << get_yearlyIncome() << endl;		
		cout << " Account Title        :	" << get_AccountTitle() << endl;
		cout << " Account Number       :	" << get_AccountNumber() << endl;
		cout << " DebitCardNumber      :	" << get_DebitCardNumber() << endl;
		cout << " AtmCardNumber        :	" << get_AtmCardNumber() << endl;
		cout << " Status               :	" << get_Status() << endl;
		cout << " Date of Registration :	" << get_DateofRegistration() << endl;
		CreateLog(ELogType::SuccessFul, AccountNumber+" IS SUCCSSFULLY DISPALY ");

	}
	string ModelToString()
	{
		string ModelString = get_Name() + "," + get_FatherName() + "," + get_ContactNumber() +
			"," + get_CNIC() + "," + get_Address() + "," + get_AccountNumber() + "," +
			get_AccountTitle() + "," + get_AtmCardNumber() + "," + get_DateofRegistration() + "," +
			get_DebitCardNumber() + "," + get_DebitCardPin() + "," + get_BusinessName() + "," + to_string(get_MonthlyIncome()) + "," +
			to_string(get_yearlyIncome()) + "," + get_Status() + ","+get_DateofRegistration()+",";

		CreateLog(ELogType::SuccessFul, "ACCOUNT MODEL TO STRING IS REQUESTED & CREATED SUCCESSFULLY");
		return ModelString;
	}
	void DisplayAllBankAccountData()
	{
		CreateLog(ELogType::SuccessFul, " REQUEST TO PRINT ALL ACCOUNTS ");
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
							CurrentAccountLoaded.set_DebitCardPin(MyAttribute);
						}
						if (Attribute == 12)
						{
							CurrentAccountLoaded.set_BusinessName(MyAttribute);
						}
						if (Attribute == 13)
						{
							CurrentAccountLoaded.set_MonthlyIncome(stod(MyAttribute));
						}
						if (Attribute == 14)
						{
							CurrentAccountLoaded.set_yearlyIncome(stod(MyAttribute));
						}
						if (Attribute == 15)
						{
							CurrentAccountLoaded.set_DateOfBussinessEstablishing((MyAttribute));
						}
						if (Attribute == 16)
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
						CreateLog(ELogType::SuccessFul, CurrentAccountLoaded.get_AccountNumber() + " REQUEST TO DISPLAY ACCOUNT");

						Data.clear();
						Attribute = 0;
					}
				}

			}
		}
		else
		{
			CreateLog(ELogType::Failed, "USER FILE CANNOT BE OPEN");
		}
	}
	void CreateNewBankAccount()
	{

		if (SaveToFile("Data\\account.dat", ModelToString()))
		{
			cout << "Saved SuccessFully" << endl;
			CreateLog(ELogType::SuccessFul, get_AccountNumber() + " ACCOUNT CREATED SUCCESSFULLY");
		}
		else
		{
			cout << "Saving Failed" << endl;
			CreateLog(ELogType::Failed, get_AccountNumber() + " ACCOUNT CREATED FAILED");
		}
	}
	void FindBankAccount(string ToFindParameter)
	{
		CreateLog(ELogType::SuccessFul, ToFindParameter + " REQUEST TO FIND ACCOUNT");
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
							CurrentAccountLoaded.set_DebitCardPin(MyAttribute);
						}
						if (Attribute == 12)
						{
							CurrentAccountLoaded.set_BusinessName(MyAttribute);
						}
						if (Attribute == 13)
						{
							CurrentAccountLoaded.set_MonthlyIncome(stod(MyAttribute));
						}
						if (Attribute == 14)
						{
							CurrentAccountLoaded.set_yearlyIncome(stod(MyAttribute));
						}
						if (Attribute == 15)
						{
							CurrentAccountLoaded.set_Status((MyAttribute));
						}
						if (Attribute == 16)
						{
							CurrentAccountLoaded.set_DateofRegistration((MyAttribute));
						}
						MyAttribute.clear();
						index = 0;
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
							CreateLog(ELogType::SuccessFul, ToFindParameter + " REQUEST TO FIND ACCOUNT (FOUND)");

						}
						Data.clear();
						Attribute = 0;
					}
				}
			}
			if (!is_found)
			{
				cout << "NO RECORD FOUND" << endl;
				CreateLog(ELogType::Warning, ToFindParameter + " REQUEST TO FIND ACCOUNT (NOT FOUND)");

			}
		}
		else
		{
	 	  CreateLog(ELogType::Failed, "ACCOUNT FILE CANNOT BE OPEN");
		}
	}
	void DeleteBankAccount(string ToFindParameter)
	{
		CreateLog(ELogType::SuccessFul, ToFindParameter + " REQUEST TO DELETE ACCOUNT");
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
							CurrentAccountLoaded.set_DebitCardPin(MyAttribute);
						}
						if (Attribute == 12)
						{
							CurrentAccountLoaded.set_BusinessName(MyAttribute);
						}
						if (Attribute == 13)
						{
							CurrentAccountLoaded.set_MonthlyIncome(stod(MyAttribute));
						}
						if (Attribute == 14)
						{
							CurrentAccountLoaded.set_yearlyIncome(stod(MyAttribute));
						}
						if (Attribute == 15)
						{
							CurrentAccountLoaded.set_DateOfBussinessEstablishing((MyAttribute));
						}
						if (Attribute == 16)
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
							CreateLog(ELogType::SuccessFul, ToFindParameter + " REQUEST TO DELETE ACCOUNT (FOUND)");
						}
						if (!is_found)
						{
							SaveToFile("Data\\temp.dat", CurrentAccountLoaded.ModelToString());
							CreateLog(ELogType::SuccessFul, CurrentAccountLoaded.get_AccountNumber() + "IS TRANSFERED SUCCESSFULLY TO TEMP.DAT");

						}
						Data.clear();
						Attribute = 0;
					}
				}
			}
			if (!is_found)
			{
				cout << "NO RECORD FOUND" << endl;
				CreateLog(ELogType::Warning, ToFindParameter + " IS REQUESTED TO DELETE (NOT FOUND)");

			}
			else
			{
				cout << "DELETED SUCESSFULLY" << endl;
			}
			reader.close();

			auto isRemoved = remove("Data\\account.dat"); //file containing old record
			auto isRenamed = rename("Data\\temp.dat", "Data\\account.dat"); //file containing new record
		}
		else
		{
		CreateLog(ELogType::Failed, "ACCOUNT FILE CANNOT BE OPEN");
		}
	}
	void UpdateBankAccount(string ToFindParameter, Accounts UpdatedRecord)
	{
		CreateLog(ELogType::SuccessFul, ToFindParameter + " IS REQUESTED TO UPDATE");
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
							CurrentAccountLoaded.set_DebitCardPin(MyAttribute);
						}
						if (Attribute == 12)
						{
							CurrentAccountLoaded.set_BusinessName(MyAttribute);
						}
						if (Attribute == 13)
						{
							CurrentAccountLoaded.set_MonthlyIncome(stod(MyAttribute));
						}
						if (Attribute == 14)
						{
							CurrentAccountLoaded.set_yearlyIncome(stod(MyAttribute));
						}
						if (Attribute == 15)
						{
							CurrentAccountLoaded.set_DateOfBussinessEstablishing((MyAttribute));
						}
						if (Attribute == 16)
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
							CreateLog(ELogType::SuccessFul, CurrentAccountLoaded.get_AccountNumber() + "IS UPDATED SUCCESSFULLY ");
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
				CreateLog(ELogType::SuccessFul, ToFindParameter + " IS REQUESTED TO UPDATED (NOT FOUND)");
			}
			else
			{
				cout << "UPDATE SUCESSFULLY" << endl;
			}
			reader.close();
			auto resul = remove("Data\\account.dat"); //file containing old record
			auto result = rename("Data\\temp.dat", "Data\\account.dat"); //file containing new record
		}
		else
		{
		CreateLog(ELogType::Failed, "ACCOUNT FILE CANNOT BE OPEN");
		}
	}
	void ChangeAccountActivityStatus(string ToFindAccountNo, EUserActivityType ActivityType)
	{
		CreateLog(ELogType::SuccessFul, ToFindAccountNo + " IS REQUESTED TO CHANGE ACTIVITY STATUS");
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
							CurrentAccountLoaded.set_DebitCardPin(MyAttribute);
						}
						if (Attribute == 12)
						{
							CurrentAccountLoaded.set_BusinessName(MyAttribute);
						}
						if (Attribute == 13)
						{
							CurrentAccountLoaded.set_MonthlyIncome(stod(MyAttribute));
						}
						if (Attribute == 14)
						{
							CurrentAccountLoaded.set_yearlyIncome(stod(MyAttribute));
						}
						if (Attribute == 15)
						{
							CurrentAccountLoaded.set_DateOfBussinessEstablishing((MyAttribute));
						}
						if (Attribute == 16)
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

						if (CurrentAccountLoaded.get_AccountNumber() == ToFindAccountNo)
						{
							is_found = true;
							switch (ActivityType)
							{
							case EUserActivityType::Active:
							{
								CurrentAccountLoaded.set_Status("A");
								break;
							}
							case EUserActivityType::Deactive:
							{
								CurrentAccountLoaded.set_Status("D");
								break;
							}
							default:
							{
								throw runtime_error("Invalid Activity Type is Selected");
								StartUp();
								break;
							}
							}
							CreateLog(ELogType::SuccessFul, CurrentAccountLoaded.get_AccountNumber() + "STATUS IS CHANGED TO" + "(" + get_Status() + ")");
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
				CreateLog(ELogType::SuccessFul, ToFindAccountNo + " REQUESTED TO CHANGE ACTIVITY STATUS (NOT FOUND)");
			}
			else
			{
				cout << "ACTIVITY CHANGED SUCESSFULLY" << endl;
				CreateLog(ELogType::SuccessFul, ToFindAccountNo + " STATUS  IS ACTIVITY STATUS IS CHANGED TO" + "(" + get_Status() + ")");
			}
			reader.close();
			auto IsRemoved = remove("Data\\account.dat"); //file containing old record
			auto IsRenamed = rename("Data\\temp.dat", "Data\\account.dat"); //file containing new record
		}
		else
		{
		 CreateLog(ELogType::Failed, "ACCOUNT FILE CANNOT BE OPEN");
		}
	}
	void ChangeAccountDebitCardPin(string ToFindAccountNo,string NewDebitCardPin) 
	{
		CreateLog(ELogType::SuccessFul, ToFindAccountNo + " IS REQUESTED TO CHANGE DEBIT CARD PIN");
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
							CurrentAccountLoaded.set_DebitCardPin(MyAttribute);
						}
						if (Attribute == 12)
						{
							CurrentAccountLoaded.set_BusinessName(MyAttribute);
						}
						if (Attribute == 13)
						{
							CurrentAccountLoaded.set_MonthlyIncome(stod(MyAttribute));
						}
						if (Attribute == 14)
						{
							CurrentAccountLoaded.set_yearlyIncome(stod(MyAttribute));
						}
						if (Attribute == 15)
						{
							CurrentAccountLoaded.set_DateOfBussinessEstablishing((MyAttribute));
						}
						if (Attribute == 16)
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

						if (CurrentAccountLoaded.get_AccountNumber() == ToFindAccountNo)
						{
							is_found = true;
							CurrentAccountLoaded.set_DebitCardPin(NewDebitCardPin);
							
							CreateLog(ELogType::SuccessFul, CurrentAccountLoaded.get_AccountNumber() + " DEBIT CARD PIN IS CHANGED");
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
				CreateLog(ELogType::SuccessFul, ToFindAccountNo + " REQUESTED TO CHANGE DEBIT CARD PIN (NOT FOUND)");
			}
			else
			{
				cout << "DEBIT CARD PIN IS CHANGED SUCESSFULLY" << endl;
				CreateLog(ELogType::SuccessFul, ToFindAccountNo + "DEBIT CARD PIN IS CHANGED SUCESSFULLY");
			}
			reader.close();
			auto IsRemoved = remove("Data\\account.dat"); //file containing old record
			auto IsRenamed = rename("Data\\temp.dat", "Data\\account.dat"); //file containing new record
		}
		else
		{
		CreateLog(ELogType::Failed, "ACCOUNT FILE CANNOT BE OPEN");
		}
	}
	bool PerformATMLogin(string AccountNumber,string DebitCardPin) 
	{
		CreateLog(ELogType::SuccessFul, AccountNumber + " REQUEST TO LOGIN BANK ACCOUNT VIA ATM");
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
							CurrentAccountLoaded.set_DebitCardPin(MyAttribute);
						}
						if (Attribute == 12)
						{
							CurrentAccountLoaded.set_BusinessName(MyAttribute);
						}
						if (Attribute == 13)
						{
							CurrentAccountLoaded.set_MonthlyIncome(stod(MyAttribute));
						}
						if (Attribute == 14)
						{
							CurrentAccountLoaded.set_yearlyIncome(stod(MyAttribute));
						}
						if (Attribute == 15)
						{
							CurrentAccountLoaded.set_DateOfBussinessEstablishing((MyAttribute));
						}
						if (Attribute == 16)
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
						//compare with Parameter
						if (CurrentAccountLoaded.get_AccountNumber() == AccountNumber&& CurrentAccountLoaded.get_DebitCardPin() == DebitCardPin)
						{
							is_found = true;							
							CreateLog(ELogType::SuccessFul, AccountNumber + " IS REQUEST TO LOGIN ACCOUNT VIA ATM (FOUND)");

						}
						Data.clear();
						Attribute = 0;
					}
				}
			}
			if (!is_found)
			{
				cout << "NO RECORD FOUND" << endl;
				CreateLog(ELogType::Warning, AccountNumber + " IS REQUEST TO LOGIN ACCOUNT VIA ATM (NOT FOUND)");
				return false;
			}
			else 
			{
				return true;
			}
		}
		else
		{
			CreateLog(ELogType::Failed, "ACCOUNT FILE CANNOT BE OPEN");
		}
	}
	Accounts()
	{
		AccountTitle = AccountNumber = DebitCardNumber = AtmCardNumber = Status = DateofRegistration = "";
	}
};