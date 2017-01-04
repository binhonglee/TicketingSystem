#include <string>
#include <vector>
#include <iostream>
#include <json/json.h>
#include "VehicleManager.hpp"
using namespace std;

VehicleManager::VehicleManager()
{

}

VehicleManager::VehicleManager(string jsonFile)
{
  ifstream jsonFile(jsonFile.c_str());

  Json::Reader reader;
  Json::Value vehicle;

  ifstream json(jsonFile.c_str(), ifstream::binary);

  bool parseSuccess = reader.parse(json, vehicle, false);

  if(parseSuccess)
  {

  }
}
