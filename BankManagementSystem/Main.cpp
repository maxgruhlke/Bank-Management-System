#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <cctype>
#include <stack>

#include "Transaction.h"
#include "BankAccount.h"
#include "User.h"
#include "Manager.h"

using namespace std;
Person* currentPerson;
int currentaccount=0; 
string toLower(string s)
{
transform(s.begin(), s.end(), s.begin(),
    [](unsigned char c){ return tolower(c); });
return s;
}

string userLogin() {
    int option = 0;
    while(true){
        string userLabel = "| Username: ";
        string passwordLabel = "| Password: ";
        string username = "";
        string password = "";

        cout << " " << setw(25) << setfill('_') << "" << endl;
        cout << setw(25) << left << setfill(' ') << "|" << "|" << endl;
        cout << setw(25) << left << "| Type back/exit anytime." << "|" << endl;

        bool foundUsername = false;
        bool foundPassword = false;
        string currentUser = "";

        do {
            cout << userLabel;
            cin >> username;

            if (toLower(username) == "back") {
                return "back";
              //  break;
            }
            if (toLower(username) == "exit") {
                return "exit";
             //   break;
            }

            string pass = User::findUser(username);

            if (!pass.empty()){
                foundUsername = true;
                currentUser = username;
            }
            else {
                cout << "Username not found in system!" << endl;
            }

        } while(!foundUsername);

        do{
            cout << passwordLabel;
            cin >> password;

            if (toLower(password) == "back") {
                return "back";
              //  break;
            }
            if (toLower(password) == "exit") {
                return "exit";
              //  break;
            }

            string correctPass = User::findUser(currentUser);

            if (password == correctPass) {
                foundPassword = true;
                cout << "Successfully logged in!" << endl;
                currentPerson = new User(currentUser, password);
            }
            else {
                cout << "Incorrect password!" << endl;
            }

        } while(!foundPassword);

        cout << "|" << setw(25) << left << setfill('_') << "" << "|" << endl;

        return "userHomePage";
    }
}

void printAccount(int accountNum)
{
    //currentuser.accounts[accountNum].printAccount()
    //prints all account information can't really do anything on this page but view the info
    //maybe add a cin asking user to enter when done viewing.

}

string userHomePage() {
    
    int option=0;
    
    do {
        cout<<" "<<setw(25)<<setfill('_')<<""<<endl;
        cout<<setw(25)<<left<<setfill(' ')<<"|"<<"|"<<endl;
        cout<<setw(25)<<left<<"| 1. New Transaction"<<"|"<<endl;
        cout<<setw(25)<<left<<"| 2. View Accounts"<<"|"<<endl;
        cout<<setw(25)<<left<<"| 3. back"<<"|"<<endl;
        cout<<setw(25)<<left<<"| 4. exit"<<"|"<<endl;
       cout<<"|"<<setw(24)<<left<<setfill('_')<<""<<"|"<<endl;

        cin >> option;
    if (option == 1) {return "transaction";}
    else if (option == 2) {return "viewAccounts";}
    else if (option == 3) {return "back";}
    else if (option == 4) {return "exit";}
    else{printAccount(option - 4);}
    } while(option == 0);
    return "";
}
void deposit()
{
    int amount=0;
cout<<"How much money would you like to put in: ";
cin>>amount;
 User* user = dynamic_cast<User*>(currentPerson);
        cout<<" "<<setw(30)<<setfill('_')<<""<<endl;
        cout<<setw(30)<<left<<setfill(' ')<<"|"<<"|"<<endl;
        BankAccount x = BankAccount(user->getUsername(), 0);
        cout <<left<<"| Account type : " <<setw(13)<< x.getAccountType() <<"|"<< endl;
        cout <<left<<"| Account number : "<<setw(11) << x.getAccountNumber() <<"|"<< endl;
        cout <<left<<"| Account balance : $"<<setw(9) << x.getAccountBalance() <<"|"<< endl;

        BankAccount z = BankAccount(user->getUsername(), 1);
        cout <<left<<"| Account type : " <<setw(13)<< z.getAccountType() <<"|"<< endl;
        cout <<left<<"| Account number : "<<setw(11) << z.getAccountNumber() <<"|"<< endl;
        cout <<left<<"| Account balance : $" <<setw(9)<< z.getAccountBalance() <<"|"<< endl;
         cout<<"|"<<setw(29)<<left<<setfill('_')<<""<<"|"<<endl;
cout<<"From which account type: ";
int accountType=0;
cin>>accountType;
//add from account 
}
void withdraw()
{
    int amount=0;
cout<<"How much money would you like to take out: ";
cin>>amount;
 User* user = dynamic_cast<User*>(currentPerson);
        cout<<" "<<setw(30)<<setfill('_')<<""<<endl;
        cout<<setw(30)<<left<<setfill(' ')<<"|"<<"|"<<endl;
        BankAccount x = BankAccount(user->getUsername(), 0);
        cout <<left<<"| Account type : " <<setw(13)<< x.getAccountType() <<"|"<< endl;
        cout <<left<<"| Account number : "<<setw(11) << x.getAccountNumber() <<"|"<< endl;
        cout <<left<<"| Account balance : $"<<setw(9) << x.getAccountBalance() <<"|"<< endl;

        BankAccount z = BankAccount(user->getUsername(), 1);
        cout <<left<<"| Account type : " <<setw(13)<< z.getAccountType() <<"|"<< endl;
        cout <<left<<"| Account number : "<<setw(11) << z.getAccountNumber() <<"|"<< endl;
        cout <<left<<"| Account balance : $" <<setw(9)<< z.getAccountBalance() <<"|"<< endl;
         cout<<"|"<<setw(29)<<left<<setfill('_')<<""<<"|"<<endl;
cout<<"From which account type: ";
int accountType=0;
cin>>accountType;
//remvoe from account 
}
void transfer()
{
        int amount=0;
cout<<"How much money would you like to transfer out: ";
cin>>amount;
    User* user = dynamic_cast<User*>(currentPerson);
        cout<<" "<<setw(30)<<setfill('_')<<""<<endl;
        cout<<setw(30)<<left<<setfill(' ')<<"|"<<"|"<<endl;
        BankAccount x = BankAccount(user->getUsername(), 0);
        cout <<left<<"| Account type : " <<setw(13)<< x.getAccountType() <<"|"<< endl;
        cout <<left<<"| Account number : "<<setw(11) << x.getAccountNumber() <<"|"<< endl;
        cout <<left<<"| Account balance : $"<<setw(9) << x.getAccountBalance() <<"|"<< endl;

        BankAccount z = BankAccount(user->getUsername(), 1);
        cout <<left<<"| Account type : " <<setw(13)<< z.getAccountType() <<"|"<< endl;
        cout <<left<<"| Account number : "<<setw(11) << z.getAccountNumber() <<"|"<< endl;
        cout <<left<<"| Account balance : $" <<setw(9)<< z.getAccountBalance() <<"|"<< endl;
         cout<<"|"<<setw(29)<<left<<setfill('_')<<""<<"|"<<endl;
         int accountType1=0;
         int accountType2=0;
cout<<"You would like to move "<<amount<<" from : (account type)";
cin>>accountType1;
cout<<"to: ";
cin>>accountType2;

//move amount from type1 to type2
}
string transaction(){
  
    int option=0;
    
    do {
        cout<<" "<<setw(25)<<setfill('_')<<""<<endl;
        cout<<setw(25)<<left<<setfill(' ')<<"|"<<"|"<<endl;
        cout<<setw(25)<<left<<"| 1. Deposit"<<"|"<<endl;
        cout<<setw(25)<<left<<"| 2. Withdraw"<<"|"<<endl;\
        cout<<setw(25)<<left<<"| 3. Transfer"<<"|"<<endl;\
        cout<<setw(25)<<left<<"| 4. back"<<"|"<<endl;
        cout<<setw(25)<<left<<"| 5. exit"<<"|"<<endl;
        cout<<"|"<<setw(24)<<left<<setfill('_')<<""<<"|"<<endl;

        cin >> option;
    if (option == 1) {
        deposit();
        return "transaction";
    
    }
    else if (option == 2) 
    {
        withdraw();
        return "transaction";}
    else if (option == 3) 
    {
        transfer();
        return "transaction";
    }
    else if (option == 4) {return "back";}
    else if (option == 5) {return "exit";}
    else{printAccount(option - 4);}
    } while(option == 0);
    return "";




    }
 


/*string createAccount(){
    string username;
    string password;
    const int numUsers = User::getNumUsers();
    int currentUsers;

    do{
        cout << "Enter your username: " << endl;
        cin >> username;
        if (toLower(username) == "back") {
                return "back";
                break;
            }
            if (toLower(username) == "exit") {
                return "exit";
                break;
            }
        cout << "Enter your password: " << endl;
        cin >> password;
        if (toLower(password) == "back") {
                return "back";
                break;
            }
            if (toLower(password) == "exit") {
                return "exit";
                break;
            }

        User::createUser(username, password);
        currentUsers = User::getNumUsers();
    } while(numUsers == currentUsers);

    return "userLogin";
}*/
string viewAccounts()
{
 User* user = dynamic_cast<User*>(currentPerson);
        cout<<" "<<setw(30)<<setfill('_')<<""<<endl;
        cout<<setw(30)<<left<<setfill(' ')<<"|"<<"|"<<endl;
        BankAccount x = BankAccount(user->getUsername(), 0);
        cout <<left<<"| Account type : " <<setw(13)<< x.getAccountType() <<"|"<< endl;
        cout <<left<<"| Account number : "<<setw(11) << x.getAccountNumber() <<"|"<< endl;
        cout <<left<<"| Account balance : $"<<setw(9) << x.getAccountBalance() <<"|"<< endl;

        BankAccount z = BankAccount(user->getUsername(), 1);
        cout <<left<<"| Account type : " <<setw(13)<< z.getAccountType() <<"|"<< endl;
        cout <<left<<"| Account number : "<<setw(11) << z.getAccountNumber() <<"|"<< endl;
        cout <<left<<"| Account balance : $" <<setw(9)<< z.getAccountBalance() <<"|"<< endl;
        cout<<setw(30)<<left<<"| "<<"|"<<endl;
        
    int option=0;
    
    do {
        
        cout<<setw(30)<<left<<"| 1. New Transaction"<<"|"<<endl;
        cout<<setw(30)<<left<<"| 2. View More Information"<<"|"<<endl;
        cout<<setw(30)<<left<<"| 3. back"<<"|"<<endl;
        cout<<setw(30)<<left<<"| 4. exit"<<"|"<<endl;
       cout<<"|"<<setw(29)<<left<<setfill('_')<<""<<"|"<<endl;

        cin >> option;
    if (option == 1) {return "transaction";}
    else if (option == 2) {
        string account="";
        int accountType=0;
        do{
            cout<<"Which account type would you like to see?: ";
        cin>>account;
         if (toLower(account) == "back") {
                return "back";
                break; 
            }
            if (toLower(account) == "exit") {
                return "exit";
                break;
            }
            
            accountType=stoi(account);
        }while(accountType!=x.getAccountType()&&accountType!=z.getAccountType());
        currentaccount=accountType;
        return "viewAccount";
    }
    else if (option == 3) {return "back";}
    else if (option == 4) {return "exit";}
    } while(option == 0);
    return "";
}
string viewAccount()
{
     User* user = dynamic_cast<User*>(currentPerson);
        cout<<" "<<setw(30)<<setfill('_')<<""<<endl;
        cout<<setw(30)<<left<<setfill(' ')<<"|"<<"|"<<endl;
BankAccount x = BankAccount(user->getUsername(), currentaccount);
        cout <<left<<"| Account type : " <<setw(13)<< x.getAccountType() <<"|"<< endl;
        cout <<left<<"| Account number : "<<setw(11) << x.getAccountNumber() <<"|"<< endl;
        cout <<left<<"| Account balance : $"<<setw(9) << x.getAccountBalance() <<"|"<< endl;
    //show transaction data
    
        int option=0;
    
    do {
        cout<<setw(30)<<left<<"| 1. back"<<"|"<<endl;
        cout<<setw(30)<<left<<"| 2. exit"<<"|"<<endl;
       cout<<"|"<<setw(29)<<left<<setfill('_')<<""<<"|"<<endl;

        cin >> option;
   
     if (option == 1) {return "back";}
    else if (option == 2) {return "exit";}
    } while(option == 0);
    return "";
}
string createAccount(){
    string username;
    string password;
    const int numUsers = User::getNumUsers();
    int currentUsers;
cout << " " << setw(25) << setfill('_') << "" << endl;
        cout << setw(25) << left << setfill(' ') << "|" << "|" << endl;
    do{
        cout << "| Enter your username: " << endl;
        cin >> username;
        
            if(toLower(username) == "back"){
                return "back";
                break;
            }
            if(toLower(username) == "exit"){
                return "exit";
                break;
            }

        cout << "| Enter your password: " << endl;
        cin >> password;
        
            if(toLower(password) == "back"){
                return "back";
                break;
            }
            if(toLower(password) == "exit"){
                return "exit";
                break;
            }


        User::createUser(username, password);
        currentUsers = User::getNumUsers();
    } while(numUsers == currentUsers);

    return "userLogin";
}

string managerLogin(){
    int option = 0;
    while(true){
        string userLabel = "| Manager Username: ";
        string passwordLabel = "| Manager Password: ";
        string username = "";
        string password = "";

        cout << " " << setw(25) << setfill('_') << "" << endl;
        cout << setw(25) << left << setfill(' ') << "|" << "|" << endl;
        cout << setw(25) << left << "| Type back/exit anytime." << "|" << endl;

        bool foundUsername = false;
        bool foundPassword = false;
        string currentUser = "";

        do{
            cout << userLabel;
            cin >> username;

            if(toLower(username) == "back"){
                return "back";
                break;
            }
            if(toLower(username) == "exit"){
                return "exit";
                break;
            }

            string pass = Manager::findManager(username);

            if(!pass.empty()){
                foundUsername = true;
                currentUser = username;
            }
            else{
                cout << "Username not found in system!" << endl;
            }

        } while(!foundUsername);

        do{
            cout << passwordLabel;
            cin >> password;

            if(toLower(password) == "back"){
                return "back";
                break;
            }
            if(toLower(password) == "exit"){
                return "exit";
                break;
            }

            string correctPass = Manager::findManager(currentUser);

            if(password == correctPass){
                foundPassword = true;
                cout << "Successfully logged in!" << endl;
                currentPerson = new Manager(currentUser, password);
            }
            else{
                cout << "Incorrect password!" << endl;
            }

        } while(!foundPassword);

        cout << "|" << setw(25) << left << setfill('_') << "" << "|" << endl;

        return "managerMenu";
    }
}


string managerMenu(){
    int option = 0;

    do{
        cout << " " << setw(35) << setfill('_') << "" << endl;
        cout << setw(35) << left << setfill(' ') << "|" << "|" << endl;
        cout << setw(35) << left << "| Manager Menu" << "|" << endl;
        cout << setw(35) << left << "| 1. View All Users" << "|" << endl;
        cout << setw(35) << left << "| 2. View User Details" << "|" << endl;
        cout << setw(35) << left << "| 3. View All Transactions" << "|" << endl;
        cout << setw(35) << left << "| 4. View User Transactions" << "|" << endl;
        cout << setw(35) << left << "| 5. Back" << "|" << endl;
        cout << setw(35) << left << "| 6. Exit" << "|" << endl;
        cout << "|" << setw(34) << left << setfill('_') << "" << "|" << endl;

        cin >> option;
        
        string inputted_username = "";
        Manager* mgr = dynamic_cast<Manager*>(currentPerson);

        switch(option){
            case 1:
                mgr->viewAllUsers();
                break;
            case 2:
                cout << "Enter username you wish to see credentials: ";
                cin >> inputted_username;
                mgr->viewUserDetails(inputted_username);
                break;
            case 3:
                mgr->viewAllTransactions();
                break;
            case 4:
                cout << "Enter username you wish to see transactions: ";
                cin >> inputted_username;
                mgr->viewUserTransactions(inputted_username);
                break;
            case 5:
                return "back";
                break;
            case 6:
                return "exit";
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    } while(true);
    
    return "managerMenu";
}


string homePage() {
    int option=0;
    do//User can choose to regular login/create account/manager login/exit
    {
        cout << " " << setw(19) << setfill('_') << "" << endl;
        cout << setw(20) << left << setfill(' ') << "|" << "|" << endl;
        cout << setw(20) << left << "| 1. User Login" << "|" << endl;
        cout << setw(20) << left << "| 2. Create Account" << "|" << endl;
        cout << setw(20) << left << "| 3. Manager Login" << "|" << endl;
        cout << setw(20) << left << "| 4. Exit" << "|" << endl;
        cout << "|" << setw(19) << left << setfill('_') << "" << "|" << endl;
        cin >> option;
    } while (option > 4 || option < 1);
    string method = "";
    switch(option) {
        case 1: //user login
            method = "userLogin";
            break; 
        case 2: //create account
            method = "createAccount";
            break;
        case 3: //manager login
            method = "managerLogin";
            break;
        case 4: // Exit
            method = "exit";
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
        {"userHomePage",userHomePage},
        {"managerLogin",managerLogin},
        {"transaction",transaction},
        {"managerMenu", managerMenu},
        {"viewAccounts", viewAccounts},
        {"viewAccount",viewAccount},
        {"createAccount",createAccount}
    };
    stack<string> pageStack;
    string currentPage = "homePage";
    pageStack.push(currentPage);
    
    do
    {
        
        string nextPage = pages[pageStack.top()]();
    if(nextPage == "back")
    {
        pageStack.pop();
        
       
    }
    else if(nextPage == "exit")
    {
        return;
    }
    else
    {pageStack.push(nextPage);}
    
    } while(!pageStack.empty());
    
}


int main() {
    //loads existing users into static user count
    User::loadExistingUsers();
    run();
    delete currentPerson;
}

