#ifndef DATASOURCEINTERFACE_H
#define DATASOURCEINTERFACE_H
#include<iostream>
#include "Person.h"
#include "File_Helper.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include<vector>
using namespace std;
// Abstract Class <<< All Methods in this class are pure virtual <<< Equal to Zero <<< No implement;
class DataSourceInterface
{
protected:
    // i Know there is not virtual or zero but this is also abstarct;
    void Add_Client(Client c);
    void Add_Employee(Employee e);
    void Add_Admin(Admin a);
    void GetAllClient();
    void GetAllEmployee();
    void GetAllAdmin();
    void RemoveAllClient();
    void RemoveAllEmployee();
    void RemoveAllAdmin();
};
#endif // DATASOURCEINTERFACE_H
