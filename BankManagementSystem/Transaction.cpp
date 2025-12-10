#include "Transaction.h"

Transaction::Transaction(BankAccount accountParam) : account(accountParam) {

}

Transaction::~Transaction() {

}

bool Transaction::withdraw(double amount) {
	string accountPath = "Users/" + account.getUser() + "/account" + to_string(account.getAccountType()) + ".txt";

	int currentAccountType = account.getAccountType();
	double currentBalance = account.getAccountBalance();
	int currentAccountNumber = account.getAccountNumber();
	vector<string> currentTransactionHistory = getTransactionHistory();

	if ((currentBalance - amount) < 0) {
		return false;
	}

	std::remove(accountPath.c_str());

	ofstream accountFile(accountPath, ofstream::app);

	if (accountFile.is_open()) {
		accountFile << "!" << to_string(currentAccountType) << to_string(currentAccountNumber) << "\n";
		accountFile << "@" << to_string(currentBalance - amount) << "\n";

		for (string transaction : currentTransactionHistory) {
			accountFile << transaction << "\n";
		}

		accountFile << "#-" <<fixed<<setprecision(2)<< amount << "\n";
		accountFile.close();
	}

	return true;
}

void Transaction::deposit(double amount) {
	string accountPath = "Users/" + account.getUser() + "/account" + to_string(account.getAccountType()) + ".txt";

	int currentAccountType = account.getAccountType();
	double currentBalance = account.getAccountBalance();
	int currentAccountNumber = account.getAccountNumber();
	vector<string> currentTransactionHistory = getTransactionHistory();

	std::remove(accountPath.c_str());

    ofstream accountFile(accountPath, ofstream::app);
	
	if (accountFile.is_open()) {
		accountFile << "!" << to_string(currentAccountType) << to_string(currentAccountNumber) << "\n";
		accountFile << "@" << to_string(currentBalance + amount) << "\n";

		for (string transaction : currentTransactionHistory) {
			accountFile << transaction << "\n";
		}

		accountFile << "#+" <<fixed<<setprecision(2)<< amount << "\n";
		accountFile.close();
	}
}

vector<string> Transaction::getTransactionHistory() {
	string userToFind = "./Users/" + account.getUser() + "/account" + to_string(account.getAccountType()) + ".txt";
	vector<string> transactionHistory = vector<string>();

	ifstream inputFile(userToFind);

	if (inputFile.is_open()) {
		string line;

		while (getline(inputFile, line)) {
			if (line[0] == '#') {
				transactionHistory.push_back(line);
			}
		}
		inputFile.close();
	}

	return transactionHistory;
}