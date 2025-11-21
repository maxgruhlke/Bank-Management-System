#include <iostream>
#include <string>
#include "Person.cpp"
#include "BankAccount.cpp"

using namespace std;

class User : public Person{

    private:
    int userID;
    int numAccounts;
    BankAccount* accounts;
    public:
    User(int userID)
    {
        accounts=new BankAccount[numAccounts];
        //find user folder based on userID and fill info about user
    }
    ~User()
    {delete[] accounts;}
    int getNumAccounts()
    {return numAccounts;}
    int getUserID(){return userID;}
    BankAccount* getAccounts()
    {
        return accounts;
    }
    static int findUser(string username,string password)
    {
        return 0;//gives userid
    }
    
};

