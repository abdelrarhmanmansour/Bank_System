#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include<vector>
#include<iostream>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "DataSourceInterface.h"
#include "File_Helper.h"
#include "Parser.h"
class File_Manager:public DataSourceInterface
{
    // same function in file helper;
public:
    static void Add_Client(Client c)
    {
        File_Helper::Save_Client(c);
    }
    static void Add_Employee(Employee e)
    {
        File_Helper::Save_Employee("employees.txt","employeelastid.txt",e);
    }
    static void Add_Admin(Admin a)
    {
        File_Helper::Save_Employee("admin.txt","adminlastid.txt",a);
    }
    static void GetAllClient()
    {
        File_Helper::Get_clients();
    }
    static void GetAllEmployee()
    {
        File_Helper::Get_employees();
    }
    static void GetAllAdmin()
    {
        File_Helper::Get_admins();
    }
    static void RemoveAllClient()
    {
        File_Helper::Clear_File("clients.txt","clientlastid.txt");
    }
    static void RemoveAllEmployee()
    {
        File_Helper::Clear_File("employees.txt","employeelastid.txt");
    }
    static void RemoveAllAdmin()
    {
        File_Helper::Clear_File("admin.txt","adminlastid.txt");
    }
public:
    // this function has import when run the project:
    static void getAlldata()
    {
        GetAllClient();
        GetAllEmployee();
        GetAllAdmin();
    }
    // update to any changes:
    static void updateClients()
    {
        RemoveAllClient();
        for(cl=allclients.begin(); cl!=allclients.end(); cl++)
        {
            Add_Client(*cl);
        }
    }
    static void updateEmployees()
    {
        RemoveAllEmployee();
        for(em=allemployees.begin(); em!=allemployees.end(); em++)
        {
            Add_Employee(*em);
        }
    }
    static void updateAdmins()
    {
        RemoveAllAdmin();
        for(auto eo=alladmins.begin(); eo!=alladmins.end(); eo++)
        {
            Add_Admin(*eo);
        }
    }
};
#endif // FILE_MANAGER_H
