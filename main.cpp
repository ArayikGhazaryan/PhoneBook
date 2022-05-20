#include <iostream>

#include "phonebook.h"

int main() 
{
    PhoneBook pBook;
    std::string sortOrder;
    std::string sortCriteria;
    std::string filePath;
    std::cout << "File Path - ";
    std::cin >> filePath;
    pBook.GetDataFromFile(filePath);

    std::cout << "“Please choose an ordering to sort: “Ascending” or “Descending”." << std::endl;
    std::cin >> sortOrder;
    std::cout << "“Please choose criteria: “Name”, “Surname” or “PhoneNumberCode”." << std::endl;
    std::cin >> sortCriteria;
    pBook.SortingData(sortOrder, sortCriteria);
    std::cout << "/n";
    std::cout << "File Structure:" << std::endl;
    pBook.Print();
    std::cout << "/n";
    std::cout << "Validations:" << std::endl;
    pBook.ValidateAllData();
    return 0;
}