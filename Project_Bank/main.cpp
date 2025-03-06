#include<iostream>
#include<cmath>
#include<string>
#include <vector>
#include<exception>
#include<algorithm>
#include<fstream>
#include<sstream>
#include "Validator.h"
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "DataSourceInterface.h"
#include "Parser.h"
#include "File_Helper.h"
#include "File_Manager.h"
#include "Client_Manager.h"
#include "Employee_Manager.h"
#include "Admin_Manager.h"
#include "Screens.h"
#include <thread>
#include <chrono>
using namespace std;
int main()
{
    Screens::Run_App();
}
