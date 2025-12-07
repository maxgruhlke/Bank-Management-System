#include "BankAccount.h"

BankAccount::BankAccount() {

}

BankAccount::BankAccount(string userParam, int accountIDParam) : user(userParam), accountID(accountIDParam){

}

BankAccount::~BankAccount() {

}

int BankAccount::getAccountType() {
    string userToFind = "./Users/" + user + "/account" + to_string(accountID) + ".txt";
    ifstream inputFile(userToFind);

    int accountType = 0;
    
    if (inputFile.is_open()) {    

        string line;

        while (getline(inputFile, line)) {
            if (line[0] == '!') {
                string formattedLine = line.erase(0, 1);
                accountType = stoi(formattedLine.erase(1, formattedLine.size()));
                break;
            }
        }
        inputFile.close();
    }
    else {
        cout << "unable to open file! at : " << userToFind << endl;
    }
    return accountType;
}

int BankAccount::getAccountNumber() {
    string userToFind = "./Users/" + user + "/account" + to_string(accountID) + ".txt";
    ifstream inputFile(userToFind);

    int accountNumber = 0;

    if (inputFile.is_open()) {

        string line;

        while (getline(inputFile, line)) {
            if (line[0] == '!') {
                string formattedLine = line.erase(0, 3);
                accountNumber = stoi(formattedLine);
                break;
            }
        }
        inputFile.close();
    }
    else {
        cout << "unable to open file! at : " << userToFind << endl;
    }
    return accountNumber;
}

int BankAccount::getAccountBalance() {
    string userToFind = "./Users/" + user + "/account" + to_string(accountID) + ".txt";
    ifstream inputFile(userToFind);

    int accountBalance = 0;

    if (inputFile.is_open()) {

        string line;

        while (getline(inputFile, line)) {
            if (line[0] == '@') {
                string formattedLine = line.erase(0, 1);
                accountBalance = stoi(formattedLine);
                break;
            }
        }
        inputFile.close();
    }
    else {
        cout << "unable to open file! at : " << userToFind << endl;
    }
    return accountBalance;
}

string BankAccount::getUser() {
    return user;
}