#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Validator.h"
#include<vector>
#include "ValidationException_Name_Password.h"
#include "ValidationException_Balance.h"
#include "ValidationException_Salary.h"
#include "Person.h"
#include "Client.h"
#include<iostream>
using namespace std;
class Employee:public Person
{
    // Attributes:
protected:
    double salary;
public:
    // Default Constructor:
    Employee()
    {
        this->salary=salary;
    }
    // Parametrized Constructor:
    Employee(int id,string name,string password,double salary):Person(id,name,password)
    {
        set_salary(salary);
    }
    // Setters:
    void set_salary(double salary)
    {
        if(Validator::Validate_Salary(salary))
        {
            this->salary=salary;
        }
        else
        {
            throw ValidationException_Salary();
        }
    }
    //Getters:
    double get_salary()
    {
        return this->salary;
    }
    // Methods:
    // Polymorphism:
    // Note: I make this Display Info Employee << Virtual << when i print my info&&ADmin print his info << not conflict;
    virtual void Display_Info()
    {
        cout <<  "The ID is: " << id << "\n";
        cout <<  "The Name is: " << name << "\n";
        cout << "The Password is: " <<  password << "\n";
        cout << "The Salary Employee is: " <<  salary << "\n";
    }
    // this function push back to vector only;
    void Add_Client(Client&c)
    {
        // this is point when i close the program the new client remove because i not save in file:
        // so go to file manager class at end to solve this:
        allclients.push_back(c);
    }
    // search by iterator with vector:
    Client* Search_Client(int id)
    {
        for(cl=allclients.begin(); cl!=allclients.end(); cl++)
        {
            // iterator<< cl is pointer to check id is id or not
            if(cl->get_id()==id)
            {
                // return iterator as pointer:
                return &(*cl);
            }
        }
        return NULL;
    }
    void listClient()
    {
        for(cl=allclients.begin(); cl!=allclients.end(); cl++)
        {
            cl->Display_Info_Client();
        }
    }
    void EditClient(int id, string name, string password, double balance)
    {
        Search_Client(id)->set_name(name);
        Search_Client(id)->set_password(password);
        Search_Client(id)->set_balance(balance);
    }
};
static vector<Employee> allemployees;
static vector<Employee>::iterator em;
#endif // EMPLOYEE_H
