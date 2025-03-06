#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H
#include<iostream>
#include "Validator.h"
#include "File_Helper.h"
#include "File_Manager.h"
#include "Person.h"
#include "Client.h"
#include "Employee.h"
using namespace std;
class Client_Manager
{
    // Methods:
private:
    // print client menu:
    static void Print_Client_Menu()
    {
        system("cls");
        cout << "(1) Display My Info\n";
        cout << "(2) Check Balance\n";
        cout << "(3) Update Password\n";
        cout << "(4) Withdraw\n";
        cout << "(5) Deposit\n";
        cout << "(6) Transfer Amount\n";
        cout << "(7) Logout\n";
    }
    // this function to return again Print_Client_Menu();
    static void Return_Back(Client*client)
    {
        system("pause");
        Client_Options(client);
    }
public:
    // update password:
    static void Update_Password(Person*person)
    {
        person->set_password(Validator::Enter_Password());
        cout << "\nUpdate Password,Successfully\n";
    }
    // login:
    static Client*Login(int id,string password)
    {
        for(cl=allclients.begin(); cl!=allclients.end(); cl++)
        {
            if(cl->get_id()==id&&cl->get_password()==password)
            {
                // return iterator as pointer:
                return &(*cl);
            }
        }
        return NULL;
    }
    // client options:
    static bool Client_Options(Client*client)
    {
        Print_Client_Menu();
        Employee e;
        double amount;
        cout << "Select Your Choice: ";
        int choice,id;
        cin >> choice;
        switch(choice)
        {
        case 1:
            system("cls");
            client->Display_Info_Client();
            break;
        case 2:
            system("cls");
            client->Check_Balance();
            break;
        case 3:
            system("cls");
            Update_Password(client);
            File_Manager::updateClients();
            break;
        case 4:
            system("cls");
            cout << "Enter Your Amount: ";
            cin >> amount;
            client->WithDraw(amount);
            File_Manager::updateClients();
            break;
        case 5:
            system("cls");
            cout << "Enter Your Deposit: ";
            cin >> amount;
            client->Deposit(amount);
            File_Manager::updateClients();
            break;
        case 6:
            system("cls");
            cout << "ID You want to Transfer: ";
            cin >> id;
            while(e.Search_Client(id)==nullptr)
            {
                system("cls");
                cout << "Invalid ID\n";
                cout << "ID You want to Transfer: ";
                cin >> id;
            }
            cout << "Enter your Amount you want to transfer: ";
            cin >> amount;
            client->Ttansfer_To(amount,*e.Search_Client(id));
            File_Manager::updateClients();
            break;
        case 7:
            return false;
            break;
        default:
            system("cls");
            Client_Options(client);
            return true;
        }
        Return_Back(client);
        return true;
    }
};
#endif // CLIENT_MANAGER_H
