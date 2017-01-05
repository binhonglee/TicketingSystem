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
  Vehicle(string type, int length, int width, string origin, string destination, string dateNtime, int id, vector< vector<int> > seatMap);
  void setType(string type);
  void setOrigin(string origin);
  void setDestination(string origin);
  void setDateNTime(string dateNtime);
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
  int getGuest(int x, int y);
  void printMap();
  void printMap(int guestId);
};
