#ifndef USER_H
#define USER_H
#include <string>
#include "Person.h"
#include "BankAccount.h"
using namespace std;

class User : public Person {
private:
    int numAccounts;
    BankAccount* accounts;

public:
    static int numUsers;

    User(string username, string password);
    ~User();

    static bool createUser(string username, string password);
    string findPerson(string username) override;

    static void loadExistingUsers();
    
    static int getNumUsers(){
        return numUsers;
    }
};

#endif
