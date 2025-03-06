#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include "Validator.h"
#include "ValidationException_Name_Password.h"
#include "ValidationException_Balance.h"
#include "ValidationException_Salary.h"
using namespace std;
class Person
{
    // Attributes:
protected:
    int id;
    string name,password;
public:
    // Default Constructor:
    Person()
    {
        this->id=0;
    }
    // Parametrized Constructor:
    Person(int id,string name,string password)
    {
        set_id(id);
        set_name(name);
        set_password(password);
    }
    // Setters:
    void set_id(int id)
    {
        this->id=id;
    }
    void set_name(string name)
    {
        if(Validator::Validate_Name(name))
        {
            this->name=name;
        }
        else
        {
            Validator::Enter_Name();
        }
    }
    void set_password(string password)
    {
        if(Validator::Validate_Password(password))
        {
            this->password=password;
        }
        else
        {
            Validator::Enter_Password();
        }
    }
    // Getters:
    int get_id()
    {
        return this->id;
    }
    string get_name()
    {
        return this->name;
    }
    string get_password()
    {
        return this->password;
    }
    // Destructor:
    ~Person()
    {

    }
};
#endif // PERSON_H
