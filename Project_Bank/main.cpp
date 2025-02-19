#include<iostream>
#include<cmath>
#include<string>
#include <vector>
#include<exception>
#include<algorithm>
#include<fstream>
#include<sstream>
#include "Validator.h"
#include "ValidationException_Name_Password.h"
#include "ValidationException_Balance.h"
#include "ValidationException_Salary.h"
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "DataSourceInterface.h"
#include "Parser.h"
#include "File_Helper.h"
#include "File_Manager.h"
using namespace std;
int main()
{
//     this number of chances;
//    int chances=3;
//    while(chances--)
//    {
//         Person:
//        try
//        {
//            int id;
//            cout << "Enter an ID: ";
//            cin >> id;
//            string name,password;
//            cout << "Enter a Name: ";
//            cin >> name;
//            cout << "Enter a password: ";
//            cin >> password;
//            system("cls");
//            Person p(id,name,password);
//            cout << "Hello to the Bank\n";
//            break;
//        }
//        catch(exception&e)
//        {
//            cout << e.what() << "\n";
//            if(chances==0)
//            {
//                cout<<"Sorry,we have to exist Program, Try Later";
//                break;
//            }
//            cout << "You have " << chances << "Chances"<<"\n";
//        }
//    }
    //this number of chances;
//    int chances=3;
//    while(chances--)
//    {
//        //Client:
//        try
//        {
//            fstream clients("clients.txt",ios::app);
//            int id;
//            cout << "Enter an ID: ";
//            cin >> id;
//            string name,password;
//            cout << "Enter a Name: ";
//            cin >> name;
//            cout << "Enter a password: ";
//            cin >> password;
//            double balance;
//            cout << "Enter an Balance: ";
//            cin >> balance;
//            system("cls");
//            Client c(id,name,password,balance),c1(id+1,"salmamohamed","rorosalma@gmail.com",balance+1000);
//            clients << c.get_id() << '|' << c.get_name() << '|' <<c.get_password() << '|' << c.get_balance() << "\n";
//            clients.close();
//            Client client =Parser::Parse_To_Client("3|leqaahani|leqqahani@mansour123|7800");
//            client.Display_Info_Client();
//            cout << "Hello to the Bank\n";
//            c.Deposit(500);
//            c.WithDraw(500);
//            c1.Ttansfer_To(1000,c);
//            c.Check_Balance();
//            c1.Check_Balance();
//            c.Display_Info_Client();
//            c1.Display_Info_Client();
//            break;
//        }
//        catch(exception&e)
//        {
//            cout << e.what() << "\n";
//            if(chances==0)
//            {
//                cout<<"Sorry,we have to exist Program, Try Later";
//                break;
//            }
//            cout << "You have " << chances << "Chances"<<"\n";
//        }
//    }
    //this number of chances;
//    int chances=3;
//    while(chances--)
//    {
//        // Employee:
//        try
//        {
//            fstream employees("employees.txt",ios::app);
//            int id;
//            cout << "Enter an ID: ";
//            cin >> id;
//            string name,password;
//            cout << "Enter a Name: ";
//            cin >> name;
//            cout << "Enter a password: ";
//            cin >> password;
//            double salary;
//            cout << "Enter an Salary: ";
//            cin >> salary;
//            system("cls");
//            Employee e(id,name,password,salary);
//            employees << e.get_id() << '|' << e.get_name() << '|' <<e.get_password() << '|' << e.get_salary() << "\n";
//            employees.close();
//            Employee employee= Parser::Parse_To_Employee("2|entsarahmed|entsarahmed12345|5000");
//            employee.Display_Info();
//            cout << "Hello to the Bank\n";
//            e.Display_Info();
//            Client c(2,"rororororor","rorororororor",1600);
//            File_Helper::Save_Client(c);
//            File_Manager::updateClients();
//            e.Add_Client(c);
//            break;
//        }
//        catch(exception&e)
//        {
//            cout << e.what() << "\n";
//            if(chances==0)
//            {
//                cout<<"Sorry,we have to exist Program, Try Later";
//                break;
//            }
//            cout << "You have " << chances << "Chances"<<"\n";
//        }
//    }
    //this number of chances;
//    int chances=3;
//    while(chances--)
//    {
//       //Admin:
//        try
//        {
//            fstream admins("admin.txt",ios::app);
//            int id;
//            cout << "Enter an ID: ";
//            cin >> id;
//            string name,password;
//            cout << "Enter a Name: ";
//            cin >> name;
//            cout << "Enter a password: ";
//            cin >> password;
//            double salary;
//            cout << "Enter an Salary: ";
//            cin >> salary;
//            system("cls");
//            Admin a(id,name,password,salary);
//            admins << a.get_id() << '|' << a.get_name() << '|' <<a.get_password() << '|' << a.get_salary() << "\n";
//            admins.close();
//            cout << "Hello to the Bank\n";
//            Admin admin = Parser::Parse_To_Admin("1|Tarekmasoud|mansour@route123|8000");
//            admin.Display_Info();
//            a.Display_Info();
//            break;
//        }
//        catch(exception&e)
//        {
//            cout << e.what() << "\n";
//            if(chances==0)
//            {
//                cout<<"Sorry,we have to exist Program, Try Later";
//                break;
//            }
//            cout << "You have " << chances << "Chances"<<"\n";
//        }
//    }

}


