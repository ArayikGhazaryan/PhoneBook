#pragma once

#include <string>
#include <vector>

class PhoneBookData {
public:
    std::string firstName;
    std::string lastName;
    std::string separator;
    std::string phoneNumber;
};

class PhoneBook {
private:
    std::vector<PhoneBookData> _phoneBookData;
public:
    PhoneBook(PhoneBookData phoneBookData);
    PhoneBook();

    void GetDataFromFile(std::string path);
    void ValidateAllData();
    void SortingData(std::string sortOrder, std::string Criteria);
    void SortByName(std::string sortOrder);
    void SortBySurname(std::string sortOrder);
    void SortByPhoneNumber(std::string sortOrder);
    std::string CheckStringsAscending(const std::string& first, const std::string& second);
    std::string CheckStringsDescending(const std::string& first, const std::string& second);
    std::string MinPhoneNumAscending(const std::string& first, const std::string& second);
    std::string MinPhoneNumDescending(const std::string& first, const std::string& second);
    void Print();
};