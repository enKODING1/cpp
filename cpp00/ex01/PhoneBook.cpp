#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <sstream>

PhoneBook::PhoneBook()
{
  index = 0;
  nbContacts = 0;
}

void PhoneBook::addContact(Contact contact)
{
    if (index < 8)
    {
      contacts[index] = contact;
      index++;
      nbContacts++;
    }
    else
    {
      index = 0;
      contacts[index] = contact;
      index++;
    }
}

void PhoneBook::searchContact()
{
 std::string input;
  int index;

  showPhonebook();
  std::cout << "Enter the index of the contact to search: ";
  std::getline(std::cin, input);

  std::stringstream ss(input);
  if ( (ss >> index) && (ss.eof()) )
  {
    if (index >= 0 && index < nbContacts)
      contacts[index].printContact(index);
    else
      std::cout << "Error: Invalid index. Out of range." << std::endl;
  }
  else
    std::cout << "Error: Invalid input. Please enter a number." << std::endl;
}

void PhoneBook::showPhonebook()
{
  for (int i = 0; i < nbContacts; ++i)
  {
    contacts[i].printContact(i);
  }
}