#ifndef VALIDATIONEXCEPTION_NAME_PASSWORD_H
#define VALIDATIONEXCEPTION_NAME_PASSWORD_H
#include<iostream>
using namespace std;
// Here make Exception Handling;
class ValidationException_Name_Password:public exception
{
public:
    const char* what() const throw()
    {
        return "Validation failed: Invalid name or password.";
    }
};
#endif // VALIDATIONEXCEPTION_NAME_PASSWORD_H
