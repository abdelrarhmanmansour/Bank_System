#ifndef VALIDATOR_H
#define VALIDATOR_H
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
};
#endif // VALIDATOR_H
