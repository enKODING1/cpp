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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

void PhoneBook::printContact(int index) const
{
  std::cout << "Contact " << index << std::endl;
  std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
  std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
  std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
  std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
  std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
}
