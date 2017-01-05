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
  Json::Value vehicles;

  ifstream json(jsonFile.c_str(), ifstream::binary);

  bool parseSuccess = reader.parse(json, vehicles, false);

  if(parseSuccess)
  {
    Json::Value::Members mbr = vehicles.getMemberNames();

    for (vector<string>::const_iterator i = mbr.begin(); i != mbr.end(); i++)
    {
      Json::Value jsonVehicle = vehicles[*i];
      string vhcStr = "vehicle";

      if (vhcStr.compare(*i) == 0)
      {
        string placeholder = jsonVehicle.asString();
      }
      else
      {
        string type = jsonVehicle["Type"].asString();
        int length = jsonVehicle["Length"].asInt();
        int width = jsonVehicle["Width"].asInt();
        string origin = jsonVehicle["Origin"].asString();
        string destination = jsonVehicle["Destination"].asString();
        string dateNtime = jsonVehicle["DateNTime"].asString();
        int id = jsonVehicle["id"].asInt();

        Json::Value jsonSeatMap = jsonVehicle["SeatMap"];
        vector< vector<int> > seatMap;

        for (int i = 0; i < length; i++)
        {
          vector<int> row;

          for (int j = 0; i < width; j++)
          {
            row.push_back(jsonSeatMap[i][j].asInt());
          }

          seatMap.push_back(row);
        }

        Vehicle vehicle(type, length, width, origin, destination, dateNtime, id, seatMap);
        add(vehicle);
      }
    }
  }
}

bool VehicleManager::add(Vehicle newVehicle)
{
  if (newVehicle.getId() <= vehicle.back().getId())
  {
    return false;
  }

  vehicles.push_back(newVehicle);
  return (vehicles.back().getId() == newVehicle.getId());
}

bool VehicleManager::remove(Vehicle toRemove)
{
  for (int i = 0; i < vehicles.size(); i++)
  {
    if (vehicles.at(i).getId() == toRemove.getId())
    {
      vehicles.erase(vehicles.begin() + i);
      return true;
    }
  }

  return false;
}

Vehicle VehicleManager::get(int id)
{
  for (int i = 0; i < vehicles.size(); i++)
  {
    if (vehicles.at(i).getId() == id)
    {
      return vehicles.at(i);
    }
  }
}

void VehicleManager::toJson(string jsonFile)
{
  Json::Value jsonLib;

  for (int i = 0; i < vehicles.size(); i++)
  {
    Json::Value jsonVehicle;
    Vehicle vehicle  = vehicles.at(i);

    jsonVehicle["Type"] = vehicle.getType();
    jsonVehicle["Length"] = vehicle.getLength();
    jsonVehicle["Width"] = vehicle.getWidth();
    jsonVehicle["Origin"] = vehicle.getOrigin();
    jsonVehicle["Destination"] = vehicle.getDestination();
    jsonVehicle["DateNTime"] = vehicle.getDateNTime();
    jsonVehicle["id"] = vehicle.getId();

    int* seatMap = new int[vehicle.getLength()][vehicle.getWidth()];

    for (int i = 0; i < vehicle.getLength(); i++)
    {
      for (int j = 0; j < vehicle.getWidth(); j++)
      {
        seatMap[i][j] = vehicle.getGuest(i, y);
      }
    }

    jsonVehicle["SeatMap"]  = seatMap;
  }

  Json::StyledStreamWriter ssw(" ");
  ofstream jsonOutFile(jsonFile.c_str(), ofstream::binary);
  ssw.write(jsonOutFile, jsonLib);
}

int VehicleManager::getId()
{
  return (vehicles.back().getId() + 1);
}
