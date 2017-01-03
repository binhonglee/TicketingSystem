#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Vehicle
{
private:
  string type;
  int length;
  int width;
  string origin;
  string destination;
  string dateNtime;
  int id;
  vector< vector<int> > seatMap;

public:
  Vehicle(int length, int width, int id);
  Vehicle(string type, int length, int width, string origin, string destination, string dateNtime, int id);
  void setType(string type);
  void setLength(int length);
  void setWidth(int width);
  void setOrigin(string origin);
  void setDestination(string origin);
  string getType();
  int getLength();
  int getWidth();
  string getOrigin();
  string getDestination();
  string getDateNTime();
  int getId();
  void initialize();
  bool bookSeat(int x, int y, int guestId);
  bool checkAvailabilty(int x, int y);
  void printMap(int guestId);
};
