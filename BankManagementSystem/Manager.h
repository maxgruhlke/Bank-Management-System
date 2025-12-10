#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include "Person.h"
#include "BankAccount.h"
using namespace std;

class Manager : public Person {
public:
    Manager(string username, string password);
    ~Manager(){}

    string findPerson(string username) override;

    static void viewAllUsers();
    static void viewUserDetails(string username);
    static void viewAllTransactions();
    static void viewUserTransactions(string username);
};

#endif
