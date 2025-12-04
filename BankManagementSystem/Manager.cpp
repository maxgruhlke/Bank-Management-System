
#include "Manager.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Manager can access all user data and transaction history
Manager::Manager(string username, string password) : Person(username, password){}

string Manager::findManager(string username){
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
                return filePassword;
            }
        }
    }

    return "";
}
