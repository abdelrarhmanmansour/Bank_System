#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H
#include<iostream>
#include "Validator.h"
#include "File_Helper.h"
#include "File_Manager.h"
#include "Employee.h"
#include "Client_Manager.h"
using namespace std;

class Employee_Manager
{
    // Methods:
private:
    // print employee menu:
    static void Print_Employee_Menu()
    {
        system("cls");
        cout << "(1) Display My Info\n";
        cout << "(2) Update Password\n";
        cout << "(3) Add New Clients\n";
        cout << "(4) Search For Clients\n";
        cout << "(5) List All Clients\n";
        cout << "(6) Edit Client Info\n";
        cout << "(7) Logout\n";
    }
    // this function to return again Print_Client_Menu();
    static void Return_Back(Employee*employee)
    {
        system("pause");
        Employee_Option(employee);
    }
public:
    static void Add_New_Client(Employee*employee)
    {
        Client client;
        client.set_id(File_Helper::Get_Last_ID("clientlastid.txt")+1);
        client.set_name(Validator::Enter_Name());
        client.set_password(Validator::Enter_Password());
        client.set_balance(Validator::Enter_Balance());
        employee->Add_Client(client);
        File_Manager::updateClients();
        cout << "Client Added,Successfully\n";
    }
    static void List_ALL_Client(Employee*employee)
    {
        system("cls");
        cout << "All Clients\n";
        employee->listClient();
    }
    static void Search_For_Clients(Employee*employee)
    {
        int id;
        system("cls");
        cout << "Enter An ID: ";
        cin >> id;
        if(employee->Search_Client(id)==nullptr)
            cout << "\nThis ID Not Found\n";
        else
            employee->Search_Client(id)->Display_Info_Client();
    }
    static void Edit_Client_Info(Employee*employee)
    {
        int id;
        system("cls");
        cout << "Enter An ID: ";
        cin >> id;
        if(employee->Search_Client(id)==nullptr)
            cout << "\nThis ID Not Found\n";
        else
        {
            string name=Validator::Enter_Name();
            string password=Validator::Enter_Password();
            double balance=Validator::Enter_Balance();
            employee->EditClient(id,name,password,balance);
            File_Manager::updateClients();
            cout << "\nEdit Client,Successfully\n";
        }
    }
    static Employee*Login(int id,string password)
    {
        for(em=allemployees.begin(); em!=allemployees.end(); em++)
            if(em->get_id()==id&&em->get_password()==password)
                return &(*em);
            else
                return NULL;
    }
    static bool Employee_Option(Employee*employee)
    {
        Print_Employee_Menu();
        cout << "Select Your Choice: ";
        int choice;
        cin >> choice;
        switch(choice)
        {
        case 1:
            system("cls");
            employee->Display_Info();
            break;
        case 2:
            Client_Manager::Update_Password(employee);
            File_Manager::updateEmployees();
            break;
        case 3:
            Add_New_Client(employee);
            break;
        case 4:
            Search_For_Clients(employee);
            break;
        case 5:
            List_ALL_Client(employee);
            break;
        case 6:
            Edit_Client_Info(employee);
            break;
        case 7:
            return false;
            break;
        default:
            system("cls");
            Employee_Option(employee);
            return true;
        }
        Return_Back(employee);
        return true;
    }
};
#endif // EMPLOYEE_MANAGER_H
