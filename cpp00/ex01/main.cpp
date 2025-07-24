#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
  PhoneBook phoneBook;
  std::string command;
  while (true)
  {
    std::cout << "Enter a command: ";
    std::cin >> command;
    if (command == "ADD")
    {
      std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
      std::cout << "Enter the first name: ";
      std::cin >> firstName;
      std::cout << "Enter the last name: ";
      std::cin >> lastName;
      std::cout << "Enter the nickname: ";
      std::cin >> nickname;
      std::cout << "Enter the phone number: ";
      std::cin >> phoneNumber;
      std::cout << "Enter the darkest secret: ";
      std::cin >> darkestSecret;
      Contact contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
      phoneBook.addContact(contact);
    }
    else if (command == "SEARCH")
    {
      phoneBook.searchContact();
    }
    else if (command == "EXIT")
    {
      break;
    }
    else
    {
      std::cout << "Invalid command" << std::endl;
    }
  }
  return 0;
}