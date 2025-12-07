#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class BankAccount {
	private:
		string user;
		int accountID;
	public:
		BankAccount();
		BankAccount(string userParam, int accountIDParam);
		~BankAccount();
		int getAccountType();
		int getAccountNumber();
		int getAccountBalance();
		string getUser();
};
#endif