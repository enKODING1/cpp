#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int index;
        int nbContacts;
    public:
      PhoneBook();
      void addContact(Contact contact);
      void searchContact() ;
      void showPhonebook();
};
#endif