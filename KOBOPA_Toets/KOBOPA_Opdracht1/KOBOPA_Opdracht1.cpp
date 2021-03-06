// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>
#include <list>
#include <vector>
#include <time.h>
#include <fstream>
using namespace std;

class PasswordGenerator {
	public:

		//Class Variables
		int array_PasswordLengths[3] = { 8, 12, 15 };

		//min and max number of characters
		int int_MinPasswordCharacters = 8;
		int int_MaxPasswordCharacters = 15;

		//default number of characters
		int int_PasswordNumberOfCharacters = 10;

		string string_AllowedCharacters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
		string string_GeneratedPassword;

		//default notification on running function
		string string_Notification = "Generating 3 passwords.";

		//Constructor
		PasswordGenerator() {

		}

		virtual void Function_GenerateNumberOfPasswords(int int_NumberOfPasswordsToGenerate) {
			
			//waarom werkt dit niet?
			//string_Notification = "Generating " + int_NumberOfPasswordsToGenerate + " passwords.";

			cout << string_Notification << endl;
			for (int i = 0; i < int_NumberOfPasswordsToGenerate; i++)
			{
				cout << "Password number " << i + 1 << " is: ";
				int_PasswordNumberOfCharacters = array_PasswordLengths[i];
				Function_GenerateSinglePassword();
				Function_OutputGeneratedPassword();
				string_GeneratedPassword.clear();
			}
			cout << endl;
		}

		virtual string Function_GenerateSinglePassword() {
			for (int i = 0; i < int_PasswordNumberOfCharacters; i++)
			{
				string_GeneratedPassword += string_AllowedCharacters.at(rand() % string_AllowedCharacters.size());
				/*
				int int_WhatCharacter(rand() % 2);
				if (int_WhatCharacter == 0) {
					string_GeneratedPassword += (rand() % 26) + 'a';
				}
				else {
					string_GeneratedPassword += (rand() % 26) + 'A';
				}
				*/
			}
			return(string_GeneratedPassword);
		};

		void Function_OutputGeneratedPassword() {
			cout << string_GeneratedPassword << endl;
		}
};

class BetterPasswordGenerator : public PasswordGenerator {
	public:
		
		//Constructor
		BetterPasswordGenerator() {
			string_Notification = "Generating 3 better passwords.";
		}

		//Override base function for better password
		string Function_GenerateSinglePassword() {

			string_AllowedCharacters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890!@#$%^&*<>";

			for (int i = 0; i < int_PasswordNumberOfCharacters; i++)
			{
				string_GeneratedPassword += string_AllowedCharacters[rand() % string_AllowedCharacters.size()];
			}
			return(string_GeneratedPassword);
		};
};

class UserPassword {
	public:

		string username;
		string password;

		UserPassword() {

		}

		UserPassword( const UserPassword &other) {
			username = other.username;
			password = other.password;
		}

		~UserPassword() {

		}
};

class PasswordList {
	public:

		vector <UserPassword> vector_UserPasswords;

		void Function_AddUserPassword(string username) {

			//create objects
			UserPassword object_UserPassword;
			BetterPasswordGenerator object_BetterPasswordGenerator;

			int int_VectorSize = vector_UserPasswords.size();
			object_UserPassword.username = username;
			object_UserPassword.password = object_BetterPasswordGenerator.Function_GenerateSinglePassword();
			vector_UserPasswords.push_back(object_UserPassword);
		}

		void Function_ReadNumberOfEntries() {
			cout << "Total Number of entries: " << vector_UserPasswords.size() << endl << endl;
		}

		void Function_ReadEntryAtIndex(int int_IndexToRead) {
			UserPassword object_UserPassword = vector_UserPasswords[int_IndexToRead];
			cout << "Entry Number: " << int_IndexToRead + 1 << endl;
			cout << "Username: " << object_UserPassword.username << endl;
			cout << "Password: " << object_UserPassword.password << endl << endl;
		}
};

void Function_WriteDataToTxt(PasswordList object_PasswordlistToSave) {

	vector <UserPassword> vector_UserPasswords = object_PasswordlistToSave.vector_UserPasswords;
	ofstream SavedUserPasswords;
	SavedUserPasswords.open("SavedUserPasswords.txt");

	//write text to txt
	SavedUserPasswords << endl << "Resultaten opdracht 3" << endl << endl;

	//write number of entries to txt
	SavedUserPasswords << "Total Number of entries: " << vector_UserPasswords.size() << endl << endl;

	//write info of all entries to txt
	for (int i = 0; i < object_PasswordlistToSave.vector_UserPasswords.size(); i++)
	{
		UserPassword object_UserPassword = vector_UserPasswords[i];
		SavedUserPasswords << "Entry Number: " << i + 1 << endl;
		SavedUserPasswords << "Username: " << object_UserPassword.username << endl;
		SavedUserPasswords << "Password: " << object_UserPassword.password << endl << endl;
	}

	SavedUserPasswords.close();
}

void Function_Opdracht1() {

	cout << endl << "Resultaten van opdracht 1: " << endl << endl;

	//Generate 3 passwords
	PasswordGenerator object_PasswordGenerator;
	object_PasswordGenerator.Function_GenerateNumberOfPasswords(3);

	//Generate 3 Better passwords
	BetterPasswordGenerator object_BetterPasswordGenerator;
	object_BetterPasswordGenerator.Function_GenerateNumberOfPasswords(3);
}

void Function_Opdracht2() {
	
	cout << endl << "Resultaten van opdracht 2:" << endl << endl;

	//create an instance of the passwordlist
	PasswordList object_PasswordList;

	//creating the user dimme and giving a password for the users
	object_PasswordList.Function_AddUserPassword("dimme");
	object_PasswordList.Function_AddUserPassword("corne");
	object_PasswordList.Function_AddUserPassword("teun");
	object_PasswordList.Function_AddUserPassword("keimpe");

	//read number of entries
	object_PasswordList.Function_ReadNumberOfEntries();

	//read info of all entries
	for (int i = 0; i < object_PasswordList.vector_UserPasswords.size(); i++)
	{
		object_PasswordList.Function_ReadEntryAtIndex(i);
	}
}

void Function_Opdracht3() {
	cout << endl << "Resultaten van opdracht 3 zijn opgelagen in een txt bestand." << endl << endl;

	//create an instance of the passwordlist
	PasswordList object_PasswordList;

	//creating the user dimme and giving a password for the users
	object_PasswordList.Function_AddUserPassword("manemjeff");
	object_PasswordList.Function_AddUserPassword("harrypotter");
	object_PasswordList.Function_AddUserPassword("twaalfkippen");
	object_PasswordList.Function_AddUserPassword("plantwater");
	object_PasswordList.Function_AddUserPassword("onzichtbarevlinder");
	object_PasswordList.Function_AddUserPassword("ikbennietziek");
	
	//save to txt file
	Function_WriteDataToTxt(object_PasswordList);
}

void main()
{
	srand(time(NULL));

	//laat opdracht 1 van de KOBOPA toets zien in de console
	Function_Opdracht1();

	//laat opdracht 2 van de KOBOPA toets zien in de console
	Function_Opdracht2();

	//sla resultaten van opdracht 2 op in txt bestand
	Function_Opdracht3();
}
