#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include "Vehicle.hpp"
using namespace std;

class VehicleManager
{
private:
  vector<Vehicle> vehicles;

public:
  VehicleManager();
  VehicleManager(string jsonFileName);
  bool add(Vehicle newVehicle);
  bool remove(Vehicle toRemove);
  Vehicle get(int id);
  void toJson(string jsonFileName);
  int getId();
};
