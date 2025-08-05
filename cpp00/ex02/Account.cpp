#include "Account.hpp"
#include <iostream>
#include <ctime>

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
    int p_amount = checkAmount();
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits ++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << checkAmount() << ";nb_deposits:" << _nbDeposits << std::endl;
};

bool Account::makeWithdrawal(int withdrawal)
{
    int p_amount = checkAmount();
    _displayTimestamp();
    if((checkAmount() < withdrawal))
    {
        std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount = _amount - withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals ++;
    _totalAmount -= withdrawal;
    std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal << ";amount:" << checkAmount() << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
};

int Account::checkAmount() const
{
    return _amount;
};

void Account::displayStatus() const
{ 
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
};

void Account::_displayTimestamp()
{
    std::time_t now = std::time(NULL);
    std::tm *time_info = std::localtime(&now);
    char buffer[32];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", time_info);
    std::cout <<"[" << buffer << "]";
};