#ifndef VALIDATIONEXCEPTION_BALANCE_H
#define VALIDATIONEXCEPTION_BALANCE_H
#include<iostream>
using namespace std;
// Here make Exception Handling;
class ValidationException_Balance:public exception
{
public:
    const char* what() const throw()
    {
        return "Validation failed: Invalid Balance";
    }
};
#endif // VALIDATIONEXCEPTION_BALANCE_H
