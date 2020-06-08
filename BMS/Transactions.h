#pragma once
#include "Abstracts.h"
class Transactions : public Accounts
{
	string TransactionId;
	TransactionType TransactionTypes;
	double Amount;
	double Balance;
	string TransactionDate;
public:
	void set_TransactionId(string TransactionId_inp)
	{
		TransactionId = TransactionId_inp;
	}
	string get_TransactionId() const
	{
		return TransactionId;
	}
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
	void set_TransactionType(TransactionType TransactionType_inp)
	{
		TransactionTypes = TransactionType_inp;
	}
	TransactionType get_TransactionType() const
	{
		return TransactionTypes;
	}
	virtual void Display() override
	{
		string type;
		switch (get_TransactionType())
		{
			case TransactionType::Deposit:
			{
				type = "Deposit";
				break;
			}
			case TransactionType::WithDraw:
			{
				type = "Withdraw";
				break;
			}
			default:
				type = "";
				break;
		}	
		BuilApplicationHeader("TRANSACTIONS NUMBER = "+ get_TransactionId());
		int ColWidth = 10;
		//
		cout << setw(ColWidth) << "ACCOUNT NUMBER" << setw(ColWidth) << "TYPE" 
			<< setw(20) << "AMOUNT" << setw(20) << "BALANCE" << setw(20) << "TRANSACTION DATE" << endl;
		cout << setw(ColWidth) << get_AccountNumber() << setw(15) << type <<
			setw(20) << to_string(get_Amount()) << setw(20) << to_string(get_Balance()) << setw(20) << get_TransactionDate() << endl;
		cout << "\n\n";
	}
	string ModelToString()
	{
		string type;
		switch (get_TransactionType())
		{
			case TransactionType::Deposit: 
			{
				type ="D";
				break;
			}
			case TransactionType::WithDraw:
			{
				type = "W";
				break;
			}
		default:
			type = "";
			break;
		}
		string ModelString = get_AccountNumber()+","+get_TransactionId()+","+ type + "," + 
			to_string(get_Amount())+","+to_string(get_Balance())+","+
			get_TransactionDate()+",";
		return ModelString;
	}
	void DisplayAllAccountTransaction()
	{
		ifstream reader;
		reader.open("Data\\transactions.dat");
		if (reader.is_open())
		{
			string Data, MyAttribute;
			int Attribute = 0, index = 0;
			while (getline(reader, Data))
			{
				Transactions TransactionLoaded;
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
							TransactionLoaded.set_AccountNumber(MyAttribute);
						}
						if (Attribute==2)
						{
							TransactionLoaded.set_TransactionId(MyAttribute);
						}
						if (Attribute == 3)
						{
							TransactionType type;
							if (MyAttribute == "D")
							{
								type = TransactionType::Deposit;
							}
							if (MyAttribute == "W")
							{
								type = TransactionType::WithDraw;
							}
							TransactionLoaded.set_TransactionType(type);
						}
						if (Attribute == 4)
						{
							TransactionLoaded.set_Amount(stod(MyAttribute));
						}
						if (Attribute == 5)
						{
							TransactionLoaded.set_Balance(stod(MyAttribute));
						}
						if (Attribute == 6)
						{
							TransactionLoaded.set_TransactionDate((MyAttribute));
						}
						MyAttribute.clear();
						index = 0;
					}

					if (Data[i] == '$')///object completed
					{
						MyAttribute.clear();
						index = 0;

						TransactionLoaded.Display();

						Data.clear();
						Attribute = 0;
					}
				}

			}
		}
	}
	void CreateNewTransction()
	{

		if (SaveToFile("Data\\transactions.dat", ModelToString()))
		{
			cout << "Saved SuccessFully" << endl;
		}
		else
		{
			cout << "Saving Failed" << endl;
		}
	}
	void FindTransactionHistoryByAccountNumber(string ToFindParameter)
	{
		bool is_found = false;
		ifstream reader;
		reader.open("Data\\transactions.dat");
		if (reader.is_open())
		{
			string Data, MyAttribute;
			int Attribute = 0, index = 0;
			while (getline(reader, Data))
			{
				Transactions TransactionLoaded;
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
							TransactionLoaded.set_AccountNumber(MyAttribute);
						}
						if (Attribute == 2)
						{
							TransactionLoaded.set_TransactionId(MyAttribute);
						}
						if (Attribute == 3)
						{
							TransactionType type;
							if (MyAttribute == "D")
							{
								type = TransactionType::Deposit;
							}
							if (MyAttribute == "W")
							{
								type = TransactionType::WithDraw;
							}
							TransactionLoaded.set_TransactionType(type);
						}
						if (Attribute == 4)
						{
							TransactionLoaded.set_Amount(stod(MyAttribute));
						}
						if (Attribute == 5)
						{
							TransactionLoaded.set_Balance(stod(MyAttribute));
						}
						if (Attribute == 6)
						{
							TransactionLoaded.set_TransactionDate((MyAttribute));
						}
						MyAttribute.clear();
						index = 0;					
					}

					if (Data[i] == '$')///object completed
					{
						MyAttribute.clear();
						index = 0;
						//compare with Parameter
						if (TransactionLoaded.get_AccountNumber() == ToFindParameter)
						{
							is_found = true;
							TransactionLoaded.Display();
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
	void DeleteATransaction(string ToFindParameterTransactionId)
	{
		bool is_found = false;
		ifstream reader("Data\\transactions.dat");
		if (reader.is_open())
		{
			string Data, MyAttribute;
			int Attribute = 0, index = 0;
			while (getline(reader, Data))
			{
				Transactions TransactionLoaded;
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
							TransactionLoaded.set_AccountNumber(MyAttribute);
						}
						if (Attribute == 2)
						{
							TransactionLoaded.set_TransactionId(MyAttribute);
						}
						if (Attribute == 3)
						{
							TransactionType type;
							if (MyAttribute == "D")
							{
								type = TransactionType::Deposit;
							}
							if (MyAttribute == "W")
							{
								type = TransactionType::WithDraw;
							}
							TransactionLoaded.set_TransactionType(type);
						}
						if (Attribute == 4)
						{
							TransactionLoaded.set_Amount(stod(MyAttribute));
						}
						if (Attribute == 5)
						{
							TransactionLoaded.set_Balance(stod(MyAttribute));
						}
						if (Attribute == 6)
						{
							TransactionLoaded.set_TransactionDate((MyAttribute));
						}
						MyAttribute.clear();
						index = 0;
					}

					if (Data[i] == '$')///object completed
					{
						MyAttribute.clear();
						index = 0;
						//<After finding specific Transaction to delete>
						//<we create a new file temp.bin in which we transfer all record (except which is requested to delete) and then rename this file to account.dat>

						if (TransactionLoaded.get_TransactionId() == ToFindParameterTransactionId)
						{
							is_found = true;
						}
						if (!is_found)
						{
							SaveToFile("Data\\temp.dat", TransactionLoaded.ModelToString());
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

			auto isRemoved = remove("Data\\transactions.dat"); //file containing old record
			auto isRenamed = rename("Data\\temp.dat", "Data\\transactions.dat"); //file containing new record
		}
	}
	void UpdateTransaction(string ToFindParameterTransactionId, Transactions UpdatedRecord)
	{
		bool is_found = false;
		ifstream reader("Data\\transactions.dat");
		if (reader.is_open())
		{
			string Data, MyAttribute;
			int Attribute = 0, index = 0;
			while (getline(reader, Data))//read a line 
			{
				Transactions TransactionLoaded;
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
							TransactionLoaded.set_AccountNumber(MyAttribute);
						}
						if (Attribute == 2)
						{
							TransactionLoaded.set_TransactionId(MyAttribute);
						}
						if (Attribute == 3)
						{
							TransactionType type;
							if (MyAttribute == "D")
							{
								type = TransactionType::Deposit;
							}
							if (MyAttribute == "W")
							{
								type = TransactionType::WithDraw;
							}
							TransactionLoaded.set_TransactionType(type);
						}
						if (Attribute == 4)
						{
							TransactionLoaded.set_Amount(stod(MyAttribute));
						}
						if (Attribute == 5)
						{
							TransactionLoaded.set_Balance(stod(MyAttribute));
						}
						if (Attribute == 6)
						{
							TransactionLoaded.set_TransactionDate((MyAttribute));
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

						if (TransactionLoaded.get_TransactionId() == ToFindParameterTransactionId)
						{
							is_found = true;
							TransactionLoaded = UpdatedRecord;
						}
						SaveToFile("Data\\temp.dat", TransactionLoaded.ModelToString());
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
			auto resul = remove("Data\\transactions.dat"); //file containing old record
			auto result = rename("Data\\temp.dat", "Data\\transactions.dat"); //file containing new record
		}
	}
	double CheckCurrentBalance(string ToFindParamerAccountNumber)
	{
		double CurrentBalance=0;
		bool is_found = false;
		ifstream reader;
		reader.open("Data\\transactions.dat");
		if (reader.is_open())
		{
			string Data, MyAttribute;
			int Attribute = 0, index = 0;
			while (getline(reader, Data))
			{
				Transactions TransactionLoaded;
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
							TransactionLoaded.set_AccountNumber(MyAttribute);
						}
						if (Attribute == 2)
						{
							TransactionLoaded.set_TransactionId(MyAttribute);
						}
						if (Attribute == 3)
						{
							TransactionType type;
							if (MyAttribute == "D")
							{
								type = TransactionType::Deposit;
							}
							if (MyAttribute == "W")
							{
								type = TransactionType::WithDraw;
							}
							TransactionLoaded.set_TransactionType(type);
						}
						if (Attribute == 4)
						{
							TransactionLoaded.set_Amount(stod(MyAttribute));
						}
						if (Attribute == 5)
						{
							TransactionLoaded.set_Balance(stod(MyAttribute));
						}
						if (Attribute == 6)
						{
							TransactionLoaded.set_TransactionDate((MyAttribute));
						}
						MyAttribute.clear();
						index = 0;
					}

					if (Data[i] == '$')///object completed
					{
						MyAttribute.clear();
						index = 0;
						//compare with Parameter
						if (TransactionLoaded.get_AccountNumber() == ToFindParamerAccountNumber)
						{
							is_found = true;
							CurrentBalance=TransactionLoaded.get_Balance();
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
		return CurrentBalance;
	}
	Transactions()
	{
		TransactionId= TransactionDate = "";
		Amount = Balance = 0;
	}
};