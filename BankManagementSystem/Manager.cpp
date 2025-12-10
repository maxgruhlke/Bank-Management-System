
#include "Manager.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Manager can access all user data and transaction history
Manager::Manager(string username, string password) : Person(username, password){}

string Manager::findPerson(string username){
    ifstream inputFile("managers.txt");
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
        else if(line[0] == '@'){
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

void Manager::viewAllUsers(){
    ifstream inputFile("users.txt");
    if(!inputFile.is_open()){
        return;
    }

    string line;
    string fileUsername = "";
    string filePassword = "";

    BankAccount dummy = BankAccount();

    cout << "===== All Users =====" << endl;

    while(getline(inputFile, line)){
        if(line[0] == '!'){
            fileUsername = line.erase(0,1);
        }
        else if(line[0] == '@'){
            filePassword = line.erase(0,1);
            cout << "Username: " << fileUsername << endl;
            cout << "Password: " << filePassword << endl;
        }
    }
    cout << "Current Active Users : " + to_string(dummy.getCurrentAccounts()) << endl;
    cout << "=====================" << endl;
    inputFile.close();
}

void Manager::viewUserDetails(string username){
    ifstream inputFile("users.txt");
    if(!inputFile.is_open()){
        return;
    }

    string line;
    string fileUsername = "";
    string filePassword = "";

    while(getline(inputFile, line)){
        if(line[0] == '!'){
            fileUsername = line.erase(0,1);
        }
        else if(line[0] == '@'){
            filePassword = line.erase(0,1);
            if(fileUsername == username){
                cout << "===== User Details =====" << endl;
                cout << "Username: " << fileUsername << endl;
                cout << "Password: " << filePassword << endl;  
                cout << "========================" << endl;
                return;
            }
        }
    }
    inputFile.close();
    cout << "User not found." << endl;
}

void Manager::viewAllTransactions() {
    ifstream inputFile("users.txt");
    if(!inputFile.is_open()){
        cout << "Unable to open users.txt" << endl;
        return;
    }

    string line;
    string username = "";

    cout << "===== All Transactions =====" << endl;

    while(getline(inputFile, line)){
        if(line[0] == '!'){
            username = line.erase(0, 1);
        }
        else if(line[0] == '@'){
            string accountPath;
            for(int accountID = 0; ; accountID++) {
                accountPath = "Users/" + username + "/account" + to_string(accountID) + ".txt";
                if(!filesystem::exists(accountPath)) break;

                ifstream accountFile(accountPath);
                if(accountFile.is_open()){
                    string accountLine;
                    cout << "User: " << username << ", Account " << accountID << " Transactions:" << endl;
                    while(getline(accountFile, accountLine)){
                        if(accountLine[0] == '#'){
                            cout << accountLine << endl;
                        }
                    }
                    accountFile.close();
                    cout << "------------------------" << endl;
                }
            }
        }
    }

    cout << "============================" << endl;
    inputFile.close();
}

void Manager::viewUserTransactions(string username){
    string accountPath;
    bool userExists = false;

    for(int accountID = 0; ; accountID++) {
        accountPath = "Users/" + username + "/account" + to_string(accountID) + ".txt";
        if(!filesystem::exists(accountPath)) break;

        userExists = true;

        ifstream accountFile(accountPath);
        if(accountFile.is_open()){
            string accountLine;
            cout << "User: " << username << ", Account " << accountID << " Transactions:" << endl;
            while(getline(accountFile, accountLine)){
                if(accountLine[0] == '#'){
                    cout << accountLine << endl;
                }
            }
            accountFile.close();
            cout << "------------------------" << endl;
        }
    }

    if(!userExists){
        cout << "User not found or has no accounts." << endl;
    }
}
