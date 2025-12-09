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
bool checkCIN (int& option)
{
if(cin.fail()) {
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            option = 0; 
            return false;
        }
        return true;
}
bool cancelTransaction()
{
    string answer="";
    cout<<"Would you like to cancel transaction? (y/n)";
    cin>>answer;
    if(answer=="y")
    {
        return true;
    }
    return false;
}
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

            User tempUser("", "");
            string pass = tempUser.findPerson(username);

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

            User tempUser("", "");
            string correctPass = tempUser.findPerson(username);

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
        checkCIN(option);
    if (option == 1) {return "transaction";}
    else if (option == 2) {return "viewAccounts";}
    else if (option == 3) {return "back";}
    else if (option == 4) {return "exit";}
    } while(option == 0);
    return "";
}
void deposit()
{
    int amount=0;
    while(amount<=0)
    {
        cout<<"How much money would you like to put in: ";
cin>>amount;
if(!checkCIN(amount))
{
if(cancelTransaction())
{
    return;
}
}
    }

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

    int accountType=-1;
   
while(accountType!=z.getAccountType()&&accountType!=x.getAccountType())
    {
            cout<<"From which account type: ";
 cin>>accountType;
if(!checkCIN(accountType))
{
    accountType=-1;
if(cancelTransaction())
{
    return;
}
}
    }
    Transaction t = Transaction(BankAccount(user->getUsername(), accountType));
    t.deposit(amount);
    cout << "You have successfully deposited $" << amount << " into account : " << accountType << endl;
}
void withdraw()
{
    int amount=0;
    while(amount<=0)
    {
        cout<<"How much money would you like to take out: ";
cin>>amount;
if(!checkCIN(amount))
{
if(cancelTransaction())
{
    return;
}
}
    }
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

    int accountType=-1;
   
while(accountType!=z.getAccountType()&&accountType!=x.getAccountType())
    {
            cout<<"From which account type: ";
 cin>>accountType;
if(!checkCIN(accountType))
{
    accountType=-1;
if(cancelTransaction())
{
    return;
}
}
    }

Transaction t = Transaction(BankAccount(user->getUsername(), accountType));
if (t.withdraw(amount) == false) {
    cout << "Error : not enough funds in account to withdraw!" << endl;
}
else {
    cout << "You have successfully withdrawn $" << amount << " from account : " << accountType << endl;
}
}
void transfer()
{
        int amount=0;
    while(amount<=0)
    {
        cout<<"How much money would you like to transfer: ";
cin>>amount;
if(!checkCIN(amount))
{
if(cancelTransaction())
{
    return;
}
}
    }
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
         int accountType1=-1;
         int accountType2=-1;
while(accountType1!=z.getAccountType()&&accountType1!=x.getAccountType())
    {
   cout<<"You would like to move "<<amount<<" from : (account type)";
cin>>accountType1;
if(!checkCIN(accountType1))
{
    accountType1=-1;
if(cancelTransaction())
{
    return;
}
}
    }

while(accountType2!=z.getAccountType()&&accountType2!=x.getAccountType())
    {
cout<<"to: ";
cin>>accountType2;
if(!checkCIN(accountType2))
{
    accountType2=-1;
if(cancelTransaction())
{
    return;
}
}
    }
    
Transaction t1 = Transaction(BankAccount(user->getUsername(), accountType1));

Transaction t2 = Transaction(BankAccount(user->getUsername(), accountType2));

    if (t1.withdraw(amount) == false) {
    cout << "Error : not enough funds in account to withdraw!" << endl;
                return;
}
else
{
    t2.deposit(amount);
     cout << "You have successfully transfered $" << amount << " from account : " << accountType1 <<"to "<<accountType2<< endl;
}
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

cin>>option;
checkCIN(option);

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
    } while(option == 0);
    return "";




    }
 

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

        cin>>option;
checkCIN(option);
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

       cin>>option;
checkCIN(option);
   
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

            Manager tempManager("", "");
            string pass = tempManager.findPerson(username);

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

            Manager tempManager("", "");
            string correctPass = tempManager.findPerson(currentUser);

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

       cin>>option;
checkCIN(option);
        
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
    } while(option==0);
    
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
        cin>>option;
checkCIN(option);
   
    string method = "";
    switch(option) {
        case 1: //user login
            return "userLogin";
            break; 
        case 2: //create account
            return "createAccount";
            break;
        case 3: //manager login
            return "managerLogin";
            break;
        case 4: // Exit
           return "exit";
    }
     } while (option==0);
     return "";
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
    {
        if(pageStack.top()!=nextPage)
        { 
            pageStack.push(nextPage);

        }
       
    }
    
    } while(!pageStack.empty());
    
}


int main() {
    //loads existing users into static user count
    User::loadExistingUsers();
    run();
    delete currentPerson;
}




