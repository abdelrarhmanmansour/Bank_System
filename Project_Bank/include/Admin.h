#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
#include<vector>
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
    void Add_Employee(Employee&e)
    {
        // this is point when i close the program the new client remove because i not save in file:
        // so go to file manager class at end to solve this:
        allemployees.push_back(e);
    }
    Employee*Search_Employee(int id)
    {
        for(em=allemployees.begin(); em!=allemployees.end(); em++)
        {
            // iterator<< cl is pointer to check id is id or not
            if(em->get_id()==id)
            {
                // return iterator as pointer:
                return &(*em);
            }
        }
        return NULL;
    }
    void Edit_Employee(int id, string name, string password, double salary)
    {
        Search_Employee(id)->set_name(name);
        Search_Employee(id)->set_password(password);
        Search_Employee(id)->set_salary(salary);
    }
    void List_Employee()
    {
        for(em=allemployees.begin(); em!=allemployees.end(); em++)
        {
            em->Display_Info();
        }
    }
};
static vector<Admin>alladmins;
static vector<Admin>eo;
#endif // ADMIN_H
