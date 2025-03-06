#ifndef CLIENT_H
#define CLIENT_H
#include<iostream>
#include<vector>
#include "Validator.h"
#include "ValidationException_Name_Password.h"
#include "ValidationException_Balance.h"
#include "ValidationException_Salary.h"
#include "Person.h"
using namespace std;
class Client:public Person
{
    // Attributes:
private:
    double balance;
public:

    // Default Constructor:
    Client()
    {
        this->balance=0.0;
    }
    // Parametrized Constructor:
    Client(int id,string name,string password,double balance):Person(id,name,password)
    {
        set_balance(balance);
    }
    // Setters:
    void set_balance(double balance)
    {
        if(Validator::Validate_Balance(balance))
        {
            this->balance=balance;
        }
        else
        {
            Validator::Enter_Balance();
        }
    }
    // Getters:
    double get_balance()
    {
        return this->balance;
    }
    // Methods:
    void Deposit(double amount)
    {
        balance+=amount;
    }
    void WithDraw(double amount)
    {
        if(amount<=balance)
        {
            balance-=amount;
        }
        else
        {
            cout << "Sorry,Amount Exceeded Balance\n";
        }
    }
    void Ttansfer_To(double amount,Client&c)
    {
        if(amount<=balance)
        {
            balance-=amount;
            c.Deposit(amount);
        }
        else
        {
            cout << "Sorry,Amount Exceeded Balance\n";
        }
    }
    void Check_Balance()
    {
        cout << "Balance is: " <<  balance << "\n";
    }
    void Display_Info_Client()
    {
        cout <<  "The ID is: " << id << "\n";
        cout <<  "The Name is: " << name << "\n";
        cout << "The Password is: " <<  password << "\n";
        cout << "The Balance is: " <<  balance << "\n";
    }
};
static vector<Client>allclients;
static vector<Client>::iterator cl;
#endif // CLIENT_H
