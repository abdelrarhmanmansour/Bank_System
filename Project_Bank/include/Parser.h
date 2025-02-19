#ifndef PARSER_H
#define PARSER_H
#include<iostream>
#include "Person.h"
#include<string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include<sstream>
#include <vector>
using namespace std;
class Parser
{
    // Methods:
private:
    // this function return vector to split any line;
    static vector<string> Split(string line)
    {
        // Convert line to string stream;
        stringstream s(line);
        string parts;
        // create vector to save data in it;
        vector<string> sub;
        while(getline(s,parts,'|'))
        {
            sub.push_back(parts);
        }
        return sub;
    }
public:
    // this function return client to split his info;
    static Client Parse_To_Client(string line)
    {
        // split line;
        vector<string>sub= Split(line);
        // create object from client;
        Client c;
        // stoi && stod :: function convert string to integer or double because vector is string;
        c.set_id(stoi(sub[0]));
        c.set_name(sub[1]);
        c.set_password(sub[2]);
        c.set_balance(stod(sub[3]));
        return c;
    }
    // this function return employee to split his info;
    static Employee Parse_To_Employee(string line)
    {
        // split line;
        vector<string>sub =Split(line);
        // create object from client;
        Employee e;
        // stoi && stod :: function convert string to integer or double because vector is string;
        e.set_id(stoi(sub[0]));
        e.set_name(sub[1]);
        e.set_password(sub[2]);
        e.set_salary(stod(sub[3]));
        return e;
    }
    // this function return employee to split his info;
    static Admin Parse_To_Admin(string line)
    {
        // split line;
        vector<string>sub =Split(line);
        // create object from client;
        Admin a;
        // stoi && stod :: function convert string to integer or double because vector is string;
        a.set_id(stoi(sub[0]));
        a.set_name(sub[1]);
        a.set_password(sub[2]);
        a.set_salary(stod(sub[3]));
        return a;
    }
};
#endif // PARSER_H
