#ifndef VALIDATOR_H
#define VALIDATOR_H
#include "ValidationException_Name_Password.h"
#include "ValidationException_Balance.h"
#include "ValidationException_Salary.h"
#include<iostream>
using namespace std;
// class Validate to check [name&&password&&balance&&salary];
class Validator
{
public:
    // Validate Name
    static bool Validate_Name(string name)
    {
        if(name.length()<5||name.length()>20)
        {
            return false;
        }
        for(int i=0; i<name.length(); i++)
        {
            if(!isalpha(name[i]))
            {
                return false;
            }
        }
        return true;
    }
    // Validate Password
    static bool Validate_Password(string password)
    {
        if(password.length()<8||password.length()>20)
        {
            return false;
        }
        return true;
    }
    // Validate Balance
    static bool Validate_Balance(double balance)
    {
        if(balance<1500)
        {
            return false;
        }
        return true;
    }
    // Validate Salary
    static bool Validate_Salary(double salary)
    {
        if(salary<5000)
        {
            return false;
        }
        return true;
    }
    // function to enter name:
    static string Enter_Name()
    {
        string name;
        system("cls");
        cout << "Enter Name: ";
        cin >> name;
        while(!Validate_Name(name))
        {
            system("cls");
            cout << "Invalid Name\n";
            cout << "the name must be alphabetic chars and min size 5 and max size 20\n";
            cout << "Enter Name: ";
            cin >> name;
        }
        return name;
    }
    // function to enter password:
    static string Enter_Password()
    {
        string password;
        system("cls");
        cout << "Enter Password: ";
        cin >> password;
        while(!Validate_Password(password))
        {
            system("cls");
            cout << "Invalid password\n";
            cout << "Password must be with min size 8 and max size 20";
            cout << "Enter password: ";
            cin >> password;
        }
        return password;
    }
    // function to enter balance:
    static double Enter_Balance()
    {
        double balance;
        system("cls");
        cout << "Enter Balance: ";
        cin >> balance;
        while(!Validate_Balance(balance))
        {
            system("cls");
            cout << "Invalid Balance\n";
            cout << "Min balance is 1500\n";
            cout << "Enter Balance: ";
            cin >> balance;
        }
        return balance;
    }
    // function to enter salary:
    static double Enter_Salary()
    {
        double salary;
        system("cls");
        cout << "Enter Salary: ";
        cin >> salary;
        while(!Validate_Salary(salary))
        {
            system("cls");
            cout << "Invalid Salary\n";
            cout << "Min Salary 5000\n";
            cout << "Enter Salary: ";
            cin >> salary;
        }
        return salary;
    }
};
#endif // VALIDATOR_H
