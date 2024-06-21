#include<bits/stdc++.h>
using namespace std;

//design BankAccount class
// properties-> accountNumber, accountHolderName, balance.
//properties-> deposit(), withdraw(), checkBalance()

class BankAccount
{
private:
    string accountNumber;
    string accountHolderName;
    double balance;
    
public:
    //constructor
    // BankAccount(const string& accNum, const string& accHolder, double bal){
    //     accountNumber=accNum;
    //     accountHolderName=accHolder;
    //     balance=bal;
    // }
    BankAccount(const string& accNum, const string& accHolder, double bal):accountNumber(accNum), accountHolderName(accHolder), balance(bal){};
    //deposit method
    void deposit(double amount){
        if(amount > 0){
            balance += amount;
            cout<<"Deposited: "<<amount<<endl;
        }
    }
    void withdraw(double amount){
        if(amount>0 && balance>=amount){
            balance-=amount;
            cout << "Withdrawn: " << amount <<endl;
        }else{
            cout << "Insufficient balance" <<endl;
        }
    }
    void checkBalance() const {
        cout<<"Balance: "<<balance<<endl;
    }
    // ~BankAccount();
};

int main(){
    BankAccount account("193719", "Aanya", 1000.0);
    account.checkBalance();
    account.deposit(500.0);
    account.checkBalance();   
    account.withdraw(200.0);
    account.checkBalance();   
    return 0;
}