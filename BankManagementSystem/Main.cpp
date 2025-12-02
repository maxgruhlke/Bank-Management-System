#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <cctype>
#include <stack>
//#include "Person.cpp"
#include "User.cpp"
#include "Manager.cpp"

using namespace std;
Person* currentPerson;
string toLower(string s)
{
transform(s.begin(), s.end(), s.begin(),
    [](unsigned char c){ return tolower(c); });
return s;
}


string userLogin()
{
    int option=0;
    int userID=-1;
    do//User can choose to regular login/create account/manager login/exit
    {
        string userLabel="| Username: ";
        string passwordLabel="| Password: ";
        string username="";
        string password="";
        cout<<" "<<setw(25)<<setfill('_')<<""<<endl;
        cout<<setw(25)<<left<<setfill(' ')<<"|"<<"|"<<endl;
        cout<<setw(25)<<left<<"| Type back/exit anytime."<<"|"<<endl;
        cout<<userLabel;
        cin>>username;
        if(toLower(username)=="back")
        {
            return "back";
        }
        else if(toLower(username)=="exit")
        {
            return "exit";
        }
        cout<<passwordLabel;
        cin>>password;
        if(toLower(password)=="back")
        {
            return "back";
        }
        else if(toLower(password)=="exit")
        {
            return "exit";
        }
        cout<<"|"<<setw(19)<<left<<setfill('_')<<""<<"|"<<endl;
        cin>>option;
        userID=User::findUser(username,password);
        //returns -1 if login wrong else returns account num
        if(userID!=-1)
        {
            currentPerson=new User(userID);
            break;
        }
    }while(true);
    
    return "bankAccount";
}
void printAccount(int accountNum)
{
    //currentuser.accounts[accountNum].printAccount()
    //prints all account information can't really do anything on this page but view the info
    //maybe add a cin asking user to enter when done viewing.

}
string bankAccount()
{
    int numOptions=4;
    int option=0;
    User* user = dynamic_cast<User*>(currentPerson);
    do
    {
        cout<<" "<<setw(25)<<setfill('_')<<""<<endl;
        cout<<setw(25)<<left<<setfill(' ')<<"|"<<"|"<<endl;
        cout<<setw(25)<<left<<"| 1. Transaction"<<"|"<<endl;
        cout<<setw(25)<<left<<"| 2. Create Account"<<"|"<<endl;
       // numOptions+=user->getNumAccounts();
       // int numAccounts=user->getNumAccounts();
       // const BankAccount* accounts=user->getAccounts();
       /*for( BankAccount account : accounts)
        {

        }
       
       */ 
        cout<<setw(25)<<left<<"| 3...6. AccountName: $456.52"<<"|"<<endl;
        cout<<setw(25)<<left<<"| 7. back"<<"|"<<endl;
        cout<<setw(25)<<left<<"| 8. exit"<<"|"<<endl;
        cout<<"|"<<setw(19)<<left<<setfill('_')<<""<<"|"<<endl;
    if(option==1){return "transaction";}
    else if(option==2){return "createBankAccount";}
    else if(option==numOptions-1){return "back";}
    else if(option==numOptions){return "exit";}
    else{printAccount(option-4);}
    }
    while(true);

}
string transaction(){return "";}
string createBankAccount(){return "";}
string createAccount()
{
    string username;
    string password;
    const int numUsers=User::getNumUsers();
    int currentUsers;
    do
    {
        cout<<"give me the username"<<endl;
        cin>>username;
        cout<<"give me the password"<<endl;
        cin>>password;
        User::createUser(username,password);
        currentUsers=User::getNumUsers();
       
    } while (numUsers==currentUsers);
    

    
    
}
string managerLogin(){return "";}


string homePage()
{
    int option=0;
    do//User can choose to regular login/create account/manager login/exit
    {
        cout<<" "<<setw(19)<<setfill('_')<<""<<endl;
        cout<<setw(20)<<left<<setfill(' ')<<"|"<<"|"<<endl;
        cout<<setw(20)<<left<<"| 1. User Login"<<"|"<<endl;
        cout<<setw(20)<<left<<"| 2. Create Account"<<"|"<<endl;
        cout<<setw(20)<<left<<"| 3. Manager Login"<<"|"<<endl;
        cout<<setw(20)<<left<<"| 4. Exit"<<"|"<<endl;
        cout<<"|"<<setw(19)<<left<<setfill('_')<<""<<"|"<<endl;
        cin>>option;
    }while(option>4||option<1);
    string method="";
    switch(option)
    {
        case 1://user login
            method="userLogin";
            break; 
        case 2://create account
        method="createAccount";
        break;
        case 3://manager login
        method="managerLogin";
        break;
        case 4:
        method="exit";
        default:
        break;
    }
return method;

}
void run()
{
    
    unordered_map<string, function<string()>> pages = {
        {"homePage", homePage},
        {"userLogin", userLogin},
        {"bankAccount",bankAccount},
        {"createAccount",createAccount},
        {"managerLogin",managerLogin},
        {"createBankAccount",createBankAccount},
        {"transaction",transaction}
    };
    stack<string>pageStack;
    string currentPage="homePage";
    
    do
    {
        pageStack.push(currentPage);
        currentPage = pages[currentPage]();
    if(currentPage=="back")
    {
        pageStack.pop();
        currentPage=pageStack.top();
    }
    else if(currentPage=="exit")
    {
        return;
    }
    }while(pageStack.size()!=0);
    
}


int main(){
run();
delete currentPerson;
    /*
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
    }*/

}
