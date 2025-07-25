#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
  this->index = 0;
}

void PhoneBook::addContact(Contact contact)
{
    if (this->index < 8)
    {
      this->contacts[this->index] = contact;
      this->index++;
    }
    else
    {
      this->index = 0;
      this->contacts[this->index] = contact;
      this->index++;
    }
}

void PhoneBook::searchContact()
{
  std::cout << "Enter the index of the contact to search: ";
  int index;
  std::cin >> index;
  if (std::cin.fail())
  {
    std::cin.clear();
    std::cout << "Invalid index" << std::endl;
    return;
  }
  if (index >= 0 && index < 8)
  {
    this->contacts[index].printContact();
  }
  else
  {
    std::cout << "Invalid index" << std::endl;
  }
}
