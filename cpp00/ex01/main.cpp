#include "PhoneBook.hpp"
#include "Contact.hpp"

bool hasOnlySpace(std::string str)
{
  if (!str.length())
    return true;
  for (std::size_t i = 0; i < str.length(); ++i)
  {
    char c = str[i];
    if (!std::isspace(c))
      return false;
  }
  return true;
}

int main()
{
  PhoneBook phoneBook;
  std::string command;
  while (true)
  {
    std::cout << "Enter a command: ";
    std::getline(std::cin, command);
    if (command == "ADD")
    {
      std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
      std::cout << "Enter the first name: ";
      std::getline(std::cin, firstName);
      std::cout << "Enter the last name: ";
      std::getline(std::cin, lastName);
      std::cout << "Enter the nickname: ";
      std::getline(std::cin, nickname);
      std::cout << "Enter the phone number: ";
      std::getline(std::cin, phoneNumber);
      std::cout << "Enter the darkest secret: ";
      std::getline(std::cin, darkestSecret);
      if (hasOnlySpace(firstName) || hasOnlySpace(lastName) || hasOnlySpace(nickname) || hasOnlySpace(phoneNumber) || hasOnlySpace(darkestSecret))
      {
        std::cout << "blank not allow" << std::endl;
        continue;
      }
      Contact contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
      phoneBook.addContact(contact);
      continue;
    }
    else if (command == "SEARCH")
    {
      // 인덱스 입력시 엔터 입력하면 멈춤
      phoneBook.searchContact();
    }
    else if (command == "EXIT")
    {
      break;
    }
    else
    {
      std::cout << "Commands: SEARCH, ADD, EXIT " << std::endl;
    }
  }
  return 0;
}