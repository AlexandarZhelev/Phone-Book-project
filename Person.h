#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

namespace N
{
	class Person
	{
	private:
		std::string firstName;
		std::string lastName;
		std::string number;
		std::string EGN;

	public:
		Person()
		{
			init();
		}

		void init()
		{
			firstName = "";
			lastName = "";
			number = "";
			EGN = "";
		}

		std::string getFirstName() const
		{
			return firstName;
		}

		std::string getLastName() const
		{
			return lastName;
		}

		std::string getNumber() const
		{
			return number;
		}

		std::string getEGN() const
		{
			return EGN;
		}

		void setFirstName(const std::string& fn)
		{
			firstName = fn;
		}

		void setLastName(const std::string& ln)
		{
			lastName = ln;
		}

		void setNumber(const std::string& num)
		{
			number = num;
		}

		void setEGN(const std::string& pin)
		{
			EGN = pin;
		}

		friend std::ostream & operator << (std::ostream &out, const Person & obj)
		{
			out << obj.getFirstName() << "\n" << obj.getLastName() << "\n" << obj.getNumber() << "\n" << obj.getEGN() << std::endl;

			return out;
		}

		friend std::istream & operator >> (std::istream &in, Person &obj)
		{
			std::string firstName1;
			std::string lastName1;
			std::string number1;
			std::string EGN1;

			in >> firstName1;
			in >> lastName1;
			in >> number1;
			in >> EGN1;

			obj.setFirstName(firstName1);
			obj.setLastName(lastName1);
			obj.setNumber(number1);
			obj.setEGN(EGN1);

			return in;
		}

		void addRecord();
		void SearchRecord();
		void ShowRecords();
	};
}