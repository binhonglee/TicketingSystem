#include <iostream>
#include <fstream>
#include <json/json.h>
#include <string>
#include <vector>
#include "Person.cpp"
using namespace std;

class LogInSystem
{
public:
  LogInSystem();
  LogInSystem(string filename);
  //Declaration of functions
  Person getUser(string);
  Person getUser(int);
  int getWrongPass();
  int login();
  void loggedIn(Person);
  Person registration();
  Person editCredentials(Person);
  void update(Person);
  string chgUsername();
  string chgPassword(Person);
  string chgEmail();
  string chgPhoneNo();
  void toTxtFile();

private:
  vector<Person> users;
  static int wrongPass = 0;
  static int globalUserId;
};
