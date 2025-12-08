#include "User.h"

int User::numUsers = 0;

User::User(string username, string password) : Person(username, password){
    numAccounts = 0;
    accounts = nullptr;
}

User::~User(){
    if(accounts != nullptr){
        delete[] accounts;
    }
}

void User::loadExistingUsers() {
    ifstream inputFile("users.txt");
    if(!inputFile.is_open()){
        return;
    }

    string line;
    while(getline(inputFile, line)){
        if(line[0] == '!'){
            numUsers++;
        }
    }
    inputFile.close();
}

string User::findPerson(string username){
    ifstream inputFile("users.txt");
    if(!inputFile.is_open()){
        return "";
    }

    string line;
    string fileUsername = "";
    string filePassword = "";

    while(getline(inputFile, line)){
        if(line[0] == '!'){
            fileUsername = line.erase(0,1);
        }
        else if(line[0] == '@') {
            filePassword = line.erase(0, 1);
            if(fileUsername == username){
                inputFile.close();
                return filePassword;
            }
        }
    }
    inputFile.close();
    return "";
}

bool User::createUser(string username, string password) {
    User temp("", ""); 
    string exists = temp.findPerson(username);
  
    
    if (exists.empty()) {
        User::numUsers++;
        
        ofstream outputFile("users.txt", ofstream::app);
        if(outputFile.is_open()){
            outputFile << "!" << username << "\n";
            outputFile << "@" << password << "\n";
        }

        if (!filesystem::exists("Users/" + username)) {
            filesystem::create_directory("Users/" + username);
        }

        BankAccount dummy = BankAccount(username, 0);

        dummy.incrementTotalAccounts();

        ofstream checkingAccount ("Users/" + username + "/account0.txt", ofstream::app);
        if (checkingAccount.is_open()) {
            checkingAccount << "!00" + to_string(dummy.getTotalAccounts()) << "\n";
            checkingAccount << "@0.00" << "\n";
        }

        dummy.incrementTotalAccounts();

        ofstream savingsAccount("Users/" + username + "/account1.txt", ofstream::app);
        if (savingsAccount.is_open()) {
            savingsAccount << "!10" + to_string(dummy.getTotalAccounts()) << "\n";
            savingsAccount << "@0.00" << "\n";
        }

        return true;
    }

    return false;
}
