#include <string>
#include <vector>
#include "Vehicle.hpp"
using namespace std;

class VehicleManager
{
private:
  vector<Vehicle> vehicles;

public:
  VehicleManager();
  VehicleManager(string jsonFile);
  bool add(Vehicle newVehicle);
  bool remove(Vehicle toRemove);
  Vehicle get(int id);
  void toJson(string jsonFile);
}
