#include <iostream>
#include <string>
#include "Transaction.cpp"
using namespace std;

class BankAccount{
private:

public:
BankAccount(){}
BankAccount(int userID, int Name)
{
    //maybe based on the userID and name of the account we could find its file location
    //possibly randomUser folder will have userID.txt that will have a text file of account names
    //then we iterate over these names that have corrlating folders with transaction files in them.
}
};
