#include "Contact.hpp"
#include <iomanip>

Contact::Contact() {}

std::string printWidth(std::string str, int width)
{
    if ((int)str.length() > width)
    {
        return str.substr(0, width - 1) + ".";
    }
    return str;
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
    return this->firstName;
}

std::string Contact::getLastName() const
{
    return this->lastName;
}

std::string Contact::getNickname() const
{
    return this->nickname;
}

std::string Contact::getPhoneNumber() const
{
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return this->darkestSecret;
}

void Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

void Contact::setNickname(std::string nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
    this->darkestSecret = darkestSecret;
}

void Contact::printContact() const
{
    std::cout << "|" << std::setw(10) << printWidth(this->firstName, 10) << "|" << std::setw(10) << printWidth(this->lastName, 10) << "|" << std::setw(10) << printWidth(this->nickname, 10) << "|" << std::endl;
}