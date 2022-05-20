#include <iostream>
#include <fstream>
#include <cstdlib> // exit
#include <vector>
#include <string>
#include <sstream>

#include "phonebook.h"

using namespace std;



PhoneBook::PhoneBook(PhoneBookData phoneBookData) : _phoneBookData{ phoneBookData } {};

PhoneBook::PhoneBook() {};

void simple_tokenizer(const string& s, std::vector<std::string>& words)
{
	stringstream ss(s);
	string word;
	int numberOfWords = 0;
	while (ss >> word)
	{
		words.push_back(word);
		numberOfWords++;
	}
}

void PhoneBook::GetDataFromFile(std::string path)
{
	std::string line;
	std::vector<std::string> words{};
	std::ifstream input_file(path);
	if (!input_file.is_open())
	{
		std::cerr << "Could not open the file - '" << path << "'" << std::endl;
		exit(1);
	}
	while (getline(input_file, line))
	{
		PhoneBookData data;
		std::vector<std::string> words{ };
		size_t pos = 0;
		simple_tokenizer(line, words);

		if (words.size() == 4)
		{
			for (auto& i : words)
			{
				data.firstName = words[0];
				data.lastName = words[1];
				data.separator = words[2];
				data.phoneNumber = words[3];
			}
			_phoneBookData.push_back(data);
		}
		else if (words.size() == 3)
		{
			data.firstName = words[0];
			data.lastName = "";
			data.separator = words[1];
			data.phoneNumber = words[2];
		}
		words.clear();
	}
}

void PhoneBook::ValidateAllData() {
	int count = 1;
	for (auto& i : _phoneBookData)
	{
		if (i.separator != ":" && i.separator != "-" && i.phoneNumber.size() != 9)
		{
			cout << "line" << count << ": phone number should be with 9 digits, the separator should be `:` or `-`." << endl;
		}
		else if (i.separator != ":" && i.separator != "-")
		{
			cout << "line" << count << ": separator should be `:` or `-`." << endl;
		}
		else if (i.phoneNumber.size() != 9)
		{
			cout << "line" << count << ": phone number should be 9 digits." << endl;
		}
		++count;
	}
}

void PhoneBook::SortingData(std::string sortOrder, std::string criteria)
{
	std::cout << sortOrder << " " << criteria << std::endl;
	if (criteria == "Name")
	{
		SortByName(sortOrder);
	}
	else if (criteria == "Surname")
	{
		SortBySurname(sortOrder);
	}
	else if (criteria == "PhoneNumberCode")
	{
		SortByPhoneNumber(sortOrder);
	}
}

void PhoneBook::SortByName(std::string sortOrder)
{
	bool isSorted = true;
	while (isSorted)
	{
		isSorted = false;
		for (int i = 0; i < _phoneBookData.size() - 1; ++i)
		{
			if (sortOrder == "Ascending")
			{
				if (CheckStringsAscending(_phoneBookData[i].firstName, _phoneBookData[i + 1].firstName) == _phoneBookData[i + 1].firstName)
				{
					swap(_phoneBookData[i], _phoneBookData[i + 1]);
					isSorted = true;
				}
			}
			else if (sortOrder == "Descending")
			{
				if (CheckStringsDescending(_phoneBookData[i].firstName, _phoneBookData[i + 1].firstName) == _phoneBookData[i + 1].firstName)
				{
					swap(_phoneBookData[i], _phoneBookData[i + 1]);
					isSorted = true;
				}
			}
		}
	}

}


void PhoneBook::SortBySurname(std::string sortOrder)
{
	bool isSorted = true;
	while (isSorted)
	{
		isSorted = false;
		for (int i = 0; i < _phoneBookData.size() - 1; ++i)
		{
			if (sortOrder == "Ascending")
			{
				if (CheckStringsAscending(_phoneBookData[i].lastName, _phoneBookData[i + 1].lastName) == _phoneBookData[i + 1].lastName)
				{
					swap(_phoneBookData[i], _phoneBookData[i + 1]);
					isSorted = true;
				}
			}
			else if (sortOrder == "Descending")
			{
				if (CheckStringsDescending(_phoneBookData[i].lastName, _phoneBookData[i + 1].lastName) == _phoneBookData[i + 1].lastName)
				{
					swap(_phoneBookData[i], _phoneBookData[i + 1]);
					isSorted = true;
				}
			}
		}
	}
}

void PhoneBook::SortByPhoneNumber(std::string sortOrder)
{
	bool isSorted = true;
	while (isSorted)
	{
		isSorted = false;
		for (int i = 0; i < _phoneBookData.size() - 1; ++i)
		{
			if (sortOrder == "Ascending")
			{
				if (MinPhoneNumAscending(_phoneBookData[i].phoneNumber, _phoneBookData[i + 1].phoneNumber) == _phoneBookData[i + 1].phoneNumber)
				{
					swap(_phoneBookData[i], _phoneBookData[i + 1]);
					isSorted = true;
				}
			}
			else if (sortOrder == "Descending")
			{
				if (MinPhoneNumDescending(_phoneBookData[i].phoneNumber, _phoneBookData[i + 1].phoneNumber) == _phoneBookData[i + 1].phoneNumber)
				{
					swap(_phoneBookData[i], _phoneBookData[i + 1]);
					isSorted = true;
				}
			}
		}
	}
}


std::string PhoneBook::CheckStringsAscending(const std::string& first, const std::string& second)
{
	for (int i = 0; i < min(first.size(), second.size()); ++i) 
	{
		if (first[i] < second[i])
		{
			return first;
		}
		else if (first[i] > second[i])
		{
			return second;
		}
	}
	return "";
}

std::string PhoneBook::CheckStringsDescending(const std::string& first, const std::string& second)
{
	for (int i = 0; i < min(first.size(), second.size()); ++i) 
	{
		if (first[i] > second[i])
		{
			return first;
		}
		else if (first[i] < second[i])
		{
			return second;
		}
	}
	return "";
}

std::string PhoneBook::MinPhoneNumAscending(const std::string& first, const std::string& second)
{
	for (int i = 0; i < 3; ++i)
	{
		if (first[i] < second[i])
		{
			return first;
		}
		else if (first[i] > second[i])
		{
			return second;
		}
	}
	return "";
}

std::string PhoneBook::MinPhoneNumDescending(const std::string& first, const std::string& second)
{
	for (int i = 0; i < 3; ++i)
	{
		if (first[i] > second[i])
		{
			return first;
		}
		else if (first[i] < second[i])
		{
			return second;
		}
	}
	return "";
}

void PhoneBook::Print()
{
	for (auto& i : _phoneBookData)
	{
		std::cout << i.firstName << " " << i.lastName << " " << i.separator << " " << i.phoneNumber << std::endl;
	}
}