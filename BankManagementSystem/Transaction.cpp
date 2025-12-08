#include "Transaction.h"

Transaction::Transaction(BankAccount accountParam) : account(accountParam) {

}

Transaction::~Transaction() {

}

bool Transaction::withdraw(double amount) {
	string accountPath = "Users/" + account.getUser() + "/account" + to_string(account.getAccountType()) + ".txt";

	int currentAccountType = account.getAccountType();
	int currentBalance = account.getAccountBalance();
	int currentTransationQuantity = getTransactionQuantity();
	vector<string> currentTransactionHistory = getTransactionHistory();

	if ((currentBalance - amount) < 0) {
		return false;
	}

	std::remove(accountPath.c_str());

	ofstream accountFile(accountPath, ofstream::app);

	if (accountFile.is_open()) {
		accountFile << "!" << to_string(currentAccountType) << to_string(currentTransationQuantity + 1) << to_string(account.getAccountNumber()) << "\n";
		accountFile << "@" << to_string(currentBalance - amount) << "\n";

		for (string transaction : currentTransactionHistory) {
			accountFile << transaction << "\n";
		}

		accountFile << "#-" + to_string(amount) << "\n";
	}

	return true;
}

void Transaction::deposit(double amount) {
	string accountPath = "Users/" + account.getUser() + "/account" + to_string(account.getAccountType()) + ".txt";

	int currentAccountType = account.getAccountType();
	int currentBalance = account.getAccountBalance();
	int currentTransationQuantity = getTransactionQuantity();
	vector<string> currentTransactionHistory = getTransactionHistory();

	std::remove(accountPath.c_str());

    ofstream accountFile(accountPath, ofstream::app);
	
	if (accountFile.is_open()) {
		accountFile << "!" << to_string(currentAccountType) << to_string(currentTransationQuantity + 1) << to_string(account.getAccountNumber()) << "\n";
		accountFile << "@" << to_string(currentBalance + amount) << "\n";

		for (string transaction : currentTransactionHistory) {
			accountFile << transaction << "\n";
		}

		accountFile << "#+" + to_string(amount) << "\n";
	}
}

int Transaction::getTransactionQuantity() {
	string userToFind = "./Users/" + account.getUser() + "/account" + to_string(account.getAccountType()) + ".txt";
	int transactionQuantity = 0;

	ifstream inputFile(userToFind);
	
	if (inputFile.is_open()) {
		string line;

		while (getline(inputFile, line)) {
			if (line[0] == '!') {
				string formattedLine = line.erase(0, 2);
				transactionQuantity = stoi(formattedLine.erase(1, formattedLine.size()));
			}
		}
	}
	return transactionQuantity;
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
	}

	return transactionHistory;
}