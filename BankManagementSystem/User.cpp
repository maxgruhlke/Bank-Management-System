#include <iostream>
#include <string>
#include "Person.cpp"
#include "BankAccount.cpp"

using namespace std;

class User : public Person{

    private:
    int numAccounts;
    string username;
    BankAccount* accounts;
    public:
    static int numUsers;

    User(string username, string password)
    {
        string pass=User::findUser(username);
        if(pass==password)
        {
            

        }
       
    }
    ~User()
    {delete[] accounts;}

    static bool createUser(string username, string password)
    {
     string exists=findUser(username);   
        if(exists.empty())
        {
            User::numUsers++;
            //add user to users.txt
            return true;
        }
        return false;
    }
    static string findUser(string username)
    {
       // return password for user
       return "";
    }
    static int getNumUsers()
    {
        return numUsers;
    }
};

