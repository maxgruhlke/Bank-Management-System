#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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

void User::loadExistingUsers(){
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

string User::findUser(string username){
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

bool User::createUser(string username, string password){
    string exists = findUser(username);   
    
    if(exists.empty()){
        User::numUsers++;
        
        ofstream outputFile("users.txt", ofstream::app);
        if(outputFile.is_open()){
            outputFile << "!" << username << "\n";
            outputFile << "@" << password << "\n";
        }
        return true;
    }

    return false;
}
