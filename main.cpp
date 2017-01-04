#include <string>
#include <vector>
#include <iostream>
#include <json/json.h>
#include "VehicleManager.cpp"
using namespace std;

int main()
{
  Vehicle test = Vehicle(10, 5, 0);

  if (test.bookSeat(3, 4, 10))
  {
    cout << "Booking success" << endl;
  }
  test.printMap(10);
}
