#ifndef SCREENS_H
#define SCREENS_H
#include<iostream>
#include "Validator.h"
#include "File_Helper.h"
#include "File_Manager.h"
#include "Employee.h"
#include "Admin.h"
#include "Client_Manager.h"
#include "Client.h"
#include "Employee_Manager.h"
#include "Admin_Manager.h"
#include <thread>
#include <chrono>
using namespace std;

class Screens
{
    // Methods to Draw:
private:
    // 1- Draw the word "BANK SYSTEM":
    static void Bank_Name()
    {
        // using ASCII art:
        cout << "===========================================\n";
        cout << "  ____  _   _ _   _ _  __   ____  _   _ _____ _____ _   _ __  __ \n";
        cout << " | __ )| | | | \\ | | |/ /  / ___|| | | |_   _| ____| \\ | |  \\/  |\n";
        cout << " |  _ \\| | | |  \\| | ' /   \\___ \\| | | | | | |  _| |  \\| | |\\/| |\n";
        cout << " | |_) | |_| | |\\  | . \\    ___) | |_| | | | | |___| |\\  | |  | |\n";
        cout << " |____/ \\___/|_| \\_|_|\\_\\  |____/ \\___/  |_| |_____|_| \\_|_|  |_|\n";
        cout << "===========================================\n";
    }
    // 2- Draw the word "WELCOME":
    static void Welcome()
    {
        // Change console color (Windows specific)
        system("Color 3f");
        cout << "===========================================\n";
        cout << " __        __   _      _   _   ___  __  __ _____ \n";
        cout << " \\ \\      / /  | |    | | | | / _ \\|  \\/  | ____|\n";
        cout << "  \\ \\ /\\ / /___| |    | | | || | | | |\\/| |  _|  \n";
        cout << "   \\ V  V / _ \\ | |__| |_| || |_| | |  | | |___ \n";
        cout << "    \\_/\\_/ \\___/ \\____/\\___/ \\___/|_|  |_|_____|\n";
        cout << "===========================================\n";
        Bank_Name();
        // Sleep for 3 seconds (cross-platform)
        this_thread::sleep_for(chrono::seconds(3));
        // Clear screen (Windows specific)
        system("cls");
        // Reset console color (Windows specific)
        system("Color 0f");
    }
    static void Login_Options()
    {
        cout << "(1) Admin\n";
        cout << "(2) Employee\n";
        cout << "(3) Client\n";
        cout << "Login As: ";
    }
    static int Login_As()
    {
        Login_Options();
        int choice;
        cin >> choice;
        if(choice==1||choice==2||choice==3)
        {
            system("cls");
            return choice;
        }
        else
        {
            system("cls");
            Login_As();
        }
    }
    static void Invalid(int c)
    {
        system("cls");
        cout << "Sorry,Invalid: Name or Password\n";
        Login_Screen(c);
    }
    static void Logout()
    {
        system("cls");
        Login_Screen(Login_As());
    }
    static void Login_Screen(int c)
    {
        int choice=c,id;
        string password;
        cout << "Enter AN ID: ";
        cin >> id;
        cout << "Enter A Password: ";
        cin >> password;
        switch(choice)
        {
        case 1:
            if(Admin_Manager::Login(id,password)!=NULL)
            {
                while(Admin_Manager::Admin_Option(Admin_Manager::Login(id,password))!=false);
                Logout();
            }
            else
            {
                Invalid(1);
            }
            break;
        case 2:
            if(Employee_Manager::Login(id,password)!=NULL)
            {
                while(Employee_Manager::Employee_Option(Employee_Manager::Login(id,password))!=false);
                Logout();
            }
            else
            {
                Invalid(2);
            }
            break;
        case 3:
            if(Client_Manager::Login(id,password)!=NULL)
            {
                while(Client_Manager::Client_Options(Client_Manager::Login(id,password))!=false);
                Logout();
            }
            else
            {
                Invalid(3);
            }
            break;
        default:
            system("cls");
            Login_As();
        }
    }
public:
    static void Run_App()
    {
        File_Manager::getAlldata();
        Welcome();
        Login_Screen(Login_As());
    }
};
#endif // SCREENS_H
