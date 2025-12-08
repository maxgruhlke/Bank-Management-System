#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

//abstract class for user and manager class
class Person {
protected:
    string username;
    string password;

public:
    Person(string user, string pass) : username(user), password(pass){}

    virtual ~Person(){}

    string getUsername() const{
        return username;
    }

    string getPassword() const{
        return password;
    }

    virtual string findPerson(string username) = 0;
};
#endif
