#include <iostream>
#include <fstream>
#include <json/json.h>
#include <string>
#include <vector>
#include "Person.hpp"
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
  void toTxtFile(string filename);

private:
  vector<Person> users;
  int wrongPass;
  int globalUserId;
};
