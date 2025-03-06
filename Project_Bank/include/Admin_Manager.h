#ifndef ADMIN_MANAGER_H
#define ADMIN_MANAGER_H
#include<iostream>
#include "Validator.h"
#include "File_Helper.h"
#include "File_Manager.h"
#include "Employee.h"
#include "Admin.h"
#include "Client_Manager.h"
#include "Employee_Manager.h"
using namespace std;

class Admin_Manager
{
    // Methods:
private:
    static void Print_Admin_Menu()
    {
        system("cls");
        cout << "(1) Display My Info\n";
        cout << "(2) Update Password\n";
        cout << "(3) Add New Clients\n";
        cout << "(4) Search For Clients\n";
        cout << "(5) List All Clients\n";
        cout << "(6) Edit Client Info\n";
        cout << "(7) Add New Employees\n";
        cout << "(8) Search For Employees\n";
        cout << "(9) List All Employees\n";
        cout << "(10) Edit Employee Info\n";
        cout << "(11) Logout\n";
    }
    // this function to return again Print_Client_Menu();
    static void Return_Back(Admin*admin)
    {
        system("pause");
        Admin_Option(admin);
    }
public:
    static Admin*Login(int id,string password)
    {
        for(auto eo=alladmins.begin(); eo!=alladmins.end(); eo++)
            if(eo-> get_id()==id&&eo->get_password()==password)
                return &(*eo);
            else
                return NULL;
    }
    static bool Admin_Option(Admin*admin)
    {
        Print_Admin_Menu();
        cout << "Select Your Choice: ";
        Employee e;
        int choice,id;
        cin >> choice;
        switch(choice)
        {
        case 1:
            system("cls");
            admin->Display_Info();
            break;
        case 2:
            Client_Manager::Update_Password(admin);
            File_Manager::updateAdmins();
            break;
        case 3:
            Employee_Manager::Add_New_Client(admin);
            break;
        case 4:
            Employee_Manager::Search_For_Clients(admin);
            break;
        case 5:
            Employee_Manager::List_ALL_Client(admin);
            break;
        case 6:
            Employee_Manager::Edit_Client_Info(admin);
            break;
        case 7:
            e.set_id(File_Helper::Get_Last_ID("employeelastid.txt")+1);
            e.set_name(Validator::Enter_Name());
            e.set_password(Validator::Enter_Password());
            e.set_salary(Validator::Enter_Salary());
            admin->Add_Employee(e);
            File_Manager::updateEmployees();
            cout << "Employee Added,Successfully\n";
            break;
        case 8:
            int id;
            system("cls");
            cout << "Enter An ID: ";
            cin >> id;
            if(admin->Search_Employee(id)==NULL)
                cout << "\nThis ID Not Found\n";
            else
                admin->Search_Employee(id)->Display_Info();
            break;
        case 9:
            system("cls");
            cout << "All Employees\n";
            admin->List_Employee();
            break;
        case 10:
            system("cls");
            cout << "Enter An ID: ";
            cin >> id;
            if(admin->Search_Employee(id)==NULL)
                cout << "\nThis ID Not Found\n";
            else
            {
                string name=Validator::Enter_Name();
                string password=Validator::Enter_Password();
                double salary=Validator::Enter_Salary();
                admin->Edit_Employee(id,name,password,salary);
                File_Manager::updateEmployees();
                cout << "\nEdit Employee,Successfully\n";
            }
            break;
        case 11:
            return false;
            break;
        default:
            system("cls");
            Admin_Option(admin);
            return true;
        }
        Return_Back(admin);
        return true;
    }
};

#endif // ADMIN_MANAGER_H
