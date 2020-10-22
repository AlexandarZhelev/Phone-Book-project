#include <iostream>
#include <fstream>
#include <string>
#include <ostream>
#include <iterator>
#include <sstream>
#include <stdlib.h>
#include <cstdio>
#include <list>

#include "Person.h"
#include "Constants.h"
#include "pch.h"

using namespace N;

//function for EGN verification
bool isValidPin(const std::string &str)
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}

bool checkCtrlNum(std::string EGN)
{
	int ctrSum = 0; // control sum
	int ctrField = 0; //control field
	int weight[] = {2, 4, 8, 5, 10, 9, 7, 3, 6}; //weighting factors

	//check if the EGN is 10 characters
	if (EGN.size() != 10)
	{
		return false;
	}

	for (int i = 0; i < 9; ++i)
	{ 
		ctrSum += weight[i] * atoi(EGN.substr(i, 1).c_str());
	}
	
	//calculate the control field
	ctrField = (ctrSum % 11) % 10;

	if (ctrField != atoi(EGN.substr(9, 1).c_str()))
	{
		return false;
	}

	else
	{
		return true;
	}
}

//function to add a new record
void Person::addRecord()
{
	std::string firstName;
	std::string lastName;
	std::string number;
	std::string EGN;

	Person newRecord;

	std::cout << "Enter information" << "\n\n";

	std::cout << "Enter first name:" << "\n";
	std::cin >> newRecord.firstName;

	std::cout << "Enter last name:" << "\n";
	std::cin >> newRecord.lastName;

	std::cout << "Enter phone number:" << "\n";
	std::cin >> newRecord.number;

	std::cout << "Enter EGN:" << "\n";
	while (true)	//check EGN validation
	{
		std::cin >> newRecord.EGN;

		if (isValidPin(newRecord.EGN) && checkCtrlNum(newRecord.EGN))
		{
			break;
		}

		else
		{
			std::cout << "Enter valid EGN and try again!" << "\n";
			std::cin.clear();
		}
	}

	system("CLS"); //clear screen

	// Open file to write
	std::ofstream data(filename, std::ofstream::app | std::ofstream::out);

	// Write data to file
	data << newRecord;

	// Close file
	data.close();
}

//record search function 
void Person::SearchRecord()
{
	bool found{ false };
	std::string pEGN;

	std::list<Person> users{};
	std::ifstream data("Input.txt");

	std::cout << "Enter EGN to find." << "\n";
	std::cin >> pEGN;

	Person obj;

	while (true)
	{
		if (!data.good())
		{
			break;
		}

		data >> obj;

		if (obj.EGN == pEGN)
		{
			found = true;

			std::cout << "Person EGN: " << obj.getEGN() << "\n";
			std::cout << "First Name: " << obj.getFirstName() << "\n";
			std::cout << "Last Name: " << obj.getLastName() << "\n";
			std::cout << "Phone Number: " << obj.getNumber() << "\n";

			std::cout << "Do you want to delete this record? y/n" << "\n";

			char result;
			std::cin >> result;

			system("CLS"); //clear screen

			while (true)
			{
				if (result == 'y')
				{
					break;
				}

				else if (result == 'n')
				{
					return;
				}

				else
				{
					std::cout << "Invalid choice!" << "\n";
					std::cin >> result;
				}
			}
		}

		else
		{
			users.push_back(obj); //filling the list with users data
		}
	}

	data.close();
	remove("Input.txt");

	std::ofstream out_file(filename, std::ofstream::app | std::ofstream::out);

	for (Person user : users)
	{
		out_file << user;
	}

	if (!found)
	{
		std::cout << "EGN not found!";
	}
}

//function to display all records
void Person::ShowRecords()
{
	std::ifstream data("Input.txt");

	while (true)
	{
		Person person;
		data >> person;

		if (!data.good())
		{
			break;
		}

		std::cout << "First Name: " << person.getFirstName() << "\n";
		std::cout << "Last Name: " << person.getLastName() << "\n";
		std::cout << "Phone number: " << person.getNumber() << "\n";
		std::cout << "EGN: " << person.getEGN() << "\n\n";
	}
}