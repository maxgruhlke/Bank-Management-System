#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "BankAccount.h"
#include <cstdio>
#include <vector>

using namespace std;

class Transaction {
	private:
		BankAccount account;
	public:
		Transaction(BankAccount accountParam);
		~Transaction();
		bool withdraw(double amount);
		void deposit(double amount);
		vector<string> getTransactionHistory();
};
#endif