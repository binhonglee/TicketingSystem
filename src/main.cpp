#include <string>
#include <vector>
#include <iostream>
#include <json/json.h>
#include "VehicleManager.hpp"
#include "LogInSystem.hpp"
using namespace std;

int main()
{
  LogInSystem users("database.txt");
  VehicleManager vehicles("vehiclesData.json");

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
        while (users.getWrongPass() < 3 && currentUser != -1)
        {
          currentUser = users.login();
        }
        break;
      case 2: users.loggedIn(users.registration()); break;
      case 0: break;
      default:
        cout << "Invalid input. Please try again." << endl;
    }
  }

  Vehicle test = Vehicle(10, 5, 0);

  if (test.bookSeat(3, 4, 10))
  {
    cout << "Booking success" << endl;
  }
  test.printMap(10);
}
