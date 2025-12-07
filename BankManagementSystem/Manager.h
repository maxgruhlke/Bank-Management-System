#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include "Person.h"
using namespace std;

class Manager : public Person {
public:
    Manager(string username, string password);
    ~Manager(){}

    static string findManager(string username);

    static void viewAllUsers();
    static void viewUserDetails(string username);
    static void viewAllTransactions();
    static void viewUserTransactions(string username);

    bool isManager() const override {
        return true;
    }
};

#endif
