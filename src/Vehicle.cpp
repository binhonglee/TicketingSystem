#include <string>
#include "Vehicle.hpp"
using namespace std;

Vehicle::Vehicle(int length, int width, int id)
{
  type = "TBA";
  origin = "TBA";
  destination = "TBA";
  dateNtime = "TBA";
  this->length = length;
  this->width = width;
  this->id = id;
  initialize();
}

Vehicle::Vehicle(string type, int length, int width, string origin, string destination, string dateNtime, int id)
{
  this->type = type;
  this->length = length;
  this->width = width;
  this->origin = origin;
  this->destination = destination;
  this->dateNtime = dateNtime;
  this->id = id;
  initialize();
}

Vehicle::Vehicle(string type, int length, int width, string origin, string destination, string dateNtime, int id, vector< vector<int> > seatMap)
{
  this->type = type;
  this->length = length;
  this->width = width;
  this->origin = origin;
  this->destination = destination;
  this->dateNtime = dateNtime;
  this->id = id;
  this->seatMap = seatMap;
}

void Vehicle::setType(string type)
{
  this->type = type;
}

void Vehicle::setOrigin(string origin)
{
  this->origin = origin;
}

void Vehicle::setDestination(string destination)
{
  this->destination = destination;
}

void Vehicle::setDateNTime(string dateNtime)
{
  this->dateNtime = dateNtime;
}

string Vehicle::getType()
{
  return type;
}

int Vehicle::getLength()
{
  return length;
}

int Vehicle::getWidth()
{
  return width;
}

string Vehicle::getOrigin()
{
  return origin;
}

string Vehicle::getDestination()
{
  return destination;
}

string Vehicle::getDateNTime()
{
  return dateNtime;
}

int Vehicle::getId()
{
  return id;
}

void Vehicle::initialize()
{
  for (int i = 0; i < length; i++)
  {
    vector<int> row;
    for (int j = 0; j < width; j++)
    {
      row.push_back(-1);
    }
    seatMap.push_back(row);
  }
}

bool Vehicle::bookSeat(int x, int y, int guestId)
{
  if (checkAvailabilty(x, y))
  {
    seatMap[x][y] = guestId;
    return true;
  }

  return false;
}

bool Vehicle::checkAvailabilty(int x, int y)
{
  return seatMap[x][y] == -1;
}

int Vehicle::getGuest(int x, int y)
{
  return seatMap[x][y];
}

void Vehicle::printMap()
{
  printMap(-2);
}

void Vehicle::printMap(int guestId)
{
  for (int i = 0; i < length; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (seatMap[i][j] == -1)
      {
        cout << "A ";
      }
      else if (seatMap[i][j] == guestId)
      {
        cout << "U ";
      }
      else
      {
        cout << "X ";
      }
    }
    cout << endl;
  }
}
