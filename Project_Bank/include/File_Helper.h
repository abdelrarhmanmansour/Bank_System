#ifndef FILE_HELPER_H
#define FILE_HELPER_H
#include<iostream>
#include <vector>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include<fstream>
#include<sstream>
#include "Parser.h"
using namespace std;
class File_Helper
{
    // Methods:
private:
    static void Save_Last_ID(string name,int id)
    {
        // open file;
        // used to write data to a file;
        //Write the value of id to the file.
        ofstream file;
        file.open(name);
        file << id;
        file.close();
    }
public:
    static int Get_Last_ID(string name)
    {
        // read file
        ifstream file;
        file.open(name);
        int id;
        // read;
        file >> id;
        file.close();
        return id;
    }
    static void Save_Client(Client c)
    {
        // i get last id from file("clientlastid.txt");
        int id= Get_Last_ID("clientlastid.txt");
        fstream file;
        file.open("clients.txt",ios::app);
        file << id+1 << '|' <<  c.get_name() << '|' << c.get_password() << '|' << c.get_balance() << "\n";
        file.close();
        Save_Last_ID("clientlastid.txt",id+1);
    }
    static void Save_Employee(string name,string lastidfile,Employee e)
    {
        // same save clients;
        int id =Get_Last_ID(lastidfile);
        fstream file;
        file.open(name,ios::app);
        file << id+1 << '|' <<  e.get_name() << '|' << e.get_password() << '|' << e.get_salary() << "\n";
        file.close();
        Save_Last_ID(lastidfile,id+1);
    }
    // we do not use files every times;
    // make vectors global to use it every where in my project;
    static void Get_clients()
    {
        string line;
        ifstream file;
        file.open("clients.txt");
        while(getline(file,line))
        {
            Client c =Parser::Parse_To_Client(line);
            // global vector;
            allclients.push_back(c);
        }
        file.close();
    }
    static void Get_employees()
    {
        string line;
        ifstream file;
        file.open("employees.txt");
        while(getline(file,line))
        {
            Employee e =Parser::Parse_To_Employee(line);
            // global vector;
            allemployees.push_back(e);
        }
        file.close();
    }
    static void Get_admins()
    {
        string line;
        ifstream file;
        file.open("admin.txt");
        while(getline(file,line))
        {
            Admin a =Parser::Parse_To_Admin(line);
            // global vector;
            alladmins.push_back(a);
        }
        file.close();
    }
    // Returns true if both files were successfully cleared and reset, false otherwise
    static bool Clear_File(string filename,string lastidfile)
    {
        // Clear the first file
        ofstream file(filename,ios::trunc);
        if (!file.is_open())
        {
            cerr << "Error: Failed to open file: " << filename <<endl;
            return false; // Indicate failure
        }
        file.close();
        // Write 0 to the second file
        ofstream file1(lastidfile,ios::out);
        if (!file1.is_open())
        {
            cerr << "Error: Failed to open file: " << lastidfile << endl;
            return false; // Indicate failure
        }
        file1 << 0;
        file1.close();
        return true; // Indicate success
    }
};
#endif // FILE_HELPER_H
