#include <iostream>
#include <stdlib.h> //library for "system CLS"

#include "pch.h"
#include "Person.h"

using namespace N;

int main()
{
	int choice;
	Person obj;

	do
	{
		std::cout << "Please enter your choice." << "\n\n";

		std::cout << "1. Add record " << "\n";
		std::cout << "2. Search record " << "\n";
		std::cout << "3. Show all records " << "\n";
		std::cout << "4. Exit " << "\n";

		//check if the entered value is a number
		while (!(std::cin >> choice))
		{
			std::cout << "\n A number must be entered!" << "\n";
			std::cin.clear();
			std::cin.ignore();
			
			break;
		}

		system("CLS"); // clear screen

		switch (choice)
		{
		case 1:
			obj.addRecord();
			break;

		case 2:
			obj.SearchRecord();
			break;

		case 3:
			obj.ShowRecords();
			break;

		case 4:
			return 0;
			break;

		default:
			std::cout << "Invalid choice!" << "\n";
			std::cout << "Please try again!" << "\n";
		}
	}

	while (choice != 4);

	system("pause");
	return 0;
}