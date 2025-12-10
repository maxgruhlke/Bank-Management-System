#include "User.h"

int User::numUsers = 0;

User::User(string username, string password) : Person(username, password){
}

User::~User(){
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
            outputFile.close();
        }
        if (!filesystem::exists("Users/")) {
            filesystem::create_directory("Users/");
        }
        if (!filesystem::exists("Users/" + username)) {
            filesystem::create_directory("Users/" + username);
        }

        BankAccount dummy = BankAccount(username, 0);

        dummy.incrementAccountNumber();
            
        ofstream checkingAccount ("Users/" + username + "/account0.txt", ofstream::app);
        if (checkingAccount.is_open()) {
            checkingAccount << "!0" + to_string(dummy.getLastAccountNumber()) << "\n";
            checkingAccount << "@0.00" << "\n";
            checkingAccount.close();
        }

        dummy.incrementAccountNumber();

        ofstream savingsAccount("Users/" + username + "/account1.txt", ofstream::app);
        if (savingsAccount.is_open()) {
            savingsAccount << "!1" + to_string(dummy.getLastAccountNumber()) << "\n";
            savingsAccount << "@0.00" << "\n";
            savingsAccount.close();
        }

        return true;
    }

    return false;
}
