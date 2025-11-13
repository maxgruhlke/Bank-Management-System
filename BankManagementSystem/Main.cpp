#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    
    ofstream outputFile("managers.txt", ofstream::app); //create or open a file for writing

    if(outputFile.is_open()){
        outputFile << "User_name#: admin" << endl;
        outputFile << "Pass: admin" << endl;

        outputFile.close();
        cout << "Data written to file successfully" << endl;
    }
    else{
        cout << "Unable to open the file for writing" << endl;
    }

    ifstream inputFile("example.txt"); //open file for reading

    if(inputFile.is_open()){
        cout << "Reading data from the file:" << endl;

        string line;
        while(getline(inputFile, line)){
            cout << line << endl;
        }

        inputFile.close();
    }
    else{
        cout << "Unable to open the file for reading" << endl;
    }
}