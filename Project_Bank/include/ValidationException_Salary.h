#ifndef VALIDATIONEXCEPTION_SALARY_H
#define VALIDATIONEXCEPTION_SALARY_H
#include<iostream>
using namespace std;
// Here make Exception Handling;
class ValidationException_Salary:public exception
{
public:
    const char* what() const throw()
    {
        return "Validation failed: Invalid Salary";
    }
};
#endif // VALIDATIONEXCEPTION_SALARY_H
