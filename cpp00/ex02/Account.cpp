#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
    _accountIndex = getNbAccounts();
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" <<_amount<<";created"<<std::endl;
    _nbAccounts++;
    _totalAmount += _amount;
};

Account::~Account()
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed"<<std::endl;
};

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()
{
    return _nbAccounts; 
};

int Account::getTotalAmount()
{
    return _totalAmount;
};

int Account::getNbDeposits()
{
    return _totalNbDeposits;
};

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
};

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:"<< getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
};

void Account::makeDeposit(int deposit)
{
    _amount += deposit;
};

bool Account::makeWithdrawal(int withdrawal)
{
    if((checkAmount() < withdrawal))
        return false;
    return true;
};

int Account::checkAmount() const
{
    return _amount;
};

void Account::displayStatus() const
{ 
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals;
};

void Account::_displayTimestamp()
{
    std::cout << "[19920104_091532]";
};