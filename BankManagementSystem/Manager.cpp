
#include <iostream>
#include <string>
#include "Person.cpp"
using namespace std;

//Manager can access all user data and transaction history
class Manager : public Person{
static int findUser(string username,string password)
    {
        return 0;//gives userid
    }
};
