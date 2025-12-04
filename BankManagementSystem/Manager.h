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

    bool isManager() const override {
        return true;
    }

    // any manager-specific functions you plan to add later
};

#endif
