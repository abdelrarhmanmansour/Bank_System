#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
#include "Validator.h"
#include "ValidationException_Name_Password.h"
#include "ValidationException_Balance.h"
#include "ValidationException_Salary.h"
#include "Person.h"
#include "Employee.h"
using namespace std;
class Admin:public Employee
{
public:
    Admin()
    {

    }
    // Parametrized Constructor:
    Admin(int id,string name,string password,double salary):Employee(id,name,password,salary)
    {

    }
    // Methods:
    void Display_Info()
    {
        cout <<  "The ID is: " << id << "\n";
        cout <<  "The Name is: " << name << "\n";
        cout << "The Password is: " <<  password << "\n";
        cout << "The Salary ADmin is: " <<  salary << "\n";
    }
};
#endif // ADMIN_H
