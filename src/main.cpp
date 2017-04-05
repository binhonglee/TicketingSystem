#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <json/json.h>
#include <exception>
#include "VehicleManager.hpp"
#include "LogInSystem.hpp"
using namespace std;

int main()
{
  string userFile = "database.txt";
  string vehicleFile = "vehiclesData.json";

  LogInSystem users;
  VehicleManager vehicles;

  ifstream userfile(userFile);
  if (userfile)
  {
    users = LogInSystem(userFile);
  }
  else
  {
    users = LogInSystem();
  }

  ifstream vehiclefile(vehicleFile);
  if (vehiclefile)
  {
    vehicles = VehicleManager(vehicleFile);
  }
  else
  {
    vehicles = VehicleManager();
  }


  int currentUser = -1;

  int userOption = -1;

  while (userOption != 0)
  {
    cout << "Please choose one of the following options :" << endl;
  	cout << "Log In       - 1" << endl;
  	cout << "Registration - 2" << endl;
  	cout << "Exit         - 0" << endl;

    cin >> userOption;

    switch (userOption)
    {
      case 1:
        if (users.getWrongPass() < 3)
        {
          currentUser = users.login();

          if (currentUser != -1)
          {
            users.loggedIn(users.getUser(currentUser));
          }
        }
        break;
      case 2: users.loggedIn(users.registration()); break;
      case 0: break;
      default:
        cout << "Invalid input. Please try again." << endl;
    }
  }

  users.toTxtFile(userFile);
  vehicles.toJson(vehicleFile);

  return 0;
}
