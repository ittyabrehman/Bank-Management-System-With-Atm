#pragma once
#include "Abstracts.h"
class User : public Person
{
	string UserName;
	string Password;
	string Email;
	string UserId;
	string IsActive;

public:
	void set_IsActive(string IsActive_inp)
	{
		IsActive = IsActive_inp;
	}
	string get_IsActive() const
	{
		return IsActive;
	}

	void set_UserId(string UserId_inp)
	{
		UserId = UserId_inp;
	}
	string get_UserId() const
	{
		return UserId;
	}

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
		cout << "User Id: " << get_UserId() << endl;
		cout << "Name: " << get_Name() << endl;
		cout << "Father Name: " << get_FatherName() << endl;
		cout << "User Name: " << get_UserName()<<endl;	
		cout << "Email: " << get_Email()<<endl;
	}
	string ModelToString() 
	{
		string ModelString = get_UserId()+","+get_Name() + "," + get_FatherName() + "," +
			get_UserName() + ","+get_Password() + "," +get_Email() + ","+get_IsActive()+",";
		CreateLog(ELogType::SuccessFul, "NEW MODELTOSTRING CREATED SUCCESSFULLY");
		return ModelString;
	}
	void CreateNewUserAccount()
	{
		if (SaveToFile("Data\\users.dat", ModelToString()))
		{
			cout << "Saved SuccessFully" << endl;
			CreateLog(ELogType::SuccessFul,"NEW USER CREATED SUCCESSFULLY");
		}
		else
		{
			cout << "Saving Failed" << endl;
			CreateLog(ELogType::SuccessFul, "NEW USER CREATED FAILED");

		}
	}
	void FindUserAccount(string ToFindParmaterUserId) 
	{
		CreateLog(ELogType::SuccessFul, ToFindParmaterUserId+" IS REQUESTED TO FIND");

		bool is_found = false;
		ifstream reader;
		reader.open("Data\\users.dat");
		if (reader.is_open())
		{
			string Data, MyAttribute;
			int Attribute = 0, index = 0;
			while (getline(reader, Data))
			{
				User UserLoaded;
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
							UserLoaded.set_UserId(MyAttribute);
						}
						if (Attribute == 2)
						{
							UserLoaded.set_Name(MyAttribute);
						}
						if (Attribute == 3)
						{
							UserLoaded.set_FatherName(MyAttribute);
						}
						if (Attribute == 4)
						{
							UserLoaded.set_UserName(MyAttribute);
						}
						if (Attribute == 5)
						{
							UserLoaded.set_Password(MyAttribute);
						}
						if (Attribute == 6)
						{
							UserLoaded.set_Email(MyAttribute);
						}
						if (Attribute == 7)
						{
							UserLoaded.set_IsActive(MyAttribute);
						}
						MyAttribute.clear();
						index = 0;

					}

					if (Data[i] == '$')///object completed
					{
						MyAttribute.clear();
						index = 0;
						//compare with Parameter
						if (UserLoaded.get_UserId() == ToFindParmaterUserId)
						{
							is_found = true;
							UserLoaded.Display();
							CreateLog(ELogType::SuccessFul, ToFindParmaterUserId + " IS REQUESTED TO FIND (FOUND & DISPLAYED)");

						}
						Data.clear();
						Attribute = 0;
					}
				}
			}
			if (!is_found)
			{
				cout << "NO RECORD FOUND" << endl;
				CreateLog(ELogType::SuccessFul, ToFindParmaterUserId + " IS REQUESTED TO FIND (NOT FOUND)");

			}
		}
	}
	void DeleteUserAccount(string ToFindParmaterUserId)
	{
		CreateLog(ELogType::SuccessFul, ToFindParmaterUserId + " IS REQUESTED TO DELETE ");

		bool is_found = false;
		ifstream reader("Data\\users.dat");
		if (reader.is_open())
		{
			string Data, MyAttribute;
			int Attribute = 0, index = 0;
			while (getline(reader, Data))
			{
				User UserLoaded;
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
							UserLoaded.set_UserId(MyAttribute);
						}
						if (Attribute == 2)
						{
							UserLoaded.set_Name(MyAttribute);
						}
						if (Attribute == 3)
						{
							UserLoaded.set_FatherName(MyAttribute);
						}
						if (Attribute == 4)
						{
							UserLoaded.set_UserName(MyAttribute);
						}
						if (Attribute == 5)
						{
							UserLoaded.set_Password(MyAttribute);
						}
						if (Attribute == 6)
						{
							UserLoaded.set_Email(MyAttribute);
						}
						if (Attribute == 7)
						{
							UserLoaded.set_IsActive(MyAttribute);
						}
						MyAttribute.clear();
						index = 0;

					}					
				
				
					if (Data[i] == '$')///object completed
					{
						MyAttribute.clear();
						index = 0;
						//<After finding specific User to delete>
						//<we create a new file temp.bin in which we transfer all record (except which is requested to delete) and then rename this file to account.dat>

						if (UserLoaded.get_UserId() == ToFindParmaterUserId)
						{
							is_found = true;
							CreateLog(ELogType::SuccessFul, ToFindParmaterUserId + " IS REQUESTED TO DELETE ");
						}
						if (!is_found)
						{
							SaveToFile("Data\\temp.dat", UserLoaded.ModelToString());
							CreateLog(ELogType::SuccessFul, UserLoaded.get_UserId() + " IS TRANSFERED TO TEMP.DAT");
						}
						Data.clear();
						Attribute = 0;
					}
				}
			}
			if (!is_found)
			{
				cout << "NO RECORD FOUND" << endl;
				CreateLog(ELogType::SuccessFul, ToFindParmaterUserId + " IS REQUESTED TO DELETE (NOT FOUND)");
			}
			else
			{
				cout << "DELETED SUCESSFULLY" << endl;
				CreateLog(ELogType::SuccessFul, ToFindParmaterUserId + " IS DELETED SUCCESSFULLY");
			}
			reader.close();

			auto isRemoved = remove("Data\\users.dat"); //file containing old record
			auto isRenamed = rename("Data\\temp.dat", "Data\\users.dat"); //file containing new record
		}
	}
	void UpdateUserAccount(string ToFindParameterUserId, User UpdatedRecord)
	{
		CreateLog(ELogType::SuccessFul, ToFindParameterUserId + " IS REQUESTED TO UPDATE ");

		bool is_found = false;
		ifstream reader("Data\\users.dat");
		if (reader.is_open())
		{
			string Data, MyAttribute;
			int Attribute = 0, index = 0;
			while (getline(reader, Data))//read a line 
			{
				User UserLoaded;
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
							UserLoaded.set_UserId(MyAttribute);
						}
						if (Attribute == 2)
						{
							UserLoaded.set_Name(MyAttribute);
						}
						if (Attribute == 3)
						{
							UserLoaded.set_FatherName(MyAttribute);
						}
						if (Attribute == 4)
						{
							UserLoaded.set_UserName(MyAttribute);
						}
						if (Attribute == 5)
						{
							UserLoaded.set_Password(MyAttribute);
						}
						if (Attribute == 6)
						{
							UserLoaded.set_Email(MyAttribute);
						}
						if (Attribute == 7)
						{
							UserLoaded.set_IsActive(MyAttribute);
						}
						MyAttribute.clear();
						index = 0;

					}

					if (Data[i] == '$')///object completed
					{
						MyAttribute.clear();
						index = 0;
						//<After finding specific user to delete>
						//<we create a new file temp.dat in which we transfer all record and then rename this file to account.dat>

						if (UserLoaded.get_UserId() == ToFindParameterUserId)
						{
							is_found = true;
							UserLoaded = UpdatedRecord;
						}
						SaveToFile("Data\\temp.dat", UserLoaded.ModelToString());
						Data.clear();
						Attribute = 0;
					}
				}
			}
			if (!is_found)
			{
				cout << "NO RECORD FOUND" << endl;
				CreateLog(ELogType::SuccessFul, ToFindParameterUserId + " IS REQUESTED TO UPDATE (NOT FOUND)");
			}
			else
			{
				cout << "UPDATED SUCESSFULLY" << endl;
				CreateLog(ELogType::SuccessFul, ToFindParameterUserId + " IS UPDATED SUCCESSFULLY");
			}
			reader.close();
			auto IsRemoved = remove("Data\\users.dat"); //file containing old record
			auto IsRenamed = rename("Data\\temp.dat", "Data\\users.dat"); //file containing new record
		}
	}
	bool PerformLogin(string username,string password)
	{
		CreateLog(ELogType::SuccessFul, username + " IS REQUESTED TO LOGIN ");
		bool is_found = false;
		ifstream reader;
		reader.open("Data\\users.dat");
		if (reader.is_open())
		{
			string Data, MyAttribute;
			int Attribute = 0, index = 0;
			while (getline(reader, Data))
			{
				User UserLoaded;
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
							UserLoaded.set_UserId(MyAttribute);
						}
						if (Attribute == 2)
						{
							UserLoaded.set_Name(MyAttribute);
						}
						if (Attribute == 3)
						{
							UserLoaded.set_FatherName(MyAttribute);
						}
						if (Attribute == 4)
						{
							UserLoaded.set_UserName(MyAttribute);
						}
						if (Attribute == 5)
						{
							UserLoaded.set_Password(MyAttribute);
						}
						if (Attribute == 6)
						{
							UserLoaded.set_Email(MyAttribute);
						}
						if (Attribute == 7)
						{
							UserLoaded.set_IsActive(MyAttribute);
						}
						MyAttribute.clear();
						index = 0;

					}

					if (Data[i] == '$')///object completed
					{
						MyAttribute.clear();
						index = 0;
						//compare with Parameters
						if (UserLoaded.get_UserName() == username && UserLoaded.get_Password() == password)
						{
							if (UserLoaded.get_IsActive()=="A")
							{
								CreateLog(ELogType::SuccessFul, username + " IS LOGIN SUCCESSFULLY");
								return true;//when login sucessFully
							}
							else 
							{
								cout << "ACCESS DENINED. YOUR ACCOUNT IS DEACTIVATED BY ADMIN" << endl;
								CreateLog(ELogType::SuccessFul, username + " ACCESS DENINED. YOUR ACCOUNT IS DEACTIVATED BY ADMIN");
								return false;
							}
							is_found = true;
						
						}
						Data.clear();
						Attribute = 0;
					}
				}
				
			}
			if (!is_found)
			{
				cout << "Invalid UserName Or Password" << endl;
				CreateLog(ELogType::SuccessFul, username + " IS REQUESTED TO LOGIN (NOT FOUND)");
				return false;
			}
			else 
			{
				CreateLog(ELogType::SuccessFul, username + " IS REQUESTED TO LOGIN (FOUND & Validate Username and password)");
				return true;
			}
		}
		else 
		{
			throw runtime_error("USER FILE CANNOT BE OPEN");
			return false;
		}
	}
	void ChangeUserActivityStatus(string ToFindParameterUserId,EUserActivityType ActivityType)
	{
		CreateLog(ELogType::SuccessFul, ToFindParameterUserId + " IS REQUESTED FOR CHANGE USER ACCOUNT STATUS");
		bool is_found = false;
		ifstream reader("Data\\users.dat");
		if (reader.is_open())
		{
			string Data, MyAttribute;
			int Attribute = 0, index = 0;
			while (getline(reader, Data))//read a line 
			{
				User UserLoaded;
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
							UserLoaded.set_UserId(MyAttribute);
						}
						if (Attribute == 2)
						{
							UserLoaded.set_Name(MyAttribute);
						}
						if (Attribute == 3)
						{
							UserLoaded.set_FatherName(MyAttribute);
						}
						if (Attribute == 4)
						{
							UserLoaded.set_UserName(MyAttribute);
						}
						if (Attribute == 5)
						{
							UserLoaded.set_Password(MyAttribute);
						}
						if (Attribute == 6)
						{
							UserLoaded.set_Email(MyAttribute);
						}
						if (Attribute == 7)
						{
							UserLoaded.set_IsActive(MyAttribute);
						}
						MyAttribute.clear();
						index = 0;

					}

					if (Data[i] == '$')///object completed
					{
						MyAttribute.clear();
						index = 0;
						//<After finding specific user to delete>
						//<we create a new file temp.dat in which we transfer all record and then rename this file to account.dat>

						if (UserLoaded.get_UserId() == ToFindParameterUserId)
						{
							is_found = true;
							switch (ActivityType)
							{
								case EUserActivityType::Active:
								{
									UserLoaded.set_IsActive("A");
									break;
								}
								case EUserActivityType::Deactive:
								{
									UserLoaded.set_IsActive("D");
									break;
								}
								default:
								{
									UserLoaded.set_IsActive("Invalid");
									throw runtime_error("Invalid Activity Type is Selected");								
									StartUp();
									break; 
								}
							}
							CreateLog(ELogType::SuccessFul, ToFindParameterUserId + " ACCOUNT STATUS CHANGED TO ("+ UserLoaded.get_IsActive()+")");
										
						}
						SaveToFile("Data\\temp.dat", UserLoaded.ModelToString());
						CreateLog(ELogType::SuccessFul, ToFindParameterUserId + " ACCOUNT TRANSFERED TO TEMP.DAT");
						Data.clear();
						Attribute = 0;
					}
				}
			}
			if (!is_found)
			{
				cout << "NO RECORD FOUND" << endl;
				CreateLog(ELogType::Warning, ToFindParameterUserId + " IS REQUESTED FOR CHANGE USER ACCOUNT STATUS (NOT FOUND)");
			}
			else
			{
				cout << "STATUS CHANGED SUCESSFULLY" << endl;
			}
			reader.close();
			auto IsRemoved = remove("Data\\users.dat"); //file containing old record
			auto IsRenamed = rename("Data\\temp.dat", "Data\\users.dat"); //file containing new record
		
		}
	}	
	User()
	{
		UserName = Password = Email = UserId=IsActive="";
	}
};